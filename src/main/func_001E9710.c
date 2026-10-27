#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct VC;
extern "C" VC* cVector_ctor_cVectorR(VC* d, const VC* s);
struct VC {
    float x, y, z, w;
    VC(const VC& o) { cVector_ctor_cVectorR(this, &o); }
} __attribute__((aligned(16)));
struct Mtx;
struct Node;
struct Obj8 { char pad[0x14]; unsigned char m14; char pad2[3]; char skel[0x10]; Node* m28; };
struct Self { char pad[8]; Obj8* m8; char pad2[0xE8 - 0xC]; unsigned char mE8; char pad3[7]; char plane[0x10]; };
extern "C" {
void* cArray_cBone_opIndex_int(void*, long);
void* cBone_Xform(void*);
VC* cXform_GetTranslation(void*);
Mtx* cXform_GetMatrix(Node*);
VC cVector_GetTransformed(VC* v, Mtx* m);
float cPlane_C(void*);
float Plane_HeightAt(void*, V*);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
}
static inline V Unit() { V l0; V* q1 = &l0; asm { sqc2 vf0, 0x0(q1) } return l0; }
static inline long NodeId(int m) { signed char n; if (m == 1) n = 7; else n = 11; return n; }
static inline float H2(void* pl, float x, float y) { V t; return Plane_HeightAt(pl, cVector_ctor_float_float_float_float(&t, x, y, 0.0f, 1.0f)); }
static inline float H1(void* pl, float x, float y) { return -H2(pl, x, y); }
static inline VC GetPos(Obj8* o, long n)
{
    if (o->m14) return cVector_GetTransformed(cXform_GetTranslation(cBone_Xform(cArray_cBone_opIndex_int(o->skel, n))), cXform_GetMatrix(o->m28));
    return *cXform_GetTranslation(o->m28);
}
extern "C" V cHumanCollisionRoutine_GetFloorContactPoint(Self* self, bool* hit, int mode, float thresh)
{
    V r = Unit();
    int m;
    *hit = 0;
    if (self->mE8 && (m = (unsigned char)mode)) {
        long n = NodeId(m);
        Obj8* o = self->m8;
        VC pos = GetPos(o, n);
        float px;
        float py;
        py = pos.y;
        px = pos.x;
        float z = cPlane_C(self->plane) != 0.0f ? H1(self->plane, px, py) / cPlane_C(self->plane) : 0.0f;
        r = V(px, py, z, 1.0f);
        if (pos.z - r.z < thresh) *hit = 1;
    }
    return r;
}






