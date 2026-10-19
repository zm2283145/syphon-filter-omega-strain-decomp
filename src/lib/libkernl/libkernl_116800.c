extern int LoadExecPS2(int, int, char*);
extern int func_00116670(void);
extern void func_00116788(void);
extern char *D_004865E0;
void func_00116800(int d0, int arg1)
{
    int s0 = func_00116670();
    func_00116788();
    LoadExecPS2(s0, arg1, D_004865E0 + 4);
}