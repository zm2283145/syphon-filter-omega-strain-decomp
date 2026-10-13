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
extern int DeleteSema(int);
extern int D_00492CE0;
extern int *func_00123320(void);

int func_003583A0(N81E0 *n, int err)
{
    n->err = err;
    if (D_00492CE0) *func_00123320() = err;
    func_003581C0();
    return err ? -1 : 0;
}