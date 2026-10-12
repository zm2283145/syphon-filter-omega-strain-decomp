typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;

int func_00304578(UpnpObj *o, int *type, int *idx)
{
    int i;
    int t;
    if (type == 0) return 2;
    *type = 0;
    if (idx == 0) return 2;
    *idx = -2;
    if (o == 0) return 2;

    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 6) { *type = o->ent[i].type; *idx = i; break; }
        if (o->ent[i].type == 7 || o->ent[i].type == 5) { *type = o->ent[i].type; *idx = i; break; }
    }
    return 0;
}
