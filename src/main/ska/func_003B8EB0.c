#include "types.h"

typedef struct { int unk0; int begin; int end; } RangeColl;
extern void List_Construct(RangeColl* self);
extern void List_CopyRange(RangeColl* self, int end, int beginRef);

/* Copy constructor: default-initializes self, then inserts src's range. */
RangeColl* GroupCollection_CopyConstruct(RangeColl* self, RangeColl* src)
{
    int first[1];
    int last[1];
    List_Construct(self);
    first[0] = (int)&src->begin;
    last[0] = src->end;
    List_CopyRange(self, *(int*)last, *(int*)first);
    return self;
}
