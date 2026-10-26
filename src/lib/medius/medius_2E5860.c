typedef struct E2E5860 {
    unsigned char state;
    char name[0x11];
    unsigned short port;
    int x14[2];
    int x1C;
    void (*cb)(int, char *, int);
} E2E5860;
extern E2E5860 D_00520358[];
extern unsigned char D_0048C4A4;
extern int rt_msg_client_echo_update(void);
extern int NetMapMsgClientError(int, int);
extern int rt_msg_client_send_echo(unsigned char *, char *, unsigned short);
extern void rt_time_get_time_stamp(int *);
extern int rt_time_elapsed(int *, unsigned int *);

int NetProcessEchoRequests(unsigned char mode)
{
    unsigned char res;
    unsigned int t;
    unsigned int i;
    int r;

    if (D_0048C4A4 != 1)
        return 0;
    r = NetMapMsgClientError(rt_msg_client_echo_update(), 0x18);
    if (r != 0)
        return r;
    for (i = 0; i < 0x100; i++) {
        switch (D_00520358[i].state) {
        case 0:
            break;
        case 1:
            res = 0;
            if (rt_msg_client_send_echo(&res, D_00520358[i].name, D_00520358[i].port) != 0)
                break;
            if (res != 1)
                break;
            rt_time_get_time_stamp(D_00520358[i].x14);
            D_00520358[i].state = 2;
            break;
        case 2:
            rt_time_elapsed(D_00520358[i].x14, &t);
            if (t <= 10000)
                break;
            D_00520358[i].state = 4;
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        case 4:
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0xE, D_00520358[i].name, 0);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        case 3:
            if (mode != 1)
                break;
            if (D_00520358[i].cb != 0) {
                D_00520358[i].cb(0, D_00520358[i].name, D_00520358[i].x1C);
                D_00520358[i].cb = 0;
            }
            D_00520358[i].state = 0;
            break;
        default:
            D_00520358[i].state = 0;
            break;
        }
    }
    return 0;
}

