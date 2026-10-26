typedef struct { int type; int f4; int f8; char pad[6]; char name[0x10]; unsigned short port; char pad2[4]; } UpnpEnt;
typedef struct { char pad[0x180]; void *h180; UpnpEnt *ent; } UpnpObj;
extern int rt_udp_get_address(void *h, int key, char *name, unsigned short *port);
extern int rt_p2p_get_peer_by_connection(UpnpObj *o, int key, int *out);
extern void rt_udp_disconnect(void *h, int key);
extern void rt_p2p_generic_disconnect(UpnpObj *o, int key, int c);
extern char *strncpy(char *, const char *, unsigned int);

void rt_p2p_handle_timeout_event(UpnpObj *o, int key, int c)
{
    char name[0x10];
    unsigned short port;
    int idx;

    idx = -2;
    if (rt_udp_get_address(o->h180, key, name, &port) != 0)
        return;
    if (rt_p2p_get_peer_by_connection(o, key, &idx) != 0 || idx == -2) {
        rt_udp_disconnect(o->h180, key);
        return;
    }
    if (key == o->ent[idx].f4) {
        strncpy(o->ent[idx].name, name, 0x10);
        o->ent[idx].port = port;
        if (o->ent[idx].f8 == -1) {
            rt_p2p_generic_disconnect(o, key, c);
        } else {
            rt_udp_disconnect(o->h180, key);
            o->ent[idx].f4 = -1;
        }
    } else if (key == o->ent[idx].f8) {
        strncpy(o->ent[idx].name, name, 0x10);
        o->ent[idx].port = port;
        if (o->ent[idx].f4 == -1) {
            rt_p2p_generic_disconnect(o, key, c);
        } else {
            rt_udp_disconnect(o->h180, key);
            o->ent[idx].f8 = -1;
        }
    }
}