typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct { UpnpSlot slot[32]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern void *memset(void *, int, unsigned int);
extern int func_00307928(int h, int key);
extern int func_00308380(int h, int key);

int func_00303598(UpnpObj *o)
{
    UpnpEnt *e;
    int i;
    if (o == 0) return 2;    e = o->ent;
    for (i = 0; i < o->count; i++, e++) {
        if (e->f4 != -1) func_00307928(o->h180, e->f4);
        if (e->f8 != -1) func_00307928(o->h180, e->f8);
        memset(&o->ent[i], 0, sizeof(UpnpEnt));
        e->f4 = e->f8 = -1;
    }
    for (i = 0; i < 32; i++) {
        if (o->slot[i].h != -1) {
            func_00308380(o->h180, o->slot[i].h);
            o->slot[i].h = -1;
        }
    }
    return 0;
}

