#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(8)

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* func_00234BB0(void* self, int n);
extern char D_0053B544[];
extern char D_004BC5D0[];
}

struct Desc3A26A0 {
    char pad0[4];
    unsigned char b4;
    char pad5[0x5C - 5];
    int prio;
};

struct V43A26A0 {
    float x, y, z, w;
};

struct Node3A26A0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Desc3A26A0* GetDesc();
    virtual void v4();
    virtual int IsAttached();
    Node3A26A0* next;
    Node3A26A0* prev;
    unsigned char bC;
};

struct Head3A26A0 {
    void* vt;
    Node3A26A0* next;
    Node3A26A0* prev;
};

struct Mgr3A26A0 {
    void* vt;
    Head3A26A0 head;
    Head3A26A0 tail;
    int count;
    char pad20[0x50 - 0x20];
    float f50;
};

extern "C" {
Node3A26A0* func_003A0EA0(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f);
Node3A26A0* func_00398E20(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f);
Node3A26A0* func_0039F860(void* p, Node3A26A0* ins, Desc3A26A0* d, int a, float f, V43A26A0* v);
}

static inline void* Alloc3A26A0(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BC5D0, line);
}

static inline Node3A26A0* New3A26A0(Node3A26A0* ins, Desc3A26A0* d, int a3, float f)
{
    void* t = Alloc3A26A0(0x180, 0x59C);
    if (t)
        t = func_003A0EA0(t, ins, d, a3, f);
    return (Node3A26A0*)t;
}

extern "C" Node3A26A0* func_003A26A0(Mgr3A26A0* mgr, Node3A26A0* ins, int name, int a3, float f)
{
    Node3A26A0* t;
    bool found;
    Node3A26A0* n;
    Desc3A26A0* d;
    bool after;
    bool seen;

    d = *(Desc3A26A0**)func_00234BB0(D_0053B544, name);
    after = 0;
    if (d->b4 == 1) {
        t = New3A26A0(ins, d, a3, f);
    } else if (!ins || !ins->bC) {
        t = (Node3A26A0*)Alloc3A26A0(0x130, 0x5A3);
        if (t)
            t = func_00398E20(t, ins, d, a3, mgr->f50);
        if (ins && ins->IsAttached())
            after = 1;
    } else {
        t = (Node3A26A0*)Alloc3A26A0(0x180, 0x5AB);
        if (t) {
            V43A26A0 v;
            v.x = 0.0f;
            v.y = 1.0f;
            v.z = 0.0f;
            v.w = 0.0f;
            t = func_0039F860(t, ins, d, a3, mgr->f50, &v);
        }
    }
    found = 0;
    seen = 0;
    for (n = mgr->head.next; n != (Node3A26A0*)&mgr->tail; n = n->next) {
        if (!after) {
            if (d->prio >= n->GetDesc()->prio) {
                found = 1;
                Node3A26A0* p = n->prev;
                t->next = n;
                t->prev = p;
                p->next = t;
                n->prev = t;
                mgr->count++;
                break;
            }
        } else {
            if (seen && (n != ins || d->prio >= n->GetDesc()->prio)) {
                found = 1;
                Node3A26A0* p = n->prev;
                t->next = n;
                t->prev = p;
                p->next = t;
                n->prev = t;
                mgr->count++;
                break;
            }
            if (n == ins)
                seen = 1;
        }
    }
    if (!found) {
        Node3A26A0* p = mgr->tail.prev;
        t->next = (Node3A26A0*)&mgr->tail;
        t->prev = p;
        p->next = t;
        mgr->tail.prev = t;
        mgr->count++;
    }
    return t;
}



