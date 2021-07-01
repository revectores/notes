# leveldb Log Format

The log file contents are a sequence of 32KB blocks. The only exception is that the tail of the file may contain a partial block:

```
log := block* partial_block?
```

Each block consists of a sequence of records:

```
block  := record* tailer?

record :=
	checksum: uint32    // crc32c of type and data[]; little-endian
	length:   uint16    // little-endian
	type:     uint8
	data:     uint8[length]
	
type := FULL | FIRST | MIDDLE | LAST
```

- `FULL` record contains the contents of an entire user record.
- `FIRST`, `MIDDLE`, `LAST` are types used for user records that have been split into multiple fragments.

A record never starts within the last 6 bytes of a block since `sizeof(uint32) + sizeof(uint16) + sizeof(uint8) = 7`. Any leftover bytes here form the trailer, which must consist entirely of zero bytes and must be skipped by readers. If exactly 7 bytes sare left in the current block, a `FIRST` record **must** be emit and then emit all of other data in subsequent blocks if the new record is non-empty.

For instance, consider a sequence of user records

```
A: length 1000
B: length 97270
C: length 8000
```

- A will be stored as a `FULL` record in the first block.
- B will be split into three fragments:
  - The first fragment will be stored as a `FIRST` record and occupies the rest of the second block.
  - The second fragment will be stored as a `MIDDLE` record and occupies the entirety of the second block.
  - The third fragment will be stored as a  `LAST` record and occupies a prefix of the third block, and left exactly 6 Bytes free since `32768 * 3 - (1000 + 7) - (97270 + 7 * 3) = 6`.
- C will be stored as a `FULL` record in the fourth block.

