typedef struct { char pad[0x24]; void* serve; char pad2[0x14]; } Cd27C410;
extern Cd27C410 D_00504080;
extern int D_005040C0[];
extern int func_0027D1D0(int *p, int a1, int a2, int mode);
extern int func_0027C3D0(void);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_0027D278(int, int);
extern int ChangeThreadPriority(int, int);
int func_0027C410(int *p, int a1, int a2, int a3)
{
    int fd, r;
    register int saved_arg asm("$5");
    if (!p) return -101;
    fd = func_0027D1D0(p, a1, a2, 1);
    if (fd < 0) return -1;
    func_0027C3D0();
    D_005040C0[2] = *p;
    r = sceSifCallRpc(&D_00504080, 0xB, 0, D_005040C0, 0x1000, D_005040C0, 0x1000, 0, 0);
    saved_arg = a3;
    if (r < 0) {
        func_0027D278(fd, saved_arg);
        return r;
    }
    ChangeThreadPriority(fd, saved_arg);
    return fd;
}
/* Keep the shared second call argument in a1 across the final branch. */
