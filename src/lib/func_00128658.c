#include "types.h"
extern int D_0058805C;
extern int func_0010D860(int fd);
struct reent_00121E20 { int _errno; };
int func_00128658(struct reent_00121E20* ptr, int fd)
{
    int ret;
    D_0058805C = 0;
    if ((ret = func_0010D860(fd)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}