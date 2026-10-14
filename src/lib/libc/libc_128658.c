/*
 * lib/libc: 4 files, 00128658-001287A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00128658 */
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
/* merge_units: end func_00128658 */

/* merge_units: begin func_001286B0 */
typedef void (*_sig_func_ptr)(int);
struct _reent { char p[0x1D4]; _sig_func_ptr *_sig_func; };
extern void *_malloc_r(struct _reent *, unsigned int);
int func_001286B0(struct _reent *ptr)
{
    int i;

    if (ptr->_sig_func == 0) {
        ptr->_sig_func = (_sig_func_ptr *)_malloc_r(ptr, sizeof(_sig_func_ptr) * 32);
        if (ptr->_sig_func == 0)
            return -1;

        for (i = 0; i < 32; i++)
            ptr->_sig_func[i] = (_sig_func_ptr)0;
    }

    return 0;
}
/* merge_units: end func_001286B0 */

/* merge_units: begin func_00128720 */
typedef void (*sigf_t)(int);
typedef struct { int _errno; char p[0x1D0]; sigf_t *_sig_func; } R00128720;
#if 0 /* merge_units */
extern int func_001286B0(R00128720 *);
#endif /* merge_units */
#define func_001286B0(a0) (func_001286B0((struct _reent *)(a0))) /* merge_units */

sigf_t func_00128720(R00128720 *ptr, int sig, sigf_t func)
{
    sigf_t old;
    if (sig < 0 || sig >= 32) {
        ptr->_errno = 0x16;
        return (sigf_t)-1;
    }
    if (ptr->_sig_func == 0 && func_001286B0(ptr) != 0) return (sigf_t)-1;
    old = ptr->_sig_func[sig];
    ptr->_sig_func[sig] = func;
    return old;
}
#undef func_001286B0 /* merge_units */
/* merge_units: end func_00128720 */

/* merge_units: begin func_001287A0 */
typedef struct { int _errno; char p[0x1D0]; sigf_t *_sig_func; } R001287A0;
#if 0 /* merge_units */
extern int func_001286B0(R001287A0 *);
#endif /* merge_units */
#define func_001286B0(a0) (func_001286B0((struct _reent *)(a0))) /* merge_units */

extern int func_001289F8(R001287A0 *);
extern int func_00128998(R001287A0 *, int, int);
int func_001287A0(R001287A0 *ptr, int sig)
{
    sigf_t func;
    if (sig < 0 || sig >= 32) {
        ptr->_errno = 0x16;
        return -1;
    }
    if (ptr->_sig_func == 0 && func_001286B0(ptr) != 0) return -1;
    func = ptr->_sig_func[sig];
    if (func == (sigf_t)0) return func_00128998(ptr, func_001289F8(ptr), sig);
    else if (func == (sigf_t)1) return 0;
    else if (func == (sigf_t)-1) {
        ptr->_errno = 0x16;
        return 1;
    } else {
        ptr->_sig_func[sig] = (sigf_t)0;
        func(sig);
        return 0;
    }
}
#undef func_001286B0 /* merge_units */
/* merge_units: end func_001287A0 */
