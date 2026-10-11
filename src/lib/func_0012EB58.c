extern int D_0058805C;
extern int func_0010D728(int fd, void* buf, unsigned int cnt);
struct reent_0012EB58 { int _errno; };
long func_0012EB58(struct reent_0012EB58* ptr, int fd, void* buf, unsigned int cnt)
{
    long ret;
    D_0058805C = 0;
    if ((ret = func_0010D728(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}