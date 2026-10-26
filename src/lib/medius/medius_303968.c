typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
int rt_p2p_get_max_peers(UpnpObj *o, int *out)
{
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    if (o == 0) return ret;
    *out = o->count;
    return 0;
}