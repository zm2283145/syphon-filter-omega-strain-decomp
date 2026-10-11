typedef struct { unsigned char b[32]; } S2DA750;
typedef struct N2DA750 { int a; struct N2DA750 *next; char *obj; } N2DA750;
extern int func_002D9E18(int, int);
extern N2DA750 *func_002ED8F8(int);
extern int func_002F3220(char *);
int func_002DA750(int a, int (*cb)(int, int, S2DA750 *), int arg, int key)
{
    int v = func_002D9E18(a, key);
    N2DA750 *n, *head;
    S2DA750 tmp;
    if (cb == 0 || v == 0) return -1;
    n = head = func_002ED8F8(v);
    while (n) {
        tmp = *(S2DA750 *)(n->obj + 0x20);
        if (func_002F3220(n->obj) & 0x4000) ((int *)&tmp)[6] |= 0x8000;
        else ((int *)&tmp)[6] &= ~0x8000;
        if (cb(a, arg, &tmp) == 0) break;
        n = n->next;
        if (n == head) n = 0;
    }
    return 0;
}