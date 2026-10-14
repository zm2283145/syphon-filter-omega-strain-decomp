typedef struct _Bigint { struct _Bigint *_next; int _k, _maxwds, _sign, _wds; unsigned long _x[1]; } _Bigint;
struct _reent126918 { char pad[0x48]; _Bigint *_p5s; };
static const int p05[3] = { 5, 25, 125 };
extern _Bigint *func_00126358(struct _reent126918 *, _Bigint *, int, int);
/* weak discarded stub: models callee defined in the same retail file (affects delay-slot filling) */
_Bigint * __attribute__((weak, section(".dtors_drop"))) func_001266D0(struct _reent126918 *p, int i) { return 0; }
extern _Bigint *func_00126708(struct _reent126918 *, _Bigint *, _Bigint *);
extern void func_00126328(struct _reent126918 *, _Bigint *);
_Bigint *func_00126918(struct _reent126918 *ptr, _Bigint *b, int k)
{
    _Bigint *b1, *p5, *p51;
    int i;
    if ((i = k & 3) != 0)
        b = func_00126358(ptr, b, p05[i - 1], 0);
    if (!(k >>= 2))
        return b;
    if (!(p5 = ptr->_p5s)) {
        p5 = ptr->_p5s = func_001266D0(ptr, 625);
        p5->_next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = func_00126708(ptr, b, p5);
            func_00126328(ptr, b);
            b = b1;
        }
        if (!(k >>= 1))
            break;
        if (!(p51 = p5->_next)) {
            p51 = p5->_next = func_00126708(ptr, p5, p5);
            p51->_next = 0;
        }
        p5 = p51;
    }
    return b;
}