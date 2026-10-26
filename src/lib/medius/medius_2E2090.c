typedef struct { unsigned char state; char name[0x11]; unsigned short port; int x14[2]; int x1C[2]; } E2E2090;
extern E2E2090 D_00520358[];
extern unsigned char D_0048C4A4;
extern int strlen(const char *);
extern char *strncpy(char *, const char *, int);
extern void *memset(void *, int, int);
extern int NetDisablePingIPs(void);
extern int NetMapMsgClientError(int, int);
extern int rt_msg_client_echo_set_default_options(void *);
extern int rt_msg_client_enable_echo(void *);
extern int NetFindEchoSlotForIP(char *, unsigned int *, unsigned short *);
extern int rt_msg_client_send_echo(unsigned char *, char *, unsigned short);
extern void rt_time_get_time_stamp(int *);
extern void EchoRequestCallback(char *, unsigned short);

int NetIPingIP(char *name, int arg)
{
    unsigned short cnt;
    unsigned char res;
    void *cb;
    unsigned int idx;
    int ret;

    if (name == 0 || strlen(name) == 0)
        return NetDisablePingIPs();
    ret = 0x17;
    if (strlen(name) != 0 && arg != 0) {
        if (D_0048C4A4 != 1) {
            ret = NetMapMsgClientError(rt_msg_client_echo_set_default_options(&cb), 0x18);
            if (ret != 0) return ret;
            cb = (void *)EchoRequestCallback;
            ret = NetMapMsgClientError(rt_msg_client_enable_echo(&cb), 0x18);
            if (ret != 0) return ret;
            memset(D_00520358, 0, 0x2400);
            D_0048C4A4 = 1;
        }
        ret = NetFindEchoSlotForIP(name, &idx, &cnt);
        if (ret != 0) return ret;
        D_00520358[idx].state = 1;
        D_00520358[idx].port = cnt;
        D_00520358[idx].x1C[1] = arg;
        strncpy(D_00520358[idx].name, name, 0x10);
        ret = NetMapMsgClientError(rt_msg_client_send_echo(&res, D_00520358[idx].name, D_00520358[idx].port), 0x18);
        if (ret != 0) return ret;
        if (res == 1) {
            D_00520358[idx].state = 2;
            rt_time_get_time_stamp(D_00520358[idx].x14);
        }
        return 0;
    }
    return ret;
}


