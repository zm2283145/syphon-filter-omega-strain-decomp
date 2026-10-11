typedef struct A00123330 { struct A00123330 *_next; int _ind; void (*_fns[32])(void); } A00123330;
typedef struct { char p[0x3C]; void (*__cleanup)(void *); char q[0x108]; A00123330 *_atexit; } R00123330;
extern R00123330 *D_00489738;
extern void func_00100218(int);
void func_00123330(int code)
{
    A00123330 *p;
    int n;
    for (p = D_00489738->_atexit; p; p = p->_next)
        for (n = p->_ind; --n >= 0;)
            (*p->_fns[n])();
    if (D_00489738->__cleanup) (*D_00489738->__cleanup)(D_00489738);
    func_00100218(code);
}
