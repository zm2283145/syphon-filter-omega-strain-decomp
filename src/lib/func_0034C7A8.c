extern void *memset(void *d, int c, unsigned int n);
extern int Libc_Sscanf(const char *s, const char *fmt, ...);
typedef struct { int family; unsigned char addr[4]; int pad[2]; } NetAddr_7A8;
int sceBInetIP2Address(NetAddr_7A8 *ip, char *str)
{
    int a, b, c, d;
    if (ip == 0 || str == 0) return -0x200;
    memset(ip, 0, 16);
    if (Libc_Sscanf(str, "%u.%u.%u.%u", &a, &b, &c, &d) != 4) return -0x200;
    ip->addr[0] = d;
    ip->family = 0;
    ip->addr[1] = c;
    ip->addr[2] = b;
    ip->addr[3] = a;
    return 0;
}