/*
 * lib/medius: 4 files, 0046AE58-0046AF38
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0046AE58 */
int D_00497E34 = 0;
extern int Medius_TerminateString(char *, int);
extern int func_00470120(char *, int, int, char *);
int func_0046AE58(char *a, int b, char *c)
{
    Medius_TerminateString(a, 0x11);
    Medius_TerminateString(c, 0x15);
    func_00470120(a, D_00497E34, b, c);
    if (D_00497E34 >= 0x3E7) D_00497E34 = 0;
    else D_00497E34 = D_00497E34 + 1;
    return 0;
}
/* merge_units: end func_0046AE58 */

/* merge_units: begin func_0046AEE8 */
extern short D_00497CC0;
extern int D_00497D60;
int func_0046AEE8(int a)
{
    if (D_00497CC0 != 1)
        return -15;
    D_00497D60 = a;
    return 0;
}
/* merge_units: end func_0046AEE8 */

/* merge_units: begin func_0046AF10 */
extern int D_00497D70;
int func_0046AF10(int a)
{
    if (D_00497CC0 != 1)
        return -15;
    D_00497D70 = a;
    return 0;
}
/* merge_units: end func_0046AF10 */

/* merge_units: begin func_0046AF38 */
extern int D_00497CF4;
int func_0046AF38(int a)
{
    if (D_00497CC0 != 1)
        return -15;
    D_00497CF4 = a;
    return 0;
}
/* merge_units: end func_0046AF38 */
