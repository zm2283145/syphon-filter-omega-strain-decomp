/*
 * SFOGame/Source/NetHuman: 10 files, 002D1940-002D1DC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D1940 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cNetHuman_InitNet: describe the cNetHuman replicated fields to the net
 * object database and register the class with its create/update/destroy
 * handlers. */
#include "net_human_fields.h"
extern "C" {
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* db, int offset, int size, int count, int type, NetHumanFieldParams* prm);
extern int NetRegisterStructure(int* h, char* name, int n);
extern int NetRegisterRemoteObjectCallback(int h, void* a, void* b, void* c);
extern unsigned char cTargetInfo_InitNet(void* self, NetHumanRecord* r, NetHumanFieldParams* prm);
extern unsigned char cAimWeapon_InitNet(void* self, NetHumanRecord* r, NetHumanFieldParams* prm);
extern void cTargetInfo_Init(NetHumanRecord*);
extern void cTargetInfo_dtor(NetHumanRecord*, int);
void cNetHuman_NetHumanCreationCallback(void* recv, int id);
void cNetHuman_NetHumanUpdateCallback(void* recv, int id, int kind);
void cNetHuman_NetHumanDeleteCallback(void);
extern char D_004AD588[]; /* "cNetHuman", shared with cNetHuman_CreateNetHuman */
extern int D_0051F078;
unsigned char cNetHuman_InitNet(void);
}
#define OFS(f) ((char*)&o.f - base)
extern "C" unsigned char cNetHuman_InitNet(void)
{
    int db;
    int h;
    NetHumanFieldParams prm;
    NetHumanRecord o;
    bool ok;
    char* base;
    unsigned char* pm;
    int r;
    o.f00 = 0;
    o.f01 = 0;
    o.f10 = 0;
    o.f14 = 0;
    o.f04 = -1;
    o.f08 = -1;
    o.f0C = -1;
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
    ok = 0;
    cTargetInfo_Init(&o);
    prm.max = 100;
    prm.ver = 1;
    pm = &prm.mode;
    *pm = 0;
    prm.flags = 0;
    if (NetRegisterObjectStart() == 0 &&
        cTargetInfo_InitNet(&o, &o, &prm) &&
        cAimWeapon_InitNet(&o.f1C, &o, &prm) &&
        (base = (char*)&o, 1) && /* the offset base is set up here, after the sub-record calls */
        NetObjectField(&db, OFS(f2C), 4, 5, 1, &prm) == 0 &&
        (*pm = 0x40, NetObjectField(&db, OFS(f30), 2, 2, 1, &prm) == 0) &&
        (prm.max = 1000, r = NetObjectField(&db, OFS(f50), 1, 1, 1, &prm), *pm = 0, r == 0) && /* mode reset either way */
        NetObjectField(&db, OFS(f3C), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f40), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f44), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f48), 4, 6, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f4C), 4, 6, 1, &prm) == 0 &&
        (*pm = 0x40, NetObjectField(&db, OFS(f38), 4, 6, 1, &prm) == 0) &&
        (prm.max = 100, NetObjectField(&db, OFS(f32), 1, 1, 1, &prm) == 0) &&
        NetObjectField(&db, OFS(f52), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f33), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f34), 1, 1, 1, &prm) == 0 &&
        NetObjectField(&db, OFS(f35), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, prm.max = 1000, NetObjectField(&db, OFS(f54), 4, 5, 1, &prm) == 0) &&
        NetObjectField(&db, OFS(f51), 1, 1, 1, &prm) == 0 &&
        (*pm = 0, NetRegisterStructure(&h, D_004AD588, 0x58) == 0) &&
        NetRegisterRemoteObjectCallback(h, cNetHuman_NetHumanCreationCallback, cNetHuman_NetHumanUpdateCallback, cNetHuman_NetHumanDeleteCallback) == 0) {
        D_0051F078 = h;
        ok = 1;
    }
    cTargetInfo_dtor(&o, 0);
    return ok;
}
static inline void merge_flush_func_002D1940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1940 */

/* merge_units: begin func_002D1D50 */
#pragma push /* merge_units */
extern unsigned char D_005723C8;

void cNetHuman_NetHumanDeleteCallback(void) {
    int v1;
    int cond;

    v1 = *(unsigned char*)(char*)&D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L002D1D68;
    *(char*)(char*)&D_005723C8 = v1;
L002D1D68:;
    *(char*)(char*)&D_005723C8 = 0;
    goto ret;
ret:;
}
static inline void merge_flush_func_002D1D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1D50 */

/* merge_units: begin func_002D1D80 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; void* h; unsigned char done; } Obj1D80;
extern int NetRequestObjectPrivateOwnership(void* h);
void cNetHuman_Activate(Obj1D80* o)
{
    if (!o->done && NetRequestObjectPrivateOwnership(o->h) == 0)
        o->done = 1;
}
static inline void merge_flush_func_002D1D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1D80 */

/* merge_units: begin func_002D1DC0 */
#pragma push /* merge_units */
/*
 * SFOGame/Source/NetHuman: 7 files, 002D1DC0-002D23D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

#include "net_owner.h"
typedef struct { char pad[0x3584]; void* link; } Obj1DC0;
typedef struct { char pad[0x1C]; char ref[8]; int owner; unsigned char b28; unsigned char b29; char pad2[2]; int netId; } Sess1DC0;
typedef struct { char pad[4]; int owner; char pad2[0x14]; Sess1DC0* sess; } Hdl1DC0;
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
extern int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, NetHuman1FF0* g, char* h, int i);
#if 0 /* merge_units */
extern void NetRequestObjectPrivateOwnership(int);
#endif /* merge_units */
#define NetRequestObjectPrivateOwnership(a0) ((void)NetRequestObjectPrivateOwnership((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cTargetInfo_Init(NetHuman1FF0*);
#endif /* merge_units */
#define cTargetInfo_Init(a0) (cTargetInfo_Init((NetHumanRecord *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cTargetInfo_dtor(NetHuman1FF0*, int);
#endif /* merge_units */
#define cTargetInfo_dtor(a0, a1) (cTargetInfo_dtor((NetHumanRecord *)(a0), (a1))) /* merge_units */

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
#undef NetRequestObjectPrivateOwnership /* merge_units */
#undef cTargetInfo_Init /* merge_units */
#undef cTargetInfo_dtor /* merge_units */
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
unsigned char cAimWeapon_InitNet(void* self, NetHumanRecord* r, NetHumanFieldParams* prm)
{
    int db;
    unsigned char ok = 0;
    if (NetObjectField(&db, (char*)&r->f21 - (char*)r, 1, 1, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f1C - (char*)r, 2, 3, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f20 - (char*)r, 1, 1, 1, prm) == 0) {
        prm->mode = 0x40;
        if (NetObjectField(&db, (char*)&r->f22 - (char*)r, 2, 2, 1, prm) == 0)
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
unsigned char cTargetInfo_InitNet(void* self, NetHumanRecord* r, NetHumanFieldParams* prm)
{
    int db;
    unsigned char ok = 0;
    prm->max = 0xFA;
    if (NetObjectField(&db, (char*)&r->f04 - (char*)r, 4, 5, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f08 - (char*)r, 4, 5, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f0C - (char*)r, 1, 0, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f00 - (char*)r, 1, 1, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f10 - (char*)r, 4, 6, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f14 - (char*)r, 4, 6, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->f18 - (char*)r, 4, 6, 1, prm) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002D23D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D23D0 */
