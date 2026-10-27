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

extern unsigned char g_IsMultiplayer;
extern char D_00582750[];
extern char D_004E0EE0[];
extern void cMessage_ctor_cMessageNameR(ValueMsg* msg, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(ValueMsg* msg, void* target, int flags);
extern void cMessage_dtor(ValueMsg* msg, int flags);

/* Sets the value; in networked mode (unless silent) broadcasts it as message kind 4. */
void cGOBJ_SetHitpoints(ValueObj* obj, int value, int silent) {
    ValueMsg msg;
    obj->value = (float)value;
    if (g_IsMultiplayer && !silent) {
        cMessage_ctor_cMessageNameR(&msg, D_00582750);
        msg.flag = 0;
        msg.vtbl = D_004E0EE0;
        msg.id = obj->id;
        msg.kind = 4;
        msg.value = value;
        QueueMessage_cMessageR_cSystemP_int(&msg, obj, 0);
        msg.vtbl = D_004E0EE0;
        cMessage_dtor(&msg, 0);
    }
}
