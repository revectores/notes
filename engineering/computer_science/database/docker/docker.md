# Docker

### 1. Basic Concepts

A **container** is a process on that has been isolated from all other processes on the machine. That isolation leverages Linux kernel **namespaces** and **cgroups**.

A **container image** is a binary file that provides the (isolated) file system which provides all the dependencies, configurations, scripts, binaries which are required to create a container.







### 2. Docker Container Implementation

##### # `namespaces`

Docker implement isolation based on **namespaces** and **cgroups**.

The `clone()` system call provides a flags bit mask that modifies their behavior and allows the caller to specify what is shared between the calling process and the child process.  For instance, if we set `CLONE_NEWPID` flag:

```c
int pid = clone(func, stack_size, CLONE_NEWPID | SIGCHLD, NULL);
```

Then the process will be created in a new PID namespace. Multiple types of namespaces can be created by specifying different flags in format `CLONE_NEW*`. The avaliable flags(namespaces) are listed below:

- `CLONE_NEWCGROUP`
- `CLONE_NEWIPC`
- `CLONE_NEWNET`
- `CLONE_NEWNS`
- `CLONE_NEWPID`
- `CLONE_NEWUSER`
- `CLONE_NEWUTS`



##### # `cgroups`

Linux control group is a mechanism to limit the resource usage of a process group, including CPU, memory, external storage, network bandwidth, etc.

The interface of cgroups is a special file system:

```shell
>> mount -t cgroup
cgroup on /sys/fs/cgroup/systemd type cgroup (rw,nosuid,nodev,noexec,relatime,xattr,name=systemd)
cgroup on /sys/fs/cgroup/freezer type cgroup (rw,nosuid,nodev,noexec,relatime,freezer)
cgroup on /sys/fs/cgroup/devices type cgroup (rw,nosuid,nodev,noexec,relatime,devices)
cgroup on /sys/fs/cgroup/pids type cgroup (rw,nosuid,nodev,noexec,relatime,pids)
cgroup on /sys/fs/cgroup/net_cls,net_prio type cgroup (rw,nosuid,nodev,noexec,relatime,net_cls,net_prio)
cgroup on /sys/fs/cgroup/hugetlb type cgroup (rw,nosuid,nodev,noexec,relatime,hugetlb)
cgroup on /sys/fs/cgroup/cpu,cpuacct type cgroup (rw,nosuid,nodev,noexec,relatime,cpu,cpuacct)
cgroup on /sys/fs/cgroup/perf_event type cgroup (rw,nosuid,nodev,noexec,relatime,perf_event)
cgroup on /sys/fs/cgroup/rdma type cgroup (rw,nosuid,nodev,noexec,relatime,rdma)
cgroup on /sys/fs/cgroup/blkio type cgroup (rw,nosuid,nodev,noexec,relatime,blkio)
cgroup on /sys/fs/cgroup/memory type cgroup (rw,nosuid,nodev,noexec,relatime,memory)
cgroup on /sys/fs/cgroup/cpuset type cgroup (rw,nosuid,nodev,noexec,relatime,cpuset)
```

Each directory represents a type of resource that can be limited by cgroups mechanism, consisting of multiple configuration file. For instance, here is the avaliable configuration file of `cpu,cpuacct` (CPU and CPU accounting)

```shell
>> ls /sys/fs/cgroup/cpu,cpuacct
cgroup.clone_children  cpu.shares         cpuacct.usage_percpu       docker             user.slice
cgroup.procs           cpu.stat           cpuacct.usage_percpu_sys   notify_on_release
cgroup.sane_behavior   cpuacct.stat       cpuacct.usage_percpu_user  release_agent
cpu.cfs_period_us      cpuacct.usage      cpuacct.usage_sys          system.slice
cpu.cfs_quota_us       cpuacct.usage_all  cpuacct.usage_user         tasks
```

We create a new group by creating a new directory under the cgroup subsystem directory, at the same time the operating system will copy the avaliable configuration files for us:

```shell
>> cd /sys/fs/cgroup/cpu,cpuacct
>> mkdir container
>> cd container
>> ls
cgroup.clone_children  cpu.shares     cpuacct.usage_all          cpuacct.usage_sys
cgroup.procs           cpu.stat       cpuacct.usage_percpu       cpuacct.usage_user
cpu.cfs_period_us      cpuacct.stat   cpuacct.usage_percpu_sys   notify_on_release
cpu.cfs_quota_us       cpuacct.usage  cpuacct.usage_percpu_user  tasks
```

Now construct an endless loop, and `top` to verify the CPU usage before and after adding it to a cgroup with limited CPU resource:

```c++
> pwd
/sys/fs/cgroup/cpu,cpuacct/container
> cat cpu.cfs_quota_us
-1
> cpu.cfs_period_us
100000

> while : ; do : ; done &
> top
> echo 20000 > cpu.cfs_quota_us
> echo ${pid} > tasks
> top
```

The CPU usage should be decreased to 20% now.

