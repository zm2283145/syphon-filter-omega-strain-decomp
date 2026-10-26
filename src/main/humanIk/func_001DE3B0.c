#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
/* ReorderList_uint_cQuaternionP_uintP: reorder 16-byte elements in place by an order table (same family as ReorderList_uint_cJointLimitsP_uintP) */
extern "C" {
void* Mem_Alloc(int, int, char*, int);
int Mem_Free(int, void*, char*, int);
extern char D_004A0170[];
}
template <class T> static inline void Swap1DE3B0(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct Q1DE3B0 {
    float x, y, z, w;
    Q1DE3B0() {}
    // 128-bit lq/sq quadword copy idiom
    Q1DE3B0(const Q1DE3B0& o) { Q1DE3B0* d = this; const Q1DE3B0* s = &o; __int128 t; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    // 128-bit lq/sq quadword copy idiom
    Q1DE3B0& operator=(const Q1DE3B0& o) { Q1DE3B0* d = this; const Q1DE3B0* s = &o; __int128 t; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" void ReorderList_uint_cQuaternionP_uintP(unsigned int n, Q1DE3B0* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)Mem_Alloc(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE3B0(data[k], data[j]);
        Swap1DE3B0(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        Mem_Free(0, tmp, D_004A0170, 0x7C3);
    }
}
