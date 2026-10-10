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

extern int func_001828B0(E3CgTree* t);
extern int func_00182880(E3CgTree* t);
extern void ColTree_VisitNode(E3CgTree* t, E3CgQuery* q, int node, int arg);
extern void ColTree_VisitLeaf(E3CgTree* t, E3CgQuery* q, int leaf, int arg);

/* Gathers collision from an 'F' tree, by node or by leaf. */
void ColGather_GatherWrapper(E3CgObj* obj, E3CgVec* pos, int arg) {
    E3CgQuery query;
    E3CgTree* tree;
    query.pos = *pos;
    query.q.owner = obj;
    tree = obj->holder->tree;
    if (tree->kind == 0x46) {
        if (tree->nodeCount > 0) {
            ColTree_VisitNode(tree, &query, func_001828B0(tree), arg);
        } else {
            ColTree_VisitLeaf(tree, &query, func_00182880(tree), arg);
        }
    }
}