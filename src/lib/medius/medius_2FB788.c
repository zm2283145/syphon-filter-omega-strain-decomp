extern void *memset(void *, int, unsigned int);
extern short D_004908EE;
extern char D_005297F0[];
extern char D_005297E0[];
unsigned int D_00490900[1] = { 0x0 };
extern unsigned short D_004908F0;
extern int D_004908F4;
extern unsigned char D_004908EC;
extern int rt_mutex_create(char *);
extern int rt_comm_startup(void);
extern int rt_msg_client_map_comm_error(int);
extern void KM_Initialize(int, int);
int rt_msg_client_startup(int a)
{
    int r;
    if (D_004908EE == 0) {
        if (rt_mutex_create(D_005297F0)) return 0x1A;
        (*(unsigned char*)D_00490900) = 1;
        r = rt_msg_client_map_comm_error(rt_comm_startup());
        if (r) return r;
        D_004908F4 = 0;
        D_004908F0 = 0;
        memset(D_005297E0, 0, 0xC);
        KM_Initialize(0, a);
        D_004908EC = 1;
    }
    D_004908EE++;
    return 0;
}
