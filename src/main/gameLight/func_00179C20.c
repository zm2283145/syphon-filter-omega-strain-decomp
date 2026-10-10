#include "types.h"
#pragma cplusplus on
struct E4Del { int pad; virtual ~E4Del(); };
struct E4Inner { int pad; E4Del d; };
typedef struct {
    void* vt;
    char pad[0x5C];
    E4Del* m60;
} E4Light;
extern char D_004DA1D0[];
extern "C" void cGOBJ_dtor(void* p, int flag);
extern "C" void operator_delete(void* p);
extern "C" E4Light* cGameLight_dtor(E4Light* p, short flag)
{
    if (p != 0) {
        p->vt = D_004DA1D0;
        if (p->m60) {
            delete p->m60;
            p->m60 = 0;
        }
        cGOBJ_dtor(p, 0);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}