#include "types.h"

typedef struct { char data[0x1D0]; } SkelInit; /* temporary built from the record */
typedef struct { char pad[0xC0]; void* record; } SkelNode;
extern void cBone_ctor_void(SkelInit* init, void* record);
extern void cBone_opAssign(SkelNode* node, SkelInit* init);
extern void cBone_dtor(SkelInit* init, int flags);

/* Initializes the node from a record via a temporary init block, then remembers the record. */
void cBone_Init(SkelNode* self, void* record)
{
    SkelInit init;
    cBone_ctor_void(&init, record);
    cBone_opAssign(self, &init);
    self->record = record;
    cBone_dtor(&init, -1);
}
