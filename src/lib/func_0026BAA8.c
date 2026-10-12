typedef struct {
    unsigned long cmd : 14;
    unsigned long mode : 2;
    unsigned long len : 8;
    unsigned long dev : 8;
} DbcCmd_baa8;

extern int sceDbcReceiveData(int port, DbcCmd_baa8 cmd, int *len, unsigned char *out);

int func_0026BAA8(int port, unsigned char *out)
{
    int buf;
    int r;
    DbcCmd_baa8 c;

    c.cmd = 2;
    c.mode = 2;
    c.len = 3;
    c.dev = 1;
    r = sceDbcReceiveData(port, c, &buf, out);
    if (r < 0) return r;
    return buf;
}
