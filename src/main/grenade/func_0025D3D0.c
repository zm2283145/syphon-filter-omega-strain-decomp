#include "types.h"
typedef struct { void* vt; } D2_Proj;
extern char D_004DC6C0[];
extern void cGOBJ_dtor(void* p, int flag);
extern void operator_delete(void* p);
D2_Proj* Projectile_Destroy(D2_Proj* p, short flag) {
    if (p != 0) {
        p->vt = D_004DC6C0;
        cGOBJ_dtor(p, 0);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}