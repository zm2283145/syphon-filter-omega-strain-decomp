typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;

extern int RtUdp_UpdateTransport(int h);
extern int RtUdp_DrainReceive(UpnpObj *o);
extern int func_00304FC8(UpnpObj *o);
int func_003036B8(UpnpObj *o)
{
    int ret = 2;
    if (o == 0) return ret;
    if (RtUdp_UpdateTransport(o->h180) != 0) return 7;
    ret = RtUdp_DrainReceive(o);
    if (ret != 0) return ret;
    ret = func_00304FC8(o);
    __asm__ __volatile__("");
    return ret;
}