/*
 * SFOGame/Source/gameCollision: 3 files, 00179E20-00179EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00179E20 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int unk0; char inl[0x5C]; void* coll; } LosProvider;
/* Returns the external collection if set, else the inline one at +4. */
void* cCollisionModelList_Game_GetList(LosProvider* p) { if (p->coll) return p->coll; return p->inl; }
static inline void merge_flush_func_00179E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179E20 */

/* merge_units: begin func_00179E40 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#include "vc_copy.h"
#include "v4_asm_copy.h"
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00179E40 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
typedef __int128 Q128;
int nActivation_GetActivationFor(...);                
}
#pragma opt_common_subs off
extern "C" void cCollisionModelList_Game_Prepare(char * arg0) {
    Q128 *var_v0;
    char * temp_s0;
    char * temp_v0;
    char *d = arg0 + 0x40;

    temp_v0 = (char *)(F_(arg0, 0x20, int));
    if (temp_v0 != NULL) {
        temp_s0 = (char *)(F_(temp_v0, 0x50, int));
        if (F_(temp_s0, 0x50, unsigned char) != 0) {
            ((VC00179E40 *)(temp_s0))->v20();
        }
        var_v0 = (__int128 *)(temp_s0 + 0x40);
    } else {
        var_v0 = (__int128 *)(arg0 + 0x30);
    }
    VCopyF(arg0 + 0x40, var_v0);
    F_(arg0, 0x60, int) = nActivation_GetActivationFor(arg0 + 0x40);
}
static inline void merge_flush_func_00179E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179E40 */

/* merge_units: begin func_00179EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cHumanSeenMsg_Clone();
extern "C" void cHumanSeenMsg_getSOBJClassId();
extern "C" void cHumanSeenMsg_Pack();
extern "C" void cHumanSeenMsg_GetMsgId();
extern "C" void cNetMsg_Pack();
extern void * const D_004DA310[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cHumanSeenMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DA310);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DA310[8] = { (void*)0x0, (void*)0x0, (void*)cHumanSeenMsg_dtor, (void*)cHumanSeenMsg_Clone, (void*)cNetMsg_Pack, (void*)cHumanSeenMsg_getSOBJClassId, (void*)cHumanSeenMsg_Pack, (void*)cHumanSeenMsg_GetMsgId };
static inline void merge_flush_func_00179EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00179EC0 */
