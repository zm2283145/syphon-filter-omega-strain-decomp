#pragma cplusplus on
struct GObj {
    char pad00[0x2C];
    unsigned char x2C;
    unsigned char x2D;
    unsigned char x2E;
    char pad2F[0x1A];
    unsigned char x49;
    char pad4A[2];
    int x4C;
    bool Own();
    bool Active() { return x2D != 0 && x2C != 0 && !(x2E != 0); }
};
struct PtrVec { int count; int cap; GObj** data; };
struct Iter {
    GObj** p;
    bool operator==(const Iter& o) const { return p == o.p; }
    bool operator!=(const Iter& o) const { return !(*this == o); }
    GObj*& operator*() const { return *p; }
    Iter& operator++() { p++; return *this; }
};
struct Self { char pad[0x1F4]; PtrVec list; };
extern "C" {
extern GObj** std_vector_imp_cGOBJPtr_1_end_void_2(PtrVec* v);
extern Iter std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(PtrVec* self, GObj** const& src);
extern Iter std_vector_cGOBJPtr_begin(PtrVec* v);
extern Iter cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(const Iter& s);
extern int D_004EE780;
unsigned char nActivation_IsActivationLoaded(Self* self);
}
static inline void EndO(Iter* o, PtrVec* v) { *o = std_vector_cGOBJPtr_pointer2iterator_cGOBJPPR_2(v, std_vector_imp_cGOBJPtr_1_end_void_2(v)); }
static inline Iter FirstI(PtrVec* v) { return cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(std_vector_cGOBJPtr_begin(v)); }
inline bool GObj::Own() { return x4C == D_004EE780; }
unsigned char nActivation_IsActivationLoaded(Self* self)
{
    unsigned char r = 1;
    PtrVec* v = &self->list;
    Iter last;
    EndO(&last, v);
    for (Iter cur = FirstI(v); cur != last; ++cur) {
        if (*cur && (*cur)->x49 == 1 && (*cur)->Own() && !(*cur)->Active()) {
            r = 0;
            break;
        }
    }
    return r;
}


