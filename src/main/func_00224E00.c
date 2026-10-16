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
extern GObj** LosCache_End(PtrVec* v);
extern Iter CachedCollection_End(PtrVec* self, GObj** const& src);
extern Iter Iter_Begin(PtrVec* v);
extern Iter Iter_Assign(const Iter& s);
extern int D_004EE780;
unsigned char Zone_IsReady(Self* self);
}
static inline void EndO(Iter* o, PtrVec* v) { *o = CachedCollection_End(v, LosCache_End(v)); }
static inline Iter FirstI(PtrVec* v) { return Iter_Assign(Iter_Begin(v)); }
inline bool GObj::Own() { return x4C == D_004EE780; }
unsigned char Zone_IsReady(Self* self)
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


