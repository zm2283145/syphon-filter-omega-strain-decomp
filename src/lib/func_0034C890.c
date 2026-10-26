extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
extern void FlushCache(int a);
int sceBInetDisplayLibnetbState(void *cd)
{
    FlushCache(0);
    return sceSifMCallRpc(cd, 0x67, 0, 0, 0, 0, 0, 0, 0);
}