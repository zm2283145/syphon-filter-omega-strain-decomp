typedef void (*sigf_t)(int);
typedef struct { int _errno; char p[0x1D0]; sigf_t *_sig_func; } R001287A0;
extern int func_001286B0(R001287A0 *);
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
