#include "types.h"
#include "human_types.h"
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
extern void Message_GetScriptTypeKey();
extern void cEquipGogglesMsg_dtor();
extern void cEquipGogglesMsg_v01();
extern void cEquipGogglesMsg_v04();
extern void cEquipGogglesMsg_v05();
extern void func_002823E0();
void * const D_004DA8B0[8] = { (void*)0x0, (void*)0x0, (void*)cEquipGogglesMsg_dtor, (void*)cEquipGogglesMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cEquipGogglesMsg_v04, (void*)cEquipGogglesMsg_v05 };
extern unsigned char D_005721C8;
extern Message* Event_Construct(Message*, void*);
extern void cMessage_dtor(void* msg, int flags);
extern int Secondary_RequestOneShot(int target, Key_1992B0* key, int n, AnimEvent* ev);
extern void Event_Send(Msg3_1992B0* m, void* o, int x);
extern void* WeaponInv_GetSlot6Record(void* w);
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void Goggles_SetMode(O_1992B0* o, unsigned char on, int f)
{
    if (o->b33E5 == 2) return;
    if (WeaponInv_GetSlot6Record(o->weapons) || f) {
        if (o->target && !o->b33E5) {
            Msg3_1992B0 m;
            Key_1992B0 key;
            AnimEvent ev;
            unsigned char r;
            AnimEvent* pe = &ev;
            Event_Construct(&pe->base, D_00542B60);
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
                if (D_005721C8 && !f) {
                    Msg3_1992B0* pm = &m;
                    Event_Construct(&pm->base, D_004EEE80);
                    pm->base.vtable = D_004DCF10;
                    pm->base.vtable = ((char*)D_004DA8B0);
                    pm->on = on;
                    m.base.unk20 = 4;
                    m.base.unk1C = 0x40;
                    Event_Send(pm, o, 0);
                    m.base.vtable = D_004DCF10;
                    cMessage_dtor(pm, 0);
                }
            }
        }
    }
    o->b33E6 = on;
}
#pragma pop
