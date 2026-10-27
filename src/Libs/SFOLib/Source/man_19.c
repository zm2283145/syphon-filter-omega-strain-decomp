/*
 * Libs/SFOLib/Source/man: 3 files, 00391810-00392260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00391810 */
#pragma push /* merge_units */
#include "types.h"

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
int strcmp(const char* a, const char* b);
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
static inline void merge_flush_func_00391B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00391B30 */

/* merge_units: begin func_00392260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

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
extern char D_004BC310[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cMan_GetTextureIDs(Self92260* self);
void cMan_BuildMan(Self92260* self, int flag);
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
static inline void merge_flush_func_00392260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00392260 */
