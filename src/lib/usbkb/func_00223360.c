extern int D_0048AB18;
extern char D_004F5820[];
extern void func_0010D1A0(int);
extern void func_0010D180(int);
extern int func_00223410(void);
extern int func_00110720(void *);
int func_00223360(int mode, int *out)
{
    if (D_0048AB18 == -1) return -1;
    switch (mode) {
    case 0:
        func_0010D1A0(D_0048AB18);
        *out = func_00223410();
        func_0010D180(D_0048AB18);
        return 0;
    case 1:
        if (func_00110720(D_004F5820) == 0) {
            *out = func_00223410();
            return 0;
        }
        return 1;
    }
    return -11;
}