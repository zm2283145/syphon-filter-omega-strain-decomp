void lintIncrement(unsigned int *a, unsigned int b)
{
    unsigned int i;
    i = 0;
L20:
    *a += b;
    if (*a >= b) return;
L30:
    i++; a++;
    if (i >= 32) return;
    if (i == 0) goto L20;
    *a += 1;
    if (*a == 0) goto L30;
}
