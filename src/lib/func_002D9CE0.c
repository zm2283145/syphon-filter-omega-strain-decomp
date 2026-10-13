typedef struct Sock { char pad[0x8C]; void* udp; char pad2[0xC0 - 0x90]; char name[16]; unsigned int port; } Sock;
extern unsigned int D_00588068;
extern void RtUdp_UpdateTransport(void*);
extern int func_00307598(void*, unsigned int, char*, unsigned short*);
extern int RtUdp_Read(void*, unsigned int, void*, unsigned int, unsigned int*);
extern int strcmp(const char*, const char*);
extern int func_002F4DA8(char*);
int func_002D9CE0(Sock* s, void* buf, unsigned int max, int* outAddr, int* outPort)
{
    char addr[16];
    unsigned short port;
    unsigned int n = 0;
    *outAddr = 0;
    *outPort = 0;
    RtUdp_UpdateTransport(s->udp);
    func_00307598(s->udp, -2, addr, &port);
    if (RtUdp_Read(s->udp, -2, buf, max, &n) != 0) return -1;
    if (n != 0) {
    if (s->port == (unsigned short)*outPort && strcmp(addr, s->name) == 0) return 0;
    D_00588068 += n;
    *outAddr = func_002F4DA8(addr);
    *outPort = port;
    }
    return n;
}
