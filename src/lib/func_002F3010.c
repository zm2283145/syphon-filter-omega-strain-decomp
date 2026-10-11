typedef struct S3010 { struct S3010 *a, *b; int c; int d[3]; int x18; } S3010;
extern void Net_AllocZeroed(void *, int);
S3010 *func_002F3010(int c)
{
    S3010 *p = 0;
    Net_AllocZeroed(&p, 0x860);
    if (p) {
        p->b = p->a = p;
        p->c = c;
        p->x18 = 0;
    }
    return p;
}