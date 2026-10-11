extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
extern void func_0010D3E0(int a);
int func_0034C890(void *cd)
{
    func_0010D3E0(0);
    return sceSifMCallRpc(cd, 0x67, 0, 0, 0, 0, 0, 0, 0);
}