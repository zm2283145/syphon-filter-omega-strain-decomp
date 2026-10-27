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

extern int std_vector_cNIEventBasePtr_size(PtrVec* v);
extern int cArray_cNIEventBasePtr_Size(PtrVec* v);
extern int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i);
extern int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i);
extern int cGOBJ_IsStreaming(NodeObj* o);
extern int cGOBJ_IsActive(NodeObj* o);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)
#pragma push
#pragma opt_strength_reduction off

int cNIEventBase_NumChildrenActive(NodeObj* self, int flag)
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
        ok = c->f2D != 0 && c->f2C != 0 && !(cGOBJ_IsStreaming(c) != 0); if (ok) {
            if (COUNTS(c, flag)) n++;
        }
        for (j = 0; j < std_vector_cNIEventBasePtr_size(&c->kids); j++) {
            NodeObj* g = *(NodeObj**)std_vector_imp_cNIEventBasePtr_1_opIndex(&c->kids, j);
            int m = 0;
            int k;
            if (cGOBJ_IsActive(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < cArray_cNIEventBasePtr_Size(&g->kids); k++) {
                m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&g->kids, k), flag);
            }
            n += m;
        }
        total += n;
    }
    return total;
}
#pragma pop


