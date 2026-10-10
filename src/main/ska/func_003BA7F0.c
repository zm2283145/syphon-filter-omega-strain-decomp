#include "types.h"

typedef struct { char data[0x1D0]; } SkelInit; /* temporary built from the record */
typedef struct { char pad[0xC0]; void* record; } SkelNode;
extern void SkelNode_Construct(SkelInit* init, void* record);
extern void func_003BA840(SkelNode* node, SkelInit* init);
extern void func_003BA9A0(SkelInit* init, int flags);

/* Initializes the node from a record via a temporary init block, then remembers the record. */
void SkelNode_InitFromRecord(SkelNode* self, void* record)
{
    SkelInit init;
    SkelNode_Construct(&init, record);
    func_003BA840(self, &init);
    self->record = record;
    func_003BA9A0(&init, -1);
}
