#pragma cplusplus on
#include "types.h"
/* cGameDirectionalLight_ctor: read a directional light record (id, 28-byte direction/colour block, enable flag, intensity) and create its LevelLight */
// quadword/byte block copy (retail's memcpy idiom; lq/sq loop, not expressible in C)
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
        nop
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
struct GLt {
    int f0;
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5();
    virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void Update();
    int f8;
    float fC;
};
struct LReader { int version; int a, b; char* cur; };
struct LRec { int kind; V3 dir; V3 col; };
struct Id { int v; };
struct GLight { void* vt; char pad4[8]; Id id; char pad10[0x60 - 0x10]; GLt* light; unsigned char on; };
extern "C" {
extern char D_004DA1D0[];
extern char D_004DA0B0[];
extern char D_004DA070[];
extern char D_00535D20[];
extern void* D_004EE890;
void cGOBJ_ctor(GLight* obj, int* id, int kind, void* type);
GLt* LightMgr_AllocPoint(void* pool, int n);
V4* Vec4_SetFromVec3W(V4* out, V3* in, float w);
void LevelLight_CreateDirectional(GLt* l, int a, V4* c);
void Vec4_Assign(void* d, V4* s);
GLight* cGameDirectionalLight_ctor(GLight* obj, LReader* r);
}
static inline int Read(LReader* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadFloat(LReader* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void Align(LReader* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline GLt* MakeDir(GLt* p0, LRec& rec, V3& col, V4& dir, V4& tmp)
{
    GLt* p = p0; /* separate copy (propagation off): retail moves the light into s3 inside the arm and back to v0 at the join */
    float x, y, z, a, b, c;
    z = rec.col.z; y = rec.col.y; x = rec.col.x;
    c = rec.dir.z; b = rec.dir.y; a = rec.dir.x;
    col.z = z; col.y = y; col.x = x; dir.z = c; dir.y = b; dir.x = a; dir.w = 0.0f;
    LevelLight_CreateDirectional(p, 2, Vec4_SetFromVec3W(&tmp, &col, 0.0f));
    *(void**)((char*)p + 4) = D_004DA070;
    Vec4_Assign((char*)p + 0x40, &dir);
    return p;
}
#pragma push
#pragma opt_propagation off
GLight* cGameDirectionalLight_ctor(GLight* obj, LReader* r)
{
    volatile int id; /* volatile: retail stores the packed id to its stack slot and reloads it */
    int gid;
    float k;
    V3 col;
    LRec rec;
    V4 dir;
    V4 tmp;
    int hi, lo;
    unsigned char en;
    gid = -1;
    cGOBJ_ctor(obj, &gid, 6, &D_004EE890);
    obj->vt = D_004DA1D0;
    obj->light = 0;
    obj->on = 1;
    obj->vt = D_004DA0B0;
    hi = Read(r);
    lo = Read(r);
    QCopy(&rec, r->cur, 28);
    r->cur += 28;
    en = *(unsigned char*)r->cur;
    r->cur++;
    Align(r);
    ReadFloat(r, &k);
    {
        GLt* l = LightMgr_AllocPoint(D_00535D20, 2);
        if (l) l = MakeDir(l, rec, col, dir, tmp);
        obj->light = l;
    }
    if (en) obj->light->fC = k;
    else obj->light->fC = 0.0f;
    obj->light->Update();
    id = lo | (hi << 16);
    obj->id.v = id;
    return obj;
}
#pragma pop
