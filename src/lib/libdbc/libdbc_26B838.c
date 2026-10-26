typedef struct { int f0; int f4; int f8; int fc; char pad[0x334 - 0x10]; } E26B838;
extern E26B838 D_004FBB88[];
extern int sceDbcGetDepNumber(int port);
int scePad2LinkDriver(int port)
{
    int n = sceDbcGetDepNumber(port);
    if (n < 0) return n;
    D_004FBB88[port].fc = n;
    D_004FBB88[port].f4 = 1;
    return n;
}