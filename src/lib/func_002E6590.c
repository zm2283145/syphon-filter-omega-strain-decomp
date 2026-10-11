extern char *strncpy(char *, const char *, unsigned int);
extern char D_005880A0[];
extern unsigned short D_0058D178;
extern int func_002DD280(void);
extern void Net_DispatchRecv(int, int, int, int, unsigned short);
void func_002E6590(const char *name, unsigned short port, int c, unsigned short d)
{
    strncpy(D_005880A0, name, 0x10);
    D_0058D178 = port;
    Net_DispatchRecv(func_002DD280(), 0xFFFF, 0x100, c, d);
}