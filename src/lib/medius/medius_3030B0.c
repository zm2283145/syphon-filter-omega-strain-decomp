typedef enum { E0 } Ty30B0;
typedef struct { Ty30B0 type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;

extern void func_00304578(UpnpObj *o, int *a, int *b);
int func_003030B0(UpnpObj *o, int *out)
{
    int l0 = 0;
    int l4 = -2;
    UpnpEnt *e;
    int ret = 2;
    if (out == 0) return ret;
    *out = -2;
    if (o == 0) return ret;
    func_00304578(o, &l0, &l4);
    if (l0 == 0) {
        e = o->ent;
        e->type = 7;
        e->f4 = -1;
        e->f8 = -1;
        *out = 0;
        return 0;
    }
    return 9;
}
