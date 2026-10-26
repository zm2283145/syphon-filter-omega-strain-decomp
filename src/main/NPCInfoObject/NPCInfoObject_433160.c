/*
 * main/NPCInfoObject: range (11 files, 00433160-00434380)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "npc_info_rec.h"
#include "net_local_id.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00433160 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { int key; unsigned char b4; } Ent_433160;
typedef struct { char pad[0x1C]; Ent_433160* ent; } Obj_433160;
typedef struct { int v; } Res_433160;
extern "C" {
extern char D_004BFCA0[];
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005723C8;
extern char D_00582778;
extern unsigned char D_00582780;
extern unsigned char D_00582788;
extern unsigned char D_00582790;
extern unsigned char D_00582798;
extern Ent_433160* D_005827F0;
extern Ent_433160* D_005827F8;
extern Ent_433160* D_00582800;
extern Ent_433160* D_00582808;
extern Ent_433160* D_00582810;
extern int D_00582A68;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;
int NetGetObject(Obj_433160** out, int key);
void cNPCInfoObject_SetOwner_cObjectIdR_int(Res_433160* r, int* key, unsigned char b);
void cNPCInfoObject_Add(Res_433160* r, int* key, unsigned char b);
}
struct Busy_433160 {
    Busy_433160() { D_00582A68++; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Busy_433160() { D_00582A68--; }
};
struct Reent_433160 {
    Reent_433160() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Reent_433160() { D_005723C8 = 0; }
};
static inline unsigned char IsHost_433160() { if (g_IsMultiplayer) return D_005721C0; return 1; }
static inline void Free_433160(Ent_433160* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BFCA0, line); }

extern "C" void cNPCInfoObject_NPCInfoCreationCallback(void* self, int key)
{
    Reent_433160 re;
    Obj_433160* o;
    if (NetGetObject(&o, key) == 0) {
        if (!D_00582780) {
            Ent_433160* old = 0;
            if (D_005827F0 && !D_00582780) old = D_005827F0;
            D_005827F0 = o->ent;
            D_00582778 = 1;
            D_00582780 = 1;
            if (!IsHost_433160() && old) {
                Res_433160 r;
                int k[1];
                Busy_433160 busy;
                k[0] = old->key;
                cNPCInfoObject_Add(&r, k, old->b4);
                cNPCInfoObject_SetOwner_cObjectIdR_int(&r, k, old->b4);
                Free_433160(old, 0x620);
            }
            D_00582A78 = key;
        } else if (!D_00582788) {
            if (D_005827F8) Free_433160(D_005827F8, 0x629);
            D_005827F8 = o->ent;
            D_00582A80 = key;
            D_00582788 = 1;
        } else if (!D_00582790) {
            if (D_00582800) Free_433160(D_00582800, 0x635);
            D_00582800 = o->ent;
            D_00582A88 = key;
            D_00582790 = 1;
        } else if (!D_00582798) {
            if (D_00582808) Free_433160(D_00582808, 0x640);
            D_00582808 = o->ent;
            D_00582A90 = key;
            D_00582798 = 1;
        } else {
            if (D_00582810) Free_433160(D_00582810, 0x64A);
            D_00582810 = o->ent;
            D_00582A98 = key;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433160 */

/* merge_units: begin func_004335F0 */
#pragma push /* merge_units */
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm_335F0;
extern int NetRegisterObjectStart(void);
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm_335F0* prm);
extern int NetRegisterStructure(int* table, char* name, int size);
extern int NetRegisterRemoteObjectCallback(int table, void* a, void* b, void* c);
extern int D_00582A70;
extern void cNPCInfoObject_NPCInfoCreationCallback();
extern void cNPCInfoObject_NPCInfoUpdateCallback();
extern void cNPCInfoObject_NPCInfoDeleteCallback();

static inline void Reset_335F0(NpcInfoRec* r)
{
    int j;
    r->key = -1;
    r->b4 = 0xFF;
    r->state = 0xFF;
    for (j = 0; j < 4; j++) { r->a6[j] = 0; r->aA[j] = 1; }
}

unsigned char NpcInfo_RegisterNetType(void)
{
    int db;
    Prm_335F0 prm;
    NpcInfoRec def;
    NpcInfoRec arr[29];
    unsigned char ok = 0;
    NpcInfoRec* p;
    int i;
    int err;
    Reset_335F0(&def);
    p = arr;
    do { Reset_335F0(p); p++; } while (p != arr + 29);
    prm.ver = 1;
    prm.flags = 0;
    prm.max = 100;
    prm.mode = 0x40;
    if (NetRegisterObjectStart() == 0) {
        NpcInfoRec* q = arr;
        NpcInfoRec* base = q;
        for (i = 0; i < 29; i++, q++)
            err = NetObjectField(&db, (char*)q - (char*)base, 1, 1, 0x10, &prm);
        if (err == 0 && NetRegisterStructure(&D_00582A70, "tNPCInfoStruct", 0x1D0) == 0) {
            NetRegisterRemoteObjectCallback(D_00582A70, cNPCInfoObject_NPCInfoCreationCallback, cNPCInfoObject_NPCInfoUpdateCallback, cNPCInfoObject_NPCInfoDeleteCallback);
            ok = 1;
        }
    }
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004335F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004335F0 */

/* merge_units: begin func_00433760 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
#if 0 /* merge_units */
extern char D_004BFCA0;
#endif /* merge_units */
#define D_004BFCA0 (*(char*)&D_004BFCA0) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
#if 0 /* merge_units */
extern int D_005827F0;
#endif /* merge_units */
#define D_005827F0 (*(int*)&D_005827F0) /* merge_units */

#if 0 /* merge_units */
extern int D_005827F8;
#endif /* merge_units */
#define D_005827F8 (*(int*)&D_005827F8) /* merge_units */

#if 0 /* merge_units */
extern int D_00582800;
#endif /* merge_units */
#define D_00582800 (*(int*)&D_00582800) /* merge_units */

#if 0 /* merge_units */
extern int D_00582808;
#endif /* merge_units */
#define D_00582808 (*(int*)&D_00582808) /* merge_units */

#if 0 /* merge_units */
extern int D_00582810;
#endif /* merge_units */
#define D_00582810 (*(int*)&D_00582810) /* merge_units */

}
extern "C" void cNPCInfoObject_DestroyNPCInfoStruct(void) {
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;

    if (D_00582780 == 0) {
        temp_s0 = D_005827F0;
        if (temp_s0 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0, &D_004BFCA0, 0x5AA);
            }
        }
        temp_s0_2 = D_005827F8;
        if (temp_s0_2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_2, &D_004BFCA0, 0x5AD);
            }
        }
        temp_s0_3 = D_00582800;
        if (temp_s0_3 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_3, &D_004BFCA0, 0x5B0);
            }
        }
        temp_s0_4 = D_00582808;
        if (temp_s0_4 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_4, &D_004BFCA0, 0x5B3);
            }
        }
        temp_s0_5 = D_00582810;
        if (temp_s0_5 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_5, &D_004BFCA0, 0x5B6);
            }
        }
        D_005827F0 = 0;
        D_005827F8 = 0;
        D_00582800 = 0;
        D_00582808 = 0;
        D_00582810 = 0;
    }
}
#undef D_004BFCA0 /* merge_units */
#undef D_005827F0 /* merge_units */
#undef D_005827F8 /* merge_units */
#undef D_00582800 /* merge_units */
#undef D_00582808 /* merge_units */
#undef D_00582810 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433760 */

/* merge_units: begin func_00433A60 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; int f1C; } P_433A60;
extern unsigned char D_005721D0;
#if 0 /* merge_units */
extern int D_005827F0;
#endif /* merge_units */
#define D_005827F0 (*(int*)&D_005827F0) /* merge_units */
#if 0 /* merge_units */
extern int D_005827F8;
#endif /* merge_units */
#define D_005827F8 (*(int*)&D_005827F8) /* merge_units */
#if 0 /* merge_units */
extern int D_00582800;
#endif /* merge_units */
#define D_00582800 (*(int*)&D_00582800) /* merge_units */
#if 0 /* merge_units */
extern int D_00582808;
#endif /* merge_units */
#define D_00582808 (*(int*)&D_00582808) /* merge_units */
#if 0 /* merge_units */
extern int D_00582810;
#endif /* merge_units */
#define D_00582810 (*(int*)&D_00582810) /* merge_units */

int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, int g, char* h, int i);
#if 0 /* merge_units */
int NetGetObject(P_433A60** out, int key);
#endif /* merge_units */
#define NetGetObject(a0, a1) (NetGetObject((void *)(a0), (a1))) /* merge_units */


static inline void Reg_433A60(int* key, int* out)
{
    P_433A60* p;
    if (!NetCreateObject(key, 2, 4, 0, 0, 0, 0, *out, "cNPCInfoObject", D_00582A70) && !NetGetObject(&p, *key)) *out = p->f1C;
}

void cNPCInfoObject_CreateNPCInfoStruct(void)
{
    if (D_005721D0 && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Reg_433A60(&D_00582A78, &D_005827F0);
        Reg_433A60(&D_00582A80, &D_005827F8);
        Reg_433A60(&D_00582A88, &D_00582800);
        Reg_433A60(&D_00582A90, &D_00582808);
        Reg_433A60(&D_00582A98, &D_00582810);
    }
}
#undef D_005827F0 /* merge_units */
#undef D_005827F8 /* merge_units */
#undef D_00582800 /* merge_units */
#undef D_00582808 /* merge_units */
#undef D_00582810 /* merge_units */
#undef NetGetObject /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433A60 */

/* merge_units: begin func_00433CE0 */
#pragma push /* merge_units */
void cNPCInfoObject_AddPendingDeactivate(int self, NpcInfoMsg* m);
void cNPCInfoObject_Deactivate(int self, int key)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    cNPCInfoObject_Setup(self);
    r = cNPCInfoObject_Find(key, &h);
    if (r) {
        NPC_INFO_COPY(m, r)
        if (D_005721D0) {
            m.f10 = h;
            m.a6[NetLocalId()] = 0;
            r->a6[NetLocalId()] = 0;
            cNPCInfoObject_AddPendingDeactivate(self, &m);
            func_00434920(self, h);
        } else {
            r->a6[NetLocalId()] = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433CE0 */

/* merge_units: begin func_00433EC0 */
#pragma push /* merge_units */
typedef struct { char pad[0xA]; unsigned char vals[4]; } R1Rec_33EC0;
#if 0 /* merge_units */
extern R1Rec_33EC0* cNPCInfoObject_Find(int key, int flag);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) ((R1Rec_33EC0 *)cNPCInfoObject_Find((a0), (void *)(a1))) /* merge_units */

unsigned char cNPCInfoObject_IsInActiveTerrain(void* self, int key, int idx)
{
    R1Rec_33EC0* r = cNPCInfoObject_Find(key, 0);
    if (r && idx >= 0 && idx < 4)
        return r->vals[idx];
    return 0;
}
#undef cNPCInfoObject_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433EC0 */

/* merge_units: begin func_00433F20 */
#pragma push /* merge_units */
void func_00434BE0(int self, NpcInfoMsg* m, unsigned char v);
void func_00433F20(int self, int key, signed char v)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (g_IsMultiplayer) {
        cNPCInfoObject_Setup(self);
        r = cNPCInfoObject_Find(key, &h);
        if (r) {
            NPC_INFO_COPY(m, r)
            m.aA[NetLocalId()] = v;
            m.f10 = h;
            r->aA[NetLocalId()] = v;
            func_00434BE0(self, &m, v);
            func_00434920(self, h);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00433F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00433F20 */

/* merge_units: begin func_004340C0 */
#pragma push /* merge_units */
#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#pragma mpwc_relax on
int NetGame_InitLocalSlot(int *, int);                        
#if 0 /* merge_units */
int cNPCInfoObject_Find(int, int);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) ((int)cNPCInfoObject_Find((a0), (void *)(a1))) /* merge_units */
                            
extern int D_00494178;
extern int D_005721A8;

unsigned char cNPCInfoObject_IsActiveOnRemote(int arg0, int arg1) {
    int temp_v0;
    unsigned char var_s1;
    int var_s0;
    int var_v0;

    temp_v0 = cNPCInfoObject_Find(arg1, 0);
    var_s1 = 0;
    if (temp_v0 != 0) {
        var_s0 = 0;
        do {
            LOCALID_(var_v0)
            if ((var_s0 != var_v0) && (F_((temp_v0 + var_s0), 0x6, unsigned char) != 0)) {
                var_s1 = 1;
            }
            var_s0 += 1;
        } while (var_s0 < 4);
    }
    return var_s1;
}
#undef cNPCInfoObject_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004340C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004340C0 */

/* merge_units: begin func_00434190 */
#pragma push /* merge_units */
typedef struct { char pad[0x6]; unsigned char vals[4]; } R1Rec_34190;
#if 0 /* merge_units */
extern R1Rec_34190* cNPCInfoObject_Find(int key, int flag);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) ((R1Rec_34190 *)cNPCInfoObject_Find((a0), (void *)(a1))) /* merge_units */

unsigned char cNPCInfoObject_IsActive(void* self, int key, int idx)
{
    R1Rec_34190* r = cNPCInfoObject_Find(key, 0);
    if (r && idx >= 0 && idx < 4)
        return r->vals[idx];
    return 0;
}
#undef cNPCInfoObject_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434190 */

/* merge_units: begin func_004341F0 */
#pragma push /* merge_units */
void cNPCInfoObject_AddPendingActivate(int self, NpcInfoMsg* m);
void cNPCInfoObject_SetActive(int self, int key)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (g_IsMultiplayer) {
        cNPCInfoObject_Setup(self);
        r = cNPCInfoObject_Find(key, &h);
        if (r) {
            NPC_INFO_COPY(m, r)
            m.a6[NetLocalId()] = 1;
            r->a6[NetLocalId()] = 1;
            m.f10 = h;
            cNPCInfoObject_AddPendingActivate(self, &m);
            func_00434920(self, h);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004341F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004341F0 */

/* merge_units: begin func_00434380 */
#pragma push /* merge_units */
typedef struct { char pad[5]; unsigned char state; } E4380;
#if 0 /* merge_units */
extern void cNPCInfoObject_Setup(int a);
#endif /* merge_units */
#define cNPCInfoObject_Setup(a0) (cNPCInfoObject_Setup((a0))) /* merge_units */

#if 0 /* merge_units */
extern E4380* cNPCInfoObject_Find(int key, int b);
#endif /* merge_units */
#define cNPCInfoObject_Find(a0, a1) ((E4380 *)cNPCInfoObject_Find((a0), (void *)(a1))) /* merge_units */

int cNPCInfoObject_GetPrevOwner(int a, int key) {
    E4380* p;
    cNPCInfoObject_Setup(a);
    p = cNPCInfoObject_Find(key, 0);
    if (p != 0 && p->state != 0xFF) return p->state;
    return -1;
}
#undef cNPCInfoObject_Setup /* merge_units */
#undef cNPCInfoObject_Find /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434380 */
