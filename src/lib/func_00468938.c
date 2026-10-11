extern void *memset(void *, int, unsigned int);
extern char D_00497CD0[];
extern short D_00497CC0;
extern int D_00497CC4;
extern void func_00468CD0(void);
extern int func_002E9648(void);
int func_00468938(void)
{
    memset(D_00497CD0, 0, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 >= 0) func_00468CD0();
    if (func_002E9648()) return -4;
    D_00497CC0 = 0;
    return 0;
}
