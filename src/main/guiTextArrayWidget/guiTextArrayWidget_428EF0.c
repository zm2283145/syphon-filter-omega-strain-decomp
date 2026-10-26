/*
 * main/guiTextArrayWidget: 5 files, 00428EF0-00429150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00428EF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Obj428EF0 { VPAD4(a) VPAD2(b) virtual void Reset(); char pad[0xC]; void* f10; unsigned char f14; };
typedef struct { int kind; int id; int val; } Pk428EF0;
extern "C" {
extern unsigned char D_005721D0;
Obj428EF0** NetMap_Lookup(int);
void* Object_LookupById(int*);
void cNetObj_SetOwner(void*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int cActivateMsg_NetReceive(int a0, int a1, int a2, Pk428EF0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk428EF0* p = arg;
        Obj428EF0** e = NetMap_Lookup(p->id);
        Obj428EF0* o;
        if (!e) { int id = p->id; o = (Obj428EF0*)Object_LookupById(&id); } else o = *e;
        if (o) {
            if (p->val > -1) { o->Reset(); cNetObj_SetOwner(o->f10, p->val); o->f14 = 0; } else o->Reset();
        }
    }
    return 0x10;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00428EF0 */

/* merge_units: begin func_00428FD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int Transport_Send(int, int, int, int);

/* Sends with the first two arguments swapped and -1 for the rest. */
int cActivateMsg_SendActivated(int a0, int a1) {
    return Transport_Send(a1, a0, -1, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00428FD0 */

/* merge_units: begin func_00428FF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004E0E80[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004E0E80;

extern "C" { char D_004BF970[] = "DeactivateMsg.hh"; }
DEFINE_MESSAGE_CLONE(cDeactivateMsg_v01, Msg_0022ED30, 0x24, D_004BF970, 0x13, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00428FF0 */

/* merge_units: begin func_004290F0 */
#pragma push /* merge_units */
extern int D_005721A0;
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(int*);
extern int NetRegisterApplicationMessage(void*, void*);
extern void cDeactivateMsg_NetReceive(void);

/* Registers the cDeactivateMsg_NetReceive handler when the preconditions hold; returns 1 on success. */
unsigned char cDeactivateMsg_NetRegister(void) {
    unsigned char ok = 0;
    int tmp[2];
    if (NetRegisterMessageStart() == 0 && Event_UnpackHeader(tmp) != 0 &&
        NetRegisterApplicationMessage(&D_005721A0, cDeactivateMsg_NetReceive) == 0) {
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_004290F0 */

/* merge_units: begin func_00429150 */
#pragma push /* merge_units */
extern int Event_PackHeader(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf);

/* Serializer for a message with no payload: header plus type id, 8 bytes. */
int cDeactivateMsg_v02(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf) {
    Event_PackHeader(msg, a1, outType, a3, a4, a5, buf);
    *outType = D_005721A0;
    return 8;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429150 */
