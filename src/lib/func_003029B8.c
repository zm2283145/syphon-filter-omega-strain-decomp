typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
int func_003029B8(UpnpObj *o, int idx, int *out)
{
    UpnpEnt *e;
    int ret = 2;
    if (out == 0) return ret;
    *out = -1;
    if (o == 0) return ret;
    if (idx < 0 || idx >= o->count) return 8;
    if (o->ent[idx].f4 != -1) *out = 0;
    else if (o->ent[idx].f8 != -1) *out = 1;
    return 0;
}