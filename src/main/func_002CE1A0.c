#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004AD148[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
}

struct Str_CE1A0 { int w[3]; };
extern "C" Str_CE1A0* func_0013BCB0(Str_CE1A0* self, const Str_CE1A0* src);

struct Val_CE1A0 {
    int a;
    int b;
    Str_CE1A0 s8;
    Str_CE1A0 s14;
    int f20;
    int f24;
};

struct Node_CE1A0 {
    Node_CE1A0* prev;
    Node_CE1A0* next;
    Val_CE1A0 value;
};

struct List_CE1A0 {
    int count;
    int alloc;
};

struct Flag_CE1A0 {
    char c;
    Flag_CE1A0() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_CE1A0() {}
};

struct Holder_CE1A0;
extern "C" {
int func_002CE4D0(Holder_CE1A0* h);
Node_CE1A0* func_002CE4E0(Holder_CE1A0* h);
int func_002CE4C0(Holder_CE1A0* h);
void func_002CE420(int alloc, Node_CE1A0* n, int count);
}

struct Holder_CE1A0 {
    int* alloc;
    Node_CE1A0* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_CE1A0()
    {
        if (func_002CE4E0(this))
            func_002CE420(func_002CE4D0(this), func_002CE4E0(this), func_002CE4C0(this));
    }
};



extern "C" int func_002CE1A0(Node_CE1A0** result, List_CE1A0* list, Node_CE1A0** pos, const Val_CE1A0* value)
{
    Node_CE1A0* n;
    int* alloc = &list->alloc;
    Flag_CE1A0 flag;
    {
        AllocGuard guard;
        n = (Node_CE1A0*)Mem_Alloc(0, 0x30, D_004AD148, 0x5C);
    }
    Holder_CE1A0 h;
    h.alloc = alloc;
    h.node = n;
    Val_CE1A0* v = &h.node->value;
    if (v) {
        v->a = value->a;
        v->b = value->b;
        func_0013BCB0(&v->s8, &value->s8);
        func_0013BCB0(&v->s14, &value->s14);
        v->f20 = value->f20;
        v->f24 = value->f24;
    }
    Node_CE1A0* p;
    Node_CE1A0* m = h.node;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    return 0;
}

