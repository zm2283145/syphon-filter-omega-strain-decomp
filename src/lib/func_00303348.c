typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; int h180; UpnpEnt *ent; int count; int f18C; int f190; int f194; void *cb198;
} UpnpObj;
typedef struct { char pad[0x40]; char a[16]; char b[16]; unsigned short pa; unsigned short pb; } UpnpInfo;
typedef struct { char addr[16]; unsigned short port; int peer; } UpnpAddr;
extern int func_00304578(UpnpObj *o, int *type, int *idx);
extern void func_002F84D0(int a, int peer, UpnpInfo *info);
extern int func_002F7D68(int a);
extern int func_002F7ED8(int a, int peer);
extern void func_002F9728(void *buf);
extern int func_002F8C50(int a, int peer, void *buf);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern void *memset(void *d, int c, unsigned int n);
extern int func_003076E0(int h, UpnpAddr *a, int *out);
int func_00303348(UpnpObj *o, UpnpInfo *info, void *cb)
{
    UpnpAddr sa;
    UpnpAddr sb;
    char buf[64];
    int state = 0;
    int idx = -2;
    int r;
    UpnpEnt *e;
    int rv = 2;

    if (o != 0 && info != 0 && cb != 0) {
    func_00304578(o, &state, &idx);
    if (state != 0)
        return 9;
    e = o->ent;
    memset(e, 0, sizeof(UpnpEnt));
    e->f8 = e->f4 = -1;
    func_002F84D0(-1, 0, info);
    e->f24 = func_002F7ED8(func_002F7D68(-1), 0);
    func_002F9728(buf);
    func_002F8C50(-1, 0, buf);
    if (String_CompareN(info->a, info->b, 16) == 0 && info->pa == info->pb) {
        info->a[0] = 0;
        info->pa = 0;
    }
    if (info->b[0] != 0 && info->pb != 0) {
        memset(&sb, 0, sizeof(sb));
        strncpy(sb.addr, info->b, 16);
        sb.port = info->pb;
        sb.peer = 0;
        r = func_003076E0(o->h180, &sb, &e->f8);
        if (r != 0x15) {
            if (r != 0)
                return 7;
            if (e->f8 == -1)
                return 7;
            e->type = 1;
        }
    }
    if (info->a[0] != 0 && info->pa != 0) {
        memset(&sa, 0, sizeof(sa));
        strncpy(sa.addr, info->a, 16);
        sa.port = info->pa;
        sa.peer = 0;
        r = func_003076E0(o->h180, &sa, &e->f4);
        if (r != 0x15) {
            if (r != 0)
                return 7;
            if (e->f4 == -1)
                return 7;
            e->type = 1;
        }
    }
    if (e->type != 1)
        return 7;
    o->cb198 = cb;
    rv = 0;
    }
    return rv;
}
