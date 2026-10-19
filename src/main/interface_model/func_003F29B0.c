#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3F29B0 { float x, y; E_3F29B0(const E_3F29B0& o) { x = o.x; y = o.y; } };
struct Vec_3F29B0 { unsigned int cap; unsigned int count; E_3F29B0* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3F29B0;
extern "C" {
extern Err_3F29B0* D_00489738;
extern char D_004BE100[];
extern char D_004BE140[];
extern char D_004BE170[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void func_003F2970(Vec_3F29B0* a, Vec_3F29B0* b);
void func_003F4390(Vec_3F29B0* a);
}

static inline E_3F29B0* Alloc_3F29B0(unsigned int n) { AllocGuard g; return (E_3F29B0*)Mem_Alloc(0, n * sizeof(E_3F29B0), D_004BE170, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void func_003F29B0(Vec_3F29B0* v0, unsigned int n0)
{
    Vec_3F29B0* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0xC00000) {
            Libc_Fprintf(D_00489738->stream, D_004BE100);
            Libc_Abort();
        }
        {
            E_3F29B0* d; E_3F29B0* s; E_3F29B0* e; Vec_3F29B0 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3F29B0(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3F29B0(*s);
                tmp.count++;
            }
            func_003F2970(&tmp, v);
            func_003F4390(&tmp);
            {
                E_3F29B0* p = tmp.data;
                if (p) { if (p) { AllocGuard g; Mem_Free(0, p, D_004BE140, 0x64); } }
            }
        }
    }
}
#pragma pop