typedef struct { char pad[4]; unsigned int flags; } Ent5CF8;
typedef struct {
    char pad[4];
    int count;
    char pad1[0xA4 - 8];
    int sock;
    unsigned char bA8;
    unsigned char bA9;
    char pad2[2];
    char info[0x3C];
    char addr[0x10];
    int user;
} Obj5CF8;
extern int func_003150D0(int sock, Obj5CF8 **out);
extern void func_002F4E20(int a, char *dst);
extern int func_002F4F90(int sock, int *out);
extern int func_002F4FB0(int sock, int sz, char *info);
extern int func_003151D8(Obj5CF8 *o, int i, Ent5CF8 **out);
extern int func_00315818(Obj5CF8 *o, Ent5CF8 *e);
extern int func_00315E28(int r, int code);
int func_00315CF8(int sock, int a, int user)
{
    Obj5CF8 *o = 0;
    int x;
    Ent5CF8 *e;
    int i, r;
    if (func_003150D0(sock, &o) != 0) return -1;
    {
        Obj5CF8 *p = o;
        p->user = user;
        func_002F4E20(a, p->addr);
    }
    r = func_00315E28(func_002F4F90(o->sock, &x), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, x, o->info), 0x2A);
    if (r != 0) return r;
    o->bA8 = 1;
    o->bA9 = 1;
    for (i = 0; i < o->count; i++) {
        r = func_003151D8(o, i, &e);
        if (r != 0) return r;
        if ((e->flags & 0xFF00FF) == 1) {
            r = func_00315818(o, e);
            if (r != 0) return r;
        }
    }
    return 0;
}
