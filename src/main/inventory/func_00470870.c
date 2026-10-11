#include "types.h"
typedef struct { int item; int count; } InvPair_h5;
typedef struct {
    int unk0;
    volatile int size;  /* 0x04 */
    InvPair_h5* data;   /* 0x08 */
    int unkC;
    void* owner;        /* 0x10 */
} Inventory_h5;
typedef struct {
    void* vtable;
    char base[0x18];
    int kind;            /* 0x1C */
    unsigned char b20;   /* 0x20 */
    char pad21[3];
    short item;          /* 0x24 */
    unsigned char count; /* 0x26 */
    unsigned char added; /* 0x27 */
} InvMsg_h5;
extern unsigned char D_005721C8;
extern char D_00587FC0[];
extern char D_004E1AC0[];
extern char D_004DCF10[];
extern void Event_Construct(InvMsg_h5* msg, void* name);
extern void Event_Send(InvMsg_h5* msg, void* target, int flags);
extern void cMessage_dtor(InvMsg_h5* msg, int flags);
extern void func_00470E10(Inventory_h5* inv, InvPair_h5* pos, int n, InvPair_h5* val);
#pragma opt_strength_reduction off
void func_00470870(Inventory_h5* inv, int item, int n, int silent)
{
    int i;
    InvPair_h5 pair;
    if (item <= -1) {
        return;
    }
    for (i = 0; i < inv->size; i++) {
        if (item == inv->data[i].item) {
            inv->data[i].count += n;
            return;
        }
    }
    pair.item = item;
    pair.count = n;
    func_00470E10(inv, &inv->data[inv->size], 1, &pair);
    if (D_005721C8 && !silent) {
        InvMsg_h5 msg;
        Event_Construct(&msg, D_00587FC0);
        msg.vtable = D_004E1AC0;
        msg.b20 = 4;
        msg.kind = 0x40;
        msg.item = item;
        msg.count = n;
        msg.added = 1;
        Event_Send(&msg, inv->owner, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#pragma opt_strength_reduction reset
