typedef struct { char pad[0x10]; int herr; char x14[0x40]; int x54; } TS;
typedef struct { char *h_name; char **h_aliases; int h_addrtype; int h_length; char **h_addr_list; } HE;
extern TS *thread_enter(int);
extern void unblock(void);
extern int sceInetName2Address(void *, int, int, void *, const char *, int, int);
extern int func_00358158(void);
extern int thread_leave(TS *, int);
extern int conv_errno(int);
extern void conv_addr_from_inet(void *, void *);
extern HE D_00533700;
extern char *D_00492CF0[];
extern char *D_00492CF8[];
extern char D_005335F8[];

HE *sceInsockGethostbyname(const char *name)
{
    TS *s;
    HE *h = &D_00533700;
    int r;
    char addr[16];
    s = thread_enter(0);
    if (s == 0) return 0;
    s->herr = 0;
    unblock();
    r = sceInetName2Address(s->x14, s->x54, 0x41, addr, name, 0, 0);
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
    h->h_name = 0;
    h->h_aliases = D_00492CF0;
    h->h_addrtype = 2;
    h->h_length = 4;
    conv_addr_from_inet(D_005335F8, addr);
    s->herr = 0;
    D_00492CF8[0] = D_005335F8;
    h->h_addr_list = D_00492CF8;
    thread_leave(s, 0);
    return h;
}