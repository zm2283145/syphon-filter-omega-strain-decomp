/*
 * SFOGame/Source/SpecFxDefs: 7 files, 00236FF0-00237380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00236FF0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int handle; unsigned char loaded; } EffSlot;
typedef struct { int d[0x28]; } HogEnt;
extern char D_004A6E60[];
extern char* D_0048ACD0[];
extern char* D_0048AD40[];
extern EffSlot SpecFxTable[];
extern char D_0053B540[];
extern void* g_TextureMgr;
extern int sprintf(char*, const char*, ...);
extern void* cFileMan_ctor_void(void*);
extern void* cFileMan_dtor(void*, int);
extern int cFileMan_EncodeFilename_charP_cHogFileR_bool(void*, const char*, int, int);
extern int cHogList_Open(int, char*, int, int);
extern void cParticleSystem_RequestEffectLoad(void*, char*, EffSlot*);
extern int cTexMan_AddTextureFromFile_cFileManR(void*, void*);
extern int cTexMan_UseMrYuckTexture(void*);

void nSfxLoader_LoadEffects(int a0, int arc)
{
    char buf[0x80];
    HogEnt e;
    int i;
    int j;

    sprintf(buf, D_004A6E60, a0);
    cFileMan_ctor_void(&e);
    for (i = 0; i < 26; i++) {
        cParticleSystem_RequestEffectLoad(D_0053B540, D_0048ACD0[i], &SpecFxTable[i]);
        SpecFxTable[i].loaded = 1;
    }
    for (j = 0; j < 15; j++) {
        cFileMan_EncodeFilename_charP_cHogFileR_bool(&e, D_0048AD40[j], cHogList_Open(arc, buf, 0, 0), 0);
        {
        int h = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &e);
        SpecFxTable[j + 26].handle = h;
        SpecFxTable[j + 26].loaded = h > -1;
        }
        if (!SpecFxTable[j + 26].loaded) {
            SpecFxTable[j + 26].handle = cTexMan_UseMrYuckTexture(g_TextureMgr);
            SpecFxTable[j + 26].loaded = 1;
        }
    }
    cFileMan_dtor(&e, -1);
}
static inline void merge_flush_func_00236FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00236FF0 */

/* merge_units: begin func_00237130 */
#pragma push /* merge_units */
extern char D_004DBAE0[];
extern int cSfxBundle_opDelete(int);
extern int cSfxBundle_dtor(int, int);

int cWeaponFx_dtor(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L00237178;
    a1 = 0;
    v0 = (int)D_004DBAE0;
    *(int*)((char*)s1 + 20) = v0;
    v0 = cSfxBundle_dtor(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L00237178;
    v0 = cSfxBundle_opDelete(a0);
L00237178:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237130 */

/* merge_units: begin func_00237190 */
#pragma push /* merge_units */
extern char D_004DBB00[];

int cParticleBundle_dtor(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L002371D8;
    a1 = 0;
    v0 = (int)D_004DBB00;
    *(int*)((char*)s1 + 20) = v0;
    v0 = cSfxBundle_dtor(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L002371D8;
    v0 = cSfxBundle_opDelete(a0);
L002371D8:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237190 */

/* merge_units: begin func_002371F0 */
#pragma push /* merge_units */
extern char D_004DBB20[];

int cLightBundle_dtor(int a0, int a1) {
    int s0, s1, v0;
    int cond;

    s1 = a0;
    cond = s1 == 0;
    s0 = a1;
    if (cond) goto L00237238;
    a1 = 0;
    v0 = (int)D_004DBB20;
    *(int*)((char*)s1 + 20) = v0;
    v0 = cSfxBundle_dtor(a0, a1);
    v0 = (short)s0;
    cond = v0 <= 0;
    a0 = s1;
    if (cond) goto L00237238;
    v0 = cSfxBundle_opDelete(a0);
L00237238:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002371F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002371F0 */

/* merge_units: begin func_00237250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNetSpawnParticleMsg class type accessor.
 */


extern int D_004F7BF0;   /* cNetSpawnParticleMsg class type id */

int cNetSpawnParticleMsg_GetMsgId(void) {
    return D_004F7BF0;
}
static inline void merge_flush_func_00237250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237250 */

/* merge_units: begin func_00237260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DBB40[];

struct Msg_00237260 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DBB40; p->a24 = s->a24; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(cNetSpawnParticleMsg_Clone, Msg_00237260, 44, D_004A6E38, 1716, CLONE_BODY)
static inline void merge_flush_func_00237260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237260 */

/* merge_units: begin func_00237380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

IdFlag* tLoadRec_ctor(IdFlag* self) {
    self->id = -1;
    self->flag = 0;
    return self;
}
static inline void merge_flush_func_00237380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00237380 */
