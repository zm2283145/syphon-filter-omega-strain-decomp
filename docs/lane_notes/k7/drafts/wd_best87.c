/* GuiWeaponDisplay_onRender: draws an object's model fitted into a screen rect (box at o+0x3E0 centred/scaled). Draft. */
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(int) { *(int*)&x = 0; *(int*)&y = 0; *(int*)&z = 0; *(int*)&w = 0; }
    V4(const V4& o) { void* d=this; __int128 t; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d),"=&r"(t):"r"(&o):"memory"); }
    V4& operator=(const V4& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V4 operator+(const V4& o) const {
        V4 r; V4* d = &r; const V4* p = this; const V4* q = &o;
        asm { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) }
        return r;
    }
    static void Sub(V4* d,const V4* p,const V4* q) { asm { lqc2 vf1,0(p); lqc2 vf2,0(q); vsub.xyzw vf1,vf1,vf2; sqc2 vf1,0(d) } }
    V4 operator-(const V4& o) const { V4 r; Sub(&r,this,&o); return r; }
    V4 operator*(float s) const { V4 r; V4* d=&r; const V4* p=this; __int128 t=0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0(%2); .set reorder" : "+r"(t): "r"(p),"r"(d),"f"(s):"memory"); return r; }
    static void Neg(V4* d,const V4* p) { asm { lqc2 vf1,0(p); vmulax.xyzw ACC,vf0,vf0x; vmsubw.xyzw vf1,vf1,vf0w; sqc2 vf1,0(d) } }
    V4 operator-() const { V4 r; Neg(&r,this); return r; }
} __attribute__((aligned(16)));
static inline V4 operator*(float s,const V4& v) { V4 r; V4* d=&r; const V4* p=&v; __int128 t=0; __asm__ volatile(".set noreorder; lqc2 $vf1,0(%1); mfc1 %0,%3; qmtc2.ni %0,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,0(%2); .set reorder":"+r"(t):"r"(p),"r"(d),"f"(s):"memory"); return r; }
#define M4MUL(o, a, b) __asm__ volatile( \
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2);" \
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1); lqc2 $vf11, 0x30(%1);" \
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w;" \
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w;" \
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w;" \
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w;" \
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" \
        : : "r"(o), "r"(b), "r"(a) : "memory")
struct M4 {
    float f[4][4];
    V4& R(int i) { return *(V4*)f[i]; }
    M4() {}
    static void Copy(M4* d,const M4* s) { __int128 qa,qb; __asm__ volatile("lq %0,0(%3);lq %1,16(%3);sq %0,0(%2);lq %0,32(%3);sq %1,16(%2);lq %1,48(%3);sq %0,32(%2);sq %1,48(%2)":"=&r"(qa),"=&r"(qb):"r"(d),"r"(s):"memory"); }
    M4(const M4& o) { Copy(this,&o); }
    M4& operator=(const M4& o) { Copy(this,&o); return *this; }
    M4(float a, float b, float c, float d, float e, float f, float g, float h,
       float i, float j, float k, float l, float m, float n, float o, float p) {
        this->f[0][0] = a; this->f[0][1] = b; this->f[0][2] = c; this->f[0][3] = d;
        this->f[1][0] = e; this->f[1][1] = f; this->f[1][2] = g; this->f[1][3] = h;
        this->f[2][0] = i; this->f[2][1] = j; this->f[2][2] = k; this->f[2][3] = l;
        this->f[3][0] = m; this->f[3][1] = n; this->f[3][2] = o; this->f[3][3] = p;
    }
    void Identity() { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(this) : "memory"); }
    void SetRot(const M4& o) {
        f[0][0] = o.f[0][0]; f[0][1] = o.f[0][1]; f[0][2] = o.f[0][2];
        f[1][0] = o.f[1][0]; f[1][1] = o.f[1][1]; f[1][2] = o.f[1][2];
        f[2][0] = o.f[2][0]; f[2][1] = o.f[2][1]; f[2][2] = o.f[2][2];
        f[0][3] = o.f[0][3]; f[1][3] = o.f[1][3]; f[2][3] = o.f[2][3];
    }
    void Translate(const V4& v) {
        M4* p = this; const V4* q = &v;
        asm { lqc2 vf1, 0x30(p); lqc2 vf2, 0x0(q); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x30(p) }
    }
    static void Multiply(M4* d,const M4* a,const M4* b) { M4MUL(d,a,b); }
    void Mul(const M4& o) { Multiply(this,this,&o); }
} __attribute__((aligned(16)));
static inline V4 Zero4() { V4 r; *(int*)&r.x = 0; *(int*)&r.y = 0; *(int*)&r.z = 0; *(int*)&r.w = 0; return r; }
struct Box {
    V4 mn, mx;
    bool IsEmpty() const { return mn.x > mx.x; }
    V4 Center() const { V4 r = (mn + mx) * 0.5f; return r; }
    V4 Size() const { return IsEmpty() ? V4(0) : mx - mn; }
};
struct Obj { char pad[0x3E0]; Box box; char pad400[0x16]; unsigned char f416; char f417; };
struct Ent { char pad[0x34]; float x, y, w, h; char pad44[8]; Obj* obj; char pad50[4]; float f54; char pad58[8]; M4 m60; };
struct MStack { char pad[0xA80]; M4 m[1]; };
extern "C" {
extern MStack g_Video;
extern int D_00538C64;
extern char D_00538C68;
void GuiWidget_onRender(void);
void XLib_ClearZBuffer(void*);
void gunList_GunRender(Obj*, int, M4*, int);
}
static inline M4& Top() { return g_Video.m[D_00538C64]; }
static inline void Push() { g_Video.m[D_00538C64 + 1] = g_Video.m[D_00538C64]; D_00538C64++; }
static inline void Mult(const M4& m) { Top().Mul(m); D_00538C68 = 1; }
static inline float FMin(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

extern "C" void GuiWeaponDisplay_onRender(Ent* e)
{
    GuiWidget_onRender();
    Obj* o = e->obj;
    if (o != 0 && o->f417 == 0 && e->f54 != 1.0f && o->box.mn.x <= o->box.mx.x) {
        const Box& box = o->box;
        XLib_ClearZBuffer(&g_Video);
        V4 c = box.Center();
        c.w = 1.0f;
        Push();
        M4 m = Top();
        const float* pw = &e->w;
        const float* ph = &e->h;
        const float* px = &e->x;
        const float* py = &e->y;
        float w = *pw;
        float h = *ph;
        float x = *px;
        V4 b, a;
        a.x = x;
        a.y = *py;
        b.x = a.x + w;
        b.y = a.y - h;
        V4 t = m.R(3);
        a.w = 0.0f;
        b.w = 0.0f;
        a.z = 200.0f + t.z;
        b.z = 200.0f + t.z;
        const V4& sz=box.Size();
        const V4* psz=&sz;
        float sx = w / psz->x;
        float sy = h / psz->y;
        float s = FMin(sx, sy);
        const V4& rc=0.5f*(a+b);
        m.SetRot(M4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
        m.Translate(rc);
        m.Translate(c * -s);
        Top() = m;
        D_00538C68 = 1;
        Mult(M4(s, 0.0f, 0.0f, 0.0f, 0.0f, s, 0.0f, 0.0f, 0.0f, 0.0f, s, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
        M4 tr;
        tr.Identity();
        tr.R(3) = c;
        Mult(tr);
        tr.R(3) = -c;
        Mult(tr);
        tr.R(3) = c;
        M4 r = tr;
        r.Mul(e->m60);
        tr.R(3) = -c;
        r.Mul(tr);
        int trans = 0x80;
        if(e->f54 != 0.0f) trans = (int)(64.0f * (1.0f - e->f54));
        e->obj->f416 = trans;
        gunList_GunRender(e->obj, 2, &r, 1);
        D_00538C64--;
        D_00538C68 = 1;
    }
}
