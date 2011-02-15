#ifndef threadprivate_h
#define threadprivate_h

extern int* a;
extern int b;

#pragma omp threadprivate(a,b)

#endif
