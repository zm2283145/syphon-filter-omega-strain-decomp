void (*D_0048C3E0)(int, int, int, char *) = 0;
extern void MGCLSetServerSessionKey(char *);
extern void MGCLSetNATServiceAddress(char *);
int GlobalMediusTypeServerSessionBeginCallback(int a, int b, int c, char *d)
{
    if (d[0x15] == 0) {
        MGCLSetServerSessionKey(d + 0x90);
        MGCLSetNATServiceAddress(d + 0x1C);
    }
    if (D_0048C3E0) D_0048C3E0(a, b, c, d);
    return 0xB4;
}
