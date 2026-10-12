typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern void *memset(void *, int, unsigned int);

int func_00304618(UpnpObj *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 0) {
            *out = i;
            memset(&o->ent[i], 0, sizeof(UpnpEnt));
            o->ent[i].f8 = o->ent[i].f4 = -1;
            break;
        }
    }
    return 0;
}

