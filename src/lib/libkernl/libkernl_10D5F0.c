/*
 * lib/libkernl: 4 files, 0010D5F0-0010D7A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010D5F0 */
#define R(a) (*(volatile unsigned int *)(a))
extern int func_001161A0(void);
extern void func_001161F8(void);
void func_0010D5F0(void)
{
    int s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    while (!(R(0x1000F000) & 4))
        ;
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
}
/* merge_units: end func_0010D5F0 */

/* merge_units: begin func_0010D680 */
extern void func_0010D4D0(volatile int *, volatile long *);
long func_0010D680(void)
{
    volatile int flag;
    volatile long ret;
    int s;
    flag = 0;
    func_0010D4D0(&flag, &ret);
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    while (!(R(0x1000F000) & 4) && !flag)
        ;
    s = func_001161A0();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) func_001161F8();
    return ret;
}
/* merge_units: end func_0010D680 */

/* merge_units: begin func_0010D728 */
extern int D_00486190;
extern int func_0010E970(void);
extern int func_0010E728(int, int);
int func_0010D728(int mode, int a, int b)
{
    if (mode == 1 || mode == 2) {
        if (!D_00486190) {
            if (!func_0010E970())
                return -1;
            D_00486190 = 1;
        }
        return func_0010E728(a, b);
    }
    return -1;
}
/* merge_units: end func_0010D728 */

/* merge_units: begin func_0010D7A8 */
extern int func_0010E8A0(int, int);
int func_0010D7A8(int mode, int a, int b)
{
    if (mode == 0) {
        if (!D_00486190) {
            if (!func_0010E970())
                return -1;
            D_00486190 = 1;
        }
        return func_0010E8A0(a, b);
    }
    return -1;
}
/* merge_units: end func_0010D7A8 */
