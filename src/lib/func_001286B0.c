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