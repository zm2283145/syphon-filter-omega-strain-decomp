typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern int func_00307530(int h, int a, int b);
extern int func_00307488(int h, int a, int b);
int func_00302B28(UpnpObj *o, int mode, int a, int b)
{
    int r;
    int ret = 2;
    if (o == 0) return ret;
    if (mode == 0) {
        if (func_00307530(o->h180, a, b) != 0) return 7;
    } else if (mode == 1) {
        if (func_00307488(o->h180, a, b) != 0) return 7;
    } else return 2;
    return 0;
}