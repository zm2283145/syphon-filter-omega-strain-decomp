extern int sceInsockSetRecvTimeout(int a, int b);
extern int Insck_Recv(int a, int b, int c, int d);
int sceNetGlueRecv(int a, int b, int c, int d)
{
    sceInsockSetRecvTimeout(a, 600000);
    return Insck_Recv(a, b, c, d);
}