/* Actor_NetPoseCorrection: in multiplayer, for a networked actor that is not
 * held/attached, if its root sits more than a margin below the ground plane
 * stored at +0x3570, snap it down onto the plane (offset by a slope-dependent
 * height) and push the plane normal to the attached body. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
#define VD(n) virtual void n();
#define VD10(p) VD(p##0) VD(p##1) VD(p##2) VD(p##3) VD(p##4) VD(p##5) VD(p##6) VD(p##7) VD(p##8) VD(p##9)
class Link {
public:
    VD10(a) VD(b0) VD(b1) VD(b2) VD(b3) VD(b4) VD(b5) VD(b6) VD(b7) VD(b8)
    virtual int Active();
};
struct Body { char pad[0x20]; int x20; char pad24[0x1E0 - 0x24]; V n; };
class Actor {
public:
    VD10(a) VD10(b) VD10(c) VD10(d) VD10(e) VD10(f)
    virtual int Probe(V* out);
    char pad4[0x14 - 4]; unsigned char held; char pad15[0x58 - 0x15]; Link* link;
    char pad5C[0x3210 - 0x5C]; int flags; char pad3214[0x3290 - 0x3214]; void* root;
    char pad3294[0x3310 - 0x3294]; Body* body; char pad3314[0x3570 - 0x3314]; V plane;
};
extern "C" {
extern unsigned char g_IsMultiplayer;
extern float D_0049CFF8;
extern float D_0049D000;
extern float D_0049D008;
void* Root_GetWorldPlacement(void* r);
V* Placement_GetQuat(void* p);
V* Placement_GetPosition(void* p);
void Quat_Assign(V* d, V* s);
void Vec4_Copy(V* d, V* s);
V* Vec4_Assign(V* d, const V* s);
V* cVector_SetW(V* v, float w);
void NpcAi_GroundActor(Actor* a, int b, int c, float z);
void Actor_NetPoseCorrection(Actor* self);
}
static inline float Dot(const V& a_, const V& b_) {
    const V* a = &a_; const V* b = &b_;
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline bool Bit(int f, int n) { return (bool)((f >> n) & 1); }
static inline bool Bit2(int f, int n) { bool r = (f >> n) & 1; return r; }
static inline bool Free(Body* b) { return !b || b->x20 == 0; }
static inline bool IsNull(void* p) { return !p; }
static inline bool IsZero(int x) { return x == 0; }
static inline bool FreeA(Body* b) { bool r = true; if (b && b->x20) r = false; return r; }
static inline bool FreeB(Body* b) { if (!b || b->x20 == 0) return true; return false; }
static inline bool NotBit(int f, int n) { return !Bit(f, n); }
static inline bool IsNZ(int x) { return x != 0; }
static inline bool Eq(int x, int y) { return x == y; }
static inline bool Free2(Actor* s) { return !s->body || IsZero(s->body->x20); }
static inline bool Z(float v) { return v == 0.0f; }
/* horizontal part of the plane normal, written through an out pointer (keeps retail's copy register order) */
static inline void Horiz(V* out, const V& v) { V n = v; V* p = &n; p->w = 0.0f; { V* pt = out; *pt = *p; } }
static inline float GroundZ(const V& n, float x, float y) { float h = 0.0f; if (n.z != 0.0f) { V p(x, y, 0.0f, 1.0f); float z = n.z; return -Dot(n, p) / z; } return h; }
static inline void SetN(Body* b, const V& v) { b->n = v; }
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Clamp(float v, float lo, float hi) { float r = 0.0f; asm { max.s r, v, lo; min.s r, r, hi } return r; }
static inline V AsDir(const V& v) { V t; V* r = cVector_SetW(Vec4_Assign(&t, &v), 0.0f); return *r; }

void Actor_NetPoseCorrection(Actor* self)
{
    if (g_IsMultiplayer) {
        bool linked = false;
        if (self->link && self->link->Active())
            linked = true;
        if (linked && !self->held) {
            bool b = false;
            bool a = false;
            if (Free2(self) && NotBit(self->flags, 4))
                a = true;
            if (a && NotBit(self->flags, 5))
                b = true;
            if (b) {
                void* root = self->root;
                V q;
                V pos;
                V tmp;
                Quat_Assign(&q, Placement_GetQuat(Root_GetWorldPlacement(root)));
                Vec4_Copy(&pos, Placement_GetPosition(Root_GetWorldPlacement(root)));
                if (Z(self->plane.x) && Z(self->plane.y) && Z(self->plane.z) && Z(self->plane.w))
                    return;
                {
                    float h = GroundZ(self->plane, pos.x, pos.y);
                    if (pos.z < h - D_0049CFF8) {
                        V m; Horiz(&m, self->plane);
                        const V* pm = &m; const float* pz = &pm->z; float s = 1.0f - Abs(*pz); float k = Clamp(s, 0.0f, 1.0f);
                        { float off = D_0049D000 + k * D_0049D008; pos.z = (h - D_0049CFF8) - off; }
                        if (!self->Probe(&tmp)) {
                            NpcAi_GroundActor(self, 1, 0, pos.z);
                            if (self->body)
                                SetN(self->body, AsDir(self->plane));
                        }
                    }
                }
            }
        }
    }
}
