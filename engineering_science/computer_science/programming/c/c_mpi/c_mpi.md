# C MPI

##### # Demo MPI Code









##### # Init and 





##### # Configuration Retriving

```c
int MPI_Comm_size(
	MPI_Comm	comm		/* in */
	int*		comm_sz_p	/* out */
)
```

```c
int MPI_Comm_rank(
	MPI_Comm	comm		/* in */
	int*		my_rank_p	/* out */
)
```





##### # `MPI_Send`



```c
int MPI_Send(
    void* msg_buf_p,				/* in */
	int msg_size,					/* in */
	MPI_Datatype msg_type,			/* in */
	int dest,						/* in */
	int tag,						/* in */
	MPI_Comm communicator			/* in */
)
```

```c
int MPI_Recv(
	void*			msg_buf_p,		/* out */
    int				buf_size,		/* in */
    MPI_Datatype	buf_type,		/* in */
    int				source,			/* in */
    int				tag,			/* in */
    MPI_Comm		communicator,	/* in */
    MPI_Status*		status_p		/* out */
)
```



The `MPI_Datatype`

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



##### # MPI From any source

```c
int MPI_Get_count(){
    
}
```







