#pragma cplusplus on

#include "types.h"

/* Deleting destructor: unlink from the owner, orphan all children, free the list. */
typedef struct { int w[1]; } It_3963B0;
typedef struct Node_3963B0 { unsigned char pad[0xB0]; struct Node_3963B0* owner; int children; } Node_3963B0;

extern "C" {
void func_00393600(void* vec, Node_3963B0** value);
void func_001913C0(It_3963B0* out, void* vec);
void func_001913A0(It_3963B0* out, void* vec);
bool func_001912A0(It_3963B0* a, It_3963B0* b);
Node_3963B0** func_00191390(It_3963B0* it);
void func_001912C0(It_3963B0* it);
void func_00396590(void* vec);
void* func_003964A0(void* vec, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Node_3963B0* func_003963B0(Node_3963B0* self, short deleteFlag)
{
    if (self) {
        Node_3963B0* me = self;
        It_3963B0 it;
        It_3963B0 end;
        if (self->owner) {
            func_00393600(&self->owner->children, &me);
            me->owner = 0;
        }
        func_001913C0(&it, &self->children);
        func_001913A0(&end, &self->children);
        for (; func_001912A0(&it, &end); func_001912C0(&it))
            (*func_00191390(&it))->owner = 0;
        func_00396590(&self->children);
        {
            void* v = &self->children;
            if (v)
                func_003964A0(v, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}