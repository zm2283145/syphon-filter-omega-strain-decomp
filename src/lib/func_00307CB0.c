typedef struct { unsigned char a; unsigned char b; unsigned short len; int x4; int x8; } H307CB0;
typedef struct { int sock; char pad4[0x20]; char *buf; char pad28[0x10]; unsigned int max; char pad3C[0xC]; unsigned char x48; } S307CB0;
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern int Socket_WriteAddressed(int sock, int addr, unsigned int port, char *buf, unsigned int len, unsigned short *written);
int rt_udp_send_unconnected(S307CB0 *s, int addr, unsigned short port, void *data, unsigned int len)
{
    H307CB0 h;
    unsigned short written = 0;
    unsigned int total;
    int ret = 2;
    if (!s)
        return ret;
    ret = 1;
    if (!addr)
        return ret;
    if (!port)
        return ret;
    if (!data)
        return ret;
    if (!len || s->max < len)
        return ret;
    memset(&h, 0, sizeof(h));
    total = len + 12;
    h.a = 0;
    h.b = s->x48;
    h.len = len;
    memcpy(s->buf, &h, sizeof(h));
    memcpy(s->buf + 12, data, len);
    if (Socket_WriteAddressed(s->sock, addr, port, s->buf, (unsigned short)total, &written) != 0 || written != total)
        return 16;
    return 0;
}
