extern int D_005227E0[4];
typedef struct NetRes { int size; int conn[4]; int p2p; } NetRes;
extern NetRes D_00520340;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;

typedef struct Info {
    char pad[0x438];
    int state;
} Info;

extern void *memset(void *, int, unsigned int);
extern int NetGetConnInfo(int, Info **);
extern unsigned short DmeToRtMsgConnectionIndex(int);
extern int rt_msg_client_update(unsigned short, unsigned char);
extern int NetMapMsgClientError(int, int);
extern int NetStreamMediaIsEnabledOnConnection(int);
extern int NetStreamMediaUpdate(int, unsigned char);
extern int rt_p2p_update(int);
extern int rt_p2p_tick(int);

int NetUpdateAll(unsigned char flag)
{
    Info *info = 0;
    int ret = 0;
    unsigned char i;
    int r;
    int ret2;

    memset(D_005227E0, 0, 0x10);
    memset(&D_00520340, 0, sizeof(NetRes));
    D_00520340.size = sizeof(NetRes);
    for (i = 0; i < 4; i++) {
        r = NetGetConnInfo(i, &info);
        if (r != 0) {
            D_00520340.conn[i] = r;
            ret = r;
            continue;
        }
        if (info == 0) {
            D_00520340.conn[i] = 0;
            continue;
        }
        if (i != 0 && (info->state == 1 || info->state == 2)) {
            r = NetMapMsgClientError(rt_msg_client_update(DmeToRtMsgConnectionIndex(i), flag), 0x18);
            if (r != 0) {
                D_00520340.conn[i] = r;
                ret = r;
                continue;
            }
            if (D_005227E0[i] != 0) {
                D_00520340.conn[i] = 0xC;
                ret = 0xC;
                continue;
            }
        }
        if (NetStreamMediaIsEnabledOnConnection(i) == 1) {
            r = NetStreamMediaUpdate(i, flag);
            if (r != 0) {
                D_00520340.conn[i] = r;
                ret = r;
            }
        }
    }
    if (D_0048C4AC == 1) {
        if (flag)
            r = rt_p2p_update(D_0048C4B0) ? 0x25 : 0;
        else
            r = rt_p2p_tick(D_0048C4B0) ? 0x25 : 0;
        if (r) {
            D_00520340.p2p = r;
            return r;
        }
        if (D_005227E0[0]) {
            D_00520340.conn[0] = 0xC;
            D_00520340.p2p = 0xC;
            return 0xC;
        }
        ret2 = ret;
        r = NetGetConnInfo(0, &info);
        if (info == 0) {
            if (ret) return ret;
            return ret2;
        }
        if (r != 0)
            return ret;
        if (info->state == 1 || info->state == 2)
            D_00520340.conn[0] = D_00520340.p2p;
    }
    return ret;
}
