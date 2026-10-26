#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
/* func_003BFAB0: clips triangle q (corner positions v[3]) against the plane y = h, keeping the part
 * above it. Nothing left: the mesh slot idx is overwritten by the last triangle and the mesh shrinks.
 * Three corners: q is rebuilt from them; four: q takes corners 0,1,2 and a copy of q takes 0,2,3 and
 * is appended. Corners are divided through by their y before use. */
struct V4;
/* plain quadword copy (lq/sq) */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" {
V4* Ptr_Identity(V4* v);
V4* Vec4_Assign(V4* d, const V4* s);
}
/* copy constructor out of line (Vec4_Assign); assignment is a quadword copy whose dead xx
 * reproduces retail's duplicated source addiu */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { Vec4_Assign(this, &o); }
    V4& operator=(const V4& o) { void* xx = (void*)&o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct V4p { float x, y, z, w; } __attribute__((aligned(16)));
struct UvX { char pad[0x10]; };
struct UvY { char pad[0x10]; };
struct CTri;
extern "C" void func_00139B00(CTri* d, const CTri* s);
/* the copy constructor is the out-of-line func_00139B00 */
struct CTri {
    CTri(const CTri& o) { func_00139B00(this, &o); }
    V4p v[4];
    UvX uv;
    unsigned char b50, b51, b52;
    char pad53[0xD];
    UvY uv2;
};
struct CMesh { int x0; int count; CTri* data; };

extern "C" {
V4 Sphere_FromCenter(const V4* a, const V4* b);
float Vec4_GetY(const V4* v);
V4 Vec4_Scale(const V4* v, float k);
V4 Vec4_Add(const V4* a, const V4* b);
void Vec4_Copy(void* d, const void* s);
void func_003B26E0(V4* v);
float* func_003B2680(V4* v);
float* func_003B2650(V4* v);
float* func_003B2630(V4* v);
void func_00139BB0(UvX* d, const UvX* s);
void func_00139BA0(UvY* d, const UvY* s);
void func_003C01D0(CMesh* m);
void func_003C01B0(CTri* t, int i, V4* v);
void func_003C0020(CTri* t);
void func_00139B00(CTri* d, const CTri* s);
void func_003BFFF0(CMesh* m, CTri* t);
void func_00131B70(CTri* t, int flag);
void func_003BFAB0(CTri* q, CMesh* mesh, int idx, V4* v, float h);
}

static inline V4 ClipEdge(const V4* a, const V4* b, float h)
{
    V4 r;
    Ptr_Identity(&r);
    V4 d = Sphere_FromCenter(b, a);
    if (Vec4_GetY(&d) != 0.0f) {
        float t = (h - Vec4_GetY(a)) / Vec4_GetY(&d);
        Vec4_Copy(&r, &Vec4_Add(a, &Vec4_Scale(&d, t)));
    } else {
        func_003B26E0(&r);
    }
    return r;
}

static inline void AssignTri(CTri* d, const CTri* s)
{
    Vec4_Copy(&d->v[0], &s->v[0]);
    Vec4_Copy(&d->v[1], &s->v[1]);
    Vec4_Copy(&d->v[2], &s->v[2]);
    Vec4_Copy(&d->v[3], &s->v[3]);
    d->b50 = s->b50;
    func_00139BB0(&d->uv, &s->uv);
    func_00139BA0(&d->uv2, &s->uv2);
    d->b51 = s->b51;
    d->b52 = s->b52;
}

static inline void EmitQuad(CTri* q, CMesh* mesh, V4* out)
{
    int i;
    for (i = 0; i < 4; i++) {
        float inv = 1.0f / *func_003B2650(&out[i]);
        *func_003B2680(&out[i]) *= inv;
        *func_003B2630(&out[i]) *= inv;
    }
    func_003C01B0(q, 0, &out[0]);
    func_003C01B0(q, 1, &out[1]);
    func_003C01B0(q, 2, &out[2]);
    func_003C0020(q);
    {
        CTri t(*q);
        func_003C01B0(&t, 0, &out[0]);
        func_003C01B0(&t, 1, &out[2]);
        func_003C01B0(&t, 2, &out[3]);
        func_003C0020(&t);
        func_003BFFF0(mesh, &t);
        func_00131B70(&t, -1);
    }
}

static inline void Finish(CTri* q, CMesh* mesh, V4* out, int n)
{
    int i;
    if (n == 3) {
        for (i = 0; i < 3; i++) {
            float inv = 1.0f / *func_003B2650(&out[i]);
            *func_003B2680(&out[i]) *= inv;
            *func_003B2630(&out[i]) *= inv;
            func_003C01B0(q, i, &out[i]);
        }
        func_003C0020(q);
    } else if (n == 4) {
        EmitQuad(q, mesh, out);
    }
}

void func_003BFAB0(CTri* q, CMesh* mesh, int idx, V4* v, float h)
{
    V4 out[4];
    int n = 0;
    int b = 1;
    int a = 2;
    int i;
    for (i = 0; i < 3; i++) {
        if (v[a].y <= h) {
            if (!(v[b].y <= h))
                out[n++] = ClipEdge(&v[a], &v[b], h);
            if (!(v[i].y <= h))
                out[n++] = ClipEdge(&v[a], &v[i], h);
        } else {
            Q16(&out[n++], &v[a]);
        }
        b = a;
        a = i;
    }
    if (n == 0) {
        CTri* last = mesh->data + mesh->count - 1;
        CTri* e = &mesh->data[idx];
        AssignTri(e, last);
        func_003C01D0(mesh);
    } else if (n >= 3) {
        Finish(q, mesh, out, n);
    }
}
