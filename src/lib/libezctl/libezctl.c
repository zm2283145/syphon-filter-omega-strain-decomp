/*
 * lib/libezctl: 2 files, 00352CD0-00352DD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00352CD0 */
extern int D_00492C30;
extern int D_00492C34;
extern char D_00533280[];
extern char D_004BADB8[], D_004BADC0[], D_004BADD0[], D_004BADE8[];
extern int func_0010F388(const char *, ...);
extern int func_00114F20(char *);
extern int func_00110358(char *, int, int);
int func_00352CD0(void)
{
    int r, i;
    if ((D_00492C30 = func_00114F20("eznetctl_inet")) < 0) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BADD0, "eznetctl_inet");
    }
    for (;;) {
        r = func_00110358(D_00533280, 0x75488909, 0);
        i = 0x10000;
        if (r < 0) {
            func_0010F388(D_004BADB8, D_004BADC0);
            func_0010F388(D_004BADE8);
        }
        if (*(int *)(D_00533280 + 0x24)) break;
        while (--i != -1)
            ;
    }
    D_00492C34 = 1;
    return r;
}
/* merge_units: end func_00352CD0 */

/* merge_units: begin func_00352DD0 */
extern int func_00114C88(int fd, int a, int b, int *stat);
extern int func_00114E90(int fd);
int func_00352DD0(void)
{
    int stat;
    if (D_00492C34 == 1) {
        if (func_00114C88(D_00492C30, 0, 0, &stat) >= 0) {
            stat = func_00114E90(D_00492C30);
            if (stat >= 0) {
                D_00492C34 = 0;
                stat = 0;
            }
        }
    }
    return stat;
}
/* merge_units: end func_00352DD0 */
