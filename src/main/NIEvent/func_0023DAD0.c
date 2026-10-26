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

extern int std_vector_cNIEventBasePtr_size(PtrVec* v);
extern int cArray_cNIEventBasePtr_Size(PtrVec* v);
extern int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i);
extern int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i);
extern int cGOBJ_IsStreaming(NodeObj* o);
extern int GameObject_IsCollisionEnabled(NodeObj* o);
extern int cNIEventBase_NumChildrenActive(NodeObj* o, int flag);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)

int cNIEventBase_NumActiveInTree(NodeObj* self, int flag);

static inline int L1(NodeObj* pp, int flag)
{
    if (pp->parent) {
        return cNIEventBase_NumActiveInTree(pp->parent, flag);
    } else {
        return cNIEventBase_NumChildrenActive(pp, flag);
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
        for (k = 0; k < cArray_cNIEventBasePtr_Size(&p->kids); k++) {
            m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&p->kids, k), flag);
        }
        return m;
    }
}

int cNIEventBase_NumActiveInTree(NodeObj* self, int flag)
{
    if (self->parent) {
        return L2(self->parent, flag);
    } else {
        int n = 0;
        int ok;
        int j;
        ok = self->f2D != 0 && self->f2C != 0 && !(cGOBJ_IsStreaming(self) != 0);
        if (ok) {
            if (COUNTS(self, flag)) n++;
        }
        for (j = 0; j < std_vector_cNIEventBasePtr_size(&self->kids); j++) {
            NodeObj* g = *(NodeObj**)std_vector_imp_cNIEventBasePtr_1_opIndex(&self->kids, j);
            int m = 0;
            int k;
            if (GameObject_IsCollisionEnabled(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < cArray_cNIEventBasePtr_Size(&g->kids); k++) {
                m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&g->kids, k), flag);
            }
            n += m;
        }
        return n;
    }
}
