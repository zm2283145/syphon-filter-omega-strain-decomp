#include "types.h"
typedef struct { int pad0; int count; int* data; } PtrVec_1AD8C0;
typedef struct { char pad[8]; PtrVec_1AD8C0 list; } Own_1AD8C0;
typedef struct { int pad0; Own_1AD8C0* owner; } Ch_1AD8C0;
extern void cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
void ActorRelation_AddChild(Own_1AD8C0* self, Ch_1AD8C0* c)
{
    Ch_1AD8C0* q = c;
    if (q->owner) {
        cArray_cTreeNode_cSkaSystemPtrPtr_Remove_OrderNotPreserved(&q->owner->list, &q);
        q->owner = 0;
    }
    c->owner = self;
    std_vector_cTreeNode_cSkaSystemPtrPtr_push_back(&self->list, &c);
}