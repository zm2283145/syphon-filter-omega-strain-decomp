typedef struct N2F95F8 { int x0; struct N2F95F8 *next; int p8, pC; int key; } N2F95F8;
extern N2F95F8 *D_004908D8;
extern void func_002F94D0(int);
void func_002F95F8(int key)
{
    N2F95F8 *n = D_004908D8;
    int k;
    if (n == 0) return;
    do {
        k = n->key;
        if ((key == -1 && k == key) || (key == (int)0x80000000 && k == (k & 0x7FFFFFFF) + key) || (key == 0 && k == (k & 0x7FFFFFFF))) {
            func_002F94D0(k);
            n = D_004908D8;
        } else {
            n = n->next;
            if (n == D_004908D8) n = 0;
        }
    } while (n);
}
