extern char D_004B0DE0[], D_004B0E18[], D_004B0F28[], D_004B0F38[];
extern void func_00127358(const char *fmt, const char *file, int line, const char *msg);
extern int func_00312E28(void *p);
extern int func_002FB3C0(void *pp);
int func_00310F08(void *p)
{
    if (p == 0) {
        func_00127358(D_004B0DE0, D_004B0E18, 0x116, D_004B0F28);
        return 3;
    }
    if (func_00312E28(p) != 0) func_00127358(D_004B0DE0, D_004B0E18, 0x11A, D_004B0F38);
    func_002FB3C0(&p);
    return 0;
}