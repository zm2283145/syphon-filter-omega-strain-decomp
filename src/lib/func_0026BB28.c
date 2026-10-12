typedef struct {
    unsigned long cmd : 14;
    unsigned long mode : 2;
    unsigned long len : 8;
    unsigned long dev : 8;
} DbcCmd_bb28;

extern void *memcpy(void *, const void *, unsigned int);
extern int sceDbcSendData2(int port, DbcCmd_bb28 cmd, int *len, void *in);

int func_0026BB28(int port, int len2, void *src2, int len1, void *src1)
{
    struct {
        int len2;
        int len1;
        unsigned char data[40];
    } pkt;
    int size;
    DbcCmd_bb28 c;

    c.cmd = 11;
    c.mode = 1;
    c.len = 3;
    size = sizeof(pkt.data);
    c.dev = 1;
    pkt.len1 = len1;
    memcpy(pkt.data, src1, len1);
    pkt.len2 = len2;
    memcpy(pkt.data + len1, src2, len2);
    return sceDbcSendData2(port, c, &size, &pkt);
}
