#pragma cplusplus on
#include "types.h"
struct H3EA630 { int id; H3EA630() { id = -1; } };
struct R3EA630 { void* vt; char p4[0x1C]; int f20; int f24; int f28; H3EA630 h; int f30; signed char f34; };
extern "C" {
void Receiver_Construct(R3EA630*, void*);
extern char D_004E06C0[];
extern char D_0055A840[];
}
static inline H3EA630* Id3EA630(H3EA630* p) { return p; }
#pragma push
#pragma opt_propagation off
extern "C" R3EA630* func_003EA630(R3EA630* r) {
    Receiver_Construct(r, D_0055A840);
    r->vt = D_004E06C0;
    r->h.id = -2;
    r->f28 = 0;
    r->f30 = 0;
    r->f20 = 0;
    r->f24 = 0;
    r->f28 = 0;
    r->h.id = Id3EA630(&H3EA630())->id;
    r->f34 = 0;
    return r;
}
#pragma pop
