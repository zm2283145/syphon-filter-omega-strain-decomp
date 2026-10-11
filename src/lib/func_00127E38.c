extern int D_0058805C;
extern int func_0010D7A8(int fd, void* buf, unsigned int cnt);
struct reent_00127E38 { int _errno; };
long func_00127E38(struct reent_00127E38* ptr, int fd, void* buf, unsigned int cnt)
{
    long ret;
    D_0058805C = 0;
    if ((ret = func_0010D7A8(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}