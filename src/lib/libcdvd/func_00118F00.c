extern volatile int D_00487890;
extern volatile int D_004878B4;
extern char D_00488A50[];
extern int func_0010F388(const char *, ...);
extern int func_00110720(void *);
extern void func_0010E1C0(int);

int func_00118F00(int mode)
{
    if (mode == 0) {
        if (D_00487890 > 0) func_0010F388("N cmd wait
");
        while (D_004878B4 || func_00110720(D_00488A50)) func_0010E1C0(0xFA0);
        return 0;
    }
    if (D_004878B4 || func_00110720(D_00488A50)) return 1;
    return 0;
}