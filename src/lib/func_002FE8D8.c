extern unsigned char D_004908EC;
extern int func_002FE8B0(void);
extern void func_002F8908(int, char *);
extern int NetConn_BufferMessage(int, int, int, char *, int, int);
int func_002FE8D8(int conn)
{
    char buf[0x40];
    unsigned char st = D_004908EC;
    if (st != 1) return 5;
    if (func_002FE8B0() != st) return 2;
    func_002F8908(0, buf);
    return NetConn_BufferMessage(conn, 0x12, 0xFFFF, buf, 0x40, 1);
}
