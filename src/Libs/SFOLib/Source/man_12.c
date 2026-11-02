/*
 * Libs/SFOLib/Source/man: 8 files, 00391020-00391810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00391020 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
void *memcpy();
int strcmp(const void *, const void *);

#pragma cplusplus on
#include "alloc_guard.h"

struct Pair391020 {
    __int128 a;
    __int128 b;
};

struct App391020 {
    char pad[0x40];
    Pair391020 pairs[1];
};

struct Self391020 {
    char pad[0x20];
    char x20[0x20];
    App391020 app;
    char padX[0x22C0 - 0x40 - sizeof(App391020)];
    short x22C0[0x20];
    short x2300[0x60];
    short x23C0;
    char pad23C2[0x2C14 - 0x23C2];
    App391020* x2C14;
};

extern "C" {
extern char g_AgentPartCache[];
extern char D_005711B0[];
extern char D_004BC310[];

void cMan_MergeSKLs(Self391020* self);
void SKL_RemoveBlanks(App391020* app);
int SKL_CountAttribs(App391020* app);
void SKL_LoadSKLParts(App391020* app, int hard, char* out);
void Monster_FindAddTexture(char* cache, __int128 name, char* tex, short* a, short* b);
int FindTex__7MonsterF1(char* cache, __int128 name);
void Monster_FreeTexture(char* cache, int slot);
int FindPart__7MonsterF1(char* cache, __int128 name);
void Monster_FreePart(char* cache, int slot);
void cMan_SortParts(Self391020* self);
#if 0 /* merge_units */
void cMan_BuildMan(Self391020* self, int flag);
#endif /* merge_units */
void cMan_BuildMan(void*, int); /* merge_units */
#define cMan_BuildMan(a0, a1) (cMan_BuildMan((void *)(a0), (a1))) /* merge_units */

}

extern "C" void cMan_AddDisguise(Self391020* self)
{
    int i;
    int j;
    int n;

    cMan_MergeSKLs(self);
    SKL_RemoveBlanks(&self->app);
    self->x23C0 = SKL_CountAttribs(&self->app);
    SKL_LoadSKLParts(&self->app, 1, self->x20);
    for (i = 0; self->app.pairs[i].b; i++) {
        Monster_FindAddTexture(g_AgentPartCache, self->app.pairs[i].b, D_005711B0, &self->x22C0[i], &self->x2300[i]);
    }
    self->x22C0[i] = 0;
    n = SKL_CountAttribs(self->x2C14);
    for (j = 0; j <= n; j++) {
        int s = FindTex__7MonsterF1(g_AgentPartCache, self->x2C14->pairs[j].b);
        if (s != -1) {
            Monster_FreeTexture(g_AgentPartCache, s);
        }
    }
    for (i = 0; i < n; i++) {
        int s = FindPart__7MonsterF1(g_AgentPartCache, self->x2C14->pairs[i].a);
        if (s != -1) {
            Monster_FreePart(g_AgentPartCache, s);
        }
    }
    {
        App391020* p = self->x2C14;
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_004BC310, 0x2DA);
    }
    self->x2C14 = 0;
    cMan_SortParts(self);
    cMan_BuildMan(self, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391020(void) {}
#undef cMan_BuildMan /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00391020 */

/* merge_units: begin func_00391210 */
#pragma push /* merge_units */
#pragma cplusplus on

struct App391210 {
    __int128 q[0x44];
};

struct Self391210 {
    char pad[0x40];
    App391210 app;
    char padX[0x2C14 - 0x40 - sizeof(App391210)];
    App391210* x2C14;
};

extern "C" {
#if 0 /* merge_units */
void cMan_GetTextureIDs(Self391210* self);
#endif /* merge_units */
void cMan_GetTextureIDs(void*); /* merge_units */
#define cMan_GetTextureIDs(a0) (cMan_GetTextureIDs((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMan_BuildMan(Self391210* self, int flag);
#endif /* merge_units */
#define cMan_BuildMan(a0, a1) (cMan_BuildMan((void *)(a0), (a1))) /* merge_units */



}

/* 16-byte block copy loop (lq/sq). */
static inline void QMove_391210(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

extern "C" void cMan_RemoveCostume(Self391210* self)
{
    App391210* s = self->x2C14;
    if (s) {
        QMove_391210(&self->app, s, 0x44);
        {
            App391210* p = self->x2C14;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BC310, 0x2A8);
        }
        self->x2C14 = 0;
        cMan_GetTextureIDs(self);
        cMan_BuildMan(self, 1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391210(void) {}
#undef cMan_GetTextureIDs /* merge_units */
#undef cMan_BuildMan /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00391210 */

/* merge_units: begin func_00391300 */
#pragma push /* merge_units */
extern int WoundEffectTable[5];
extern unsigned char D_0053B340;
extern unsigned char D_0053B341;
extern unsigned char D_0053B348;
extern unsigned char D_0053B349;
extern int FindFace(char* name, int which);
void cMan_ManInit(void)
{
    int i;
    if (WoundEffectTable[0] == -1) {
        WoundEffectTable[0] = 0;
    }
    for (i = 1; i < 5; i++) {
        if (WoundEffectTable[i] == -1) {
            WoundEffectTable[i] = WoundEffectTable[0];
        }
    }
    D_0053B340 = FindFace("EMO_SHOT", 0);
    D_0053B341 = FindFace("EMO_SHOT", 1);
    D_0053B348 = FindFace("BLINKBOTH", 0);
    D_0053B349 = FindFace("BLINKBOTH", 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00391300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00391300 */

/* merge_units: begin func_003913D0 */
#pragma push /* merge_units */
/* cMan_SetBoneSet */
typedef struct { char name[16]; } Pt2_PresetName;
typedef struct { unsigned int count; Pt2_PresetName e[24]; } Pt2_PresetTbl;
typedef struct { float x, y, z, w; } Pt2_Sc;
typedef struct { char pad0[4]; char bones[0x10]; unsigned char hasMorph; char pad15[3]; char morph[4]; } Pt2_Skl;
typedef struct { char pad0[0x40]; char name[0x2BC4]; Pt2_Skl* skel; char pad2C08[8]; unsigned char preset; } Pt2_App;
extern Pt2_PresetTbl D_00571300;
extern Pt2_Sc* D_00571484[];
extern float* cArray_cBoneScale_opIndex(void*, int);
extern void* cArray_cBone_opIndex_int_2(void*, int);
extern void cBone_SetScaleX(void*, float);
extern void cBone_SetScaleY(void*, float);
extern void cBone_SetScaleZ(void*, float);

int cMan_SetBoneSet(Pt2_App* a, int preset) {
    Pt2_Sc* s;
    int i;
    if (preset < 0) {
        for (preset = 0; (unsigned int)preset < D_00571300.count; preset++) {
            if (!strcmp(a->name, D_00571300.e[preset].name)) break;
        }
        if ((unsigned int)preset >= D_00571300.count) {
            strcmp(a->name, "BONENOSCALE");
            return 0;
        }
    }
    if ((unsigned int)preset >= D_00571300.count) return 0;
    memcpy(a->name, D_00571300.e[preset].name, 0xF);
    s = D_00571484[preset];
    for (i = 0; i < 0x15; i++, s++) {
        Pt2_Skl* k;
        float v;
        k = a->skel; v = s->x;
        cArray_cBoneScale_opIndex(k->bones, i)[0] = v;
        if (k->hasMorph) cBone_SetScaleX(cArray_cBone_opIndex_int_2(k->morph, i), v);
        k = a->skel; v = s->y;
        cArray_cBoneScale_opIndex(k->bones, i)[1] = v;
        if (k->hasMorph) cBone_SetScaleY(cArray_cBone_opIndex_int_2(k->morph, i), v);
        k = a->skel; v = s->z;
        cArray_cBoneScale_opIndex(k->bones, i)[2] = v;
        if (k->hasMorph) cBone_SetScaleZ(cArray_cBone_opIndex_int_2(k->morph, i), v);
    }
    a->preset = preset;
    return preset;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003913D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003913D0 */

/* merge_units: begin func_003915B0 */
#pragma push /* merge_units */
typedef struct {
    short time;
    unsigned short value;
} lipSyncData;

typedef struct {
    short count;
    unsigned short timeIndex;
    short time1;
    short time2;
    float value1;
    float value2;
} lipSyncKeys;

typedef struct {
    char pad0[0x23F0];
    float faceBlends[8];
    char pad2410[0x2BC1 - 0x2410];
    unsigned char faceBlendCount;
    unsigned char faceBlendNumbers[8];
    char pad2BCA[0x2C18 - 0x2BCA];
    lipSyncKeys speechAnim[21];
    lipSyncData** speechHeader;
    int speechTime;
} cMan;

extern int g_TimerAccum;
extern long g_TickCounter64;

static inline int DivTime(long n)
{
    int bit = 1 << 30;
    int q = 0;
    long d = 100;
    int i;
    d <<= 30;
    for (i = 0; i < 31; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}

static inline float Lerp(float a, float b, float t) { return a + (b - a) * t; }
void cMan_LipSyncUpdate(cMan* self)
{
    int stillPlaying;
    int time1;
    int time2;
    int timeIndex;
    int faceCount;
    int time;
    int j;
    lipSyncData* data;

    stillPlaying = 0;
    faceCount = self->faceBlendCount;
    time = DivTime(g_TickCounter64 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f));time -= self->speechTime;
    for (j = 0; j < 21; j++) {
        time2 = self->speechAnim[j].time2;
        while (time2 < time) {
            timeIndex = self->speechAnim[j].timeIndex + 1;
            if (timeIndex >= self->speechAnim[j].count) break;
            self->speechAnim[j].timeIndex = timeIndex;
            data = self->speechHeader[j];
            self->speechAnim[j].time1 = self->speechAnim[j].time2;
            data = (lipSyncData*)((char*)data + (timeIndex << 2));
            self->speechAnim[j].time2 = data->time;
            time2 = self->speechAnim[j].time2;
            self->speechAnim[j].value1 = self->speechAnim[j].value2;
            self->speechAnim[j].value2 = 3.0517578125e-05f * data->value;
            if (self->speechAnim[j].value1 == 0.0f && self->speechAnim[j].value2 == 0.0f) {
                self->speechAnim[j].time1 = self->speechAnim[j].time2;
            }
        }
        time1 = self->speechAnim[j].time1;
        if (time <= time2) {
            stillPlaying = 1;
            if (time1 < time && faceCount < 8) {
                time2 -= time1;
                self->faceBlends[faceCount] = Lerp(self->speechAnim[j].value1, self->speechAnim[j].value2, (float)(time - time1) / (float)time2);
                self->faceBlendNumbers[faceCount] = j;
                if (j >= 19) self->faceBlendNumbers[faceCount] = j + 4;
                faceCount++;
            }
        }
    }
    self->faceBlendCount = faceCount;
    if (!stillPlaying) self->speechHeader = 0;
}
static inline void merge_flush_func_003915B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003915B0 */

/* merge_units: begin func_00391810 */
#pragma push /* merge_units */
typedef struct {
    short a;
    unsigned short ua;
    short b;
    unsigned short ub;
} LpdKey;

typedef struct {
    short count;
    short on;
    short a;
    short b;
    float fa;
    float fb;
} LpdTrack;

typedef struct {
    char pad0[0x2C18];
    LpdTrack trk[21];
    int** tbl;
    int time;
} Lpd;

void cMan_LipSyncPlay(Lpd* s, int* data)
{
    int* p;
    int i;
    s->tbl = (int**)data;
    p = (int*)s->tbl;
    if (p[0] < 0x7D00) {
        int* base;
        int off;
        int j;
        off = 0;
        base = p;
        for (j = 0; j <= 21; j++) {
            off += *p++;
            s->tbl[j] = base + off;
        }
    }
    for (i = 0; i < 21; i++) {
        s->trk[i].on = 1;
        s->trk[i].count = s->tbl[i + 1] - s->tbl[i];
        if (s->trk[i].count > 0) {
            LpdKey* k = (LpdKey*)s->tbl[i];
            s->trk[i].a = k->a;
            s->trk[i].b = k->b;
            s->trk[i].fa = 3.0517578125e-05f * k->ua;
            s->trk[i].fb = 3.0517578125e-05f * k->ub;
            if (s->trk[i].fa == 0.0f && s->trk[i].fb == 0.0f) {
                s->trk[i].a = s->trk[i].b;
            }
        } else {
            s->trk[i].a = 0;
            s->trk[i].b = 0;
            s->trk[i].fa = 0.0f;
            s->trk[i].fb = 0.0f;
        }
    }
    s->time = DivTime(g_TickCounter64 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f));
}
static inline void merge_flush_func_00391810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00391810 */

/* merge_units: begin func_00391B30 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
/* Unit 0x391B30 (built with CodeWarrior 3.0 build 50, like cMan_LipSyncPlay): cMan_LipSyncLoad registers the
 * lip-sync tracks of an archive, cMan_EyeTracking drives the look-at face channels.
 * VU0 macro-mode ops, lq/sq quad copies and the VU0 flag test are inline asm (no C spelling). */

typedef struct { char pad[4]; int count; } HogHdr_391B30;
typedef struct { char pad[0x148]; HogHdr_391B30* hdr; } Arc_391B30;
extern "C" {
typedef struct { int* data[16]; } LpdTab_391B30;
extern char D_004BC420[];
extern char D_0053B370[][16];
extern LpdTab_391B30 D_0053B470;
extern unsigned char D_0053B4B0;
extern int D_0053B4B8;
char* cHogFile_GetBlockName(Arc_391B30* a, int i);
int* cHogFile_GetBlock_int(Arc_391B30* a, int i);
char* strrchr(const char* s, int c);
#if 0 /* merge_units */
int strcmp(const char* a, const char* b);
#endif /* merge_units */
#define strcmp(a0, a1) (strcmp((const void *)(a0), (const void *)(a1))) /* merge_units */

void strCpyPad(char* dst, int n, const char* src);
int snd_BankLoad(const char* name, int flags);
void cMan_LipSyncLoad(Arc_391B30* a, const char* bank);
}

/* Registers every lip-sync track of the archive (members with the track extension): copies
 * the name, relocates the member's 15 offset words in place, then loads the sound bank. */
extern "C" void cMan_LipSyncLoad(Arc_391B30* a, const char* bank)
{
    int n; int* p; int i; int off; char* name;
    n = a->hdr->count;
    for (i = 0; i < n; i++) {
        char* ext;
        name = cHogFile_GetBlockName(a, i);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        off = 0;
        if (strcmp(ext, D_004BC420) == 0) {
            int* base;
            int k;
            strCpyPad(D_0053B370[D_0053B4B0], 15, name);
            D_0053B470.data[D_0053B4B0] = cHogFile_GetBlock_int(a, i);
            p = cHogFile_GetBlock_int(a, i);
            base = cHogFile_GetBlock_int(a, i);
            for (k = 0; k <= 21; k++) {
                off += *p++;
                D_0053B470.data[D_0053B4B0][k] = (int)(base + off);
            }
            D_0053B4B0++;
        }
    }
    D_0053B4B8 = snd_BankLoad(bank, 0);
}

/* cMan_EyeTracking: turns the gaze target (the looked-at object's position, else the stored
 * default) into the head frame, flattens it to the upper half, scales it and writes the
 * horizontal / vertical look amounts into the face blend channels. */
struct V {
    float x, y, z, w;
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
class GazeObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual V GetPosition();
    int pad4[2];
    int serial;
};
struct GazeRig { char pad0[0x14]; unsigned char flag14; char pad15[3]; char nodes[0x10]; void* xform; };
struct GazeActor {
    char pad0[0x23F0];
    float weight[9];
    char pad2414[0x2BC1 - 0x2414];
    unsigned char nchan;
    unsigned char chan[9];
    char pad2BCB[0x2C04 - 0x2BCB];
    GazeRig* rig;
    char pad2C08[0x2D70 - 0x2C08];
    GazeObj* target;
    int targetId;
    char pad2D78[8];
    V gaze;
};
extern "C" {
void* cArray_cBone_opIndex_int(void* v, int i);
void* cBone_Xform(void* n);
M* cXform_GetMatrix(void* x);
void cMatrix_GetTransformed(M* out, M* in, M* m);
void cMatrix_ctor_cMatrixR(M* d, M* s);
void cMatrix_Copy_InvertRotTrans(M* out, M* in);
void cVector_Transform_cMatrixR(V* v, M* m);
void cMan_EyeTracking(GazeActor* a);
}
static inline void ToLocal(V* d, M* f) { M inv; cMatrix_Copy_InvertRotTrans(&inv, f); cVector_Transform_cMatrixR(d, &inv); }
/* weak-handle check (idiom of src/main/human/cHuman_ReceiveDamage.c) */
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
static inline bool Valid(GazeActor* a) { bool ok = true; if (!IsNullNV(a->target) && !SameNV(a->target->serial, a->targetId)) ok = false; return ok; }
static inline GazeObj* GetTarget(GazeActor* a) { return Valid(a) ? a->target : 0; }
static inline void Normalize3(V* v)
{
    asm {
        lqc2 vf1, 0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(v)
    }
}
static inline int IsZero3(V* v)
{
    int k, f;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Scale(V* v, float s) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(v), "f"(s) : "memory"); }

/* the first normalize goes through this wrapper: its dead xx is retail's duplicated addiu */
static inline void NormalizeW(V* v) { void* xx = v; /* dead on purpose: retail keeps this addiu */ Normalize3(v); }
extern "C" void cMan_EyeTracking(GazeActor* a)
{
    V dir;
    M frame;
    GazeRig* r = a->rig;
    int n; int idx; int j;
    if (r->flag14) {
        M* t = cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(r->nodes, 14)));
        cMatrix_GetTransformed(&frame, t, cXform_GetMatrix(r->xform));
    } else {
        cMatrix_ctor_cMatrixR(&frame, cXform_GetMatrix(r->xform));
    }
    if (GetTarget(a)) {
        dir = GetTarget(a)->GetPosition();
    } else {
        dir = a->gaze;
    }
    ToLocal(&dir, &frame);
    NormalizeW(&dir);
    if (dir.y < 0.0f) {
        dir.y = 0.0f;
        if (!IsZero3(&dir)) Normalize3(&dir);
    }
    Scale(&dir, 1.5f);
    n = a->nchan;
    {
        float v = dir.x;
        idx = -1;
        if (v != 0.0f) {
            for (j = 0; j < n; j++) {
                unsigned char c = a->chan[j];
                if (c == 22 || c == 21) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                idx = n;
                n++;
                if (n >= 9) return;
            }
            if (v > 0.0f) {
                if (v > 1.0f) v = 1.0f;
                a->weight[idx] = v;
                a->chan[idx] = 22;
            }
            if (v < 0.0f) {
                v = -v;
                if (v > 1.0f) v = 1.0f;
                a->weight[idx] = v;
                a->chan[idx] = 21;
            }
            a->nchan = n;
        }
    }
    {
        float v = dir.z;
        idx = -1;
        if (v != 0.0f) {
            for (j = 0; j < n; j++) {
                unsigned char c = a->chan[j];
                if (c == 19 || c == 20) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                idx = n;
                n++;
                if (n >= 9) return;
            }
            if (v > 0.0f) {
                if (v > 1.0f) v = 1.0f;
                a->weight[idx] = v;
                a->chan[idx] = 19;
            }
            if (v < 0.0f) {
                v = -v;
                if (v > 1.0f) v = 1.0f;
                a->weight[idx] = v;
                a->chan[idx] = 20;
            }
            a->nchan = n;
        }
    }
}
#undef strcmp /* merge_units */
static inline void merge_flush_func_00391B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00391B30 */

/* merge_units: begin func_00392260 */
#pragma push /* merge_units */
#pragma cplusplus on

struct App92260 {
    __int128 q[0x44];
};

struct Self92260 {
    char pad[0x40];
    App92260 app;               /* 0x40 */
    char pad480[0x2C14 - 0x40 - sizeof(App92260)];
    App92260* saved;            /* 0x2C14 */
};

extern "C" {
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
#endif /* merge_units */

#if 0 /* merge_units */
void cMan_GetTextureIDs(Self92260* self);
#endif /* merge_units */
#define cMan_GetTextureIDs(a0) (cMan_GetTextureIDs((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMan_BuildMan(Self92260* self, int flag);
#endif /* merge_units */
#define cMan_BuildMan(a0, a1) (cMan_BuildMan((void *)(a0), (a1))) /* merge_units */

void cMan_FreeMan(Self92260* self);
void operator_delete(void* p);
}

/* 16-byte block copy loop (lq/sq), as in cMan_RemoveCostume. */
static inline void QMove_392260(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

extern "C" Self92260* cMan_dtor(Self92260* self, short flag)
{
    if (self) {
        App92260* s = self->saved;
        if (s) {
            QMove_392260(&self->app, s, 0x44);
            {
                App92260* p = self->saved;
                AllocGuard g;
                cMemMan_Deallocate(0, p, D_004BC310, 0x11F);
            }
            self->saved = 0;
            cMan_GetTextureIDs(self);
            cMan_BuildMan(self, 1);
        }
        cMan_FreeMan(self);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
#undef cMan_GetTextureIDs /* merge_units */
#undef cMan_BuildMan /* merge_units */
static inline void merge_flush_func_00392260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392260 */
