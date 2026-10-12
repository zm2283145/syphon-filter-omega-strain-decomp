#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3B7270 { int v; E_3B7270(const E_3B7270& o) { v = o.v; } };
struct Vec_3B7270 { unsigned int cap; unsigned int count; E_3B7270* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3B7270;
extern "C" {
extern Err_3B7270* D_00489738;
extern char D_0049F388[];
extern char D_004A6460[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void func_00121B60(void);
void func_00123BE8(void* s, char* msg);
void func_0022A770(Vec_3B7270* a, Vec_3B7270* b);
void func_001C4F10(Vec_3B7270* a);
}

static inline E_3B7270* Alloc_3B7270(unsigned int n) { AllocGuard g; return (E_3B7270*)Mem_Alloc(0, n * sizeof(E_3B7270), D_004A6460, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void AnchorKeys_Reserve(Vec_3B7270* v0, unsigned int n0)
{
    Vec_3B7270* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x1800000) {
            func_00123BE8(D_00489738->stream, "vector::reserve length error\n");
            func_00121B60();
        }
        {
            E_3B7270* d; E_3B7270* s; E_3B7270* e; Vec_3B7270 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3B7270(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3B7270(*s);
                tmp.count++;
            }
            func_0022A770(&tmp, v);
            func_001C4F10(&tmp);
            {
                E_3B7270* p = tmp.data;
                if (p) { if (p) { AllocGuard g; Mem_Free(0, p, D_0049F388, 0x64); } }
            }
        }
    }
}
#pragma pop