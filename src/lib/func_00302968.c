typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; char pad2[0x1C]; int f1B0; } UpnpObj;

extern int func_00307328(int h, int a, int b);
int func_00302968(UpnpObj *o, int a, int x)
{
    int ret = 2;
    if (o == 0) return ret;
    if (x == 0) return ret;
    if (func_00307328(o->h180, a, x) != 0) return 5;
    o->f1B0 = x;
    return 0;
}