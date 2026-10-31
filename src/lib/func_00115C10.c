typedef struct {
    unsigned PageMask, EntryHi, EntryLo0, EntryLo1;
} TLBEntry;

typedef struct {
    int NumKernel, NumDefault, NumExtended, NumWired;
    TLBEntry *kernelTLB, *defaultTLB, *extendedTLB;
} TLBInfo;

extern TLBInfo D_00486898;
extern char D_00498BB0[], D_00498BE8[], D_00498C00[], D_00498C18[];
extern int kprintf(const char *, ...);
extern void Exit_2(int);
extern int _SetTLBEntry(int, unsigned, unsigned, unsigned, unsigned);

int InitTLB32MB(void)
{
    /* SDK kernel code keeps the TLB index in t9 across the syscall stubs (retail does too) */
    register int i asm("$25");
    int n;
    TLBEntry *e;

    kprintf(D_00498BB0, D_00486898.NumKernel - 1, D_00486898.NumKernel,
            D_00486898.NumKernel + D_00486898.NumDefault - 1,
            D_00486898.NumKernel + D_00486898.NumDefault,
            D_00486898.NumKernel + D_00486898.NumDefault + D_00486898.NumExtended - 1);
    /* COP0 Wired register write */
    __asm__ volatile("mtc0 $0, $6\n\tsync.p");
    n = D_00486898.NumKernel;
    i = 0;
    if (n > 0x30) {
        kprintf(D_00498BE8);
        Exit_2(1);
    }
    e = D_00486898.kernelTLB;
    for (; i < n; i++, e++)
        _SetTLBEntry(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    n = i + D_00486898.NumDefault;
    if (n > 0x30) {
        kprintf(D_00498C00);
        Exit_2(1);
    }
    e = D_00486898.defaultTLB;
    for (; i < n; i++, e++)
        _SetTLBEntry(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    D_00486898.NumWired = i;
    /* COP0 Wired register write */
    __asm__ volatile("mtc0 %0, $6\n\tsync.p" :: "r"(i));
    if (D_00486898.NumExtended > 0) {
        n = i + D_00486898.NumExtended;
        if (n > 0x30) {
            kprintf(D_00498C18);
            Exit_2(1);
        }
        e = D_00486898.extendedTLB;
        for (; i < n; i++, e++)
            _SetTLBEntry(i, e->PageMask, e->EntryHi, e->EntryLo0, e->EntryLo1);
    }
    {
        int j;
        for (j = i; j < 0x30; j++)
            _SetTLBEntry(j, 0, 0xE0000000 + (j << 13), 0, 0);
    }
    return i;
}