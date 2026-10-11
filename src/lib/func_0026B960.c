typedef struct { int f0; int f4; int f8; int fc; char pad[0x334 - 0x10]; } E26B960;
extern E26B960 D_004FBB88[];
typedef struct { char pad[0x7C]; int f7c; } R26B960;
extern R26B960* func_0026B890(int port);
int func_0026B960(int port)
{
    R26B960* r = func_0026B890(port);
    int v = r->f7c;
    if (v == 0) return 0;
    if (v == D_004FBB88[port].f8) return 0;
    D_004FBB88[port].f8 = v;
    return 1;
}