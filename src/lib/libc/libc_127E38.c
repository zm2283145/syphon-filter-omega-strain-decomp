/*
 * lib/libc: 2 files, 00127E38-00127E98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00127E38 */
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
/* merge_units: end func_00127E38 */

/* merge_units: begin func_00127E98 */
#include "types.h"
extern void* D_00489738;
extern void func_001261B0(void* r);
extern void func_00126230(void* r);
extern void* _realloc_r(void* reent, unsigned int n, unsigned int elem_size);
void* func_00127E98(unsigned int n, unsigned int size)
{
    void* r;
    func_001261B0(D_00489738);
    r = _realloc_r(D_00489738, n, size);
    func_00126230(D_00489738);
    return r;
}
/* merge_units: end func_00127E98 */
