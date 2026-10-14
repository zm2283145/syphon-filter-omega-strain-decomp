typedef struct { unsigned char init; char pad[3]; int count; int owner; } Lock23D8;
extern int func_00302610(int *tid);
extern int func_003025E0(Lock23D8 *l);
int RecursiveLock_Release(Lock23D8 *l, int *left)
{
    int tid;
    int r;
    if (l == 0) return 2;
    if (l->init != 1) return 2;
    r = func_00302610(&tid);
    if (r != 0) return r;
    if (tid != l->owner) return 4;
    if (l->count == 0) return 5;
    l->count--;
    if (left) *left = l->count;
    if (l->count == 0) {
        l->owner = 0;
        r = func_003025E0(l);
        if (r != 0) return r;
    }
    return 0;
}
