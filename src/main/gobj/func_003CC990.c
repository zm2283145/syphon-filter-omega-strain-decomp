#include "types.h"

typedef struct ValueMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char kind;   /* 0x20 */
    char pad21[3];
    unsigned char flag;   /* 0x24 */
    char pad25[3];
    int id;               /* 0x28 */
    int value;            /* 0x2C */
} ValueMsg;

typedef struct ValueObj {
    char pad00[0xC];
    int id;               /* 0x0C */
    char pad10[0x30];
    float value;          /* 0x40 */
} ValueObj;

extern unsigned char D_005721C8;
extern char D_00582750[];
extern char D_004E0EE0[];
extern void Event_Construct(ValueMsg* msg, void* type);
extern void Event_Send(ValueMsg* msg, void* target, int flags);
extern void cMessage_dtor(ValueMsg* msg, int flags);

/* Sets the value; in networked mode (unless silent) broadcasts it as message kind 4. */
void func_003CC990(ValueObj* obj, int value, int silent) {
    ValueMsg msg;
    obj->value = (float)value;
    if (D_005721C8 && !silent) {
        Event_Construct(&msg, D_00582750);
        msg.flag = 0;
        msg.vtbl = D_004E0EE0;
        msg.id = obj->id;
        msg.kind = 4;
        msg.value = value;
        Event_Send(&msg, obj, 0);
        msg.vtbl = D_004E0EE0;
        cMessage_dtor(&msg, 0);
    }
}
