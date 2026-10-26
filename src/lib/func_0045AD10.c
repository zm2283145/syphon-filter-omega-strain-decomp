extern int sceInsockSetRecvTimeout(int a, int b);
extern int Insck_Recvfrom(int a, int b, int c, int d, int e, int f);
int sceNetGlueRecvfrom(int a, int b, int c, int d, int e, int f)
{
    sceInsockSetRecvTimeout(a, 600000);
    return Insck_Recvfrom(a, b, c, d, e, f);
}