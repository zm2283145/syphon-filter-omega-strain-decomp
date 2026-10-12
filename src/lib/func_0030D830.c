typedef struct {
    int sock;
    char pad[0x24];
    char host[0x10];
    unsigned short port;
    char pad2[6];
    int timer[3];
    unsigned char active;
} UpnpD830;
extern int func_003060F0(int *timer, unsigned int *elapsed);
extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
extern void func_003060D8(int *timer);
int func_0030D830(UpnpD830 *u)
{
    char pkt[4];
    unsigned short sent = 0;
    unsigned int elapsed;
    if (u->active) {
        func_003060F0(u->timer, &elapsed);
        if (elapsed > 5000) {
            pkt[3] = 0xD4;
            Socket_WriteAddressed(u->sock, u->host, u->port, pkt, 4, &sent);
            func_003060D8(u->timer);
        }
    }
    return 0;
}
