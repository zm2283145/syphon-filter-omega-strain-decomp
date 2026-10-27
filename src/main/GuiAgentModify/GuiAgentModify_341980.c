/*
 * main/GuiAgentModify: range (2 files, 00341980-00341A30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
int strcmp(const void *, const void *);

/* merge_units: begin func_00341980 */
#pragma push /* merge_units */
typedef union { __int128 q; char s[16]; } KeyCA70;
typedef struct { __int128 q; char pad[0x10]; } EntCA70;
typedef struct { char pad[0xE0]; EntCA70 e[(0x2420 - 0xE0) / 0x20]; unsigned short count; } TblCA70;
typedef struct { char pad[0x8C]; TblCA70* tbl; char pad74[0x10C - 0x90]; char idx; } ObjCA70;
extern char D_004B9F80[];
static inline int kca70eq(__int128 m, __int128 a, __int128 b) {
    __int128 r;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach r, r, r
    }
    return (long)r == -1;
}
static inline __int128 kca70q(__int128 v) { __int128 r; asm { pcpyld r, $zero, v } return r; }
void GuiAgentModify_findFacePart(ObjCA70* self) {
    __int128 mask = kca70q(0xFFFFFFFF00);
    KeyCA70 key;
    int i;
    Libc_Strcpy(key.s, D_004B9F80);
    
    for (i = 0; i < self->tbl->count; i++) {
        if (kca70eq(mask, key.q, self->tbl->e[i].q)) {
            self->idx = i;
            return;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341980 */

/* merge_units: begin func_00341A30 */
#pragma push /* merge_units */
typedef struct { char name[16]; } P_Name;
typedef struct { float x, y, z, w; } P_Sc;
typedef struct { unsigned int count; P_Name e[24]; P_Sc* sc[1]; } P_Tbl;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } P_Skl;
typedef struct { char pad0[0xA0]; char name[0x2BC4]; P_Skl* skel; } P_App;
typedef struct { char pad0[0x8C]; P_App* app; } P_Obj;
extern P_Tbl D_00571300;
extern float* cArray_cBoneScale_opIndex(void*, int);
extern void* cArray_cBone_opIndex_int_2(void*, int);
extern void cBone_SetScaleX(void*, float);
extern void cBone_SetScaleY(void*, float);
extern void cBone_SetScaleZ(void*, float);

void GuiAgentModify_NextBoneSet(P_Obj* o) {
    unsigned int preset;
    int i;
    for (preset = 0; preset < D_00571300.count; preset++) {
        if (!strcmp(o->app->name, D_00571300.e[preset].name)) break;
    }
    preset++;
    if (preset >= D_00571300.count) preset = 0;
    memcpy(o->app->name, D_00571300.e[preset].name, 0xF);
    for (i = 0; i < 0x15; i++) {
        P_Skl* k;
        float v;
        v = D_00571300.sc[preset][i].x; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[0] = v;
        if (k->hasMorph) cBone_SetScaleX(cArray_cBone_opIndex_int_2(k->morph, i), v);
        v = D_00571300.sc[preset][i].y; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[1] = v;
        if (k->hasMorph) cBone_SetScaleY(cArray_cBone_opIndex_int_2(k->morph, i), v);
        v = D_00571300.sc[preset][i].z; k = o->app->skel;
        cArray_cBoneScale_opIndex(k->bones, i)[2] = v;
        if (k->hasMorph) cBone_SetScaleZ(cArray_cBone_opIndex_int_2(k->morph, i), v);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00341A30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00341A30 */
