#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3FECD0 { __int128 q; E_3FECD0(const E_3FECD0& o) { q = o.q; } };
struct Vec_3FECD0 { unsigned int cap; unsigned int count; E_3FECD0* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3FECD0;
extern "C" {
extern Err_3FECD0* D_00489738;
extern char D_004BE520[];
extern char D_004BE530[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void func_003FEC90(Vec_3FECD0* a, Vec_3FECD0* b);
void func_003F4390(Vec_3FECD0* a);
}

static inline E_3FECD0* Alloc_3FECD0(unsigned int n) { AllocGuard g; return (E_3FECD0*)Mem_Alloc(0, n * sizeof(E_3FECD0), D_004BE530, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void func_003FECD0(Vec_3FECD0* v0, unsigned int n0)
{
    Vec_3FECD0* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, "vector::reserve length error\n");
            Libc_Abort();
        }
        {
            E_3FECD0* d; E_3FECD0* s; E_3FECD0* e; Vec_3FECD0 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3FECD0(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3FECD0(*s);
                tmp.count++;
            }
            func_003FEC90(&tmp, v);
            tmp.count = 0;
            {
                E_3FECD0* p = tmp.data;
                if (p) { if (p) { AllocGuard g; Mem_Free(0, p, D_004BE520, 0x64); } }
            }
        }
    }
}
#pragma pop