extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, char **);
extern int func_003018E0(char *, int);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int func_002FD670(unsigned short id, unsigned char f)
{
    char buf[16];
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (func_003018E0(buf, 2) || func_003018E0(buf + 1, f == 1)) return 7;
    return NetConn_BufferMessage(*(int *)(p + 0x80), 0xD, 0xFFFF, buf, 2, 0);
}
