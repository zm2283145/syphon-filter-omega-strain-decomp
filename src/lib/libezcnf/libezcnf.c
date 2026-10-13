/*
 * lib/libezcnf: 2 files, 0033F508-0033F608
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033F508 */
extern int D_004928E8;
extern int D_004928EC;
extern char D_00533040[];
extern char D_004B9D10[], D_004B9D18[], D_004B9D28[], D_004B9D40[];
extern int func_0010F388(const char *, ...);
extern int func_00114F20(char *);
extern int func_00110358(char *, int, int);
int func_0033F508(void)
{
    int r, i;
    if ((D_004928E8 = func_00114F20("eznetcnf")) < 0) {
        func_0010F388(D_004B9D10, D_004B9D18);
        func_0010F388(D_004B9D28, "eznetcnf");
    }
    for (;;) {
        r = func_00110358(D_00533040, 0x75499128, 0);
        i = 0x10000;
        if (r < 0) {
            func_0010F388(D_004B9D10, D_004B9D18);
            func_0010F388(D_004B9D40);
        }
        if (*(int *)(D_00533040 + 0x24)) break;
        while (--i != -1)
            ;
    }
    D_004928EC = 1;
    return r;
}
/* merge_units: end func_0033F508 */

/* merge_units: begin func_0033F608 */
extern int func_00114C88(int fd, int a, int b, int *stat);
extern int func_00114E90(int fd);
int func_0033F608(void)
{
    int stat;
    if (D_004928EC == 1) {
        if (func_00114C88(D_004928E8, 0, 0, &stat) >= 0) {
            stat = func_00114E90(D_004928E8);
            if (stat >= 0) {
                D_004928EC = 0;
                stat = 0;
            }
        }
    }
    return stat;
}
/* merge_units: end func_0033F608 */
