extern void *memset(void *, int, unsigned int);
typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FC970;
extern unsigned char D_004908EC;
extern S2FC970 D_005297E0;
extern int rt_comm_create(int *, int, int, int *);
extern int rt_msg_client_map_comm_error(int);
int rt_msg_client_ienable_echo(int *x)
{
    int m[3];
    int r;
    unsigned char st = D_004908EC;
    if (st != 1) return 5;
    if (x == 0) return 2;
    if (D_005297E0.flag) return 1;
    memset(m, 0, 0xC);
    m[0] = 3;
    r = rt_msg_client_map_comm_error(rt_comm_create(&D_005297E0.x4, 0, 0, m));
    if (r) return r;
    D_005297E0.x8 = *x;
    D_005297E0.flag = st;
    return r;
}
