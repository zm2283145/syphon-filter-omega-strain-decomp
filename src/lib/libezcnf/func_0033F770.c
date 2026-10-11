typedef struct { char b[0x68]; } E0033F770;
typedef struct { int count; char pad[0x2C]; E0033F770 e[1]; } T0033F770;
extern char D_004B9D10[], D_004B9D18[], D_004B9DD8[], D_004B9E00[];
extern int func_0010F388(const char *, ...);
E0033F770 *ezNetCnfGetCombination(T0033F770 *t, int idx)
{
    if (t == 0 || t->count == 0) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9DD8);
        return 0;
    }
    if (idx <= 0 || t->count < idx) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9E00, idx);
        return 0;
    }
    return &t->e[idx - 1];
}
