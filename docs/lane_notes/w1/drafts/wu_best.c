/* WeatherEmitter_Update = cParticleBox::NextFrame (0x0039A000, 4356 B), lane W1 draft. */
#include "types.h"
#pragma cplusplus on
#pragma inline_depth(10)
#pragma enumsalwaysint off
enum eBlockType { BLOCK_NONE, BLOCK_NEW, BLOCK_OLD };
#include "vslot_pad.h"

typedef __int128 u_long128;

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { void* xx = this; u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; cVector* d = this; const cVector* s = &o; u_long128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    cVector& operator+=(const cVector& b) { cVector* d = this; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(this), "r"(&b) : "memory"); return *this; }
    float Length() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2 %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    float Dot(const cVector& b) const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2 %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory"); return r; }
    void Normalize();
} __attribute__((aligned(16)));

struct cMatrix {
    cVector r0, r1, r2, r3;
    cMatrix() { void* p = this; int t; asm volatile { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
    cMatrix(const cMatrix& o, int) {}
    const cVector& Up() const { return r1; }
};

inline void cVector::Normalize()
{
    cVector* a = this;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(a)
    }
}

/* V * float, MW asm (no zero-init) */
static inline void OpM(cVector* pr, const cVector* pa, float s)
{
    const cVector* a_ = pa;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a_)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
}
static inline cVector operator*(const cVector& a, float s) { cVector r; OpM(&r, &a, s); return r; }
/* V * float, GCC asm with paddub zero */
static inline void OpMZ(cVector* pr, const cVector* pa, float s)
{
    u_long128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(pr), "r"(pa), "f"(s) : "memory");
}
static inline cVector MulZ(const cVector& a, float s) { cVector r; OpMZ(&r, &a, s); return r; }
static inline void OpS(cVector* pr, const cVector* pa, const cVector* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; OpS(&r, &a, &b); return r; }

static inline float FMax(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float FMin(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float FAbs(float a) { float r = 0.0f; __asm__ volatile("abs.s %0, %1" : "=f"(r) : "f"(a)); return r; }

static inline cVector Unit(const cVector& a) { cVector v = a; v.Normalize(); return v; }
static inline float LenXY(const cVector& a) { cVector v = a; v.z = 0.0f; return v.Length(); }
static inline float LenYZ(const cVector& a) { cVector v = a; v.x = 0.0f; return v.Length(); }

extern "C" int Libc_Rand(void);
extern "C" float Libc_Atan2f(float y, float x);
extern "C" float Libc_Tanf(float x);
static inline float RndS(float s) { float m = 2147483648.0f; return s * ((float)Libc_Rand() / (1.0f + m)); }
static inline float Rnd() { float m = 2147483648.0f; return (float)Libc_Rand() / (1.0f + m); }

static inline bool Wrap(float& p, float c, float h)
{
    bool w = false;
    float d = p - c;
    if (d < -h) {
        p = c + h;
        w = true;
    } else if (!(d <= h)) {
        p = c - h;
        w = true;
    }
    return w;
}

class cGOBJ {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual cVector GetPosition();
    virtual cMatrix GetMatrix();
};

struct tChild { char d[0xE0]; };
struct cBoxDefinition {
    char p0[0xC];
    int numParticles;
    char p10[4];
    float size;
    char p18[0x50 - 0x18];
    float alpha;
    char p54[0x68 - 0x54];
    float windForce;
    char p6C[0x180 - 0x6C];
    int numChildren;
    char p184[0x190 - 0x184];
    tChild child[8];
    char p890[0x998 - 0x890];
    float velocity;
};
struct tPiece {
    float x, y, z;
    float velX, velY, velZ;
    float alpha;
    unsigned char offScreenZ;
};
struct cParticleBox;
struct tPieceBlock { tPiece* buffer; cParticleBox* owner; float distance; int particleCount; };
struct cWind {
    cVector wind[4];
};
struct cParticle;
struct cParticleBox {
    char p0[0x6C];
    int particleCount;
    char p70[0xE0 - 0x70];
    cVector size;
    cVector lastOwnerPos;
    cBoxDefinition* definition;
    cGOBJ* owner;
    tPieceBlock* pieceBlockPtr;
    float near;
    float far;
    float nearAlpha;
    float farHalf;
    float floorZ;
    float particleCountRatio;
    float halfFov;
    int renderCount;
    int floorCollisionChildId;
    unsigned char type;
    unsigned char gobjRelative;
};

extern "C" {
void cParticleBase_NextFrame(cParticleBox* self, cParticle* system, const cMatrix* m, float t, const cVector* wind);
int GetEffectID__15cParticleSystemCFRC1(void* sys, void* key);
cBoxDefinition** cLList_cParticleDefinitionPtr_opIndex(void* self, int n);
eBlockType cParticleBox_RequestBlock(cParticleBox* self, int* count, float distance);
cVector cWind_GetTurbulence_cVectorR(cWind* w, const cVector& v);
cVector cWind_GetTurbulence_float_float_float(cWind* w, float x, float y, float z);
void* cParticle_AddChild(cParticle* system, cParticleBox* parent, int id, const cMatrix* m, float t);
extern char D_0053B540[];
extern char D_0053B544[];
extern cWind D_0053B5C0;
}

static inline tPiece* At(cParticleBox* s, int i)
{
    tPieceBlock* h = s->pieceBlockPtr;
    tPiece* e = 0;
    if (h && h->owner == s) e = &h->buffer[i];
    return e;
}

#define HALF_PI 1.5707964f

extern "C" void WeatherEmitter_Update(cParticleBox* self, cParticle* system, const cMatrix& matrix, float elapsedTime, const cVector* localWind)
{
    float alpha;
    if (!self->owner) return;
    cMatrix mat;
    cParticleBase_NextFrame(self, system, &matrix, elapsedTime, localWind);
    cVector center = matrix.r3;
    float distanceFromOwner = (center - self->owner->GetPosition()).Length();
    cVector ownerMotion = self->owner->GetPosition() - self->lastOwnerPos;
    self->lastOwnerPos = self->owner->GetPosition();

    int childCount = 0;
    cBoxDefinition* childDef = 0;
    if (self->definition->numChildren > 0) {
        int i;
        for (i = 0; i < self->definition->numChildren; i++) {
            cBoxDefinition* d = *cLList_cParticleDefinitionPtr_opIndex(D_0053B544, GetEffectID__15cParticleSystemCFRC1(D_0053B540, &self->definition->child[i]));
            if (d && d->numParticles == 0) {
                childDef = d;
                childCount = self->particleCount / 12;
                break;
            }
        }
    }

    eBlockType blockType = cParticleBox_RequestBlock(self, &self->particleCount, distanceFromOwner);
    if (blockType == BLOCK_NONE) return;

    cVector size = self->size;
    cVector sizeHalf = MulZ(size, 0.5f);
    cVector ownerYAxis = self->owner->GetMatrix().Up();
    int cappedParticleCount = self->particleCount;
    cappedParticleCount = (int)((float)self->particleCount * self->particleCountRatio);
    float pitch = Libc_Atan2f(ownerYAxis.z, LenXY(ownerYAxis));
    float t = Libc_Tanf(self->halfFov);
    float top = pitch + t;
    top = FMax(top, t);
    top = FMin(top, HALF_PI);
    float bottom = pitch - t;
    bottom = FMin(bottom, -t);
    bottom = FMax(bottom, -HALF_PI);
    float mid = 0.5f * (self->far + self->near);
    float topZ = self->owner->GetPosition().z + mid * (top / HALF_PI);
    float bottomZ = self->owner->GetPosition().z + mid * (bottom / HALF_PI);
    bottomZ = FMax(bottomZ, center.z - sizeHalf.z);

    int i;
    for (i = 0; i < self->particleCount; i++) {
        tPiece* piece = At(self, i);
        if (!piece) continue;
        alpha = 0.0f;
        if (blockType == 1) {
            cVector pos;
            pos.x = RndS(size.x) - sizeHalf.x;
            pos.y = RndS(size.y) - sizeHalf.y;
            pos.z = (topZ - bottomZ) * Rnd() - 0.5f * (topZ - bottomZ);
            if (self->type) {
                cVector windTurbulence = MulZ(Unit(pos), 0.4f);
                piece->velX = windTurbulence.x;
                piece->velY = windTurbulence.y;
                piece->velZ = windTurbulence.z;
            }
            pos.x += center.x;
            pos.y += center.y;
            pos.z += bottomZ;
            piece->x = pos.x;
            piece->y = pos.y;
            piece->z = pos.z;
            piece->alpha = 0.0f;
            piece->offScreenZ = 0;
            if (i > cappedParticleCount) piece->offScreenZ = 1;
            __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&ownerMotion) : "memory");
        }
        if (!(i > cappedParticleCount && piece->offScreenZ)) {
            if (piece->offScreenZ) {
                piece->offScreenZ = 0;
                if (!self->type) piece->z = topZ + (topZ - bottomZ) * Rnd();
            }
            cVector pos(piece->x, piece->y, piece->z, 1.0f);
            pos.z -= self->definition->velocity;
            if (!(self->definition->windForce <= 0.01f)) {
                if (localWind) {
                    pos += *localWind * self->definition->windForce;
                } else {
                    cVector wind = D_0053B5C0.wind[0];
                    if (self->type == 0) {
                        cVector windTurbulence = MulZ(Unit(pos), 0.4f);
                        wind += cWind_GetTurbulence_cVectorR(&D_0053B5C0, windTurbulence);
                    } else {
                        wind += cWind_GetTurbulence_float_float_float(&D_0053B5C0, piece->velX, piece->velY, piece->velZ);
                    }
                    pos += wind * self->definition->windForce;
                }
            }
            float radius = 1.0f;
            bool wrapped = false;
            bool randX = false;
            bool randY = false;
            bool randZ = false;
            if (i < childCount) radius = 0.5f * childDef->size;
            if (Wrap(pos.x, center.x, sizeHalf.x + radius)) {
                wrapped = randZ = randY = true;
            } else if (Wrap(pos.y, center.y, sizeHalf.y + radius)) {
                wrapped = randZ = randX = true;
            }
            if (pos.z < bottomZ - radius) {
                if (self->floorCollisionChildId >= 0 && !(piece->alpha <= 0.01f) && ownerYAxis.z <= 0.5f) {
                    cVector floorCollisionPos = pos;
                    floorCollisionPos.z = center.z - sizeHalf.z;
                    mat.r3 = floorCollisionPos;
                    cParticle_AddChild(system, self, self->floorCollisionChildId, &mat, elapsedTime);
                }
                randY = randX = true;
                pos.z += radius + (topZ - bottomZ);
                if (i > cappedParticleCount) piece->offScreenZ = 1;
                wrapped = true;
            } else if (!(pos.z <= topZ + radius)) {
                wrapped = randY = randX = true;
                pos.z += bottomZ - topZ - radius;
            }
            if (randX) pos.x = center.x + RndS(size.x) - sizeHalf.x;
            if (randY) pos.y = center.y + RndS(size.y) - sizeHalf.y;
            if (randZ) {
                pos.z = bottomZ + (topZ - bottomZ) * Rnd() - 0.5f * (topZ - bottomZ);
                if (!self->type) pos.z += topZ - bottomZ;
            }
            if (!self->type) {
                piece->velX = pos.x - piece->x;
                piece->velY = pos.y - piece->y;
                piece->velZ = pos.z - piece->z;
            }
            if (i < childCount) {
                pos += ownerMotion * 0.5f;
                cVector deltaFromOwner = pos - self->owner->GetPosition();
                if (!(ownerYAxis.z <= 0.5f) || !(deltaFromOwner.Dot(ownerYAxis) <= 0.0f)) {
                    Libc_Atan2f(-ownerYAxis.x, LenYZ(ownerYAxis));
                    float n = self->near;
                    float f = self->far;
                    float m = 0.5f * (f + n);
                    float range = f - n;
                    distanceFromOwner = deltaFromOwner.Length();
                    if (!(distanceFromOwner < n) && distanceFromOwner <= f) {
                        float hr = 0.5f * range;
                        float zr = deltaFromOwner.z / (size.z + size.z);
                        alpha = 1.0f - FAbs(distanceFromOwner - m) / hr;
                        alpha *= FMax(zr * zr, 1.0f);
                    }
                    alpha = FMin(alpha, 1.0f);
                    alpha = FMax(alpha, 0.0f);
                    alpha *= childDef->alpha;
                    if (wrapped) piece->alpha = 0.0f;
                    if (piece->alpha < alpha) alpha = piece->alpha + 0.15f * (alpha - piece->alpha);
                }
            } else if (!wrapped || self->type == 1) {
                cVector deltaFromOwner = pos - self->owner->GetPosition();
                if (!(ownerYAxis.z <= 0.5f) || !(deltaFromOwner.Dot(ownerYAxis) <= 0.0f)) {
                    float dist = deltaFromOwner.Length();
                    if (!(dist < self->far)) {
                        alpha = 0.2f;
                    } else if (dist <= self->near) {
                        alpha = self->definition->alpha;
                    } else {
                        alpha = FMin(self->definition->alpha * (1.2f - (dist - self->near) / (self->far - self->near)), self->definition->alpha);
                    }
                    if (piece->alpha < alpha) alpha = piece->alpha + 0.15f * (alpha - piece->alpha);
                }
            }
            piece->x = pos.x;
            piece->y = pos.y;
            piece->z = pos.z;
        }
        piece->alpha = alpha;
    }
}
