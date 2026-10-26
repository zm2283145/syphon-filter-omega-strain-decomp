typedef struct { int id; int addr; int a; int b; } Res4028;
typedef struct {
    char pad[0xA4];
    int sock;
    char pad3[0x208 - 0xA8];
    unsigned char state;
    char pad4[0x218 - 0x209];
    Res4028 res;
} Obj4028;
extern short D_00491432;
extern unsigned char D_00491430;
extern int NetIsValidClientIndex(int addr);
extern int NetStreamMediaGetValidInfo(int id, Obj4028 **out);
extern int NetGetClientInfo(int id, int addr, int *out);
extern int rt_audio_enum_players(int sock, int (*cb)(), int arg);
extern int NetStreamMediaEnumClientCallback();
int NetIStreamMediaGetClientInfo(int id, int addr, Res4028 *out)
{
    Obj4028 *o;
    int h;
    int ok;
    int t;
    int r;
    h = 0;
    if (out == 0) return 0x17;
    out->id = id;
    out->addr = addr;
    out->a = 0;
    out->b = 0;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    t = NetIsValidClientIndex(addr);
    if (t != ok) return 0x17;
    r = NetStreamMediaGetValidInfo(id, &o);
    if (r != 0) return r;
    if (NetGetClientInfo(id, addr, &h) == 0) {
        if (h != 0) {
            o->state = t;
            o->res = *out;
            if (rt_audio_enum_players(o->sock, NetStreamMediaEnumClientCallback, 0) == 0) {
                if (o->state == 0) {
                    *out = o->res;
                }
            }
            o->state = 0;
        }
    }
    return 0;
}
