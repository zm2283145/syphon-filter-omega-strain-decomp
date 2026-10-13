#pragma cplusplus on
#include "alloc_guard.h"
struct N_0013C030 { N_0013C030* left; N_0013C030* right; int f8; char val[4]; };
extern "C" {
void String_Dtor(void* p, short f);
void Mem_Free(int pool, void* p, const char* file, int line);
}
extern "C" void func_0013C030(void* t, N_0013C030* n)
{
    if (n->left) func_0013C030(t, n->left);
    if (n->right) func_0013C030(t, n->right);
    if (n->val) { if (n->val) String_Dtor(n->val, 0); }
    if (n) {
        AllocGuard g;
        Mem_Free(0, n, "allocator.hh", 0x64);
    }
}