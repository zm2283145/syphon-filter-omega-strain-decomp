typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; char *x50; int x54; unsigned int x58; int x5C; int x60; } N81E0;
int D_00492CCC = 0;
N81E0 *D_00492CD0 = 0;
N81E0 *D_00492CD4 = 0;
extern void sceLibnetTerminate(void *);
extern void my_free(void *);
extern void *my_malloc(int);
extern int unblock(void);
extern int func_00358158(void);
extern int GetThreadId(void);
extern int sceLibnetInitialize(void *, unsigned int, int, int);

N81E0 *Insck_GetThreadContext(int flag)
{
    int tid = GetThreadId();
    N81E0 *n;
    if (func_00358158() < 0) return 0;
    for (n = D_00492CD0; n; n = n->next) {
        if (tid == n->tid) goto out;
    }
    if (++D_00492CCC >= 0x100) {
        N81E0 *x;
        n = D_00492CD4;
        x = n->next;
        if (n->prev) n->prev->next = x;
        else D_00492CD0 = x;
        if (n->next) n->next->prev = n->prev;
        else D_00492CD4 = n->prev;
        sceLibnetTerminate(n->x14);
        my_free(n->x50);
        my_free(n);
        D_00492CCC--;
    }
    n = my_malloc(0x64);
    if (n) {
        unsigned int mask;
        n->tid = tid;
        n->x58 = 0x800;
        n->x5C = 0x2000;
        n->x60 = 0x20;
        mask = 0xFFFFFFC0;
        n->x50 = my_malloc(0x87F);
        if (n->x50 == 0) goto fail;
        n->x54 = (int)(n->x50 + 0x3F) & -0x40;
        if (sceLibnetInitialize(n->x14, (n->x58 + 0x63) & mask, n->x5C, n->x60) < 0) {
            my_free(n->x50);
fail:
            my_free(n);
            D_00492CCC--;
            unblock();
            return 0;
        }
        n->next = D_00492CD0;
        if (D_00492CD0) D_00492CD0->prev = n;
        else D_00492CD4 = n;
        D_00492CD0 = n;
        n->prev = 0;
    }
out:
    if (flag == 0) n->err = 0;
    return n;
}