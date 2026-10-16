/*
 * main/globalization: 7 files, 003FF570-003FF850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FF570 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_0055D4A0;            /* cDisableMsg type id */
extern int Event_PackHeader(void* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf);

/* Serializes a cDisableMsg: header plus one word, 12 bytes. */
int cDisableMsg_v02(L4Msg24* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf) {
    Event_PackHeader(msg, a1, outType, a3, a4, a5, buf);
    buf->unk08 = msg->unk24;
    *outType = D_0055D4A0;
    return 12;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF570 */

/* merge_units: begin func_003FF5D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Obj003FF5D0 { VPAD8(a) VPAD1(b) virtual void Set(int v); };
typedef struct { int kind; int id; int val; } Pk003FF5D0;
extern "C" {
extern unsigned char D_005721D0;
Obj003FF5D0** NetMap_Lookup(int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_003FF5D0(int a0, int a1, int a2, Pk003FF5D0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk003FF5D0* p = arg;
        Obj003FF5D0** obj = NetMap_Lookup(p->id);
        if (obj) (*obj)->Set(p->val);
    }
    return 0xC;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003FF5D0 */

/* merge_units: begin func_003FF650 */
#pragma push /* merge_units */
extern unsigned char D_005721C8;
extern void Transport_Send(void* a, void* b, int c, void* d);
void NetMsg_Send(void* a0, void* a1, void* a2)
{
    if (D_005721C8)
        Transport_Send(a1, a0, -1, a2);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF650 */

/* merge_units: begin func_003FF690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004E0880[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cEnableMsg_v01(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "EnableMsg.hh", 0x21);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004E0880;
        p->w24 = self->w24;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF690 */

/* merge_units: begin func_003FF790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cEnableMsg script type registration and type-id slot.
 */


extern int D_0055D4C8;
extern int D_0055D4D0;
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

void ScriptType_cEnableMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_0055D4D0, *base);
}

int cEnableMsg_v03(void) {
    return D_0055D4C8;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF790 */

/* merge_units: begin func_003FF7D0 */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int func_002E9F08(void* t, void* fn);
extern int D_0055D4C0;
extern int func_003FF8B0();
unsigned char func_003FF7D0(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        func_002E9F08(&D_0055D4C0, func_003FF8B0) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF7D0 */

/* merge_units: begin func_003FF850 */
#pragma push /* merge_units */
/* Serializes a cEnableMsg: header plus one word, 12 bytes. */
int cEnableMsg_v02(L4Msg24* msg, int a1, int* outType, int a3, int a4, int a5, L4EventBuf* buf) {
    Event_PackHeader(msg, a1, outType, a3, a4, a5, buf);
    buf->unk08 = msg->unk24;
    *outType = D_0055D4C0;
    return 12;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF850 */
