/*
 * main/weapon: range (2 files, 00141240-00141300)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00141240 */
#pragma push /* merge_units */
typedef struct { int a; int id; int b; int count; } S141240;
typedef struct { char pad[0xF0]; unsigned char kind; } W141240;
extern void* g_WeaponDatabase;
extern W141240* cWeaponDB_GetEntry(void*, int);
extern int cWeapon_ReadyToFire(void*, int);
int cWeapon_Ready(char* self) {
    unsigned char i = *(unsigned char*)(self + 0x84);
    S141240* s;
    if (i != 6) {
        s = (S141240*)(self + (i << 4) + 4);
        switch (cWeaponDB_GetEntry(g_WeaponDatabase, s->id)->kind) {
        case 0: case 8: case 9:
            return cWeapon_ReadyToFire(self, 0);
        case 1: case 7:
            return s->count > 0;
        case 3: case 4: case 5: case 10:
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141240 */

/* merge_units: begin func_00141300 */
#pragma push /* merge_units */
#pragma cplusplus on
class R_1300 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1300 { void* vt; char pad[0x20]; int id; char f28; char pad29[7]; };
struct SEv_1300 { void* vt; char pad4[0x1C]; char f20; char pad21[0x57]; char f78[0x9C]; char f114[0xAC]; };
struct Slot_1300 { int pad0; int id; int f8; int count; };
struct Own_1300 { char pad[0x14]; unsigned char f14; char pad15[0x43]; R_1300* recv; };
struct W_1300 { char pad[0x48]; unsigned char kind; char pad49[0xA7]; unsigned char fF0; };
struct S_1300 { int pad0; Slot_1300 slots[8]; unsigned char cur; char pad85[3]; Own_1300* own; };
extern "C" {
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern char D_004DAE30[];
extern char g_Game[];
extern char D_004F27F0[];
extern char D_004F2990[];
extern char D_004F2B30[];
#if 0 /* merge_units */
W_1300* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((W_1300 *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

void cMessage_ctor_cMessageNameR(void* e, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* e, void* target, int a);
void cMessage_dtor(void* e, int f);
void cPlaySoundMsg_ctor_cSndFxR(void* e, void* preset, void* src);
void cFileMan_dtor(void* p, int a);
}
extern "C" int cWeapon_ReloadIfOutOfAmmo(S_1300* self)
{
    SEv_1300 se;
    Ev_1300 e;
    if (self->cur != 6) {
        Slot_1300* s = &self->slots[self->cur];
        W_1300* w = cWeaponDB_GetEntry(g_WeaponDatabase, s->id);
        if (!w->fF0 && !s->f8) {
            if (s->count > 0) {
                cMessage_ctor_cMessageNameR(&e, g_ActorActionMsgClass);
                e.f28 = 0;
                e.vt = D_004E0840;
                e.id = 0x3C;
                QueueMessage_cMessageR_cSystemP_int(&e, self->own, 0);
                e.vt = D_004E0840;
                cMessage_dtor(&e, 0);
                return 1;
            }
            if (self->own->f14) {
                unsigned char local = 0;
                R_1300* r = self->own->recv;
                if (r && r->IsLocal())
                    local = 1;
                if (local) {
                    char* preset;
                    switch (w->kind) {
                    case 2:
                        preset = D_004F2990;
                        break;
                    case 4:
                        preset = D_004F2B30;
                        break;
                    default:
                        preset = D_004F27F0;
                        break;
                    }
                    if (preset) {
                        cPlaySoundMsg_ctor_cSndFxR(&se, preset, self->own);
                        se.f20 = 1;
                        QueueMessage_cMessageR_cSystemP_int(&se, g_Game, 0);
                        se.vt = D_004DAE30;
                        cFileMan_dtor(se.f114, -1);
                        cFileMan_dtor(se.f78, -1);
                        cMessage_dtor(&se, 0);
                    }
                }
            }
        }
    }
    return 0;
}
#undef cWeaponDB_GetEntry /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141300 */
