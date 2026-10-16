#include "types.h"

typedef struct NodeObj {
    char pad00[0x2C];
    unsigned char f2C;  /* 0x2C */
    unsigned char f2D;  /* 0x2D */
    unsigned char f2E;  /* 0x2E */
    char pad2F[0x60 - 0x2F];
    int state;          /* 0x60 */
    char pad64[0x94 - 0x64];
    struct NodeObj* parent; /* 0x94 */
    int pad98;
    PtrVec kids;        /* 0x9C */
} NodeObj;

extern int func_0023DA80(PtrVec* v);
extern int func_0023DA90(PtrVec* v);
extern int* func_0023DAA0(PtrVec* v, int i);
extern int* func_0023DAB0(PtrVec* v, int i);
extern int func_0023DAC0(NodeObj* o);
extern int GameObject_IsCollisionEnabled(NodeObj* o);
extern int func_0023D810(NodeObj* o, int flag);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)

int func_0023DAD0(NodeObj* self, int flag);

static inline int L1(NodeObj* pp, int flag)
{
    if (pp->parent) {
        return func_0023DAD0(pp->parent, flag);
    } else {
        return func_0023D810(pp, flag);
    }
}

static inline int L2(NodeObj* p, int flag)
{
    if (p->parent) {
        return L1(p->parent, flag);
    } else {
        int m = 0;
        int k;
        if (GameObject_IsCollisionEnabled(p)) {
            if (COUNTS(p, flag)) m++;
        }
        for (k = 0; k < func_0023DA90(&p->kids); k++) {
            m += func_0023D810(*(NodeObj**)func_0023DAA0(&p->kids, k), flag);
        }
        return m;
    }
}

int func_0023DAD0(NodeObj* self, int flag)
{
    if (self->parent) {
        return L2(self->parent, flag);
    } else {
        int n = 0;
        int ok;
        int j;
        ok = self->f2D != 0 && self->f2C != 0 && !(func_0023DAC0(self) != 0);
        if (ok) {
            if (COUNTS(self, flag)) n++;
        }
        for (j = 0; j < func_0023DA80(&self->kids); j++) {
            NodeObj* g = *(NodeObj**)func_0023DAB0(&self->kids, j);
            int m = 0;
            int k;
            if (GameObject_IsCollisionEnabled(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < func_0023DA90(&g->kids); k++) {
                m += func_0023D810(*(NodeObj**)func_0023DAA0(&g->kids, k), flag);
            }
            n += m;
        }
        return n;
    }
}
