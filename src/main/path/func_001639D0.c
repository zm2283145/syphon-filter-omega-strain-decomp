#pragma cplusplus on

#include "types.h"

extern "C" {
extern char D_004D9740[];
extern char D_004D9730[];
extern char D_004D9720[];
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
        m->vtable = D_004D9730;
        if (m)
            m->vtable = D_004D9720;
    }
}

extern "C" Obj_3A3210* func_001639D0(Obj_3A3210* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004D9740;
        MemberDtor_3A3210(&self->b);
        MemberDtor_3A3210(&self->a);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}