typedef struct { char pad[0x30]; int f30; int f34; } Obj323550;
typedef int (*CopyFn323550)(void* dst, void* src, int n);
extern CopyFn323550  D_004E1D40;
extern int func_00323620(Obj323550* o);
int func_00323550(Obj323550* o)
{
    int r = func_00323620(o);
    if (r == 0) {
        D_004E1D40((void*)o->f30, (void*)0x11000000, 0x1000);
        D_004E1D40((void*)o->f34, (void*)0x11004000, 0x1000);
    }
    return r;
}