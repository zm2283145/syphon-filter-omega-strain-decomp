typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; void *x50; } N81E0;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern int D_00492CCC;
extern int D_00492CC8;
extern void func_0034B7E8(void *);
extern void func_00357D88(void *);
extern int func_003581C0(void);
extern int func_00358158(void);
extern int func_0010D050(void);
extern int func_0010D170(int);
void func_00358BB0(N81E0 *n)
{
    N81E0 *x = n->next;
    if (n->prev) n->prev->next = x;
    else D_00492CD0 = x;
    if (n->next) n->next->prev = n->prev;
    else D_00492CD4 = n->prev;
    func_0034B7E8(n->x14);
    func_00357D88(n->x50);
    func_00357D88(n);
    D_00492CCC--;
}