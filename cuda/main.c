int main(void)
{
    // Initialize
    if (cuInit(0) != CUDA_SUCCESS)
	exit (0);
    // Get number of devices supporting CUDA
    int deviceCount = 0;
    cuDeviceGetCount(&deviceCount);
    if (deviceCount == 0) {
	printf("There is no device supporting CUDA.\n");
	exit (0);
    }
    // Get handle for device 0
    CUdevice cuDevice = 0;
    cuDeviceGet(&cuDevice, 0);
    // Create context
    CUcontext cuContext;
    cuCtxCreate(&cuContext, 0, cuDevice);
    // Create module from binary file
    CUmodule cuModule;
    cuModuleLoad(&cuModule, “VecAdd.ptx”);
    // Get function handle from module
    CUfunction vecAdd;
    cuModuleGetFunction(&vecAdd, cuModule, "VecAdd");
    // Allocate vectors in device memory
    size_t size = N * sizeof(float);
    CUdeviceptr d_A;


    cuMemAlloc(&d_A, size);
    CUdeviceptr d_B;
    cuMemAlloc(&d_B, size);
    CUdeviceptr d_C;
    cuMemAlloc(&d_C, size);
    // Copy vectors from host memory to device memory
    // h_A and h_B are input vectors stored in host memory
    cuMemcpyHtoD(d_A, h_A, size);
    cuMemcpyHtoD(d_B, h_B, size);
    // Invoke kernel
#define ALIGN_UP(offset, alignment)					\
    (offset) = ((offset) + (alignment) – 1) & ~((alignment) – 1)
    int offset = 0;
    ALIGN_UP(offset, __alignof(d_A));
    cuParamSetv(vecAdd, offset, &d_A, sizeof(d_A));
    offset += sizeof(d_A);
    ALIGN_UP(offset, __alignof(d_B));
    cuParamSetv(vecAdd, offset, &d_B, sizeof(d_B));
    offset += sizeof(d_B);
    ALIGN_UP(offset, __alignof(d_C));
    cuParamSetv(vecAdd, offset, &d_C, sizeof(d_C));
    offset += sizeof(d_C);
    cuParamSetSize(VecAdd, offset);
    int threadsPerBlock = 256;
    int blocksPerGrid =
	(N + threadsPerBlock – 1) / threadsPerBlock;
    cuFuncSetBlockShape(vecAdd, threadsPerBlock, 1, 1);
    cuLaunchGrid(VecAdd, blocksPerGrid, 1);
    // Copy result from device memory to host memory
    // h_C contains the result in host memory
    cuMemcpyDtoH(h_C, d_C, size);
    // Free device memory
    cuMemFree(d_A);
    cuMemFree(d_B);
    cuMemFree(d_C);

    return (0);
}
