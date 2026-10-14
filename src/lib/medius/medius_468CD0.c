/*
 * lib/medius: 5 files, 00468CD0-00468F78
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00468CD0 */
extern short D_00497CC0;
extern int D_00497CC4;
extern int func_002EC738(int);
int func_00468CD0(void)
{
    int r;
    if (D_00497CC0 != 1) return -0xF;
    {
        int *pc = &D_00497CC4;
        if (*pc < 0) return -0x10;
        r = func_002EC738(*pc);
        *pc = -1;
    }
    return r ? -3 : 0;
}
/* merge_units: end func_00468CD0 */

/* merge_units: begin func_00468D38 */
extern unsigned int D_00497CC8;
extern int D_00497CCC;
extern signed char D_00497CD0;
extern int D_00497CF0;
extern int func_002EBC48(int *);
extern int func_00468308(void);
extern int func_002EC4F8(void);
int func_00468D38(void)
{
    int t = 0;
    int r, e;
    func_002EBC48(&t);
    if (D_00497CC0 != 1) return -15;
    r = func_00468308();
    if (r != 0) return r;
    if ((unsigned int)(t - D_00497CCC) > D_00497CC8 && D_00497CD0 != 0 && D_00497CC4 >= 0)
        D_00497CCC = t;
    e = func_002EC4F8();
    if (e == 0) return 0;
    D_00497CF0 = e;
    return -10;
}
/* merge_units: end func_00468D38 */

/* merge_units: begin func_00468DD8 */
int D_00497CE4 = 0;
int D_00497CE8 = 0;
int D_00497CEC = 0;
int func_00468DD8(void)
{
    int t = 0;
    int r, e;
    func_002EBC48(&t);
    if (D_00497CC0 != 1) return -15;
    r = func_00468308();
    if (r != 0) return r;
    if ((unsigned int)(t - D_00497CCC) > D_00497CC8 && D_00497CD0 != 0 && D_00497CC4 >= 0)
        D_00497CCC = t;
    e = func_002EC4F8();
    if (D_00497CEC == 1 && D_00497CE4 == D_00497CE8) {
        D_00497CEC = 0;
        D_00497CE4 = 0;
        D_00497CE8 = 0;
        r = func_002EC738(D_00497CC4);
        D_00497CC4 = -1;
        return r != 0 ? -3 : 0;
    }
    if (e == 0) return 0;
    D_00497CF0 = e;
    return -10;
}
/* merge_units: end func_00468DD8 */

/* merge_units: begin func_00468EF0 */
int func_00468EF0(void)
{
    int t = 0;
    int r;
    func_002EBC48(&t);
    if (D_00497CC0 != 1) return -15;
    r = func_00468308();
    if (r != 0) return r;
    if ((unsigned int)(t - D_00497CCC) > D_00497CC8 && D_00497CD0 != 0 && D_00497CC4 >= 0)
        D_00497CCC = t;
    return 0;
}
/* merge_units: end func_00468EF0 */

/* merge_units: begin func_00468F78 */
extern int func_004700F8(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);extern int D_00598638;
int func_00468F78(char *a)
{
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    func_004700F8(a, 0x11);
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598638, 0x18, a) ? -5 : 0;
}
/* merge_units: end func_00468F78 */
