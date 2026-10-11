extern int D_0058805C;
extern int func_0010D820(int fd, void* buf, unsigned int cnt);
struct reent_00127298 { int _errno; };
int func_00127298(struct reent_00127298* ptr, int fd, void* buf, unsigned int cnt)
{
    int ret;
    D_0058805C = 0;
    if ((ret = func_0010D820(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}