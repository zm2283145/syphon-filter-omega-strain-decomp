/*
 * SFOGame/Source/NetHuman: 7 files, 002D1DC0-002D23D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D1DC0 */
#pragma push /* merge_units */
#include "types.h"
#include "net_owner.h"
typedef struct { char pad[0x3584]; void* link; } Obj1DC0;
typedef struct { char pad[0x1C]; char ref[8]; int owner; unsigned char b28; unsigned char b29; char pad2[2]; int netId; } Sess1DC0;
typedef struct { char pad[4]; int owner; char pad2[0x14]; Sess1DC0* sess; } Hdl1DC0;
extern unsigned char D_005723C8;
extern unsigned char D_0051F080;
extern Obj1DC0* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void cAimWeapon_Creation(void* ref, Obj1DC0* o);
extern void cTargetInfo_Creation(Sess1DC0* s, Obj1DC0* o);
#pragma push
#pragma opt_common_subs off
void cNetHuman_NetHumanUpdateCallback(void* recv, int id, int kind)
{
    struct { int pad; int oid; Hdl1DC0* h; } sl;
    if (!D_005723C8)
        D_005723C8 = 1;
    if (NetGetObject((NetOwnerHdl**)&sl.h, id) == 0) {
        Sess1DC0* s = sl.h->sess;
        if (kind == -2 && sl.h->owner == NetOwner_LocalId(D_005721A8) && D_0051F080) {
            s->owner = id;
            s->b28 = 1;
            if (s->b29) {
                Obj1DC0* o;
                sl.oid = s->netId;
                o = nGobjManager_LookupGOBJ_cObjectIdR(&sl.oid);
                if (o) {
                    cAimWeapon_Creation(s->ref, o);
                    cTargetInfo_Creation(s, o);
                    o->link = s;
                }
                D_0051F080 = 0;
                s->b29 = 0;
            }
        }
    }
    D_005723C8 = 0;
}
#pragma pop
static inline void merge_flush_func_002D1DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1DC0 */

/* merge_units: begin func_002D1F00 */
#pragma push /* merge_units */
typedef struct { char pad[0x3584]; void* link; } Obj1F00;
typedef struct { char pad[0x10]; void* val; } Ent1F00;
typedef struct { char pad[0x1C]; char ref[8]; int owner; unsigned char b28; unsigned char b29; char pad2[2]; int netId; } Sess1F00;
typedef struct { char pad[4]; int owner; char pad2[0x14]; Sess1F00* sess; } Hdl1F00;
#if 0 /* merge_units */
extern Obj1F00* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj1F00 *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

#if 0 /* merge_units */
extern void cAimWeapon_Creation(void* ref, Obj1F00* o);
#endif /* merge_units */
#define cAimWeapon_Creation(a0, a1) (cAimWeapon_Creation((a0), (Obj1DC0 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cTargetInfo_Creation(Sess1F00* s, Obj1F00* o);
#endif /* merge_units */
#define cTargetInfo_Creation(a0, a1) (cTargetInfo_Creation((Sess1DC0 *)(a0), (Obj1DC0 *)(a1))) /* merge_units */

extern Ent1F00* cNetObj_GetNetSystem(int);
extern Ent1F00* cNetObj_AddSystem(int, void*, int);
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void cNetHuman_NetHumanCreationCallback(void* recv, int id)
{
    struct { int pad; int oid; Hdl1F00* h; } sl;
    if (!D_005723C8)
        D_005723C8 = 1;
    if (NetGetObject((NetOwnerHdl**)&sl.h, id) == 0) {
        Obj1F00* r;
        Sess1F00* s = sl.h->sess;
        s->b29 = 0;
        s->b28 = 0;
        s->owner = id;
        sl.oid = s->netId;
        r = nGobjManager_LookupGOBJ_cObjectIdR(&sl.oid);
        if (r) {
            Obj1F00* o = r;
            cAimWeapon_Creation(s->ref, o);
            cTargetInfo_Creation(s, o);
            o->link = s;
        } else {
            Ent1F00* e = cNetObj_GetNetSystem(s->netId);
            if (e)
                e->val = s;
            else
                cNetObj_AddSystem(s->netId, recv, 0)->val = s;
        }
    }
    D_005723C8 = 0;
}
#pragma pop
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#undef cAimWeapon_Creation /* merge_units */
#undef cTargetInfo_Creation /* merge_units */
static inline void merge_flush_func_002D1F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1F00 */

/* merge_units: begin func_002D1FF0 */
#pragma push /* merge_units */
typedef struct {
    unsigned char f00, f01; char p02[2];
    int f04;
    int f08;
    signed char f0C; char p0D[3];
    int f10, f14, f18;
    short f1C; char p1E[2];
    unsigned char f20, f21; short f22;
    char p24[4];
    unsigned char f28, f29; char p2A[2];
    int f2C;
    short f30; unsigned char f32, f33;
    char p34[4];
    float f38;
    int f3C, f40;
    char p44[0xC];
    unsigned char f50; char p51[0xB];
} NetHuman1FF0;
extern unsigned char D_005721D0;
extern int D_0051F088;
extern int D_0051F078;
extern int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, NetHuman1FF0* g, char* h, int i);
extern void NetRequestObjectPrivateOwnership(int);
extern void cTargetInfo_Init(NetHuman1FF0*);
extern void cTargetInfo_dtor(NetHuman1FF0*, int);
void cNetHuman_CreateNetHuman(void* recv, int id)
{
    if (D_005721D0) {
        NetHuman1FF0 o;
        int h;
        o.f00 = 0;
        o.f01 = 0;
        o.f04 = -1;
        o.f08 = -1;
        o.f0C = -1;
        o.f10 = 0;
        o.f14 = 0;
        o.f18 = 0;
        o.f28 = 0;
        o.f30 = 4;
        o.f32 = 0;
        o.f33 = 0;
        o.f38 = 1000.0f;
        o.f3C = 0;
        o.f40 = 0;
        o.f50 = 0;
        o.f22 = 0;
        o.f21 = 0;
        o.f1C = 0;
        o.f20 = 0;
        cTargetInfo_Init(&o);
        o.f2C = id;
        o.f29 = 1;
        if (NetCreateObject(&h, 2, 4, 0, 0, 0, 0, &o, "cNetHuman", D_0051F078) == 0) {
            D_0051F080 = 1;
            NetRequestObjectPrivateOwnership(h);
            D_0051F088++;
        }
        cTargetInfo_dtor(&o, 0);
    }
}
static inline void merge_flush_func_002D1FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1FF0 */

/* merge_units: begin func_002D2110 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int id; unsigned char active; } Obj2110;
extern int NetReleaseObjectPrivateOwnership(int id);
void cNetHuman_Deactivate(Obj2110* o)
{
    if (NetOwner_IsMine(o->id) && NetReleaseObjectPrivateOwnership(o->id) == 0)
        o->active = 0;
}
static inline void merge_flush_func_002D2110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2110 */

/* merge_units: begin func_002D2210 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int id; } Obj2210;
unsigned char func_002D2210(Obj2210* o)
{
    return NetOwner_IsMine(o->id);
}
static inline void merge_flush_func_002D2210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2210 */

/* merge_units: begin func_002D22E0 */
#pragma push /* merge_units */
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm22E0;
typedef struct { char pad[0x1C]; short a[2]; unsigned char b; unsigned char c; short d[2]; } Rec22E0;
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm22E0* prm);
unsigned char cAimWeapon_InitNet(int unused, Rec22E0* r, Prm22E0* prm)
{
    int db;
    unsigned char ok = 0;
    if (NetObjectField(&db, (char*)&r->c - (char*)r, 1, 1, 1, prm) == 0 &&
        NetObjectField(&db, (char*)r->a - (char*)r, 2, 3, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->b - (char*)r, 1, 1, 1, prm) == 0) {
        prm->mode = 0x40;
        if (NetObjectField(&db, (char*)r->d - (char*)r, 2, 2, 1, prm) == 0)
            ok = 1;
    }
    prm->mode = 0;
    return ok;
}
static inline void merge_flush_func_002D22E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D22E0 */

/* merge_units: begin func_002D23D0 */
#pragma push /* merge_units */
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm23D0;
typedef struct { unsigned char a; char pad[3]; int b[1]; int c[1]; unsigned char d; char pad2[3]; int e; int f; int g; } Rec23D0;
#if 0 /* merge_units */
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm23D0* prm);
#endif /* merge_units */
#define NetObjectField(a0, a1, a2, a3, a4, a5) (NetObjectField((a0), (a1), (a2), (a3), (a4), (Prm22E0 *)(a5))) /* merge_units */

unsigned char cTargetInfo_InitNet(int unused, Rec23D0* r, Prm23D0* prm)
{
    int db;
    unsigned char ok = 0;
    prm->max = 0xFA;
    if (NetObjectField(&db, (char*)r->b - (char*)r, 4, 5, 1, prm) == 0 &&
        NetObjectField(&db, (char*)r->c - (char*)r, 4, 5, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->d - (char*)r, 1, 0, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->a - (char*)r, 1, 1, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->e - (char*)r, 4, 6, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f - (char*)r, 4, 6, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->g - (char*)r, 4, 6, 1, prm) == 0)
        ok = 1;
    return ok;
}
#undef NetObjectField /* merge_units */
static inline void merge_flush_func_002D23D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D23D0 */
