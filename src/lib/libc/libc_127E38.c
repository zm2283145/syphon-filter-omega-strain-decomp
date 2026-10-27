/*
 * lib/libc: 2 files, 00127E38-00127E98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00127E38 */
extern int D_0058805C;
extern int Libc_Read(int fd, void* buf, unsigned int cnt);
struct reent_00127E38 { int _errno; };
long Newlib_ReadR(struct reent_00127E38* ptr, int fd, void* buf, unsigned int cnt)
{
    long ret;
    D_0058805C = 0;
    if ((ret = Libc_Read(fd, buf, cnt)) == -1 && D_0058805C != 0)
        ptr->_errno = D_0058805C;
    return ret;
}
/* merge_units: end func_00127E38 */

/* merge_units: begin func_00127E98 */
#include "types.h"
extern void* D_00489738;
extern void Newlib_MallocLock(void* r);
extern void Newlib_MallocUnlock(void* r);
extern void* _realloc_r(void* reent, unsigned int n, unsigned int elem_size);
void* Libc_Realloc(unsigned int n, unsigned int size)
{
    void* r;
    Newlib_MallocLock(D_00489738);
    r = _realloc_r(D_00489738, n, size);
    Newlib_MallocUnlock(D_00489738);
    return r;
}
/* merge_units: end func_00127E98 */
