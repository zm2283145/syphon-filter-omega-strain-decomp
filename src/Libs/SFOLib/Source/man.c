/*
 * Libs/SFOLib/Source/man: 3 files, 00383660-003836B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin texman_383660 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

List* std_list_deleter_int_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_texman_383660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end texman_383660 */

/* merge_units: begin func_00383680 */
#pragma push /* merge_units */
typedef struct { unsigned char pad[0x2D96]; short v; } Obj_383680;
void ActorModel_GlowDown(Obj_383680* o)
{
    o->v -= 2;
    if (o->v < 0) o->v = 0;
}
static inline void merge_flush_func_00383680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00383680 */

/* merge_units: begin func_003836B0 */
#pragma push /* merge_units */
/* 003836B0 gunList::GunRender(unsigned int dcode, const cMatrix& gunLocation, int hud) (man.cc).
 * Rebuilt from the early prototype (DWARF locals/types, .line table, disassembly at 0x377010) on the
 * cMan_ManRender / gunList_LoadGunHog helper set. Locals follow the prototype declaration order (it fixes
 * the stack slots); the copy helpers differ per site only in their dead `this`/source pointer copies,
 * which reproduce retail's dead addiu instructions. Inline asm is used only for the VU0 macro-mode and
 * 128-bit lq/sq operations, which C cannot express. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
typedef unsigned long long U64;
typedef unsigned int u32;
typedef __int128 u_long128;

/* 128-bit lq/sq copies (single, 4-quadword, n-quadword loop) and VU0 macro-mode matrix/vector math:
 * inline asm because C has no 128-bit move or VU0 operations. */
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void QCopy(void* d, const void* s, int n) {
    int nn = n; __int128 t; const void* ss = s; void* dd = d;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu dd, dd, 0x10
        addi nn, nn, -1
        addiu ss, ss, 0x10
        bgtz nn, lp
        sq t, -0x10(dd)
        .set reorder
    }
}
static inline void Mul44(void* d, const void* a, const void* b)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1); lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}
struct M;
static inline void Mul3(void* d, const void* a, const M& bb)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1)\n"
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddz.xyzw $vf12, $vf6, $vf8z\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddz.xyzw $vf13, $vf6, $vf9z\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddz.xyzw $vf14, $vf6, $vf10z\n"
        "vmove.xyzw $vf15, $vf7\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(&bb), "r"(a) : "memory");
}

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; RQ(this, &o); }
    V(const V& o, int) { void* xx = this; V* d = this; const V* s = &o; RQ(d, s); }
    V& operator=(const V& o) { void* xx = this; RQ(this, &o); return *this; }
    V operator+(const V& o) const;
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

/* VU0 vector add (no C equivalent); parameter order (a, p, b) reproduces retail's register choice */
static inline void VAdd(const V* a, V* p, const V* b) { asm { lqc2 vf1, 0x0(a)
 lqc2 vf2, 0x0(b)
 vadd.xyzw vf1, vf1, vf2
 sqc2 vf1, 0x0(p) } }
inline V V::operator+(const V& o) const { V r; VAdd(this, &r, &o); return r; }
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; RQ4(this, &o); }
    M(const M* p);
    M(float a, float b, float c, float d, float e, float f, float g, float h, float i);
    M& operator=(const M& o) { const void* yy = &o; RQ4(this, &o); return *this; }
    void As(const M& o) { const void* yy = &o; void* xx = this; RQ4(this, &o); }
    void Set(const M& o) { void* xx = this; const M* s = &o; RQ4(this, s); }
    void Set2(const M& o) { void* xx = this; RQ4(this, &o); }
    V& R(int i) { return *(V*)m[i]; }
    void SetT(const V& v) { void* xx = &R(3); RQ(&R(3), &v); }
    void Identity() { void* xx = this; __int128 t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $0; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $0; sq %0, 0x0(%1)" : "=&r"(t) : "r"(this) : "memory"); }
    M operator*(const M& b) const { M r; Mul44(&r, this, &b); return r; } /* return copy-initialises the caller's object */
    void Rotate(V* v) const { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(v), "r"(this), "r"(v) : "memory"); }
    void Translate(const V& v) { void* xx = this; __asm__ volatile("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" : : "r"(this), "r"(&v) : "memory"); }
    bool IsIdentity() const {
        return m[0][0] == 1.0f && m[0][1] == 0.0f && m[0][2] == 0.0f && m[0][3] == 0.0f &&
               m[1][0] == 0.0f && m[1][1] == 1.0f && m[1][2] == 0.0f && m[1][3] == 0.0f &&
               m[2][0] == 0.0f && m[2][1] == 0.0f && m[2][2] == 1.0f && m[2][3] == 0.0f &&
               m[3][0] == 0.0f && m[3][1] == 0.0f && m[3][2] == 0.0f && m[3][3] == 1.0f;
    }
} __attribute__((aligned(16)));

struct NxM {
    float m[3][4];
    NxM& operator=(const M& s) { for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) m[i][j] = s.m[i][j]; return *this; }
    NxM& operator=(const NxM& s) { for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) m[i][j] = s.m[i][j]; return *this; }
};
struct BoneRM {
    M bone;
    NxM lights;
    BoneRM& operator=(const BoneRM& o) { void* xx = this; bone = o.bone; lights = o.lights; return *this; }
};
struct gunRenderSPAD {
    U64 gunTex0[8];
    BoneRM gunBoneData[12];
};
struct hexVect { u32 x, y, z, w; };
struct flagVect { u32 x; float y; u32 z, w; };
struct manVect { float x, y, z, w; };
struct manStaticData {
    U64 dmaCNT;
    U64 vifUnpack;
    U64 partflagsUnused;
    u32 partflagsMagic;
    float partflagsPower;
    U64 pflags5unused;
    u32 pflags5magic;
    float pflags5power;
    U64 pflags4camo;
    u32 pflags4magic;
    float pflags4power;
    manVect pflags3;
    manVect pflags2;
    hexVect pflags;
    flagVect gflags;
    M colors;
    V ambiant;
    hexVect primAlpha;
    hexVect primAnti;
    hexVect primTex0;
    hexVect primTex2;
    BoneRM mats[21];
    hexVect vifStart;
};

struct cQuaternion { float x, y, z, w; } __attribute__((aligned(16)));
struct boneOffset { float x, y, z; int parent; };
struct cVector_NoInitHACK { float x, y, z, w; };
struct gunBones {
    cQuaternion orient;
    union U { boneOffset the; cVector_NoInitHACK offset; } u;
};
struct manRefs { unsigned char qwc; unsigned char vertCount; };
struct Parts {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
};
struct manAttribs { u_long128 partName; u_long128 texName; };
struct cBox { V min; V max; };
struct gunList {
    char gunName[32];
    manAttribs gunAttribsTable[8];
    gunBones gunBulletOffset;
    gunBones gunBonesOffsets[12];
    Parts gunParts[2][8];
    short gunTexID[8];
    short gunTexID2[8];
    cBox gunBBox;
    char* gunHog;
    u_long128* casingModelPart;
    unsigned short casingModelqwc;
    short gunWDBIndex;
    unsigned char gunPartCount;
    unsigned char gunHoldType;
    unsigned char gunHoldTypeHand2;
    unsigned char gunAnimType;
    signed char gunHolsterPart;
    signed char gunFlarePart;
    signed char gunLightPart;
    signed char gunStockPartOn;
    signed char gunStockPartOff;
    unsigned char gunGlow;
    signed char gunTransparency;
    signed char gunLoading;
    unsigned char gunMalloc;
    unsigned char gunIsBullet;
    int gunRefCount;
};
struct cTexture { char name[0x50]; U64 tex01; };
struct cTexMan {
    int txtrBuffAddr;
    int txtrBuffEndAddr;
    cTexture** textures;
    int maxTextures;
    int numTextures;
    unsigned char txtrsModifiable;
    unsigned char txtrsNoUploads;
    unsigned char batchTerm;
    unsigned int numBatchTIDs;
    short batchTIDs[512];
    void AddTID(int id) {
        unsigned n = numBatchTIDs;
        if (n < 512) {
            if (n == 0 || batchTIDs[n - 1] != id) batchTIDs[numBatchTIDs++] = id;
        }
    }
};
struct Ctx {
    char pad0[0xA80];
    M stk[32];
};
extern "C" {
extern Ctx g_Video;
extern int D_00538C64;
extern char D_00538C68;
extern U64 D_004BC1B0;
extern U64 D_005392D8;
extern int D_005382C8;
extern int D_005382CC;
extern int D_005382D0;
extern int D_005382D4;
extern float D_00538380;
extern float D_00538370;
extern int D_005381C4;
extern int D_00538164;
extern int D_00538170;
extern int D_004932C0[];
extern int D_004932E0[];
extern char D_00537F80[];
extern cTexMan* g_TextureMgr;
extern char D_0047DB00[];
extern u32 D_004933F0;
extern float D_004933F8;
extern M D_00537E10;
extern V D_00537D80;
extern M D_0055DF40;
extern M D_00537DD0;
extern M D_0055DF80;
extern M D_0055DF00;
extern u32 g_VideoFrameCounter;
int XLib_SetModelContext(Ctx*, const M*, u32, int);
void cDmaMan_InsertChain(void*, int, int, int);
void cTexMan_EndBatch(cTexMan*);
void* cDmaMan_BeginChain_eDmaChannel_int(void*, int, int);
void cMan_GetLocal2ScreenMatrix(M*, M*);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_Transpose(M* m);
void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
float SIN(float);
float COS(float);
void cDmaMan_EndChain_int_ulongP(void*, int, void*);
void XLib_Restore(Ctx*);
}
inline M::M(float a, float b, float c, float d, float e, float f, float g, float h, float i) { cMatrix_Set_ColumnMajorForm(this, a, b, c, d, e, f, g, h, i); }
inline M::M(const M* p) { cMatrix_ctor_cMatrixR(this, p); }
static inline M Transposed(const M& m) { M a; return M(cMatrix_Transpose(cMatrix_ctor_cMatrixR(&a, &m))); }
static inline void MulTo34(NxM& d, const M& a, const M& b) { M r; const M* pa = &a; Mul44(&r, pa, &b); d = r; }
#define TOP (&g_Video.stk[D_00538C64])
static inline float FogF(float n, float y) { float b = D_00538370; return b + n / y; }
static inline void SetFog(int v) { D_005382C8 = 1; D_005382CC = 5; D_005382D0 = v; D_005382D4 = 3; }
static inline void SetTex(int v) {
    if (v != D_00538170) {
        cDmaMan_InsertChain(D_00537F80, 1, D_004932C0[v], D_004932E0[v]);
        D_00538170 = v;
    }
    D_005381C4++;
}
static inline void Push() { g_Video.stk[D_00538C64 + 1] = g_Video.stk[D_00538C64]; D_00538C64++; }
static inline void MulBy(M* d, const M* b) { Mul44(d, d, b); D_00538C68 = 1; }
static inline void Pop() { D_00538C64--; D_00538C68 = 1; }

extern "C" void gunList_GunRender(gunList* self, u32 dcode, const M& gunLocation, int hud)
{
    gunRenderSPAD* SPAD = (gunRenderSPAD*)0x70000000;
    int transparency = 128;
    u32 renderContext;
    int show;
    int theLOD;
    int fog;

    if (self->gunLoading) return;
    Push();
    MulBy(TOP, &gunLocation);
    D_005392D8 = D_004BC1B0;
    if (self->gunTransparency >= 0) {
        SetFog(self->gunTransparency);
        transparency = self->gunTransparency + 1;
    } else {
        SetFog(transparency);
    }
    renderContext = XLib_SetModelContext(&g_Video, &gunLocation, dcode, 0x480000);
    show = 1;
    if (!hud) {
        if (renderContext & 0x80000000) {
            Pop();
            return;
        }
        if (renderContext & 0x40000000) show = 2;
    }
    theLOD = 0;
    fog = 255;
    if (!hud) {
        M& local2CameraMatrix = *TOP;
        V gunPos(local2CameraMatrix.R(3), 0);
        float distance = gunPos.Length();
        theLOD = 0;
        theLOD = distance / 22.0f;
        if (theLOD > 1) theLOD = 1;
        if (renderContext & 0x80) {
            float fogging = FogF(D_00538380, gunPos.y);
            if (fogging > 255.0f) fogging = 255.0f;
            if (fogging < 0.0f) fogging = 0.0f;
            fog = (int)fogging;
            if (fogging == 0.0f) {
                Pop();
                return;
            }
        }
    }
    D_005381C4 = 0;
    SetTex(D_00538164);
    {
        cTexMan& texMan = *g_TextureMgr;
        short* texPtr;
        texMan.numBatchTIDs = 0;
        texMan.batchTerm = 0;
        if (!theLOD) {
            texPtr = self->gunTexID;
            for (int j = self->gunPartCount; j > 0; j--) texMan.AddTID(*texPtr++);
            cTexMan_EndBatch(&texMan);
            for (int j = 0; j < self->gunPartCount; j++) SPAD->gunTex0[j] = texMan.textures[self->gunTexID[j]]->tex01;
        } else {
            texPtr = self->gunTexID2;
            for (int j = self->gunPartCount; j > 0; j--) texMan.AddTID(*texPtr++);
            cTexMan_EndBatch(&texMan);
            for (int j = 0; j < self->gunPartCount; j++) SPAD->gunTex0[j] = texMan.textures[self->gunTexID2[j]]->tex01;
        }
    }
    int kMaxGunDmaSize = self->gunPartCount * 3 + 245;
    U64* dmaVif = (U64*)cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, kMaxGunDmaSize);
    *dmaVif++ = ((U64)(u32)D_0047DB00 << 32) + 0x3000000A;
    *dmaVif++ = 0;
    manStaticData& header = *(manStaticData*)dmaVif;
    dmaVif += 0xA50 / 8;
    header.dmaCNT = 0x100000A4;
    header.vifUnpack = ((U64)0x6CA30075 << 32) | 0x01000404;
    header.partflagsUnused = 0;
    header.partflagsMagic = D_004933F0;
    header.partflagsPower = D_004933F8;
    header.pflags5unused = 0;
    header.pflags5magic = D_004933F0;
    header.pflags5power = D_004933F8;
    header.gflags.x = transparency + 0x47000000;
    header.gflags.y = 0;
    header.gflags.z = show - 1;
    header.gflags.w = fog << 4;
    if (renderContext & 0x80) {
        header.primAlpha.x = 0x8000;
        header.primAlpha.y = 0x303E4000;
        header.primAlpha.z = 0x412;
        header.primAlpha.w = 0x303E4000;
        header.primAnti.x = 0x8000;
        header.primAnti.y = 0x307E4000;
        header.primAnti.z = 0x412;
        header.primAnti.w = 0x303E4000;
    } else {
        header.primAlpha.x = 0x8000;
        header.primAlpha.y = 0x302E4000;
        header.primAlpha.z = 0x412;
        header.primAlpha.w = 0x302E4000;
        header.primAnti.x = 0x8000;
        header.primAnti.y = 0x306E4000;
        header.primAnti.z = 0x412;
        header.primAnti.w = 0x302E4000;
    }
    header.primTex0.x = 1;
    header.primTex0.y = 0x10000000;
    header.primTex0.z = 6;
    header.primTex0.w = 0;
    header.primTex2.x = 1;
    header.primTex2.y = 0x10000000;
    header.primTex2.z = 6;
    header.primTex2.w = 0;
    if (!hud) {
        header.colors.Set(D_00537E10);
        V ambiant = D_00537D80 + V(8388608.0f, 8388608.0f, 8388608.0f, 0.0f);
        header.ambiant = ambiant;
    } else {
        header.colors.Set2(D_0055DF40);
        header.ambiant = V(8388608.0f, 8388608.0f, 8388608.0f, 128.0f);
    }
    header.vifStart.x = 0x15000000;
    header.vifStart.y = 0;
    header.vifStart.z = 0;
    header.vifStart.w = 0;
    M local2ScreenMatrix;
    {
        M& local2CameraMatrix = *TOP;
        cMan_GetLocal2ScreenMatrix(&local2ScreenMatrix, &local2CameraMatrix);
    }
    M rhandMat;
    rhandMat.Identity();
    SPAD->gunBoneData[0].bone.Set2(rhandMat);
    M lights;
    if (!hud) {
        MulTo34(SPAD->gunBoneData[0].lights, D_00537DD0, rhandMat);
    } else if (gunLocation.IsIdentity()) {
        SPAD->gunBoneData[0].lights = D_0055DF80;
    } else {
        lights.Set2(D_0055DF00);
        lights.SetT(V(0.0f, 0.0f, 0.0f, 0.0f));
        lights.As(Transposed(lights));
        M lights2 = gunLocation * lights;
        lights2.As(Transposed(lights2));
        SPAD->gunBoneData[0].lights = lights2;
    }
    V offset;
    for (int j = 1; j < 11; j++) {
        offset = *(V*)&self->gunBonesOffsets[j].u.offset;
        rhandMat.Rotate(&offset);
        SPAD->gunBoneData[j] = SPAD->gunBoneData[self->gunBonesOffsets[j].u.the.parent];
        SPAD->gunBoneData[j].bone.Translate(offset);
    }
    if (self->gunGlow) {
        u32 frameCount = g_VideoFrameCounter;
        float ang = (float)((frameCount >> 1 & 0x1F) * 81) * 0.017453292f;
        float sn = SIN(ang);
        float cs = COS(ang);
        Mul3(&SPAD->gunBoneData[3].bone, &SPAD->gunBoneData[3].bone, M(cs, 0.0f, sn, 0.0f, 1.0f, 0.0f, -sn, 0.0f, cs));
    }
    for (int j = 0; j < 11; j++) Mul44(&SPAD->gunBoneData[j].bone, &local2ScreenMatrix, &SPAD->gunBoneData[j].bone);
    U64 vifCode3 = ((U64)0x6C540085 << 32) | 0x15000000;
    *dmaVif++ = 0x10000054;
    *dmaVif++ = vifCode3;
    QCopy(dmaVif, SPAD->gunBoneData, 0x54);
    dmaVif += 0x540 / 8;
    
    
    for (u32 j = 0; j < self->gunPartCount; j++) {
        gunList* p = (gunList*)((j << 4) + ((theLOD << 7) + (u32)self));
        if (j == self->gunHolsterPart) continue;
        if (j == self->gunFlarePart) continue;
        if (j == self->gunLightPart) continue;
        if (j == self->gunStockPartOff) continue;
        if (p->gunParts[0][0].part) {
            dmaVif[0] = 0x10000001;
            dmaVif[1] = ((U64)0x6C018068 << 32) | 0x01000404;
            dmaVif[2] = SPAD->gunTex0[j];
            dmaVif[3] = 0;
            dmaVif[4] = (p->gunParts[0][0].qwc + 0x30000000) + ((U64)(u32)p->gunParts[0][0].part << 32);
            dmaVif[5] = 0;
            dmaVif += 6;
        }
    }
    cDmaMan_EndChain_int_ulongP(D_00537F80, 1, dmaVif);
    XLib_Restore(&g_Video);
    Pop();
}
static inline void merge_flush_func_003836B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003836B0 */
