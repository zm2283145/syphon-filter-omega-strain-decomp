#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3F3150 { float x, y, z, w; E_3F3150(const E_3F3150& o) { x = o.x; y = o.y; z = o.z; w = o.w; } };
struct Vec_3F3150 { unsigned int cap; unsigned int count; E_3F3150* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3F3150;
extern "C" {
extern Err_3F3150* D_00489738;
extern char D_004BE100[];
extern char D_004BE130[];
extern char D_004BE160[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void std_swap_vectordeleterR_vectordeleterR_44(Vec_3F3150* a, Vec_3F3150* b);
void func_003F43A0(Vec_3F3150* a);
}

static inline E_3F3150* Alloc_3F3150(unsigned int n) { AllocGuard g; return (E_3F3150*)cMemMan_Allocate(0, n * sizeof(E_3F3150), D_004BE160, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void func_003F3150(Vec_3F3150* v0, unsigned int n0)
{
    Vec_3F3150* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, D_004BE100);
            Libc_Abort();
        }
        {
            E_3F3150* d; E_3F3150* s; E_3F3150* e; Vec_3F3150 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3F3150(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3F3150(*s);
                tmp.count++;
            }
            std_swap_vectordeleterR_vectordeleterR_44(&tmp, v);
            func_003F43A0(&tmp);
            {
                E_3F3150* p = tmp.data;
                if (p) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BE130, 0x64); } }
            }
        }
    }
}
#pragma pop