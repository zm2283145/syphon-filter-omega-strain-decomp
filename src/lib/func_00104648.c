typedef int u_long128 __attribute__((mode(TI)));
typedef struct { u_long128 *p; int a, b; u_long128 *last; } QBuf;
void func_00104648(QBuf *b, u_long128 q) { b->last = b->p; *b->p++ = q; }