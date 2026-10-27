extern int sceInsockSetRecvTimeout(int a, int b);
extern int sceInsockRecv(int a, int b, int c, int d);
int sceNetGlueRecv(int a, int b, int c, int d)
{
    sceInsockSetRecvTimeout(a, 600000);
    return sceInsockRecv(a, b, c, d);
}