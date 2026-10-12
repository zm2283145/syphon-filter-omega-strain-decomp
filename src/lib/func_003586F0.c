typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; char *x50; int x54; unsigned int x58; int x5C; int x60; } N81E0;
extern int D_00492CCC;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern void func_0034B7E8(void *);
extern void func_00357D88(void *);
extern void *func_00357D50(int);
extern N81E0 *func_003581E0(int);
extern int func_003583A0(N81E0 *, int);
extern int sceLibnetInitialize(void *, unsigned int, int, int);

int func_003586F0(unsigned int a, int b, int c)
{
    N81E0 *n = func_003581E0(0);
    unsigned int mask;
    int err;
    if (n == 0) return -1;
    mask = 0xFFFFFFC0;
    func_0034B7E8(n->x14);
    func_00357D88(n->x50);
    n->x5C = b;
    n->x60 = c;
    n->x58 = a;
    n->x50 = func_00357D50((a + 0x63) | 0x3F);
    if (n->x50 == 0) {
        N81E0 *x = n->next;
        if (n->prev) n->prev->next = x;
        else D_00492CD0 = x;
        if (n->next) n->next->prev = n->prev;
        else D_00492CD4 = n->prev;
        func_00357D88(n);
        D_00492CCC--;
        return func_003583A0(n, 0xC);
    } else {
        n->x54 = (int)(n->x50 + 0x3F) & -0x40;
        if (sceLibnetInitialize(n->x14, (n->x58 + 0x63) & mask, n->x5C, n->x60) < 0) {
            N81E0 *x = n->next;
            if (n->prev) n->prev->next = x;
            else D_00492CD0 = x;
            if (n->next) n->next->prev = n->prev;
            else D_00492CD4 = n->prev;
            func_00357D88(n);
            D_00492CCC--;
            return func_003583A0(n, 0x16);
        } else {
            return func_003583A0(n, 0);
        }
    }
}

