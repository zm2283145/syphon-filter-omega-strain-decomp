/*
 * main/globalization: 4 files, 003FF330-003FF4F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FF330 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_U(b, 8) = MP_I(e, 0x24); MP_U(b, 9) = MP_U(e, 0x28);

DEFINE_MESSAGE_PACK_NOTYPE(cCharActionMsg_Pack, 12, D_0055D490, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003FF330 */

/* merge_units: begin func_003FF3B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004E0860[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cDisableMsg_Clone(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)cMemMan_Allocate(0, 0x28, "DisableMsg.hh", 0x21);
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
        p->vtable = D_004E0860;
        p->w24 = self->w24;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF3B0 */

/* merge_units: begin func_003FF4B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cDisableMsg script type registration and type-id slot.
 */


extern int D_0055D4A8;
extern int D_0055D4B0;
extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int baseType);

void cDisableMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_0055D4B0, *base);
}

int cDisableMsg_getSOBJClassId(void) {
    return D_0055D4A8;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF4B0 */

/* merge_units: begin func_003FF4F0 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterApplicationMessage(void* t, void* fn);
extern int D_0055D4A0;
extern int cDisableMsg_DisableCallback();
unsigned char cDisableMsg_InitNet(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(buf) != 0 && NetMessageField(buf, ok, 4, 1) == 0 &&
        NetRegisterApplicationMessage(&D_0055D4A0, cDisableMsg_DisableCallback) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF4F0 */
