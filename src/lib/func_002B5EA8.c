/* res is stored in both semaphore branches (gcc merges them); the extra refs give retail's s0/s1/s2 assignment */
typedef struct { int a; int op; int x8; } RQ;
extern RQ D_00506640;
extern int D_00506B68;
extern int WaitSema(int);
extern int func_0010D1B0(int);

int func_002B5EA8(int poll, int *op, int *res)
{
    RQ *r = &D_00506640;
    if (r->op == 0) return -1;
    if (op) *op = r->op;
    if (poll == 0) {
        WaitSema(D_00506B68);
        if (res) *res = r->x8;
    } else {
        if (func_0010D1B0(D_00506B68) < 0) return 0;
        if (res) *res = r->x8;
    }
    if (op) *op = r->op;
    r->op = 0;
    return 1;
}

