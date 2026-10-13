#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004DFAC8[];
extern char D_004DFAB8[];
extern char D_004DFAD8[];
extern char D_004BC5D0[];
void operator_delete(void* allocation);
void Mem_Free(int a, void* p, char* file, int line);
}

struct Obj_3A2BA0 {
    virtual void Destroy(int flag);
};

struct Node_3A2BA0 {
    void* vtable;
    Node_3A2BA0* next;
    Node_3A2BA0* prev;
};

struct Self_3A2BA0 {
    void* vtable;
    Node_3A2BA0 head;
    Node_3A2BA0 tail;
    int count;
    Obj_3A2BA0* owned;
};

static inline void NodeDtor_3A2BA0(Node_3A2BA0* m)
{
    if (m) {
        m->vtable = D_004DFAB8;
        if (m)
            m->vtable = D_004DFAD8;
    }
}

extern "C" Self_3A2BA0* func_003A2BA0(Self_3A2BA0* self, short deleteFlag)
{
    if (self) {
        while (self->count != 0) {
            Node_3A2BA0* n = self->head.next;
            Node_3A2BA0* nx = n->next;
            Node_3A2BA0* pv = n->prev;
            pv->next = nx;
            nx->prev = pv;
            self->count--;
            {
                AllocGuard g;
                ((Obj_3A2BA0*)n)->Destroy(-1);
                Mem_Free(0, n, D_004BC5D0, 0x570);
            }
        }
        self->head.next = &self->tail;
        self->head.prev = &self->head;
        self->tail.next = &self->tail;
        self->tail.prev = &self->head;
        self->count = 0;
        Obj_3A2BA0* o = self->owned;
        if (o) {
            {
                AllocGuard g;
                o->Destroy(-1);
                Mem_Free(0, o, D_004BC5D0, 0x576);
            }
            self->owned = 0;
        }
        if (self) {
            self->vtable = D_004DFAC8;
            NodeDtor_3A2BA0(&self->tail);
            NodeDtor_3A2BA0(&self->head);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}


