int func_001168E0(volatile unsigned int* d, volatile unsigned int* s, unsigned int n)
{
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) *d++ = *s++;
    return 0;
}