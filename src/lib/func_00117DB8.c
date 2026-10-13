typedef struct N7DB8 {
    struct N7DB8 *next;
    volatile int id;
    int (*func)(int, int, int, void *);
    void *arg;
} N7DB8;

extern N7DB8 *volatile D_004E9AC0;

int func_00117DB8(int id, int b, int c, N7DB8 *n)
{
    int ret = n->func(((int)n << 4) | (id & 0xFE) | 1, b, c, n->arg);
    if (ret == 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        return -1;
    }
    return ret;
}
