#pragma cplusplus on
#include "types.h"

typedef struct LNode_3EE610 { struct LNode_3EE610* prev; struct LNode_3EE610* next; void* val; } LNode_3EE610;
struct It_3EE610 { LNode_3EE610* n; };

struct Self_3EE610;
extern "C" {
It_3EE610 func_003ED850(void* l);
void func_003ED860(It_3EE610* out, It_3EE610* in);
It_3EE610 func_003ED870(void* l);
void func_003F43D0(void* p, float f);
int func_003EE610(Self_3EE610* self, float f);
}
struct ItE_3EE610 : It_3EE610 { ItE_3EE610(const ItE_3EE610& o) { n = o.n; } ItE_3EE610(const It_3EE610& t) { func_003ED860((It_3EE610*)this, (It_3EE610*)&t); } };
struct Self_3EE610 {
    char pad0[0x60]; unsigned char b60; char pad61[0x6C - 0x61];
    unsigned short n6C; unsigned short n6E; char pad70[0x84 - 0x70];
    Self_3EE610** a84; void* p88; char l8C[0xD0 - 0x8C];
};
static inline ItE_3EE610 B0_3EE610(void* l) { return ItE_3EE610(func_003ED870(l)); }
static inline ItE_3EE610 E0_3EE610(void* l) { return ItE_3EE610(func_003ED850(l)); }
static inline ItE_3EE610 B1_3EE610(void* l) { return B0_3EE610(l); }
static inline ItE_3EE610 BeginE_3EE610(void* l) { return B1_3EE610(l); }
static inline ItE_3EE610 End_3EE610(void* l) { return E0_3EE610(l); }
static inline bool Ne_3EE610(const It_3EE610& a, const ItE_3EE610& b) { return a.n != b.n; }

extern "C" int func_003EE610(Self_3EE610* self, float f)
{
    if (self->b60) {
        It_3EE610 it = ItE_3EE610(BeginE_3EE610(self->l8C));
        while (Ne_3EE610(it, End_3EE610(self->l8C))) {
            func_003F43D0(it.n->val, f);
            it.n = it.n->next;
        }
        { int i; for (i = 0; i < self->n6E; i++) func_003EE610(self->a84[i], f); }
    }
    return 1;
}



