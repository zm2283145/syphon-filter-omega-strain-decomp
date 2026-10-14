typedef struct { int f0; int f4; int f8; int fc; char pad[0x334 - 0x10]; } E26B3A0;
extern E26B3A0 D_004FBB88[];
extern int sceDbcDeleteSocket(int port);
int func_0026B3A0(int port)
{
    int r = sceDbcDeleteSocket(port);
    if (r >= 0) {
        int off = port * sizeof(E26B3A0);
        ((E26B3A0*)(off + (int)D_004FBB88))->f0 = 0;
        D_004FBB88[port].f4 = 0;
        D_004FBB88[port].fc = 0;
        return 1;
    }
    return r;
}