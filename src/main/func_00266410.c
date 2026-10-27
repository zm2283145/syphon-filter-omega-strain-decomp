#include "types.h"
#pragma cplusplus on
class O266 { public: int pad; virtual ~O266(); };
typedef struct { int a; int b; unsigned char flag; char pad[3]; O266* child; char sub[4]; } S266;
extern "C" void cAirTaser_Release(S266*);
extern "C" void std_vector_deleter_TaserPoint_clear(void*);
extern "C" void cAirTaser_Reset(S266* p) {
    p->flag = 0;
    cAirTaser_Release(p);
    std_vector_deleter_TaserPoint_clear(&p->sub);
    if (p->child) {
        delete p->child;
        p->child = 0;
    }
}