#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; int t; const V* v = this; V* q = &c;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

extern "C" {
void cVector_ctor_void(V*);
void cVector_VU0Add(V*, const V*, const V*);
void cVector_ctor_cVectorR(V*, const V*);
void std_vector_int_ctor_int_int(void*, int, int);
void std_vector_pod_int_reserve(void*, int);
void func_0013A040(void*, int);
int** std_vector_pod_int_data(void*);
void std_vector_cGOBJPtr_push_back(void*, int*);
}
extern int D_0048A140;
extern int D_004EE780;

struct IntArr {
    int pad; int size; int* data; unsigned char canExpand;
    IntArr(int n, int v) { IntArr* p = this; std_vector_int_ctor_int_int(p, n, v); p->canExpand = 1; }
    __declspec(weak) __declspec(DROPDTOR) ~IntArr() { func_0013A040(this, -1); }
    int& operator[](int i) { return data[i]; }
};
struct PtrArr { int pad; int size; void** data; unsigned char canExpand; };

struct Xform;
struct Xform { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void update(); char pad04[0x3C]; V pos; };

struct Box { V mn, mx; };

static inline void AddO(V* out, const V& a, const V& b)
{
    V r;
    cVector_ctor_void(&r);
    cVector_VU0Add(&r, &a, &b);
    cVector_ctor_cVectorR(out, &r);
}
static inline void AddO2(V* out, const V& a, const V& b) { AddO(out, a, b); }
static inline V Half(const Box* b)
{
    V s;
    AddO2(&s, b->mn, b->mx);
    return s * 0.5f;
}
static inline V Center(const Box* b)
{
    V t = Half(b);
    return t;
}

struct Terrain {
    char pad[0x1F4];
    PtrArr mActivationList;
    PtrArr mActivationIDList;
    PtrArr mSortedActivationList;
    char pad224[0xC];
    Box mBBox;
};
struct Gobj { char pad[0x4C]; int subclass; bool Is(int id) const { return subclass == id; } };

extern "C" PtrArr* cTerrain_GetActivationSortedByDist(Terrain* self, Xform* xform)
{
    int i;
    int j;
    int terrCount = self->mActivationList.size;
    int listSize = 0;
    if (((unsigned char*)xform)[0x50]) {
        xform->update();
    }
    V keyLoc = xform->pos;
    V delta;
    IntArr distList(terrCount, D_0048A140);
    if (terrCount != self->mSortedActivationList.size) {
        std_vector_pod_int_reserve(&self->mSortedActivationList, terrCount);
    }
    self->mSortedActivationList.size = 0;
    int kMaxDist = 100000000;
    for (i = 0; i < terrCount; i++) {
        Gobj* actGobj = (Gobj*)self->mActivationList.data[i];
        if (actGobj && actGobj->Is(D_004EE780)) {
            Terrain* terrGobj = (Terrain*)actGobj;
            delta = keyLoc - Center(&terrGobj->mBBox);
            distList[i] = (int)delta.LenSq();
            if (distList[i] > kMaxDist) {
                distList[i] = kMaxDist;
            }
            listSize++;
        }
    }
    float maxDist = kMaxDist;
    float minDist = -1.0f;
    for (i = 0; i < listSize; ) {
        for (j = 0; j < listSize; j++) {
            if (distList[j] <= maxDist && distList[j] > minDist) {
                maxDist = distList[j];
            }
        }
        for (j = 0; j < listSize; j++) {
            if (distList[j] <= maxDist && distList[j] > minDist) {
                std_vector_cGOBJPtr_push_back(&self->mSortedActivationList, *std_vector_pod_int_data(&self->mActivationList) + j);
                i++;
            }
        }
        minDist = maxDist;
        maxDist = kMaxDist;
    }
    for (i = listSize; i < terrCount; i++) {
        std_vector_cGOBJPtr_push_back(&self->mSortedActivationList, *std_vector_pod_int_data(&self->mActivationList) + i);
    }
    return &self->mSortedActivationList;
}