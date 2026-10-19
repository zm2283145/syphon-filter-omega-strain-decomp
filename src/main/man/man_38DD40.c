/*
 * main/man: range (2 files, 0038DD40-0038DE20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"

/* merge_units: begin func_0038DD40 */
#pragma push /* merge_units */
extern void TexCache_LoadPartTexture(void* cache, __int128 name, int arg, short* slot, short* out);
extern char g_AgentPartCache[];
char D_00493410[16] = "_THER_BLA_----0";
char D_00493420[16] = "_THER_COO_----0";
char D_00493430[16] = "_THER_WAR_----0";
char D_00493440[16] = "_THER_HOT_----0";
char D_00493450[16] = "_THER_FLA_----0";
extern short D_0053B360;
extern short D_0053B362;
extern short D_0053B364;
extern short D_0053B366;
extern short D_0053B368;
#pragma opt_propagation off
void TexCache_AddThermalTextures(int arg)
{
    short tmp;
    __int128* p;
    p = (__int128*)D_00493410;
    TexCache_LoadPartTexture(g_AgentPartCache, *p, arg, &D_0053B360, &tmp);
    p = (__int128*)D_00493420;
    TexCache_LoadPartTexture(g_AgentPartCache, *p, arg, &D_0053B362, &tmp);
    p = (__int128*)D_00493430;
    TexCache_LoadPartTexture(g_AgentPartCache, *p, arg, &D_0053B364, &tmp);
    TexCache_LoadPartTexture(g_AgentPartCache, *(__int128*)D_00493440, arg, &D_0053B366, &tmp);
    TexCache_LoadPartTexture(g_AgentPartCache, *(__int128*)D_00493450, arg, &D_0053B368, &tmp);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DD40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038DD40 */

/* merge_units: begin func_0038DE20 */
#pragma push /* merge_units */
extern char D_004BC3B0[];
extern unsigned int D_005712F0[];
extern __int128* D_005712F8[];
static inline int ks0038DE20eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks0038DE20and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks0038DE20from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks0038DE20meq(__int128 m, __int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pand t, m, a
        pand b, m, b
        pceqw t, t, b
        ppach r, t, t
    }
    return r == -1;
}
int ActorModel_GetMorphCount(int idx)
{
    __int128 mask = ks0038DE20from(0xFFFFFFFFFFFFLL);
    __int128 key;
    __int128* e;
    unsigned int i;
    int n;
    String_Copy(&key, D_004BC3B0);
    e = D_005712F8[idx];
    n = 0;
    for (i = 0; i < D_005712F0[idx]; i++) {
        if (ks0038DE20meq(mask, key, e[i]))
            n++;
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038DE20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038DE20 */
