extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, char **);
extern int func_00301988(char *, unsigned short);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int func_002FD860(unsigned short id, int x)
{
    char buf[16];
    char *p = 0;
    int r;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &p);
    if (r) return r;
    if (func_00301988(buf, x)) return 7;
    return NetConn_BufferMessage(*(int *)(p + 0x80), 0xE, 0xFFFF, buf, 2, 0);
}
