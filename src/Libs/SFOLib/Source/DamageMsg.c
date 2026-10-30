/*
 * Libs/SFOLib/Source/DamageMsg: 8 files, 00407DA0-004081E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00407DA0 */
#pragma push /* merge_units */
#include "types.h"
typedef union { long long q[4]; char s[32]; __int128 v[2]; } H2Key;
typedef struct { char b[0x440]; } H2Pack;
typedef struct { H2Key* keys; H2Pack* packs; int count; } H2Registry;
extern void strCpyPad(char* dst, int n, char* src);
/* Finds the registry packing whose key equals the upper-cased stem of name. */
H2Pack* SKLHog_FindSKL(H2Registry* reg, char* name) {
    int n;
    char* p;
    int i;
    H2Key key;
    if (name == 0)
        return 0;
    n = reg->count;
    strCpyPad(p = key.s, 0x1f, name);
    while (*p != 0) {
        int c = *(volatile char*)p;
        if (c >= 'a' && c <= 'z')
            *p = c - 0x20;
        p++;
    }
    for (i = 0; i < n; i++) {
        if (reg->keys[i].q[0] == key.q[0] && reg->keys[i].q[1] == key.q[1] &&
            reg->keys[i].q[2] == key.q[2] && reg->keys[i].q[3] == key.q[3])
            return &reg->packs[i];
    }
    return 0;
}
static inline void merge_flush_func_00407DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407DA0 */

/* merge_units: begin func_00407EC0 */
#pragma push /* merge_units */
/* Copies the stem of a file name (up to '.') into a zero-padded key. */
void strCpyPad(char* dst, int n, char* src) {
    int i = 0;
    char c;
    while (!!(c = *src) && i < n) {
        if (c == '.')
            break;
        *dst++ = c;
        src++;
        i++;
    }
    while (i < n) {
        *dst++ = 0;
        i++;
    }
    *dst = 0;
}
static inline void merge_flush_func_00407EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407EC0 */

/* merge_units: begin func_00407F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DFD80[];
extern "C" char D_004E08A0[];
MSG_CLONE_BEGIN(cDamageMsg_Clone, 0x30, "DamageMsg.hh", 0x20)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E08A0;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(char, 0x2C) = S(char, 0x2C);
    F(char, 0x2D) = S(char, 0x2D);
    F(unsigned char, 0x2E) = S(unsigned char, 0x2E);
MSG_CLONE_END
static inline void merge_flush_func_00407F40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00407F40 */

/* merge_units: begin func_00408060 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cDamageMsg script accessor natives, script type registration and the
 * type-descriptor virtual slots.
 */

#include "loose04_types.h"

extern int D_00571700;
extern int D_00571708;
extern int cGOBJ_SOBJ_toInt(int who);
extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int baseType);

int Script_cDamageMsg_Type(cDamageMsg** msg) {
    return (*msg)->type;
}

int Script_cDamageMsg_Where(cDamageMsg** msg) {
    return (*msg)->where;
}

int Script_cDamageMsg_Attacker(cDamageMsg** msg) {
    return cGOBJ_SOBJ_toInt((*msg)->attacker);
}

/* Returns the float damage value as its raw bits. */
int Script_cDamageMsg_Damage(cDamageMsg** msg) {
    int loc[1];

    loc[0] = *(int*)&(*msg)->damage;
    return *(int*)loc;
}

void cDamageMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_00571708, *base);
}

int cDamageMsg_SOBJ_getClassId(void) {
    return (int)&D_00571700;
}

int cDamageMsg_getSOBJClassId(void) {
    return D_00571700;
}
static inline void merge_flush_func_00408060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408060 */

/* merge_units: begin func_00408100 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void* reg);
extern int cMessage_RegisterFields(void* desc);

extern int NetMessageField(void* desc, void* field, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_005716F8;
extern int cDamageMsg_DamageCallback(int, int, int, void*);
unsigned char cDamageMsg_InitNet(void* reg)
{
    struct { long long file; char f8; char padC[3]; int fC; short f10; short f12; short f14; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cMessage_RegisterFields(&L.file) != 0
        && NetMessageField(&L.file, &L.f8, 1, 1) == 0
        && NetMessageField(&L.file, &L.fC, 4, 1) == 0
        && NetMessageField(&L.file, &L.f10, 2, 1) == 0
        && NetMessageField(&L.file, &L.f14, 2, 1) == 0
        && NetMessageField(&L.file, &L.f12, 2, 1) == 0
        && NetRegisterMessage(&D_005716F8, 2, cDamageMsg_DamageCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_00408100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408100 */

/* merge_units: begin func_004081E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
#include "vslot_pad.h"
struct Tgt4081E0 { char pad[0x38]; int kind; };
struct Sub4081E0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int Check(); };
struct Obj4081E0 { VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e) virtual void Hit(float amt, Tgt4081E0* src, int a, int b, int c, int d, int e); char pad[0x10]; unsigned char b14; char p15[0x43]; Sub4081E0* sub; };
typedef struct { int kind; int id; unsigned char b8; char p9[3]; int fC; short h10; short h12; unsigned short h14; } Pk4081E0;
typedef struct { void* vt; char p4[0x20]; int amt; Tgt4081E0* tgt; signed char b2C; signed char b2D; char p2E[6]; int tid; } Evt4081E0;
extern "C" {
extern unsigned char D_005721D0;
extern char g_MsgLibDamageRequestKey[], D_004E08A0[];
extern void cMessage_ctor_cMessageNameR(Evt4081E0* e, void* type);
void* nGobjManager_LookupGOBJ_cObjectIdR(int*);
Obj4081E0** cNetObj_GetNetSystem(int);
void QueueMessage_cMessageR_cSystemP_int_int(Evt4081E0*, void*, int, int);
void cMessage_dtor(Evt4081E0*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int cDamageMsg_DamageCallback(int a0, int a1, int a2, void* packet) {
    Pk4081E0* arg = (Pk4081E0*)packet;
    NetRecvGuard g;
    if (D_005721D0) {
        Evt4081E0 e;
        int k[1];
        Obj4081E0** look;
        Evt4081E0* p = &e;
Tgt4081E0** pt;
Pk4081E0* a = arg;
Obj4081E0* o;
        cMessage_ctor_cMessageNameR(p, g_MsgLibDamageRequestKey);
        e.vt = D_004E08A0;
        e.tid = a->fC;
        p->tgt = (Tgt4081E0*)nGobjManager_LookupGOBJ_cObjectIdR((int*)((char*)&e + 0x34));
        p->b2D = a->h10;
        p->amt = a->h14;
        p->b2C = a->h12;
        look = cNetObj_GetNetSystem(a->id);
        if (!look) { k[0] = a->id; o = (Obj4081E0*)nGobjManager_LookupGOBJ_cObjectIdR(k); } else o = *look;
        pt = &e.tgt;
        if (o && *pt) {
            if (a->b8) QueueMessage_cMessageR_cSystemP_int_int(&e, o, 0, 0);
            else {
                unsigned char ok = 0;
                if (o->sub && o->sub->Check()) ok = 1;
                if (ok && o->b14) {
                    if ((*pt)->kind != 0x80) o->Hit((float)e.amt, *pt, e.b2D, e.b2C, 0, 1, 0);
                } else o->Hit((float)e.amt, *pt, e.b2D, e.b2C, 0, 1, 0);
            }
        }
        e.vt = D_004E08A0;
        cMessage_dtor(&e, 0);
    }
    return 0x18;
}
#pragma pop
static inline void merge_flush_func_004081E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004081E0 */

/* merge_units: begin func_004083D0 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_BODY(e, b) MP_U(b, 8) = MP_U(e, 0x2E); MP_I(b, 0xC) = MP_I(MP_P(e, 0x28), 0xC); MP_H(b, 0x10) = MP_U(e, 0x2D); MP_H(b, 0x14) = MP_I(e, 0x24); MP_H(b, 0x12) = MP_U(e, 0x2C);

DEFINE_MESSAGE_PACK(cDamageMsg_Pack, 0x18, D_005716F8, PACK_BODY)
static inline void merge_flush_func_004083D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004083D0 */

/* merge_units: begin func_00408470 */
#pragma push /* merge_units */
typedef struct { int a; int b; unsigned char ready; } O470;
extern int cMaterialPropertiesTable_Lookup_charP_ucharR(O470* o, const char* name, unsigned char* out);
unsigned char cMaterialPropertiesTable_Lookup_charP(O470* o, const char* name) {
    unsigned char r = 0;
    if (!o->ready || !name || !*name)
        return 0;
    cMaterialPropertiesTable_Lookup_charP_ucharR(o, name, &r);
    return r;
}
static inline void merge_flush_func_00408470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408470 */
