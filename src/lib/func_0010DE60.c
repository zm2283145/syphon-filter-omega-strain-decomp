/* SDK helper thread: request ring dispatcher */
typedef struct { unsigned char cmd; unsigned char arg; } ReqDE60;
typedef struct { unsigned int idx; int pad; ReqDE60 q[512]; } RingDE60;
extern int D_004E2400;
extern int WaitSema(int);
extern int func_0010D090(int);
extern int func_0010D010(int);
extern int func_0010D0D0(int);
extern int func_0010F350(const char *, ...);
void func_0010DE60(RingDE60 *r)
{
    for (;;) {
        unsigned int i;
        WaitSema(D_004E2400);
        i = r->idx & 0x1FF;
        r->idx = i + 1;
        switch (r->q[i].cmd) {
        case 0:
            func_0010D090(r->q[i].arg);
            break;
        case 1:
            func_0010D010(r->q[i].arg);
            break;
        case 2:
            func_0010D0D0(r->q[i].arg);
            break;
        default:
            func_0010F350("## internel error in libkernl.a!\n");
            break;
        }
    }
}
