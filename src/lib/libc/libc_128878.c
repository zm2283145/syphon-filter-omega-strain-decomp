typedef void (*_sig_func_ptr)(int);
struct _reent128878 { char pad[0x1D4]; _sig_func_ptr *_sig_func; };
/* weak discarded stub: models callee defined in the same retail file (affects delay-slot filling) */
int __attribute__((weak, section(".dtors_drop"))) Newlib_InitSignalR(struct _reent128878 *p) { return 0; }
int Newlib_SigtrampR(struct _reent128878 *ptr, int sig)
{
    _sig_func_ptr func;
    if (sig < 0 || sig >= 32)
        return -1;
    if (ptr->_sig_func == 0 && Newlib_InitSignalR(ptr) != 0)
        return -1;
    func = ptr->_sig_func[sig];
    if (func == (_sig_func_ptr)0)
        return 1;
    else if (func == (_sig_func_ptr)-1)
        return 2;
    else if (func == (_sig_func_ptr)1)
        return 3;
    else {
        ptr->_sig_func[sig] = (_sig_func_ptr)0;
        func(sig);
        return 0;
    }
}