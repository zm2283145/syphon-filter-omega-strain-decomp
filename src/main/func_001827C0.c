#include "types.h"

typedef struct E3CgVec { float x, y, z; } E3CgVec;
typedef union E3CgQuery {
    E3CgVec pos;
    struct { float x; void* owner; float z; } q;
} E3CgQuery;
typedef struct E3CgTree {
    char unk0;
    char unk1;
    signed char kind;   /* 0x2: 'F' = 0x46 */
    char unk3;
    int nodeCount;      /* 0x4 */
} E3CgTree;
typedef struct E3CgHolder { E3CgTree* tree; } E3CgHolder;
typedef struct E3CgObj { int unk0; E3CgHolder* holder; } E3CgObj;

extern int cCollisionModel_Data_GetTreeRootNode(E3CgTree* t);
extern int cCollisionModel_Data_GetTreeSoleLeaf(E3CgTree* t);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(E3CgTree* t, E3CgQuery* q, int node, int arg);
extern void cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(E3CgTree* t, E3CgQuery* q, int leaf, int arg);

/* Gathers collision from an 'F' tree, by node or by leaf. */
void cCollisionModel_GetNearFaces_cCollisionFaceCollector_cBoxR(E3CgObj* obj, E3CgVec* pos, int arg) {
    E3CgQuery query;
    E3CgTree* tree;
    query.pos = *pos;
    query.q.owner = obj;
    tree = obj->holder->tree;
    if (tree->kind == 0x46) {
        if (tree->nodeCount > 0) {
            cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeNodeR_cBoxR(tree, &query, cCollisionModel_Data_GetTreeRootNode(tree), arg);
        } else {
            cCollisionModel_Data_GetNearFaces_cCollisionFaceCollectorR_cCollisionModelTreeLeafR_cBoxR(tree, &query, cCollisionModel_Data_GetTreeSoleLeaf(tree), arg);
        }
    }
}