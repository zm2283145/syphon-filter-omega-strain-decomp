typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; int h180; UpnpEnt *ent; int count; int f18C; int f190;
} UpnpObj;
typedef struct { char pad[0x40]; char a[16]; char b[16]; unsigned short pa; unsigned short pb; } UpnpInfo;
typedef struct { char addr[16]; unsigned short port; int peer; } UpnpAddr;
extern int func_00304578(UpnpObj *o, int *type, int *idx);
extern int func_003043E8(UpnpObj *o, UpnpInfo *info, int *idx);
extern int func_00304618(UpnpObj *o, int *idx);
extern void func_002F84D0(int a, int peer, UpnpInfo *info);
extern int func_002F7D68(int a);
extern int func_002F7ED8(int a, int peer);
extern void func_002F9728(void *buf);
extern int func_002F8C50(int a, int peer, void *buf);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_003083E8(int h, UpnpAddr *a, int *out);
int func_00303130(UpnpObj *o, UpnpInfo *info)
{
    UpnpAddr s;
    char buf[64];
    int state = 0;
    int idx = -2;
    int r;
    UpnpEnt *e;
    int rv = 2;

    if (o != 0 && info != 0) {
        func_00304578(o, &state, &idx);
        if (state == 7) {
            idx = -2;
            rv = func_003043E8(o, info, &idx);
            if (rv == 0) {
                if (idx == -2) {
                    rv = func_00304618(o, &idx);
                    if (rv == 0) {
                        rv = 10;
                        if (idx != -2) {
                            e = &o->ent[idx];
                            func_002F84D0(-1, idx, info);
                            e->f24 = func_002F7ED8(func_002F7D68(-1), idx);
                            func_002F9728(buf);
                            func_002F8C50(-1, idx, buf);
                            s.peer = idx;
                            if (String_CompareN(info->a, info->b, 16) == 0 && info->pa == info->pb) {
                                info->a[0] = 0;
                                info->pa = 0;
                            }
                            if (info->a[0] != 0 && info->pa != 0) {
                                strncpy(s.addr, info->a, 16);
                                s.port = info->pa;
                                r = func_003083E8(o->h180, &s, &e->f4);
                                if (r != 0x15) {
                                    if (r != 0) { rv = 7; goto out; }
                                    e->type = 2;
                                }
                            }
                            if (info->b[0] != 0 && info->pb != 0) {
                                strncpy(s.addr, info->b, 16);
                                s.port = info->pb;
                                r = func_003083E8(o->h180, &s, &e->f8);
                                if (r != 0x15) {
                                    if (r != 0) { rv = 7; goto out; }
                                    e->type = 2;
                                }
                            }
                            rv = 0;
                        }
                    }
                } else {
                    rv = 9;
                }
            }
        } else {
            rv = 0;
        }
    }
out:
    return rv;
}