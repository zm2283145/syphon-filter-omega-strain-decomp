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
extern void func_003F45A0(void *p, float t);
void func_003EE510(Node *n, float t)
{
    int i;
    for (i = 0; i < n->nA; i++) {
        func_003F45A0(n->a[i], t);
    }
    for (i = 0; i < n->nB; i++) {
        if (n->b[i]->skip <= 0) {
            func_003EE510(n->b[i], t);
        }
    }
}
