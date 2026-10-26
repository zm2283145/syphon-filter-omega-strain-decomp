#pragma cplusplus on
#pragma always_inline on
#include "types.h"
/* Unit 0x391B30 (built with CodeWarrior 3.0 build 50, like Lpd_Init): func_00391B30 registers the
 * lip-sync tracks of an archive, Actor_UpdateGaze drives the look-at face channels.
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
char* Archive_GetMemberName(Arc_391B30* a, int i);
int* Hog_GetMemberInPlace(Arc_391B30* a, int i);
char* strrchr(const char* s, int c);
int strcmp(const char* a, const char* b);
void Appearance_RegistryKey(char* dst, int n, const char* src);
int snd_BankLoad(const char* name, int flags);
void func_00391B30(Arc_391B30* a, const char* bank);
}

/* Registers every lip-sync track of the archive (members with the track extension): copies
 * the name, relocates the member's 15 offset words in place, then loads the sound bank. */
extern "C" void func_00391B30(Arc_391B30* a, const char* bank)
{
    int n; int* p; int i; int off; char* name;
    n = a->hdr->count;
    for (i = 0; i < n; i++) {
        char* ext;
        name = Archive_GetMemberName(a, i);
        ext = strrchr(name, '.');
        if (!ext) ext = name;
        off = 0;
        if (strcmp(ext, D_004BC420) == 0) {
            int* base;
            int k;
            Appearance_RegistryKey(D_0053B370[D_0053B4B0], 15, name);
            D_0053B470.data[D_0053B4B0] = Hog_GetMemberInPlace(a, i);
            p = Hog_GetMemberInPlace(a, i);
            base = Hog_GetMemberInPlace(a, i);
            for (k = 0; k <= 21; k++) {
                off += *p++;
                D_0053B470.data[D_0053B4B0][k] = (int)(base + off);
            }
            D_0053B4B0++;
        }
    }
    D_0053B4B8 = snd_BankLoad(bank, 0);
}

/* Actor_UpdateGaze: turns the gaze target (the looked-at object's position, else the stored
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
void* Skeleton_NodeAt(void* v, int i);
void* func_0019F420(void* n);
M* Transform_GetUpdated(void* x);
void Actor_ShotFrameNodeWorld(M* out, M* in, M* m);
void Mtx_Copy(M* d, M* s);
void Mtx_InvertRigid_13ECA0(M* out, M* in);
void Mtx_Multiply4(V* v, M* m);
void Actor_UpdateGaze(GazeActor* a);
}
static inline void ToLocal(V* d, M* f) { M inv; Mtx_InvertRigid_13ECA0(&inv, f); Mtx_Multiply4(d, &inv); }
/* weak-handle check (idiom of src/main/human/Actor_HandleCombatEvent.c) */
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
extern "C" void Actor_UpdateGaze(GazeActor* a)
{
    V dir;
    M frame;
    GazeRig* r = a->rig;
    int n; int idx; int j;
    if (r->flag14) {
        M* t = Transform_GetUpdated(func_0019F420(Skeleton_NodeAt(r->nodes, 14)));
        Actor_ShotFrameNodeWorld(&frame, t, Transform_GetUpdated(r->xform));
    } else {
        Mtx_Copy(&frame, Transform_GetUpdated(r->xform));
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
