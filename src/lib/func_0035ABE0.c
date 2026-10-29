typedef struct { char pad[0x10]; int herr; char x14[0x40]; int x54; } TS;
typedef struct { char *h_name; char **h_aliases; int h_addrtype; int h_length; char **h_addr_list; } HE;
extern TS *thread_enter(int);
extern void unblock(void);
extern int sceInetAddress2Name(void *, int, int, char *, int, void *, int, int);
extern int func_00358158(void);
extern int thread_leave(TS *, int);
extern int conv_errno(int);
extern void conv_addr_to_inet(void *, const char *);
extern void Libc_Bcopy(const void *, void *, int);
extern HE D_00533700;
extern char *D_00492CF0[];
extern char *D_00492CF8[];
extern char D_005335F8[];
extern char D_00533600[];

HE *sceInsockGethostbyaddr(const char *addr, int len, int type)
{
    TS *s;
    HE *h = &D_00533700;
    int r;
    int herr;
    char ia[16];
    s = thread_enter(0);
    if (s == 0) return 0;
    if (type != 2) {
        s->herr = -1;
        thread_leave(s, 0x6A);
        return 0;
    }
    if (len != 4) {
        s->herr = -1;
        thread_leave(s, 0x16);
        return 0;
    }
    s->herr = 0;
    unblock();
    conv_addr_to_inet(ia, addr);
    r = sceInetAddress2Name(s->x14, s->x54, 0x40, D_00533600, 0x100, ia, 0, 0);
    if (func_00358158() < 0) {
        s->herr = -1;
        thread_leave(s, -1);
        return 0;
    }
    if (r < 0) {
        if (r == -500 || r == -515) {
            s->herr = 1;
            thread_leave(s, 0);
        } else if (r == -516) {
            s->herr = 2;
            thread_leave(s, 0);
        } else if (r == -517) {
            s->herr = 3;
            thread_leave(s, 0);
        } else if (r == -518) {
            s->herr = 4;
            thread_leave(s, 0);
        } else {
            s->herr = -1;
            thread_leave(s, conv_errno(r));
        }
        return 0;
    }
    h->h_name = D_00533600;
    h->h_aliases = D_00492CF0;
    h->h_addrtype = type;
    h->h_length = len;
    Libc_Bcopy(addr, D_005335F8, 4);
    s->herr = 0;
    D_00492CF8[0] = D_005335F8;
    h->h_addr_list = D_00492CF8;
    thread_leave(s, 0);
    return h;
}