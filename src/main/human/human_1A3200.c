/*
 * main/human: range (4 files, 001A3200-001A3520)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "net_local_id.h"

/* merge_units: begin func_001A3200 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct M4u { __int128 r0, r1, r2, r3; M4u() {} };
struct Pt { char pad[0x44]; float x, y, z; };
struct VObj { VPAD16(a) VPAD4(b) VPAD1(c) virtual int IsAlive(); };
struct Obj {
    VPAD16(a) VPAD8(b) VPAD4(c) VPAD1(d) virtual int Slot29();
    VPAD16(e) VPAD8(f) VPAD4(g) VPAD1(h) virtual M4u GetMtx();
    char pad4[0x28];
    unsigned char b2C, b2D; unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    VObj* obj;
    char pad5C[0x3584 - 0x5C];
    Pt* pt;
};
extern "C" void Actor_GetBackpackDropMatrix(M4u* out, Obj* o); /* gsynth: defined below */
#pragma pop
typedef struct { int w[16]; } Buf_1A3200;
typedef struct { char pad[0x3464]; int h; } O_1A3200;
#if 0 /* merge_units */
extern void Actor_GetBackpackDropMatrix(Buf_1A3200* b, O_1A3200* o);
#endif /* merge_units */
#define Actor_GetBackpackDropMatrix(a0, a1) (Actor_GetBackpackDropMatrix((void *)(a0), (void *)(a1))) /* merge_units */

extern void Backpack_Place(int h, Buf_1A3200* b, int f);
void func_001A3200(O_1A3200* o)
{
    Buf_1A3200 b;
    if (o->h) {
        Actor_GetBackpackDropMatrix(&b, o);
        Backpack_Place(o->h, &b, 0);
    }
}
#undef Actor_GetBackpackDropMatrix /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A3200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A3200 */

/* merge_units: begin func_001A3250 */
#pragma push /* merge_units */
typedef struct { int w[16]; } Buf_1A3250;
typedef struct { char pad[0x3464]; int h; } O_1A3250;
#if 0 /* merge_units */
extern void Actor_GetBackpackDropMatrix(Buf_1A3250* b, O_1A3250* o);
#endif /* merge_units */
#define Actor_GetBackpackDropMatrix(a0, a1) (Actor_GetBackpackDropMatrix((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void Backpack_Place(int h, Buf_1A3250* b, int f);
#endif /* merge_units */
#define Backpack_Place(a0, a1, a2) (Backpack_Place((a0), (void *)(a1), (a2))) /* merge_units */

extern void Backpack_TurnOn(int h);
void Actor_TurnOnWeaponPickup(O_1A3250* o)
{
    Buf_1A3250 b;
    if (o->h) {
        Actor_GetBackpackDropMatrix(&b, o);
        Backpack_Place(o->h, &b, 1);
        Backpack_TurnOn(o->h);
    }
}
#undef Actor_GetBackpackDropMatrix /* merge_units */
#undef Backpack_Place /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A3250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A3250 */

/* merge_units: begin func_001A32A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4u { __int128 q; };

struct Ang { float x, y, z; };
struct Fv { float x, y, z, w; };



extern "C" {
extern float Math_CosThunk(float);
extern float Math_SinThunk(float);
extern void* Mtx44_SetRotation(M4u* m, float a, float b, float c, float d, float e, float f,
                               float g, float h, float i);
extern signed char D_004EED90;
extern Ang D_004EEDA0;
extern signed char D_004EEDB0;
extern M4u D_004EEDC0;
extern V4u D_004EEDF0;
}
static inline bool Not(unsigned char v) { return !(v != 0); }
/* plain asm sq: lets the delay-slot filler move later code past it */
static inline void StR(void* d, __int128 t) { asm { sq t, 0(d) } }
#pragma opt_propagation off
extern "C" void Actor_GetBackpackDropMatrix(M4u* out, Obj* o)
{
    if (!D_004EED90) {
        D_004EEDA0.y = 0.0f;
        D_004EEDA0.z = 0.0f;
        D_004EEDA0.x = 1.5707964f;
        D_004EED90 = 1;
    }
    if (!D_004EEDB0) {
        float y = D_004EEDA0.y;
        float x = D_004EEDA0.x;
        float z = D_004EEDA0.z;
        float cy = Math_CosThunk(y);
        float sy = Math_SinThunk(y);
        float cx = Math_CosThunk(x);
        float sx = Math_SinThunk(x);
        float cz = Math_CosThunk(z);
        float sz = Math_SinThunk(z);
        float czcy = cz * cy;
        float czsy = cz * sy;
        float szcy = sz * cy;
        float szsy = sz * sy;
        Mtx44_SetRotation(&D_004EEDC0,
                          czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                          szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                          -cx * sy, sx, cx * cy);
        D_004EEDB0 = 1;
    }
    {
        V4u pos;
        V4u* pp;
        bool b;
        bool a;
        {
            M4u m = o->GetMtx();
            M4u* mp = &m;
            pp = &pos;
            __int128 t = VLoadF(&mp->r3);
            b = false;
            a = false;
            StR(pp, t);
        }
        if (!(o->b2D == 0) && !(o->b2C == 0))
            a = true;
        if (a && Not(o->b2E))
            b = true;
        if (!b && o->Slot29()) {
            bool alive = false;
            if (o->obj && o->obj->IsAlive())
                alive = true;
            if (alive) {
                Pt* p = o->pt;
                if (p) {
                    ((Fv*)&pos)->x = p->x;
                    ((Fv*)&pos)->y = p->y;
                    ((Fv*)&pos)->z = p->z;
                }
            }
        }
        V4u* d;
        __int128 tp = V4Load(&pos);
        d = &D_004EEDF0;
        asm { .set reorder } /* barrier: keeps the two address loads paired */
        {
            M4u* s = &D_004EEDC0;
            V4Store(d, tp);
            __int128 t0;
            __int128 t1;
            t0 = s->r0; t1 = s->r1; out->r0 = t0;
            t0 = s->r2; out->r1 = t1;
            t1 = s->r3; out->r2 = t0;
            out->r3 = t1;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A32A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A32A0 */

/* merge_units: begin func_001A3520 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {int Event_Construct(char **, char *);
int Event_Send(char **, char * , int);
int Inventory_HasAnyItem(int);
int cMessage_dtor(char **, int);
int WeaponInv_MoveItemsToBackpack(int, int);
int WorldInv_AddArmor(int, int, int);
int Backpack_Construct(char * , int, int);
int ItemInv_Any(int);
extern "C" void Message_GetScriptTypeKey();
extern "C" void cNetBackpackMsg_dtor();
extern "C" void cNetBackpackMsg_v01();
extern "C" void cNetBackpackMsg_v04();
extern "C" void cNetBackpackMsg_v05();
extern "C" void func_002823E0();
void * const D_004DCEF0[8] = { (void*)0x0, (void*)0x0, (void*)cNetBackpackMsg_dtor, (void*)cNetBackpackMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cNetBackpackMsg_v04, (void*)cNetBackpackMsg_v05 };
extern char D_004DCF10;
extern char D_005061B0;
}
#pragma opt_common_subs off
extern "C" void Npc_DeadStateDrop(char * arg0) {
    char * sp40[12];
    int x; int inv;
    if (F_(arg0, 0x3464, int) == 0) {
        inv = F_(arg0, 0x3524, int);
        x = F_(arg0, 0x33A0, int);
        bool ok; if (!Inventory_HasAnyItem(inv) && !x) { ok = F_(arg0, 0x2D, unsigned char) && F_(arg0, 0x2C, unsigned char) && !F_(arg0, 0x2E, unsigned char) && F_(arg0, 0x3468, unsigned char); if (!ok && !ItemInv_Any(F_(arg0, 0x3528, int))) return; } {
        if (F_(arg0, 0x14, unsigned char) != 0) {
            F_(arg0, 0x3464, int) = Backpack_Construct(arg0, 1, 0);
            WeaponInv_MoveItemsToBackpack(inv, F_(arg0, 0x3464, int));
            if (x != 0) {
                WorldInv_AddArmor(F_(arg0, 0x3464, int), x, F_(arg0, 0x339C, int));
            }
            unsigned char on = *(volatile unsigned char*)&D_005721C8; if (on != 0) { int h; int id; int a = D_005721A8; if (on) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); id = D_00494178; } else id = 0;
                h = F_(arg0, 0x3464, int);
                Event_Construct(sp40, &D_005061B0);
                sp40[0] = &(*(char*)D_004DCEF0);
                F_(sp40, 0x28, int) = h;
                F_(sp40, 0x20, signed char) = 4;
                F_(sp40, 0x2C, int) = id;
                F_(sp40, 0x24, signed char) = 0;
                Event_Send(sp40, arg0, 0);
                sp40[0] = &D_004DCF10;
                cMessage_dtor(sp40, 0);
            }
        }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A3520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A3520 */
