#include "types.h"

typedef struct { char pad[0xC]; unsigned char flag; } Obj1E;

extern void std_vector_cCollisionEdgePtr_ctor(Obj1E* self);
extern void std_vector_cCollisionEdgePtr_push_back(Obj1E* self, int* value);

/* Initializes the object, sets its flag and assigns the given value; returns self. */
Obj1E* cEdgeGroup_ctor_cCollisionEdgeP(Obj1E* self, int value)
{
    std_vector_cCollisionEdgePtr_ctor(self);
    self->flag = 1;
    std_vector_cCollisionEdgePtr_push_back(self, &value);
    return self;
}
