#include "types.h"

/* Message object (vtable, base data, parameters). */
typedef struct HumanMsg {
    void* vtable;
    char base[0x18];
    int size;
    unsigned char kind;
    char pad[3];
    unsigned char value;
    unsigned char extra;
    char pad2[0xA];
} HumanMsg;

typedef struct Human346C {
    char pad[0x346C];
    unsigned char value;
} Human346C;

extern unsigned char D_005721C8;
extern char D_004EEE98[];
extern char D_004DA9D0[]; /* message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(HumanMsg* msg, void* name);
extern void Event_Send(HumanMsg* msg, void* target, int flags);
extern void cMessage_dtor(HumanMsg* msg, int flags);

/* Stores the byte at +0x346C and, when D_005721C8 is set and not silent, broadcasts it. */
void func_001990F0(Human346C* self, unsigned char value, int silent) {
    HumanMsg msg;
    self->value = value;
    if (D_005721C8 && !silent) {
        Event_Construct(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.value = value;
        msg.kind = 4;
        msg.size = 0x40;
        msg.extra = 0;
        Event_Send(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
