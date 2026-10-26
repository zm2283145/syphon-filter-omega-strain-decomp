typedef struct N7ED8 { int a; struct N7ED8 *next; unsigned int key; } N7ED8;
N7ED8 *GetKeyChain(N7ED8 *l, unsigned int key)
{
    N7ED8 *n = 0;
    key &= 0x1FFFFFFF;
    if (l) n = *(N7ED8 **)((char *)l + 8);
    while (n && n->key != key) n = n->next;
    return n;
}