typedef struct Node {
    char pad0[0x6C];
    unsigned short nA;
    unsigned short nB;
    char pad70[0x10];
    void **a;
    struct Node **b;
    char pad88[4];
    int skip;
} Node;
extern void IeElement_EvaluateAt(void *p, float t);
void IeNode_PropagateTrackColour(Node *n, float t)
{
    int i;
    for (i = 0; i < n->nA; i++) {
        IeElement_EvaluateAt(n->a[i], t);
    }
    for (i = 0; i < n->nB; i++) {
        if (n->b[i]->skip <= 0) {
            IeNode_PropagateTrackColour(n->b[i], t);
        }
    }
}
