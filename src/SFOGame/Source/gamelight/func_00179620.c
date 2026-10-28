#pragma cplusplus on
#include "types.h"
/* cGameSceneLight_ctor: read a point/spot light record and create its LevelLight */
static inline void QCopy(void* dst0, void* src0, int n0)
{
    int n; int t; int m; char* dst; char* src;
    n = n0; dst = (char*)dst0; src = (char*)src0;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
struct V4 { float x, y, z, w; };
struct V3 { float x, y, z; };
struct PLt {
    int f0;
    void* vt;
    int f8;
    float fC;
    float f10;
    float f14;
    char pad18[5];
    unsigned char f1D;
    char pad1E[0x40 - 0x1E];
    V4 v40;
    float f50;
    float f54;
    unsigned char f58;
    int f5C;
};
struct LReader { int version; int a, b; char* cur; };
struct LRec { int kind; V3 pos; V3 col; float inner; float outer; };
struct Id { int v; };
struct GLight { void* vt; char pad4[8]; Id id; char pad10[0x60 - 0x10]; PLt* light; unsigned char on; };
extern "C" {
extern char D_004DA1D0[];
extern char D_004D9F50[];
extern char D_004DF700[];
extern char g_LightMgr[];
extern void* D_004EE890;
void cGOBJ_ctor(GLight* obj, int* id, int kind, void* type);
PLt* cLightMan_AddLight(void* pool, int n);
V4* tRGBA_ctor_tRGBR_float(V4* out, V3* in, float w);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(PLt* l, int a, V4* c, V4* pos, int b);
void cVector_ctor_float_float_float_float(V4* v, float x, float y, float z, float w);
void LightEffect_SetInner(PLt* l, float v);
void LightEffect_SetOuter(PLt* l, float v);
void cSceneLight_Init(PLt* l);
void cLightSrc_SetId(PLt* l, int id);
float Libc_Cosf(float a);
GLight* cGameSceneLight_ctor(GLight* obj, LReader* r);
}
static inline void Q16(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline float Deg2Rad(float d) { return 0.017453292f * d; }
static inline void SetA(PLt* l, float v) { l->f10 = v; }
static inline void SetB(PLt* l, float v) { l->f14 = v; }
static inline int Read(LReader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadFloat(LReader* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline unsigned char ReadByte(LReader* r) { unsigned char v = *(unsigned char*)r->cur; r->cur++; return v; }
static inline void Align(LReader* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline PLt* MakePoint(PLt* p0, LRec& rec, V3& col, V4& pos, V4& tmp, volatile int& id)
{
    int i = id;
    float x, y, z, a, b, c;
    z = rec.col.z; y = rec.col.y; x = rec.col.x;
    c = rec.pos.z; b = rec.pos.y; a = rec.pos.x;
    col.z = z; col.y = y; col.x = x; pos.z = c; pos.y = b; pos.x = a; pos.w = 1.0f;
    PLt* p = p0;
    cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(p, 0x10, tRGBA_ctor_tRGBR_float(&tmp, &col, 0.0f), &pos, 0);
    p->vt = D_004DF700;
    cVector_ctor_float_float_float_float(&p->v40, 0.0f, 0.0f, 0.0f, 0.0f);
    p->f50 = 0.0f;
    p->f54 = 0.0f;
    p->f58 = 1;
    p->f5C = 0;
    LightEffect_SetInner(p, 0.0f);
    LightEffect_SetOuter(p, 0.0f);
    cSceneLight_Init(p);
    cLightSrc_SetId(p, i);
    return p;
}
#pragma push
#pragma opt_propagation off
GLight* cGameSceneLight_ctor(GLight* obj, LReader* r)
{
    volatile int id;
    int gid;
    V3 col;
    LRec rec;
    V4 v;
    V4 pos;
    V4 tmp;
    int hi, lo;
    float outer, inner, k;
    unsigned char en, f8, f10;
    gid = -1;
    cGOBJ_ctor(obj, &gid, 6, &D_004EE890);
    obj->vt = D_004DA1D0;
    obj->light = 0;
    obj->on = 1;
    obj->vt = D_004D9F50;
    f8 = 0;
    f10 = 0;
    v.x = 0.0f; v.y = 0.0f; v.z = 0.0f; v.w = 0.0f;
    hi = Read(r);
    lo = Read(r);
    r->cur += 4;
    r->cur += 4;
    QCopy(&rec, r->cur, 0x24);
    r->cur += 0x24;
    ReadFloat(r, &v.x);
    ReadFloat(r, &v.y);
    ReadFloat(r, &v.z);
    ReadFloat(r, &outer);
    ReadFloat(r, &inner);
    en = ReadByte(r);
    Align(r);
    if (r->version >= 0x3B) {
        f8 = ReadByte(r);
        Align(r);
        f10 = ReadByte(r);
        Align(r);
    }
    ReadFloat(r, &k);
    id = lo | (hi << 16);
    obj->id.v = id;
    {
        PLt* l;
        PLt* a = cLightMan_AddLight(g_LightMgr, 0x10);
        if (a) a = MakePoint(a, rec, col, pos, tmp, id);
        l = a;
        if (l) {
            SetA(l, rec.inner);
            SetB(l, rec.outer);
            l->f50 = Libc_Cosf(Deg2Rad(0.5f * outer));
            l->f54 = Libc_Cosf(Deg2Rad(0.5f * inner));
            Q16(&l->v40, &v);
            if (en) l->fC = k;
            else l->fC = 0.0f;
            if (f8) l->f1D |= 8;
            if (f10) l->f1D |= 0x10;
        }
        obj->light = l;
    }
    return obj;
}
#pragma pop
