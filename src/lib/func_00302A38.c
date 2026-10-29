typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern int rt_udp_get_address(int h, int a, char *b, unsigned short *c);
extern char *strncpy(char *, const char *, unsigned int);int rt_p2p_get_peer_address(UpnpObj *o, int idx, int mode, char *addr, unsigned short *port)
{
    int ret = 2;
    if (o == 0) return ret;
    if (idx < 0 || idx >= o->count) return 8;
    if (mode == 0) {
        if (o->ent[idx].f4 != -1) {
            if (rt_udp_get_address(o->h180, o->ent[idx].f4, addr, port) != 0) return 7;
        } else {
            strncpy(addr, o->ent[idx].addr, 16);
            *port = o->ent[idx].port;
        }
    } else if (mode == 1) {
        if (o->ent[idx].f8 != -1) {
            if (rt_udp_get_address(o->h180, o->ent[idx].f8, addr, port) != 0) return 7;
        } else {
            strncpy(addr, o->ent[idx].addr, 16);
            *port = o->ent[idx].port;
        }
    } else return 2;
    return 0;
}