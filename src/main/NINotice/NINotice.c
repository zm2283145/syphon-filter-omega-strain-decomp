/*
 * main/NINotice: 3 files, 002373A0-00237500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002373A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define CMSG_KIND_T char
#define CMSG_NO_PROTOS /* cMessage_dtor is declared by DEFINE_VTABLE_BASE_DTOR below */
#include "cmessage.h"

#define cMessage_vtable  D_004DFD80
#define cNINotice_vtable D_004DBEB0

extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char cMessage_vtable[];
extern char cNINotice_vtable[];
}

/* cNINotice (NIEvent.hh): a cMessage carrying one word whose low byte is the
 * notice action (read by the script Action() accessor). 0x28 bytes. */
struct cNINotice {
    CMSG_HEADER;
    int action; /* +0x24 */
};

/* Clone (vtable slot 1): heap copy of the message, built the way the inlined
 * copy constructors do it (base part first, then the derived vtable). */
extern "C" cNINotice* cCrateInteractMsg_Clone(cNINotice* self)
{
    cNINotice* copy;
    {
        AllocGuard guard;
        copy = (cNINotice*)cMemMan_Allocate(0, sizeof(cNINotice), "NIEvent.hh", 0x28);
    }
    if (copy) {
        copy->vtable = cMessage_vtable;
        copy->type = self->type;
        copy->magic = self->magic;
        copy->time = self->time;
        copy->unk10 = self->unk10;
        copy->target = self->target;
        copy->stampKind = self->stampKind;
        copy->flags = self->flags;
        copy->kind = self->kind;
        copy->vtable = cNINotice_vtable;
        copy->action = self->action;
    }
    return copy;
}
#pragma pop /* merge_units */
/* merge_units: end func_002373A0 */

/* merge_units: begin func_002374A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNINotice_dtor, cNINotice_vtable, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002374A0 */

/* merge_units: begin func_00237500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F7D20; /* cNINotice script type key */
extern int D_004F7D28; /* cNINotice script type id */
extern int* cMessage_SOBJ_getClassId(void); /* address of the cMessage type key */
extern void cScriptBase_declareParent(int type, int parentType);

/* Action(notice): returns the notice's action byte (low byte of cNINotice.action, +0x24). */
int Script_cNINotice_Action(unsigned char** args) {
    return args[0][0x24];
}

/* cNINotice derives from cMessage. */
void cNINotice_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7D28, *parent);
}

int cNINotice_getSOBJClassId(void) {
    return D_004F7D20;
}
#pragma pop /* merge_units */
/* merge_units: end func_00237500 */
