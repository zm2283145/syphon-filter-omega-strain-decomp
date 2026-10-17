typedef struct { int type; int f4; int f8; char pad[6]; char name[0x10]; unsigned short port; char pad2[4]; } UpnpEnt;
typedef struct { char pad[0x180]; void *h180; UpnpEnt *ent; } UpnpObj;
extern int func_00307598(void *h, int key, char *name, unsigned short *port);
extern int func_00304508(UpnpObj *o, int key, int *out);
extern void func_00307928(void *h, int key);
extern void func_00305268(UpnpObj *o, int key, int c);
extern char *strncpy(char *, const char *, unsigned int);

void func_003041B0(UpnpObj *o, int key, int c)
{
    char name[0x10];
    unsigned short port;
    int idx;

    idx = -2;
    if (func_00307598(o->h180, key, name, &port) != 0)
        return;
    if (func_00304508(o, key, &idx) != 0 || idx == -2) {
        func_00307928(o->h180, key);
        return;
    }
    if (key == o->ent[idx].f4) {
        strncpy(o->ent[idx].name, name, 0x10);
        o->ent[idx].port = port;
        if (o->ent[idx].f8 == -1) {
            func_00305268(o, key, c);
        } else {
            func_00307928(o->h180, key);
            o->ent[idx].f4 = -1;
        }
    } else if (key == o->ent[idx].f8) {
        strncpy(o->ent[idx].name, name, 0x10);
        o->ent[idx].port = port;
        if (o->ent[idx].f4 == -1) {
            func_00305268(o, key, c);
        } else {
            func_00307928(o->h180, key);
            o->ent[idx].f8 = -1;
        }
    }
}