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

DEFINE_MESSAGE_PACK_NOTYPE(func_003FF330, 12, D_0055D490, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003FF330 */

/* merge_units: begin func_003FF3B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004E0860[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cDisableMsg_v01(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "DisableMsg.hh", 0x21);
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
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

void ScriptType_cDisableMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_0055D4B0, *base);
}

int cDisableMsg_v03(void) {
    return D_0055D4A8;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF4B0 */

/* merge_units: begin func_003FF4F0 */
#pragma push /* merge_units */
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int func_002E9F08(void* t, void* fn);
extern int D_0055D4A0;
extern int func_003FF5D0();
unsigned char func_003FF4F0(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        func_002E9F08(&D_0055D4A0, func_003FF5D0) == 0) {
        r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FF4F0 */
