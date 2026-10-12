#include "types.h"

typedef struct Node Node_;
typedef struct NodeObj {
    char pad00[0x2C];
    unsigned char f2C;  /* 0x2C */
    unsigned char f2D;  /* 0x2D */
    unsigned char f2E;  /* 0x2E */
    char pad2F[0x60 - 0x2F];
    int state;          /* 0x60 */
    char pad64[0x9C - 0x64];
    PtrVec kids;        /* 0x9C */
} NodeObj;

extern int func_0023DA80(PtrVec* v);
extern int func_0023DA90(PtrVec* v);
extern int* func_0023DAA0(PtrVec* v, int i);
extern int* func_0023DAB0(PtrVec* v, int i);
extern int func_0023DAC0(NodeObj* o);
extern int func_001830D0(NodeObj* o);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)
#pragma push
#pragma opt_strength_reduction off

int func_0023D810(NodeObj* self, int flag)
{
    int total = 0; int ok;
    int i;
    ok = self->f2D != 0 && self->f2C != 0 && !(self->f2E != 0); if (ok) {
        if (COUNTS(self, flag)) total++;
    }
    for (i = 0; i < self->kids.count; i++) {
        NodeObj* c = (NodeObj*)self->kids.data[i];
        int n = 0;
        int j;
        ok = c->f2D != 0 && c->f2C != 0 && !(func_0023DAC0(c) != 0); if (ok) {
            if (COUNTS(c, flag)) n++;
        }
        for (j = 0; j < func_0023DA80(&c->kids); j++) {
            NodeObj* g = *(NodeObj**)func_0023DAB0(&c->kids, j);
            int m = 0;
            int k;
            if (func_001830D0(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < func_0023DA90(&g->kids); k++) {
                m += func_0023D810(*(NodeObj**)func_0023DAA0(&g->kids, k), flag);
            }
            n += m;
        }
        total += n;
    }
    return total;
}
#pragma pop


