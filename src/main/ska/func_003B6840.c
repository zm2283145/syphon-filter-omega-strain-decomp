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
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void* Mem_PlacementNew(unsigned int size, void* p);
void cSkaAnimAnchorListEntry_ctor(void* d, E_6840* s);
void cString4_opAssign(void* d, E_6840* s);
void cSkaAnimAnchor_opAssign(void* d, void* s);
void cSkaAnimAnchorListEntry_dtor(E_6840* p, int flag);
void std_vector_deleter_cSkaAnimAnchorListEntry_clear(V_6840* v);
void opDelete_cSkaAnimAnchorListEntryP_int_bool_charP_etc(void* p, int a, int b, char* file, int line);
}

static inline const unsigned int& Min_6840(const unsigned int& a, const unsigned int& b) { return (b < a) ? b : a; }
static inline E_6840* Alloc_6840(unsigned int n) { AllocGuard g; return (E_6840*)Mem_Alloc(0, n * sizeof(E_6840), D_004BCFB8, 0x5C); }

extern "C" void std_vector_imp_cSkaAnimAnchorListEntry_do_assign(V_6840* v, E_6840* first, E_6840* last)
{
    unsigned int n = last - first;
    if (n <= v->cap) {
        E_6840* e = v->data + Min_6840(n, v->count);
        E_6840* p = v->data;
        for (; p < e; p++, first++) {
            cString4_opAssign(p, first);
            cSkaAnimAnchor_opAssign(p->b, first->b);
        }
        if (n < v->count) {
            E_6840* end = v->data + v->count;
            for (; p < end; p++) cSkaAnimAnchorListEntry_dtor(p, -1);
            v->count = n;
        } else if (v->count < n) {
            for (; first != last; first++, p++) {
                void* o = Mem_PlacementNew(sizeof(E_6840), p);
                if (o) cSkaAnimAnchorListEntry_ctor(o, first);
                v->count++;
            }
        }
    } else {
        if (n > 0x40000) {
            Libc_Fprintf(D_00489738->stream, "vector::assign length error\n");
            Libc_Abort();
        }
        std_vector_deleter_cSkaAnimAnchorListEntry_clear(v);
        if (v->data) {
            if (v->data) opDelete_cSkaAnimAnchorListEntryP_int_bool_charP_etc(v->data, 0, 0, D_004BC4E0, 0x64);
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
                void* o = Mem_PlacementNew(sizeof(E_6840), p);
                if (o) cSkaAnimAnchorListEntry_ctor(o, first);
                v->count++;
            }
        }
    }
}




