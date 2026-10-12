typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;

int func_00302B88(UpnpObj *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 4) { *out = i; break; }
        if (o->ent[i].type == 7) { *out = i; break; }
    }
    return 0;
}
