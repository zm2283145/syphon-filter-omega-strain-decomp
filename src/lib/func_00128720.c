typedef void (*sigf_t)(int);
typedef struct { int _errno; char p[0x1D0]; sigf_t *_sig_func; } R00128720;
extern int func_001286B0(R00128720 *);
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
