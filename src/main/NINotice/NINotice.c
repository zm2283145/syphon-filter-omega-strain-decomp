/*
 * main/NINotice: 3 files, 002373A0-00237500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin cNINotice_v01 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DBEB0[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cNINotice_v01(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "NIEvent.hh", 0x28);
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
        p->vtable = D_004DBEB0;
        p->w24 = self->w24;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end cNINotice_v01 */

/* merge_units: begin cNINotice_dtor */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNINotice_dtor, D_004DBEB0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end cNINotice_dtor */

/* merge_units: begin Script_cNINotice_Action */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F7D20; /* cNINotice script type key */
extern int D_004F7D28; /* cNINotice script type id */
extern int* Message_GetScriptTypeKeyPtr(void); /* address of the cMessage type key */
extern void ScriptType_SetParent(int type, int parentType);

/* Action(notice): returns the notice's action byte (+0x24). */
int Script_cNINotice_Action(unsigned char** args) {
    return args[0][36];
}

/* cNINotice derives from cMessage. */
void ScriptType_cNINotice_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7D28, *parent);
}

int cNINotice_v03(void) {
    return D_004F7D20;
}
#pragma pop /* merge_units */
/* merge_units: end Script_cNINotice_Action */
