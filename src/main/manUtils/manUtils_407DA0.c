/*
 * main/manUtils: 5 files, 00407DA0-00408100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00407DA0 */
#pragma push /* merge_units */
#include "types.h"
typedef union { long long q[4]; char s[32]; __int128 v[2]; } H2Key;
typedef struct { char b[0x440]; } H2Pack;
typedef struct { H2Key* keys; H2Pack* packs; int count; } H2Registry;
extern void Appearance_RegistryKey(char* dst, int n, char* src);
/* Finds the registry packing whose key equals the upper-cased stem of name. */
H2Pack* SklRegistry_Find(H2Registry* reg, char* name) {
    int n;
    char* p;
    int i;
    H2Key key;
    if (name == 0)
        return 0;
    n = reg->count;
    Appearance_RegistryKey(p = key.s, 0x1f, name);
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
#pragma pop /* merge_units */
/* merge_units: end func_00407DA0 */

/* merge_units: begin func_00407EC0 */
#pragma push /* merge_units */
/* Copies the stem of a file name (up to '.') into a zero-padded key. */
void Appearance_RegistryKey(char* dst, int n, char* src) {
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
#pragma pop /* merge_units */
/* merge_units: end func_00407EC0 */

/* merge_units: begin func_00407F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DFD80[];
extern "C" char D_004E08A0[];
MSG_CLONE_BEGIN(cDamageMsg_v01, 0x30, "DamageMsg.hh", 0x20)
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
extern int GObj_IdentityA(int who);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cDamageMsg_Type(cDamageMsg** msg) {
    return (*msg)->type;
}

int Script_cDamageMsg_Where(cDamageMsg** msg) {
    return (*msg)->where;
}

int Script_cDamageMsg_Attacker(cDamageMsg** msg) {
    return GObj_IdentityA((*msg)->attacker);
}

/* Returns the float damage value as its raw bits. */
int Script_cDamageMsg_Damage(cDamageMsg** msg) {
    int loc[1];

    loc[0] = *(int*)&(*msg)->damage;
    return *(int*)loc;
}

void ScriptType_cDamageMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_00571708, *base);
}

int cDamageMsg_SOBJ_getClassId(void) {
    return (int)&D_00571700;
}

int cDamageMsg_v03(void) {
    return D_00571700;
}
#pragma pop /* merge_units */
/* merge_units: end func_00408060 */

/* merge_units: begin func_00408100 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void* reg);
extern int Event_UnpackHeader(void* desc);

extern int NetMessageField(void* desc, void* field, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_005716F8;
extern void cDamageMsg_NetReceive(void);
unsigned char cDamageMsg_NetRegister(void* reg)
{
    struct { long long file; char f8; char padC[3]; int fC; short f10; short f12; short f14; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && Event_UnpackHeader(&L.file) != 0
        && NetMessageField(&L.file, &L.f8, 1, 1) == 0
        && NetMessageField(&L.file, &L.fC, 4, 1) == 0
        && NetMessageField(&L.file, &L.f10, 2, 1) == 0
        && NetMessageField(&L.file, &L.f14, 2, 1) == 0
        && NetMessageField(&L.file, &L.f12, 2, 1) == 0
        && NetMsg_RegisterType(&D_005716F8, 2, cDamageMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_00408100 */
