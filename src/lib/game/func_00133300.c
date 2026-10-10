typedef int C1q_1333 __attribute__((mode(TI)));
typedef struct { C1q_1333 r[4]; } C1Mtx_1333;
C1Mtx_1333* Mtx_Copy(C1Mtx_1333* d, C1Mtx_1333* s)
{
    C1q_1333 a = s->r[0];
    C1q_1333 b = s->r[1];
    d->r[0] = a;
    a = s->r[2];
    d->r[1] = b;
    b = s->r[3];
    d->r[2] = a;
    d->r[3] = b;
    return d;
}