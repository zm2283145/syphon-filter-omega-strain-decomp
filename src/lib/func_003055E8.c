typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct { UpnpSlot slot[32]; int h180; } UpnpObj;
typedef struct { int f0; char a[16]; char b[16]; unsigned short pa; unsigned short pb; int f28; } PeerInfo;
typedef struct { int type; int f4; int f8; char pad[6]; char name[16]; unsigned short port; } PeerOut;
extern int func_00307598(int h, int ep, char *addr, unsigned short *port);
extern int func_003079E0(int h, int ep, int val);
extern void func_002F9728(void *buf);
extern int func_002F8C50(int a, int peer, void *buf);
extern int func_00308278(int h, int ep);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);

int func_003055E8(UpnpObj *o, PeerInfo *in, PeerOut *out)
{
    char addr[16];
    unsigned short port;
    unsigned int i;
    if (o == 0) return 0;
    if (in == 0) return 0;
    i = 0;
    do {
        if (o->slot[i].h == -1) continue;
        if (func_00307598(o->h180, o->slot[i].h, addr, &port) != 0) break;
        if (String_CompareN(addr, in->a, 16) == 0 && port == in->pa && port != 0) {
            char buf[64];
            func_003079E0(o->h180, o->slot[i].h, in->f28);
            func_002F9728(buf);
            func_002F8C50(-1, in->f28, buf);
            func_00308278(o->h180, o->slot[i].h);
            strncpy(out->name, in->b, 16);
            out->port = in->pb;
            out->f4 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
        if (String_CompareN(addr, in->b, 16) == 0 && port == in->pb && port != 0) {
            char buf[64];
            func_003079E0(o->h180, o->slot[i].h, in->f28);
            func_002F9728(buf);
            func_002F8C50(-1, in->f28, buf);
            func_00308278(o->h180, o->slot[i].h);
            strncpy(out->name, in->a, 16);
            out->port = in->pa;
            out->f8 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
    } while (++i < 32);
    return 0;
}



