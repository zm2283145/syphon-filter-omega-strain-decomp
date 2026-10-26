typedef struct { int handle; int a; int b; int result; int user; } Req5A28;
typedef struct Obj5A28 {
    char pad0[9];
    unsigned char state;
    char pad1[0x3C - 10];
    void (*cb)(Req5A28 *);
    int user;
    char pad2[0xA9 - 0x44];
    unsigned char mode;
} Obj5A28;
extern int NetStreamMediaFindValidInfo(int id, Obj5A28 **out);
extern int NetStreamMediaAudioTypeToMediaFormat(int handle, int dst);
int NetStreamMediaRecordCallback(int id, int dst, int a, int b)
{
    Obj5A28 *o = 0;
    Req5A28 r;
    if (a == 0) return 0;
    if (dst == 0) return 0;
    if (NetStreamMediaFindValidInfo(id, &o) != 0) return 0;
    r.handle = 0;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        int u = o->user;
        r.a = a;
        r.b = b;
        r.user = u;
        o->cb(&r);
    }
    if (NetStreamMediaAudioTypeToMediaFormat(r.handle, dst) != 0) return 0;
    return r.result;
}
