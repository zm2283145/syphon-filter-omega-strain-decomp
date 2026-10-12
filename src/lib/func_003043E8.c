typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { char pad[0x40]; char a40[16]; char a50[16]; unsigned short p60; unsigned short p62; } UpnpAddr;
extern int func_00302A38(UpnpObj *o, int peer, int mode, char *addr, unsigned short *port);
extern int String_CompareN(const char *, const char *, unsigned int);

int func_003043E8(UpnpObj *o, UpnpAddr *a, int *out)
{
    char addr[16];
    unsigned short port;
    int i;
    int match;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;
    if (a == 0) return 2;    for (i = 0; i < o->count; i++) {
        match = 0;
        func_00302A38(o, i, 0, addr, &port);
        String_CompareN(addr, a->a40, 16);
        func_00302A38(o, i, 1, addr, &port);
        if (String_CompareN(addr, a->a50, 16) == 0) match = (port == a->p62);
        if (match) { *out = i; break; }
    }
    return 0;
}
