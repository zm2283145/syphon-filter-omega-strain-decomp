#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct E_6840 { char a[0x10]; char b[0x170]; };
struct V_6840 { unsigned int cap; unsigned int count; E_6840* data; };
typedef struct { char pad[0xC]; void* stream; } Err_6840;
extern "C" {
extern Err_6840* D_00489738;
extern char D_004BC4E0[];
extern char D_004BCFB8[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void func_00121B60(void);
void func_00123BE8(void* s, char* msg);
void* func_00139BC0(unsigned int size, void* p);
void func_003B6B20(void* d, E_6840* s);
void func_003B6F70(void* d, E_6840* s);
void func_003B6DC0(void* d, void* s);
void func_00396D80(E_6840* p, int flag);
void func_00396D00(V_6840* v);
void func_00396260(void* p, int a, int b, char* file, int line);
}

static inline const unsigned int& Min_6840(const unsigned int& a, const unsigned int& b) { return (b < a) ? b : a; }
static inline E_6840* Alloc_6840(unsigned int n) { AllocGuard g; return (E_6840*)Mem_Alloc(0, n * sizeof(E_6840), D_004BCFB8, 0x5C); }

extern "C" void func_003B6840(V_6840* v, E_6840* first, E_6840* last)
{
    unsigned int n = last - first;
    if (n <= v->cap) {
        E_6840* e = v->data + Min_6840(n, v->count);
        E_6840* p = v->data;
        for (; p < e; p++, first++) {
            func_003B6F70(p, first);
            func_003B6DC0(p->b, first->b);
        }
        if (n < v->count) {
            E_6840* end = v->data + v->count;
            for (; p < end; p++) func_00396D80(p, -1);
            v->count = n;
        } else if (v->count < n) {
            for (; first != last; first++, p++) {
                void* o = func_00139BC0(sizeof(E_6840), p);
                if (o) func_003B6B20(o, first);
                v->count++;
            }
        }
    } else {
        if (n > 0x40000) {
            func_00123BE8(D_00489738->stream, "vector::assign length error\n");
            func_00121B60();
        }
        func_00396D00(v);
        if (v->data) {
            if (v->data) func_00396260(v->data, 0, 0, D_004BC4E0, 0x64);
            v->data = 0;
            v->cap = 0;
        }
        {
            E_6840** pdata = &v->data;
            *pdata = Alloc_6840(n);
        }
        v->cap = n;
        {
            E_6840* p = v->data;
            for (; first != last; first++, p++) {
                void* o = func_00139BC0(sizeof(E_6840), p);
                if (o) func_003B6B20(o, first);
                v->count++;
            }
        }
    }
}




