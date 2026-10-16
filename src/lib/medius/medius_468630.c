/*
 * lib/medius: 2 files, 00468630-00468708
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00468630 */
extern short D_00497CC0;
extern int D_00497D60, D_00497D70, D_00497CF4, D_00497DC4, D_00497CC8, D_00497CCC;
extern void func_00467DD0(int);
extern void func_002EBC48(int *);
extern int func_0046E790(void);
int func_00468630(int *cfg, int *out)
{
    if (D_00497CC0 == 1) {
        *out = -1;
        return -0x13;
    }
    func_00467DD0(0);
    D_00497D60 = cfg[0];
    D_00497D70 = cfg[1];
    D_00497CF4 = cfg[2];
    D_00497DC4 = cfg[3];
    D_00497CC8 = cfg[4];
    func_002EBC48(&D_00497CCC);
    if (func_0046E790()) {
        *out = -1;
        return -1;
    }
    D_00497CC0 = 1;
    *out = 0;
    return 0;
}
/* merge_units: end func_00468630 */

/* merge_units: begin func_00468708 */
typedef struct { char c[0x26]; } M00468708;
static const M00468708 months_init = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
extern int sprintf(char *, const char *, ...);
extern char *strstr(const char *, const char *);
extern int atoi(const char *);
int func_00468708(char *out)
{
    M00468708 months = months_init;
    char mon[16];
    int n;
    char *date = "Nov 25 2003";
    char *tm = "16:13:50";
    sprintf(mon, "%.3s", date);
    n = (strstr(months.c, mon) - months.c) / 3 + 1;
    sprintf(out, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", n, atoi(date + 4), date + 7, tm, tm + 3, tm + 6);
    return 0;
}
/* merge_units: end func_00468708 */
