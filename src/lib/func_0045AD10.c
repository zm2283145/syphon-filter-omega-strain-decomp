extern int sceInsockSetRecvTimeout(int a, int b);
extern int sceInsockRecvfrom(int a, int b, int c, int d, int e, int f);
int sceNetGlueRecvfrom(int a, int b, int c, int d, int e, int f)
{
    sceInsockSetRecvTimeout(a, 600000);
    return sceInsockRecvfrom(a, b, c, d, e, f);
}