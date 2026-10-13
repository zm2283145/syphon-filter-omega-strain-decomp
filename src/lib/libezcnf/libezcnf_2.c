/*
 * lib/libezcnf: 2 files, 0033F688-0033F770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033F688 */
extern int D_004928EC;
extern char D_00533080[];
extern char D_00533040[];
extern char D_004B9D10[];
extern char D_004B9D18[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCnfGetCombinationList(char *name, int a, int b)
{
    char *res = D_00533080;
    if (!D_004928EC) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388("RPC service not running\n");
        return -1;
    }
    if (0x130 > 0x1340) { /* inlined RPC size check, constant-false here: only its message remains */
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388("RPC data size 0x%x exceeds buffer size 0x%x\n", 0x130, 0x1340);
        return -1;
    }
    String_Copy(res + 0x10, name);
    ((int *)res)[0] = b;
    ((int *)res)[1] = a;
    func_00110528(D_00533040, 1, 0, res, 0x130, res, 0x130, 0, 0);
    func_0010F388(D_004B9D10, D_004B9D18);
    func_0010F388("ezNetCnfGetCombinationList returned %d\n", *(int *)res);
    return *(int *)res;
}
/* merge_units: end func_0033F688 */

/* merge_units: begin func_0033F770 */
typedef struct { char b[0x68]; } E0033F770;
typedef struct { int count; char pad[0x2C]; E0033F770 e[1]; } T0033F770;
E0033F770 *ezNetCnfGetCombination(T0033F770 *t, int idx)
{
    if (t == 0 || t->count == 0) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388("ezNetCnfGetCombination: pList is empty\n");
        return 0;
    }
    if (idx <= 0 || t->count < idx) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388("ezNetCnfGetCombination: invalid Combination number (%d)\n", idx);
        return 0;
    }
    return &t->e[idx - 1];
}
/* merge_units: end func_0033F770 */
