#include "types.h"
typedef struct { char pad[0x4C]; int type; } A_455550;
typedef struct { char pad[0x30]; A_455550* f30; } G_455550;
typedef struct { char pad[0x48]; void* f48; } O_455550;
extern G_455550* D_004FFC0C;
extern int D_0049D010;
extern void func_0041EFA0(O_455550*);
extern int func_00176110(G_455550*);
extern void func_00454F80(O_455550*, int);
extern void func_00455260(O_455550*, A_455550*, int);

void func_00455550(O_455550* o)
{
    G_455550* g;
    func_0041EFA0(o);
    if (o->f48 && (g = D_004FFC0C)) {
        if (func_00176110(g) == -1) {
            func_00454F80(o, 1);
        } else {
            A_455550* a = g->f30;
            a = (a && a->type == D_0049D010) ? a : 0;
            func_00455260(o, a, func_00176110(g));
        }
    }
}
