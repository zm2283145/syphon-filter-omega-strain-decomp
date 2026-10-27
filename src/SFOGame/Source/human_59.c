/*
 * SFOGame/Source/human: 2 files, 00199290-001992B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00199290 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* Network stream cursor shared by message (de)serializers. */
extern signed char* D_005061D0;

/* Read one signed byte from the network stream and advance. */
int NetStream_ReadS8(void) {
    signed char* p;

    p = D_005061D0;
    D_005061D0 = p + 1;
    return *p;
}
static inline void merge_flush_func_00199290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00199290 */

/* merge_units: begin func_001992B0 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_1992B0;
typedef struct { Message base; unsigned char on; } Msg3_1992B0;
typedef struct {
    char pad[0x3314]; int target; char pad3318[0x33E5 - 0x3318];
    unsigned char b33E5; unsigned char b33E6; char pad33E7[0x3524 - 0x33E7]; void* weapons;
} O_1992B0;
extern char D_004DA930[];
extern char D_00542B60[];
extern char D_0049E070[];
extern char D_004EEE80[];
extern char D_004DCF10[];
extern void cMessage_getSOBJClassId();
extern void cEquipGogglesMsg_dtor();
extern void cEquipGogglesMsg_Clone();
extern void cEquipGogglesMsg_Pack();
extern void cEquipGogglesMsg_v05();
extern void cNetMsg_Pack();
void * const D_004DA8B0[8] = { (void*)0x0, (void*)0x0, (void*)cEquipGogglesMsg_dtor, (void*)cEquipGogglesMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cEquipGogglesMsg_Pack, (void*)cEquipGogglesMsg_v05 };
extern unsigned char g_IsMultiplayer;
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);
extern void cMessage_dtor(void* msg, int flags);
extern int Secondary_RequestOneShot(int target, Key_1992B0* key, int n, AnimEvent* ev);
extern void QueueMessage_cMessageR_cSystemP_int(Msg3_1992B0* m, void* o, int x);
extern void* cWeapon_GetGoggleEntry(void* w);
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void cHuman_RequestEquipGoggles(O_1992B0* o, unsigned char on, int f)
{
    if (o->b33E5 == 2) return;
    if (cWeapon_GetGoggleEntry(o->weapons) || f) {
        if (o->target && !o->b33E5) {
            Msg3_1992B0 m;
            Key_1992B0 key;
            AnimEvent ev;
            unsigned char r;
            AnimEvent* pe = &ev;
            cMessage_ctor_cMessageNameR(&pe->base, D_00542B60);
            pe->base.vtable = D_004DA930;
            pe->unk24 = 3;
            pe->unk28 = 0;
            pe->unk2C = (int)o;
            pe->unk30 = 0;
            pe->unk34 = 0.0f;
            CKC_COPY_S(key.c, D_0049E070)
            r = Secondary_RequestOneShot(o->target, &key, 1, &ev);
            ev.base.vtable = D_004DA930;
            cMessage_dtor(&ev, 0);
            if (r) {
                o->b33E5 = 1;
                if (g_IsMultiplayer && !f) {
                    Msg3_1992B0* pm = &m;
                    cMessage_ctor_cMessageNameR(&pm->base, D_004EEE80);
                    pm->base.vtable = D_004DCF10;
                    pm->base.vtable = ((char*)D_004DA8B0);
                    pm->on = on;
                    m.base.unk20 = 4;
                    m.base.unk1C = 0x40;
                    QueueMessage_cMessageR_cSystemP_int(pm, o, 0);
                    m.base.vtable = D_004DCF10;
                    cMessage_dtor(pm, 0);
                }
            }
        }
    }
    o->b33E6 = on;
}
#pragma pop
static inline void merge_flush_func_001992B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001992B0 */
