#include "types.h"
typedef struct { int pad0; int count; int* data; } PtrVec_1AD8C0;
typedef struct { char pad[8]; PtrVec_1AD8C0 list; } Own_1AD8C0;
typedef struct { int pad0; Own_1AD8C0* owner; } Ch_1AD8C0;
extern void func_001AD940(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
extern void func_001AD920(PtrVec_1AD8C0* v, Ch_1AD8C0** value);
void ActorRelation_AddChild(Own_1AD8C0* self, Ch_1AD8C0* c)
{
    Ch_1AD8C0* q = c;
    if (q->owner) {
        func_001AD940(&q->owner->list, &q);
        q->owner = 0;
    }
    c->owner = self;
    func_001AD920(&self->list, &c);
}