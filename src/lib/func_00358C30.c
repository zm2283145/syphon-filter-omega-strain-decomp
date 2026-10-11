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
extern void func_00358BB0(N81E0 *);

int func_00358C30(int tid)
{
    N81E0 *n;
    if (tid == 0) tid = func_0010D050();
    if (func_00358158() < 0) return -1;
    if (tid == -1) {
        while ((n = D_00492CD0) != 0) func_00358BB0(n);
    } else {
        for (n = D_00492CD0; n; n = n->next) {
            if (tid == n->tid) {
                func_00358BB0(n);
                break;
            }
        }
    }
    if (D_00492CCC <= 0) {
        func_0010D170(D_00492CC8);
        D_00492CC8 = -1;
        return 0;
    }
    func_003581C0();
    return 0;
}