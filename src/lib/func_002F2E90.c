typedef struct N2F2E90 { struct N2F2E90 *prev, *next; int key; int arr[4]; } N2F2E90;
extern void Net_AllocZeroed(N2F2E90 **, int);
N2F2E90 *func_002F2E90(int key)
{
    N2F2E90 *n = 0;
    unsigned int i;
    Net_AllocZeroed(&n, 0x1C);
    if (n) {
    n->key = key;
    n->prev = n;
    n->next = n;
    for (i = 0; i < 4; i++) n->arr[i] = 0xFFFF;
    }
    return n;
}
