/*
 * SFOGame/Source/GuiAgentCreate: 4 files, 0028CD70-0028D300
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028CD70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    char pad[0x70];
    __int128 save70;
    char pad2[0x2C04 - 0x80];
    int keep;
    char pad3[0x2C10 - 0x2C08];
    signed char preset;
    char pad4[0x2DF0 - 0x2C11];
} __attribute__((aligned(16))) S28C;
extern void cMan_SetBoneSet(S28C* s, int preset);
static inline void QCopy_28C(void* d0, void* s0) { int n = 0x2DF; void* s = s0; void* d = d0;
    asm {
        .set noreorder
        nop
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
void GuiAgentCreate_CloneMan(void* unused, S28C* s, S28C* src)
{
    __int128 q = s->save70;
    int k = s->keep;
    QCopy_28C(s, src);
    s->keep = k;
    cMan_SetBoneSet(s, s->preset);
    s->save70 = q;
}
static inline void merge_flush_func_0028CD70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028CD70 */

/* merge_units: begin func_0028CDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* GuiAgentCreate_Randomize_2: reset the preview skeleton from the current agent table entry, then for
   each appearance row (2..10) step that row's part (mesh, colour, preset, morph or texture)
   a random 1..4 times in the given direction. */
typedef struct { __int128 a; __int128 b; } Ent_CDE0;
typedef struct {
    char pad0[0x40];
    char app[0x40];             /* +0x40 */
    Ent_CDE0 e[0xF2];           /* +0x80 */
    char x1EC0[0x500];          /* +0x1EC0 */
    unsigned short count;       /* +0x23C0 */
    char pad23C2[0x2C04 - 0x23C2];
    int keep;                   /* +0x2C04 */
    char pad2C08[4];
    unsigned char body;         /* +0x2C0C */
    signed char tone;           /* +0x2C0D */
    char pad2C0E[2];
    signed char preset;         /* +0x2C10 */
    char pad2C11[0x2DF0 - 0x2C11];
} Skel_CDE0;
typedef struct { char pad[0x60]; Skel_CDE0 skel; } Tbl_CDE0;
typedef struct { unsigned char mode; unsigned char slot; short pos; } Tab_CDE0;
typedef struct {
    char pad0[0x70];
    Tbl_CDE0* tbl;          /* +0x70 */
    char pad74[0xDC - 0x74];
    int tone;               /* +0xDC */
    char padE0[8];
    int vE8;                /* +0xE8 */
} S_CDE0;

extern "C" {
extern char g_AgentPartCache[];
extern __int128* D_0048B460;
extern Tab_CDE0 D_0048B500[][11];
extern unsigned int D_00571300;
void srand(unsigned int seed);
int Libc_Rand(void);
signed char SKL_FindRace(void* a);
#if 0 /* merge_units */
void cMan_SetBoneSet(Skel_CDE0* s, int preset);
#endif /* merge_units */
#define cMan_SetBoneSet(a0, a1) (cMan_SetBoneSet((S28C *)(a0), (a1))) /* merge_units */

int FindPart__7MonsterF1(char* cache, __int128 name);
int Monster_FindNextPart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
int Monster_FindNextSamePart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
int AgentPacking_StepTexture(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, int tone, void* app, void* x);
int FindTextureNumber__7MonsterF1(void* db, __int128 key);
int cMan_NextFaceShape(Skel_CDE0* s, int dir, int idx, int body);
void GuiAgentCreate_Randomize_2(S_CDE0* self, Skel_CDE0* skel, int dir);
}

/* quadword block copy loop (n quadwords), the retail struct copy */
static inline void QCopy(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

static inline Tbl_CDE0* Tbl(S_CDE0* s) { Tbl_CDE0* p = s->tbl; return p; }
void GuiAgentCreate_Randomize_2(S_CDE0* self, Skel_CDE0* skel, int dir)
{
    int item; int partNumber; int texNumber; int bodyPart; int partTexMode; int sex; int found; int count; int j1; int j2; int j3; int bone; int j4; int j5;
    srand(*(unsigned int*)0x10000000);
    {
        Skel_CDE0* src = &Tbl(self)->skel;
        __int128 save = *(__int128*)&skel->app[0x30];
        int keep = skel->keep;
        QCopy(skel, src, 0x2DF0 / 16);
        skel->keep = keep;
        cMan_SetBoneSet(skel, skel->preset);
        *(__int128*)&skel->app[0x30] = save;
    }
    sex = skel->body;
    for (item = 2; item < 11; item++) {
        count = Libc_Rand() & 3;
        count++;
        bodyPart = D_0048B500[sex][item].slot;
        partTexMode = D_0048B500[sex][item].mode;
        self->tone = SKL_FindRace(skel->app);
        skel->tone = self->tone;
        if (partTexMode == 0) {
            partNumber = FindPart__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].a);
            for (j1 = 0; j1 < count; j1++) {
                found = Monster_FindNextPart(g_AgentPartCache, dir, skel->e[bodyPart].a, partNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1) {
                    partNumber = found;
                    FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
                }
            }
        } else if (partTexMode == 7) {
            partNumber = FindPart__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].a);
            for (j2 = 0; j2 < count; j2++) {
                found = Monster_FindNextSamePart(g_AgentPartCache, dir, skel->e[bodyPart].a, partNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1) {
                    partNumber = found;
                    FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
                }
            }
        } else if (partTexMode == 1 || partTexMode == 1) {
            texNumber = FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
            for (j3 = 0; j3 < count; j3++) {
                if (bodyPart < skel->count)
                    found = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, skel->e[bodyPart].a, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                else
                    found = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1)
                    texNumber = found;
            }
        } else if (partTexMode == 5) {
            bone = skel->preset + count * dir;
            if (bone < 0)
                bone = D_00571300 - bone;
            if (bone < 0)
                bone = 0;
            if ((unsigned int)bone >= D_00571300)
                bone -= D_00571300;
            if ((unsigned int)bone >= D_00571300)
                bone = 0;
            skel->preset = bone;
            cMan_SetBoneSet(skel, bone);
        } else if (partTexMode == 6) {
            for (j4 = 0; j4 < count; j4++)
                self->vE8 = cMan_NextFaceShape(skel, dir, self->vE8, sex);
        } else if (partTexMode == 8) {
            texNumber = FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
            for (j5 = 0; j5 < count; j5++) {
                found = AgentPacking_StepTexture(g_AgentPartCache, dir, skel->e[bodyPart].a, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1)
                    texNumber = found;
            }
        }
    }
}
#undef cMan_SetBoneSet /* merge_units */
static inline void merge_flush_func_0028CDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028CDE0 */

/* merge_units: begin func_0028D300 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
void *memcpy();
int strcmp(const void *, const void *);

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D4E0;
typedef struct { char pad[0x130]; V4_D4E0 v; } O_D4E0;
void cBone_SetScaleZ(O_D4E0* o, float z); /* gsynth: defined below */
typedef struct { char name[16]; } P_Name;
typedef struct { float x, y, z, w; } P_Sc;
typedef struct { unsigned int count; P_Name e[24]; P_Sc* sc[1]; } P_Tbl;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } P_Skl;
typedef struct { char pad0[0xA0]; char name[0x2BC4]; P_Skl* skel; } P_App;
typedef struct { char pad0[0x70]; P_App* app; } P_Obj;
#if 0 /* merge_units */
extern P_Tbl D_00571300;
#endif /* merge_units */
#define D_00571300 (*(P_Tbl*)&D_00571300) /* merge_units */

extern float* cArray_cBoneScale_opIndex(void*, int);
extern void* cArray_cBone_opIndex_int_2(void*, int);
extern void cBone_SetScaleX(void*, float);
extern void cBone_SetScaleY(void*, float);
#if 0 /* merge_units */
extern void cBone_SetScaleZ(void*, float);
#endif /* merge_units */
#define cBone_SetScaleZ(a0, a1) (cBone_SetScaleZ((O_D4E0 *)(a0), (a1))) /* merge_units */



void GuiAgentCreate_NextBoneSet(P_Obj* o) {
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
static inline void merge_flush_func_0028D300(void) {}
#undef D_00571300 /* merge_units */
#undef cBone_SetScaleZ /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028D300 */

/* merge_units: begin func_0028D4E0 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void cBone_SetScaleZ(O_D4E0* o, float z) {
    V4_D4E0 r; V4_D4E0 t;
    V4_D4E0* d2;
    V4_D4E0* d3;
    V4_D4E0* d1;
    float b; float c; float d; float a;
    d1 = &t; *d1 = o->v; d2 = &t; d2->z = z; d3 = &r; *d3 = *d2;
    d = r.w; c = r.z; b = r.y; a = r.x;
    o->v.x = a; o->v.y = b; o->v.z = c; o->v.w = d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028D4E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028D4E0 */
