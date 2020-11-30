# CUDA Introduction

**CUDA(Compute Unified Device Architecture)** is a parallel computing platform and application programming interface model created by [Nvidia]().

Host: The CPU and its memory (host memory) 

Device: The GPU and its memory (device memory).

GPU connected to PCI-e, hence GPU also connects to the host memory. On the contrary, CPU cannot read device memory normally. Copy action can be executed between host memory and device memory in both directions, which can usually be the bottleneck of GPU computation.

A computer with both CPU and GPU is considered **heterogeneous**.



Basic `Hello, world` program with device code:

```c
__device__ void device_func(void){}
__global__ void kernel_func(void){
	device_func();
}

int main() {
    kernel_func<<<1,1>>>();
    printf();
    return 0;
}
```

`__global__` keyword indicates the function is running on the device but invoked in the kernel. `__device__` indicates the function is running on the device and invoked in the device.



```c
__global__ void add(int *a, int *b, int *c){
    *c = *a + *b;
}
```

Note the the parameter pointers should be 



`cudaMalloc()`, `cudaFree()`, `cudaMemcpy()` functions are provided for memory management.

```c
cudaMemcpy(
    void*		dst,
	const void*	src,
	size_t		count,
	enum		type,
);
```



```c
int main(void) {
	int a, b, c;
    
}
```





