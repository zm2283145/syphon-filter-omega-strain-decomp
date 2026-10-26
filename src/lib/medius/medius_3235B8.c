typedef struct { char pad[0x30]; int f30; int f34; } Obj3235B8;
typedef int (*CopyFn3235B8)(void* dst, void* src, int n);
extern CopyFn3235B8 D_004E1D40;
extern int VU0CheckStores(Obj3235B8* o);
int VU0Restore(Obj3235B8* o)
{
    int r = VU0CheckStores(o);
    if (r == 0) {
        D_004E1D40((void*)0x11000000, (void*)o->f30, 0x1000);
        D_004E1D40((void*)0x11004000, (void*)o->f34, 0x1000);
    }
    return r;
}