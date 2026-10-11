typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern void func_002F94D0(int a);
extern void func_002F95F8(int a);
extern void func_00306F98(int h);
extern int func_002FB3C0(void *pp);
int func_003028E8(UpnpObj *o)
{
    UpnpObj *h = 0;
    int ret = 2;
    if (o == 0) return ret;
    h = o;
    func_002F94D0(-1);
    func_002F95F8(-1);
    func_00306F98(h->h180);
    if (h->f190) func_002FB3C0(&h->f190);
    if (h->ent) func_002FB3C0(&h->ent);
    func_002FB3C0(&h);
    return 0;
}