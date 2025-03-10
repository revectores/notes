# TiCDC Sink Module

`Sink` module in `TiCDC` is responsible for dispatching binlog processed by other compoents of TiCDC to downstream systems, for instances, DTS, MySQL, or middlewares (Kafka, Pulsar, etc.).





##### # `Sink` Interface

The `Sink` interface is defined by six methods, where `EmitChangedEvents`, 

| Method                                                       |
| ------------------------------------------------------------ |
| `Initialize(ctx context.Context, tableInfo []*model.SimpleTableInfo) error` |
| `EmitChangedEvents(ctx context.Context, rows ...*model.RowChangedEvent) error` |
| `EmitDDLEvent(ctx context.Context, ddl *model.DDLEvent) error` |
| `FlushRowChangedEvents(ctx context.Context, resolvedTs uint64) (uint64, error)` |
| `EmitCheckpointTs(ctx context.Context, ts uint64) error`     |
| `Close() error`                                              |

```go
type Sink interface {
	Initialize(ctx context.Context, tableInfo []*model.SimpleTableInfo) error

	// EmitRowChangedEvents sends Row Changed Event to Sink
	// EmitRowChangedEvents may write rows to downstream directly;
	EmitRowChangedEvents(ctx context.Context, rows ...*model.RowChangedEvent) error

	// EmitDDLEvent sends DDL Event to Sink
	// EmitDDLEvent should execute DDL to downstream synchronously
	EmitDDLEvent(ctx context.Context, ddl *model.DDLEvent) error

	// FlushRowChangedEvents flushes each row which of commitTs less than or equal to `resolvedTs` into downstream.
	// TiCDC guarantees that all of Event which of commitTs less than or equal to `resolvedTs` are sent to Sink through `EmitRowChangedEvents`
	FlushRowChangedEvents(ctx context.Context, resolvedTs uint64) (uint64, error)

	// EmitCheckpointTs sends CheckpointTs to Sink
	// TiCDC guarantees that all Events **in the cluster** which of commitTs less than or equal `checkpointTs` are sent to downstream successfully.
	EmitCheckpointTs(ctx context.Context, ts uint64) error

	// Close closes the Sink
	Close() error
}
```

where the `resolvedTs` is the central concept of 

In the latest version of `TiCDC` 






where the `RowChangedEvent` represents a row changed event, composing of three types of fields:

- Table information: `Table`, `TableInfoVersion`.
- Row modifications:  `rowID int64`, `PreColumns`, `Columns`, `IndexColumns`.
- Transaction time information: `startTs`, `CommitTs`.

```go
// RowChangedEvent represents a row changed event
type RowChangedEvent struct {
	StartTs  uint64 `json:"start-ts"`
	CommitTs uint64 `json:"commit-ts"`

	RowID int64 `json:"row-id"`

	Table *TableName `json:"table"`

	TableInfoVersion uint64 `json:"table-info-version,omitempty"`

	Columns      []*Column `json:"columns"`
	PreColumns   []*Column `json:"pre-columns"`
	IndexColumns [][]int

	// approximate size of this event, calculate by tikv proto bytes size
	ApproximateSize int64
}
```





