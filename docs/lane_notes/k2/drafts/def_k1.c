typedef struct E { char pad0[0x14]; int state; char pad18[0x10]; unsigned char kind; } E;
typedef struct CbMsg { int a0; int a1; E *e; int state; int x10; int arg; } CbMsg;
typedef struct G { char pad0[0x400]; int nid; char pad404[0x2C]; int cb; int arg; char pad438[8]; int cnt; } G;
extern int NetGetConnInfo(int, G **);
extern int NetGetClientInfo(int, int, E **);
extern void NetClientLeaves(int, int);
extern int NetStreamMediaIsEnabledOnConnection(int);
extern int NetStreamMediaRemoteClientDisconnects(int, int);
extern void RemoteClientDisconnects();
extern void ElectSessionMaster(int, int, int, int);
extern void *memset(void *, int, unsigned int);

int RemoteClientDisconnectEvent(int input0, int a1)
{
    register int a0 asm("$17") = input0;
    CbMsg m;
    G *g = 0;
    E *e = 0;
    int nid;
    int r;

    if (a1 < 0 && a0 >= 0x100) return 0x17;
    r = NetGetConnInfo(a0, &g);
    if (r != 0) return r;
    if (g == 0) return r;
    r = NetGetClientInfo(a0, a1, &e);
    if (r != 0) return r;
    nid = g->nid;
    if (e == 0) {
        if (g->cnt != 0) g->cnt--;
        r = NetGetClientInfo(a0, nid, &e);
        if (r != 0) return r;
        if (e == 0) return r;
        if (e->state == 3) ElectSessionMaster(a0, 0, 0, 0);
        return 0;
    } else if (e->kind != 0) {
        NetClientLeaves(a0, a1);
        if (nid != 0x100) {
            unsigned char k;
            r = NetGetClientInfo(a0, nid, &e);
            if (r != 0) return r;
            if (g == 0) return r;
            k = e->kind;
            if (k == 1) {
                if (NetStreamMediaIsEnabledOnConnection(a0) == k) NetStreamMediaRemoteClientDisconnects(a0, a1);
                if (g->cb != 0) {
                    r = NetGetClientInfo(a0, a1, &e);
                    if (r != 0) return r;
                    if (g == 0) return r;
                    memset(&m, 0, sizeof(m));
                    { E* entry = e; G* conn = g; int state = entry->state; int arg = conn->arg;
                    m.state = state; m.arg = arg; m.a0 = a0; m.a1 = a1; m.e = entry; }
                    ((void (*)(CbMsg *))g->cb)(&m);
                }
            }
        }
        RemoteClientDisconnects(a0, a1);
        r = NetGetClientInfo(a0, nid, &e);
        if (r != 0) return r;
        if (e == 0) return r;
        { register int state asm("$3"); register int match asm("$2");
        state = e->state; match = 3;
        if (state != match) return 0;
        ElectSessionMaster(a0, 0, 0, 0); return 0; }
    } else {
        if (g->cnt != 0) g->cnt--;
    }
    if (e->state == 3) ElectSessionMaster(a0, 0, 0, 0);
    return 0;
}
