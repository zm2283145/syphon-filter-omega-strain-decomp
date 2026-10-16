#pragma inline_depth(8)
typedef struct Node_3EEBE0 {
    char pad0[0x60];
    char flag;
    char pad61[0xD];
    unsigned short count;
    char pad70[0x14];
    struct Node_3EEBE0 **children;
} Node_3EEBE0;

/* The recursive flag propagation as CodeWarrior inlined it into itself five levels deep. */
void IeNode_SetShown(Node_3EEBE0 *n, char v, int recurse);

static inline void L5_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) IeNode_SetShown(n->children[i], v, 1);
}
static inline void L4_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L5_3EEBE0(n->children[i], v);
}
static inline void L3_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L4_3EEBE0(n->children[i], v);
}
static inline void L2_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L3_3EEBE0(n->children[i], v);
}
static inline void L1_3EEBE0(Node_3EEBE0 *n, char v)
{
    int i;
    n->flag = v;
    for (i = 0; i < n->count; i++) L2_3EEBE0(n->children[i], v);
}

void IeNode_SetShown(Node_3EEBE0 *n, char v, int recurse)
{
    int i;
    n->flag = v;
    if (recurse) {
        for (i = 0; i < n->count; i++) L1_3EEBE0(n->children[i], v);
    }
}

