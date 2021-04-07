# Interprocess Communication

**Interprocess communication(IPC)** are required since processes are seperated different [virtual address space](). There are multiple IPC mechanism in modern Unix systems:

- **Pipe**.
- **FIFO** or **named pipe**.
- **Message Queue**.
- **Signal**.
- **Semaphore**.
- **Shared Memory**.
- [**Socket**](). Socket interface can be used to both local machine IPC and **network IPC**. Socket interface is a general-purpose interface which provides multiple transportation-level protocols support.
