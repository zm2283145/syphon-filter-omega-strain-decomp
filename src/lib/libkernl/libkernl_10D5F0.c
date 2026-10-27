/*
 * lib/libkernl: 4 files, 0010D5F0-0010D7A8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0010D5F0 */
#define R(a) (*(volatile unsigned int *)(a))
extern int DIntr(void);
extern void EIntr(void);
void VSync(void)
{
    int s = DIntr();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) EIntr();
    while (!(R(0x1000F000) & 4))
        ;
    s = DIntr();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) EIntr();
}
/* merge_units: end func_0010D5F0 */

/* merge_units: begin func_0010D680 */
extern void SetVSyncFlag(volatile int *, volatile long *);
long VSync2(void)
{
    volatile int flag;
    volatile long ret;
    int s;
    flag = 0;
    SetVSyncFlag(&flag, &ret);
    s = DIntr();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) EIntr();
    while (!(R(0x1000F000) & 4) && !flag)
        ;
    s = DIntr();
    R(0x1000F000) = 4;
    __asm__ __volatile__("sync");
    if (s) EIntr();
    return ret;
}
/* merge_units: end func_0010D680 */

/* merge_units: begin func_0010D728 */
extern int D_00486190;
extern int sceTtyInit(void);
extern int sceTtyWrite(int, int);
int Libc_Write(int mode, int a, int b)
{
    if (mode == 1 || mode == 2) {
        if (!D_00486190) {
            if (!sceTtyInit())
                return -1;
            D_00486190 = 1;
        }
        return sceTtyWrite(a, b);
    }
    return -1;
}
/* merge_units: end func_0010D728 */

/* merge_units: begin func_0010D7A8 */
extern int sceTtyRead(int, int);
int Libc_Read(int mode, int a, int b)
{
    if (mode == 0) {
        if (!D_00486190) {
            if (!sceTtyInit())
                return -1;
            D_00486190 = 1;
        }
        return sceTtyRead(a, b);
    }
    return -1;
}
/* merge_units: end func_0010D7A8 */
