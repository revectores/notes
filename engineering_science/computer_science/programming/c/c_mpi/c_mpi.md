# C MPI

### 1. C MPI Introduction

##### # C MPI Demo Code

The [mpi_demo.c](src__mpi_demo/mpi_demo.c) is given to illustrate the fundamental structure of a C MPI program.



##### # C MPI Compiling

To compile the MPI program, use `mpicc`, a wrapper of `gcc`, which links to the headers and libraries that MPI required automatically:

```shell 
mpicc -g -Wall -o mpi_demo mpi_demo.c
```

Use `mpiexec` to run the MPI program:

```shell
mpiexec -n <number-of-processes> ./mpi_demo
```

here `-n` option sets the the number of processes it establishes.



##### # Naming Convention

The object name defined by MPI obey the two form:

- Start by `MPI_`.

- For variables and functions, the first character of name is captalized, for macros and constants, all of the characters are captalized.

By following the naming convention, one can easily tell whether an object is defined by MPI.







### 2. C MPI Fundamental Workflow

##### # `MPI_Init` and `MPI_Finalize`

`MPI_Init` initialize the MPI system:

```c
int MPI_Init(
	int*		argc_p		/* in/out */
    char***		argv_p		/* in/out */
);
```

The parameters `argc_p`, `argv_p` are pointers to `argc` and `argv`. Set `NULL` if not used. 

After all MPI operations finished, use `MPI_Finalize` to do the clean up:

```c
int MPI_Finalize(void);
```

All MPI operations should be invoked only between `MPI_Init` and `MPI_Finalize`.



##### # MPI Communicator

A **MPI communicator** is a collection of processes that can send messages to each other. The special global communicator `MPI_COMM_WORLD` consists all of the running programs, which is craeted by `MPI_Init`.

The communicator must be specified when send or receive messages. The propose of MPI communicator is creating a "communication space", avoiding accidentally send or receive to wrong processes.



##### # Communicator Configuration Retriving

The functions `MPI_Comm_size` and `MPI_Comm_rank` get number of processes and the rank of current process of given communicator `comm`.

```c
int MPI_Comm_size(
	MPI_Comm	comm		/* in */
	int*		comm_sz_p	/* out */
);
```

```c
int MPI_Comm_rank(
	MPI_Comm	comm		/* in */
	int*		my_rank_p	/* out */
);
```

For example, the [mpi_demo.c](src__mpi_demo/mpi_demo.c) use

```c
MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
```

to the number of processes and current process rank in global communicator `MPI_COMM_WORLD`.



##### # `MPI_Send`

The `MPI_Send` and `MPI_Recv` is a pair for communication. `MPI_Send` send message to the recevier:

```c
int MPI_Send(
    void* msg_buf_p,				/* in */
	int msg_size,					/* in */
	MPI_Datatype msg_type,			/* in */
	int dest,						/* in */
	int tag,						/* in */
	MPI_Comm communicator			/* in */
);
```

The first three parameters `msg_buf_p`, `msg_size` and `msg_type` determine the connect of message, and the last three parameters `dest`, `tag` and `communicator` determine the determination of message.

- `msg_buf_p` is a pointer to the message content.

- `msg_size` and `mg_type` specify how many bytes in memory should be sent. For instance, in [mpi_demo.c](src__mpi_demo/mpi_demo.c) `msg_size=strlen(greeting)+1`, `msg_type=MPI_CHAR`, which tell the MPI program to send `strlen(greeting)+1` bytes.

    Since it's not possible for the MPI function to use the C keyword as the argument, MPI provides the predefined constants in type [`MPI_Datatype`](#mpi_datatype) to represent type.

- `communicator` and `dest` set which recevier (by specifying communicator and the rank) should receive the message.

- `tag` is used to distinguish message sent by the same source.

`MPI_Recv` receive the message sent by `MPI_Send`:

```c
int MPI_Recv(
	void*			msg_buf_p,		/* out */
    int				buf_size,		/* in */
    MPI_Datatype	buf_type,		/* in */
    int				source,			/* in */
    int				tag,			/* in */
    MPI_Comm		communicator,	/* in */
    MPI_Status*		status_p		/* out */
);
```

To receive from specific source/tag, the parameters shall be set properly corespondingly in the receiver side. While there may be some cases that multiple senders might send messages in unpredicatable sequence, that is, we do not know which sender might send the message first. 

In such case the wildcard constants `MPI_ANY_SOURCE` and `MPI_ANY_TAG` can be filled to the `source` and `tag` parameter, which allows messages from any sources or any tags (in specified communicator) to be received. There is no a wildcard for communicator, that is, the communicator must always be specified.

When we filled source/tag with wildcard, `status_p` can be used to get the information about the source/tag, by examing its properties:

```c
MPI_Status status;

status.MPI_SOURCE;
status.MPI_TAG;
```

The retrieve of data size requires a function invocation:

```c
int MPI_Get_count (
    MPI_Status		status_p	/* in */,
    MPI_Datatype	type		/* in */,
    int*			count_p		/* out */
);
```



##### # `MPI_Datatype`

`MPI_Datatype` use to represent the type in C:

| `MPI_Datatype`       | C Datatype             |
| :------------------- | :--------------------- |
| `MPI_CHAR`           | `signed char`          |
| `MPI_SHORT`          | `signed short int`     |
| `MPI_INT`            | `signed int`           |
| `MPI_LONG`           | `signed long int`      |
| `MPI_LONG_LONG`      | `signed long long int` |
| `MPI_UNSIGNED_CHAR`  | `unsigned char`        |
| `MPI_UNSIGNED_SHORT` | `unsigned short int`   |
| `MPI_UNSIGNED`       | `unsigned int`         |
| `MPI_UNSIGNED_LONG`  | `unsigned long int`    |
| `MPI_FLOAT`          | `float`                |
| `MPI_DOUBLE`         | `double`               |
| `MPI_LONG_DOUBLE`    | `long double`          |
| `MPI_BYTE`           |                        |
| `MPI_PACKED`         |                        |







### 3. C MPI IO

The output file descriptor is avaliable for all the processors, while the input can only be read by process with rank `0`(the "controller" process). Some functions must be defined by the user to pass the input from process `0` into other processes.







### 4. C MPI Collective Communication

##### # MPI Data Reduction

`MPI_Reduce` collects the data in all the processes and reduce them by predefined `operator`, which encapsulates the process about manually construct propogation tree:

```c
int MPI_Reduce(
	void*			input_data_p,	/* in */
    void*			output_data_p,	/* out */
    int				count,			/* in */
    MPI_Datatype	datatype,		/* in */
    MPI_Op			operator,		/* in */
    int				dest_process,	/* in */
    MPI_Comm		comm			/* in */
);
```

To use the collective communication properly, note the following rules:

- All the processes in the same communicator must invoke the collective communication function.
- The `dest_process ` must be set as the same.

Since no `tag` is provided in the collective communication, if multiple communication are called, the mapping is simply depends on the order, for example:

| Time |         Process 0         |         Process 1         |         Process 2         |
| :--: | :-----------------------: | :-----------------------: | :-----------------------: |
|  0   |      `a = 1, c = 2`       |      `a = 1, c = 2`       |      `a = 1, c = 2`       |
|  1   | `MPI_Reduce(&a, &b, ...)` | `MPI_Reduce(&c, &d, ...)` | `MPI_Reduce(&a, &b, ...)` |
|  2   | `MPI_Reduce(&c, &d, ...)` | `MPI_Reduce(&a, &b, ...)` | `MPI_Reduce(&c, &d, ...)` |

Assume process 0 is configured as the destination, the final output will be `b=1+2+1=4` and `d=2+1+2=5`.

When using `MPI_Reduce`, the `output_data_p` is only avaliable for the one process that set to be the `dest_process`. To make all the processes get the output, use `MPI_Allreduce`:

```c
int MPI_Allreduce(
	void*			input_data_p,	/* in */
    void*			output_data_p,	/* out */
    int				count,			/* in */
    MPI_Datatype	datatype,		/* in */
	MPI_Op			operator		/* in */
	MPI_Comm		comm			/* in */
)
```

The only difference in the argument list is that `Allreduce` does not require `dest_process` since all processes shall get the output.



##### # `MPI_Op`

The list of operators supported by `MPI`:

|   Operator   |         Interpretation          |
| :----------: | :-----------------------------: |
|  `MPI_MAX`   |             maximum             |
|  `MPI_MIN`   |             minimum             |
|  `MPI_SUM`   |               sum               |
|  `MPI_PROD`  |             product             |
|  `MPI_LAND`  |           logical and           |
|  `MPI_BAND`  |           bitwise and           |
|  `MPI_LOR`   |           logical or            |
|  `MPI_BOR`   |           bitwise or            |
|  `MPI_LXOR`  |      logical exclusive or       |
|  `MPI_BXOR`  |      bitwise exclusive or       |
| `MPI_MAXLOC` | maximum and location of maximum |
| `MPI_MINLOC` | minimum and location of mimimum |



##### # Data Distribution

There are two basic approaches to distribute components of data into processes:

- **Block partition**, which compute how many data a process should have, and then devides the processes into blocks containing continuous data. For exmaple, if we devides data with id 1~12 into 3 processes, the block partition first compute each process got 4 data, and then devide from the start:

- | Process ID | Process 1  | Process 2  |   Process 3   |
    | :--------: | :--------: | :--------: | :-----------: |
    |    Data    | 1, 2, 3, 4 | 5, 6, 7, 8 | 9, 10, 11, 12 |

    

- **Cyclic partition**, which 



##### # MPI Data Distribution

Distribution is simply the reverse of reduction, boardcast is simply the reverse of reduce:

```c
int MPI_Bcast (
	void*			data_p,		/* in/out */
	int				count,		/* in */
	MPI_Datatype	datatype,	/* in */
	int				source_proc,/* in */
	MPI_Comm		comm,		/* in */
)
```

which boardcast the `data_p` into all process in communicator `comm`.

`Bcast` just simply send all the processes with the same data, to distribute the data to processes as different components, the `MPI_Scatter` function is designated:

```c
int MPI_Scatter (
	void*			send_buf_p,	/* in */
	int				send_count,	/* in */
	MPI_Datatype	send_type,	/* in */
	void*			recv_buf_p,	/* out */
    int				recv_count,	/* in */
    MPI_Datatype	recv_type,	/* in */
    int				src_proc,	/* in */
    MPI_Comm		comm		/* in */
)
```



