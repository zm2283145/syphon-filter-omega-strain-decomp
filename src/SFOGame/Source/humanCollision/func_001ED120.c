#pragma cplusplus on
#include "types.h"
#pragma opt_rotateloops off
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct cCollisionEdge;
struct WI { cCollisionEdge* const* p; };
static inline bool weq(const WI& a, const WI& b) { return a.p == b.p; }
static inline bool wne(const WI& a, const WI& b) { return !(weq(a, b) != 0); }
struct CI {
    WI it;
    CI() {}
    
    cCollisionEdge& operator*() const { cCollisionEdge* const& r = *it.p; return *r; }
    CI& operator++() { ++it.p; return *this; }
    CI operator++(int) { CI t = *this; ++it.p; return t; }
    CI& inc2() { WI t = it; ++t.p; it = t; return *this; }
    bool operator!=(const CI& o) const { return wne(it, o.it); }
};
struct EL {
    unsigned long long edgeIndex; void* parentModel; unsigned int pad;
    unsigned char operator==(const EL& b) const
    {
        unsigned long long r; long long m = -1; __asm__("" : "+r"(m));
        const EL* pe = this; const EL* pb = &b;
        unsigned char res;
        asm volatile { lq a1, 0(pe); lq a3, 0(pb); pceqw a1, a1, a3; ppach a1, a1, a1; sltu a1, a1, m; xori a1, a1, 1; andi res, a1, 0xff }
        return res;
    }
};
struct cCollisionEdge { char pad[0x50]; EL edgeLocator; };
struct cEdgeGroup;
extern "C" {
cCollisionEdge* const* std_vector_imp_cCollisionEdgePtr_1_begin(const cEdgeGroup* v);
cCollisionEdge* const* std_vector_imp_cCollisionEdgePtr_1_end(const cEdgeGroup* v);
WI std_vector_cCollisionEdgePtr_pointer2iterator(const cEdgeGroup* v, cCollisionEdge* const* const& p);
unsigned char cEdgeGroup_IsEdgeInsideGroup(const cEdgeGroup* self, const cCollisionEdge& inputEdge);
}
static inline WI vbegin(const cEdgeGroup* self) { return std_vector_cCollisionEdgePtr_pointer2iterator(self, std_vector_imp_cCollisionEdgePtr_1_begin(self)); }
static inline WI vend(const cEdgeGroup* self) { return std_vector_cCollisionEdgePtr_pointer2iterator(self, std_vector_imp_cCollisionEdgePtr_1_end(self)); }

unsigned char cEdgeGroup_IsEdgeInsideGroup(const cEdgeGroup* self, const cCollisionEdge& inputEdge)
{
    unsigned char res;
    CI currEdge;
    CI end;
    currEdge.it = vbegin(self);
    end.it = vend(self);
    for (; currEdge != end; ++currEdge) {
        cCollisionEdge& edge = *currEdge;
        const EL* pe = &edge.edgeLocator; long long m = -1; __asm__("" : "+r"(m)); const EL* pb = &inputEdge.edgeLocator;
        asm volatile { lq a1, 0(pe); lq a3, 0(pb); pceqw a1, a1, a3; ppach a1, a1, a1; sltu a1, a1, m; xori a1, a1, 1; andi res, a1, 0xff }
        if (res)
            return 1;
    }
    return false;
}


