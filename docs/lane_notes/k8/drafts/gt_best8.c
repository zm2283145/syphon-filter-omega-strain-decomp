#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; Q16(d, s); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; Q16(d, s); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; };
struct M { VP r[4]; } __attribute__((aligned(16)));
struct V3 { float x, y, z, w; V3(float a, float b, float c) { x = a; y = b; z = c; w = 0.0f; } } __attribute__((aligned(16)));
struct AA {
    float x, y, z, a;
    AA(const V3& v, float an) { x = v.x; y = v.y; z = v.z; a = an; }
} __attribute__((aligned(16)));
extern "C" {
float Libc_Cosf(float);
float Libc_Sinf(float);
}
struct QA {
    float x, y, z, w;
    QA(const AA& aa) {
        float h = 0.5f * aa.a;
        float c = Libc_Cosf(h);
        float s = Libc_Sinf(h);
        w = c;
        x = s * aa.x;
        y = s * aa.y;
        z = s * aa.z;
    }
} __attribute__((aligned(16)));
struct Root;
struct Plc;
struct Other { char pad[0x394]; float f394; };
struct Human {
    char pad0[0x320C];
    int state;          /* 0x320C */
    int f3210;          /* 0x3210 */
    char pad3214[0x3248 - 0x3214];
    int f3248;          /* 0x3248 */
    int f324C;          /* 0x324C */
    char pad3250[0x3290 - 0x3250];
    Root* r0;           /* 0x3290 */
    Root* r1;           /* 0x3294 */
    Root* r2;           /* 0x3298 */
    char pad329C[0x3310 - 0x329C];
    Other* f3310;       /* 0x3310 */
};
extern "C" {
extern signed char D_0049D024;
extern M D_0055C9F0;
Plc* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root* r);
V* cQuatVec_Rotation(Plc* p);
V* cQuatVec_Translation(Plc* p);
void* cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Root* r);
void cSkaAnimAnchor_TreeNode_UpdateTransform(Root* r);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(Root* r);
void* cSKM_GOBJ_GetSkeleton_void(Human* h);
V cSkeleton_GetBoneToWorldTranslation(void* m, int node);
int cGOBJ_IsOnMovingElevator(Human* h);
}
static inline char* WorldPlc(Root* r)
{
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r);
        return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r);
    }
    return cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r) + 0x50;
}
static inline V ScaleR(const V& a, float k)
{
    V r;
    int t;
    V* pr = &r;
    const V* pa = &a;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(k) : "memory");
    return r;
}
static inline V ScaleV(V a, float k)
{
    V r;
    V* pr = &r;
    V* pa = &a;
    int t;
    __int128 tt = 0;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(k) : "memory");
    return r;
}
static inline V Add(const V& a, const V& b)
{
    V r;
    const V* pa = &a;
    V* pr = &r;
    const V* pb = &b;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
    return r;
}
static inline V Add2(const V& a, const V& b)
{
    V r;
    const V* pa = &a;
    asm { .set at }
    V* pr = &r;
    const V* pb = &b;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
    return r;
}
static inline V ComposeR(const V* b, const V* c)
{
    V r;
    V* q1 = &r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vmul.xyzw vf3, vf1, vf2; vopmula.xyz ACC, vf1, vf2; vmaddaw.xyz ACC, vf1, vf2w; vmaddaw.xyz ACC, vf2, vf1w; vopmsub.xyz vf4, vf2, vf1; vsubaz.w ACC, vf3, vf3z; vmsubay.w ACC, vf0, vf3y; vmsubx.w vf4, vf0, vf3x; sqc2 vf4, 0x0(%0)" : : "r"(q1), "r"(c), "r"(b) : "memory");
    return r;
}
static inline V Scale(const V& a, float k) { return ScaleR(a, k); }
static inline V Compose(const V* b, const V* c) { return ComposeR(b, c); }
static inline void Normalize(V* v)
{
    __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyzw vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddaz.w ACC, vf0, vf2z; vmaddw.w vf3, vf0, vf2w; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyzw vf4, vf1, Q; sqc2 vf4, 0x0(%0)" : : "r"(v) : "memory");
}
static inline M* QuatToMtx(M* a, const V* b)
{
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
    return a;
}
static inline void Build(M* out, const V& q, const V& pos)
{
    M m;
    M* pm = QuatToMtx(&m, &q);
    out->r[0].x = m.r[0].x;
    out->r[0].y = m.r[0].y;
    out->r[0].z = m.r[0].z;
    out->r[1].x = m.r[1].x;
    out->r[1].y = m.r[1].y;
    out->r[1].z = m.r[1].z;
    out->r[2].x = m.r[2].x;
    out->r[2].y = m.r[2].y;
    out->r[2].z = m.r[2].z;
    out->r[0].w = m.r[0].w;
    out->r[1].w = m.r[1].w;
    out->r[2].w = m.r[2].w;
    *(V*)&out->r[3] = pos;
}
extern "C" void func_001B0F30(M* out, Human* h, int* mode, int flag)
{
    Root* r0 = h->r0;
    Root* r1 = h->r1;
    Root* r2 = h->r2;
    Root* r;
    V quat;
    V pos;
    switch (h->state) {
    case 0x10: case 1: case 8: case 7: case 0x14:
        *mode = 1;
        r = r1;
        break;
    default:
        *mode = 0;
        r = r0;
        break;
    }
    if (h->state == 0x10) {
        float a = *(float*)((char*)r1 + 0xD0);
        float b = *(float*)((char*)r2 + 0xD0);
        if (0.0f == a && 0.0f == b) {
            quat = *cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r0));
            pos = *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r0));
            *mode = 0;
        } else {
            float inv = 1.0f / (a + b);
            quat = Add(Scale(*(V*)WorldPlc(r1), a), Scale(*cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r2)), b));
            pos = ScaleV(Add2(Scale(*cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r1)), a), Scale(*cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r2)), b)), inv);
            *mode = 2;
        }
    } else if (h->state == 1 && ((h->f3248 >> 6) & 1)) {
        float an = 3.1415927f;
        QA aq(AA(V3(0.0f, 0.0f, 1.0f), an));
        quat = Compose((V*)&aq, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r)));
        pos = *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r));
    } else {
        quat = *cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r));
        pos = *cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r));
    }
    if (*mode == 0 && h->f3310) {
        pos.z -= h->f3310->f394;
    }
    Normalize(&quat);
    pos.w = 1.0f;
    if (flag) {
        V sk = cSkeleton_GetBoneToWorldTranslation(cSKM_GOBJ_GetSkeleton_void(h), D_0049D024);
        pos.x = sk.x;
        pos.y = sk.y;
    }
    int st = h->state;
    if (((st == 4 || st == 5) && ((h->f3248 >> 10) & 1)) || (((h->f3210 >> 21) & 1) && ((h->f324C >> 1) & 1))) {
        if (!cGOBJ_IsOnMovingElevator(h)) {
            *mode = -1;
            __int128 t0, t1, t2, t3;
            __int128* d = (__int128*)out;
            const __int128* s = (const __int128*)&D_0055C9F0;
            t0 = s[0];
            t1 = s[1];
            d[0] = t0;
            t2 = s[2];
            d[1] = t1;
            t3 = s[3];
            d[2] = t2;
            d[3] = t3;
            return;
        }
        Build(out, quat, pos);
    } else {
        Build(out, quat, pos);
    }
}
