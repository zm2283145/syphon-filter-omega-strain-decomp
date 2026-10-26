/*
 * lib/medius: 2 files, 002E5BA8-002E5CC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E5BA8 */
typedef struct E2E5BA8 {
    unsigned char state;
    char name[0x11];
    unsigned short port;
    int x14[2];
    int x1C;
    void (*cb)(int, char *, int);
} E2E5BA8;
extern E2E5BA8 D_00520358[];
extern unsigned char D_0048C4A4;
extern int rt_msg_client_echo_shutdown(void);
extern int NetMapMsgClientError(int, int);
extern void *memset(void *, int, unsigned int);

int NetDisablePingIPs(void)
{
    unsigned int i;
    int r;

    for (i = 0; i < 0x100; i++) {
        if (D_00520358[i].state == 1 || D_00520358[i].state == 2)
            D_00520358[i].state = 4;
        if (D_00520358[i].state == 4) {
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
        }
    }
    if (D_0048C4A4 == 1) {
        r = NetMapMsgClientError(rt_msg_client_echo_shutdown(), 0x18);
        if (r != 0)
            return r;
        D_0048C4A4 = 0;
    }
    memset(D_00520358, 0, 0x2400);
    return 0;
}
/* merge_units: end func_002E5BA8 */

/* merge_units: begin func_002E5CC0 */
extern int NetIsValidClientIndex(int);
extern int NetGetClientInfo(unsigned int, int, unsigned char **);
int NetGetClientConnectStatus(unsigned int a, int b, int *out)
{
    unsigned char *p = 0;
    int r;
    if (a >= 4) return 0x17;
    if (NetIsValidClientIndex(b) != 1) return 0x17;
    if (out == 0) return 0x17;
    *out = 0xFFFFFF;
    r = NetGetClientInfo(a, b, &p);
    if (r) return r;
    if (p == 0) return r;
    *out = p[0x28] != 0;
    return 0x1E;
}
/* merge_units: end func_002E5CC0 */
