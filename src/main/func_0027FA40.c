#include "types.h"
#pragma cplusplus on
#pragma bool on
#pragma inline_depth(8)
typedef int Q128 __attribute__((mode(TI)));
static inline void QCopy(void* d, const void* s) { Q128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Vec3f {
    float x, y, z, w;
    Vec3f(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3f(const Vec3f& o) { x = o.x; y = o.y; z = o.z; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3f() {}
    Vec3f& operator=(const Vec3f& o) { const void* xx = &o; Q128 tt = 0; QCopy(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void Sub(Vec3f* r, const Vec3f& a, const Vec3f& b) { float bz = b.z, by = b.y, bx = b.x; r->Set(a.x - bx, a.y - by, a.z - bz); }
static inline Vec3f operator-(const Vec3f& a, const Vec3f& b) { return Vec3f(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline Vec3f operator+(Vec3f a, const Vec3f& b) { a.x += b.x; a.y += b.y; a.z += b.z; return a; }
struct Quat {
    float x, y, z, w;
    Quat() {}
    Quat(bool) { Quat* p = this; asm { sqc2 vf0, 0x0(p) } }
    Quat(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    Quat(const Quat& o) { void* xx = this; *(Q128*)this = *(const Q128*)&o; }
    Quat& operator=(const Quat& o) { Q128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Node_FA40 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Refresh(); /* +0x58 */
    int pad4[3];
    float m10[16];
    unsigned char b50;
};
struct Tgt {
    char pad0[0xC];
    int id;
    char pad10[0x2C - 0x10];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x50 - 0x2F];
    int x50;
    bool IsB() const { return !b2E; }
    bool Ready() const { bool r = false; bool a = false; if (b2D && b2C) a = true; if (a && IsB()) r = true; return r; }
};
struct Cam {
    char pad0[0x50];
    Node_FA40* x50;
    char pad54[0xD04 - 0x54];
    Tgt* hp;
    int hid;
    char padD0C[0xD80 - 0xD0C];
    unsigned char bD80, bD81;
    static bool Same(int a, int b) { return a == b; }
    bool Valid() const { return !hp || Same(hp->id, hid); }
    Tgt* Get() const { return Valid() ? hp : 0; }
    int GetX50() const { return Get() ? Get()->x50 : 0; }
};
extern "C" {
extern void PlayerCamera_LookAtLock(Cam*, Vec3f*, int, int, int, Quat*);
extern void Mtx_ToEuler(Vec3f*, float*);
extern float func_00280040(Vec3f*);
extern float* func_00280050(Vec3f*);
extern Vec3f* func_00280060(Vec3f*);
extern float func_0027FF80(Vec3f*);
extern float* func_0027FF90(Vec3f*);
extern float func_0027FFA0(Vec3f*);
extern float* func_0027FFB0(Vec3f*);
extern Vec3f* func_0027FF60(Vec3f*, Vec3f*);
extern float Math_WrapAnglePi(float);
extern float Math_Cos(float);
extern float Math_Sin(float);
extern float fabsf(float);
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

static inline void Wrap(Vec3f* t, Vec3f& d)
{
    Vec3f r;
    func_00280060(&r);
    *func_00280050(&r) = Math_WrapAnglePi(func_00280040(&d));
    *func_0027FFB0(&r) = Math_WrapAnglePi(func_0027FFA0(&d));
    *func_0027FF90(&r) = Math_WrapAnglePi(func_0027FF80(&d));
    func_0027FF60(t, &r);
}
extern "C" void PlayerCamera_UpdateR1Pick(Cam* self, Quat* out)
{
    if (self->GetX50()) {
        if (self->Get()->Ready()) {
            Vec3f tgt;
            Vec3f e;
            Vec3f d;
            Quat q2;
            Vec3f t;
            Quat qf;
            Node_FA40* n;
            int a2;
            q2 = Quat(true);
            { void* yy = &q2; }
            PlayerCamera_LookAtLock(self, &tgt, a2, 10, 0, &q2);
            n = self->x50;
            if (n->b50) n->Refresh();
            Mtx_ToEuler(&e, n->m10);
            Sub(&d, tgt, e);
            Wrap(&t, d);
            d = t;
            if (self->bD80) {
                self->bD80 = d.x > 0.0f && d.x < 0.34906584f;
            } else {
                self->bD80 = d.x > -0.17453292f && d.x < 0.5235988f;
            }
            if (self->bD81) {
                self->bD81 = Abs(d.z) < 0.5235988f;
            } else {
                self->bD81 = Abs(d.z) < 1.0471976f;
            }
            if (self->bD80) d.x = 0.0f;
            if (self->bD81) d.z = 0.0f;
            {
                Vec3f s = e + d;
                float hx = 0.5f * s.x;
                float hy = 0.5f * s.y;
                float hz = 0.5f * s.z;
                float cx = Math_Cos(hx);
                float cy = Math_Cos(hy);
                float cz = Math_Cos(hz);
                float sx = Math_Sin(hx);
                float sy = Math_Sin(hy);
                float sz = Math_Sin(hz);
                float cycz = cy * cz;
                float sysz = sy * sz;
                float sycz = sy * cz;
                float cysz = cy * sz;
                qf.w = cx * cycz - sx * sysz;
                qf.x = sx * cycz - cx * sysz;
                qf.y = cx * sycz + sx * cysz;
                qf.z = cx * cysz + sx * sycz;
                QCopy(out, &qf);
            }
        }
    }
}