#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3F3900 { float x, y, z, w; E_3F3900(const E_3F3900& o) { x = o.x; y = o.y; z = o.z; w = o.w; } };
struct Vec_3F3900 { unsigned int cap; unsigned int count; E_3F3900* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3F3900;
extern "C" {
extern Err_3F3900* D_00489738;
extern char D_004BE100[];
extern char D_004BE120[];
extern char D_004BE150[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void std_swap_vectordeleterR_vectordeleterR_45(Vec_3F3900* a, Vec_3F3900* b);
void func_003F43B0(Vec_3F3900* a);
}

static inline E_3F3900* Alloc_3F3900(unsigned int n) { AllocGuard g; return (E_3F3900*)Mem_Alloc(0, n * sizeof(E_3F3900), D_004BE150, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void func_003F3900(Vec_3F3900* v0, unsigned int n0)
{
    Vec_3F3900* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, D_004BE100);
            Libc_Abort();
        }
        {
            E_3F3900* d; E_3F3900* s; E_3F3900* e; Vec_3F3900 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3F3900(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3F3900(*s);
                tmp.count++;
            }
            std_swap_vectordeleterR_vectordeleterR_45(&tmp, v);
            func_003F43B0(&tmp);
            {
                E_3F3900* p = tmp.data;
                if (p) { if (p) { AllocGuard g; Mem_Free(0, p, D_004BE120, 0x64); } }
            }
        }
    }
}
#pragma pop