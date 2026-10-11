typedef struct { int used; int sock; int pad[5]; } Sock;
extern Sock D_00518A08[];
extern int func_002BB898(int);
extern int sceDbcDeleteSocket(int);
int func_002BB8C8(int i)
{
    if (func_002BB898(i) == 0) return 0;
    sceDbcDeleteSocket(D_00518A08[i].sock);
    D_00518A08[i].used = 0;
    return 1;
}
