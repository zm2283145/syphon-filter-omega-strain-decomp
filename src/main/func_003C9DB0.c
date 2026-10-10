#include "types.h"

typedef struct { unsigned int kind : 2; unsigned int time : 30; } MsgStamp;
typedef struct { MsgStamp stamp; int target; } MsgInfo;
typedef struct {
    void* vtable;
    int sender;
    char pad8[4];
    unsigned int time;
    char pad10[4];
    int target;
    unsigned int kind;
    int unk1C;
    unsigned char type;
} cMessage;

extern char D_004DFD80[];
extern unsigned int func_0042B1A0(int a);
extern void func_00429CB0(unsigned int dt);

/* cMessage constructor (type 5). */
cMessage* cMessage_ctor5(cMessage* self, int sender, MsgInfo* info)
{
    MsgStamp stamp;
    self->vtable = D_004DFD80;
    self->sender = sender;
    self->target = info->target;
    self->unk1C = 0;
    self->type = 5;
    *(int*)&stamp = *(int*)&info->stamp;
    self->time = stamp.time;
    self->kind = stamp.kind;
    func_00429CB0(func_0042B1A0(0) - self->time);
    return self;
}
