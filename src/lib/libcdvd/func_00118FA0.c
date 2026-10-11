extern volatile int D_00487890;
extern char D_00498D20[];
extern char D_00489400[];
extern int func_0010F388(const char *, ...);
extern int func_00110720(void *);
extern void func_0010E1C0(int);

int func_00118FA0(int mode)
{
    if (mode == 0) {
        if (D_00487890 > 0) func_0010F388(D_00498D20);
        while (func_00110720(D_00489400)) func_0010E1C0(0xFA0);
        return 0;
    }
    return func_00110720(D_00489400);
}