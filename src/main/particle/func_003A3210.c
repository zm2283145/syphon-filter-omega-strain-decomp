#pragma cplusplus on

#include "types.h"

/* Deleting destructor with two inlined member destructors (vtable chains). */
extern "C" {
extern char D_004DFAC8[];
extern char D_004DFAB8[];
extern char D_004DFAD8[];
void operator_delete(void* allocation);
}

struct Member_3A3210 { void* vtable; };
struct Obj_3A3210 {
    void* vtable;
    Member_3A3210 a;
    int pad[2];
    Member_3A3210 b;
};

static inline void MemberDtor_3A3210(Member_3A3210* m)
{
    if (m) {
        m->vtable = D_004DFAB8;
        if (m)
            m->vtable = D_004DFAD8;
    }
}

extern "C" Obj_3A3210* func_003A3210(Obj_3A3210* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DFAC8;
        MemberDtor_3A3210(&self->b);
        MemberDtor_3A3210(&self->a);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}