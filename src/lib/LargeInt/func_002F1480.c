void func_002F1480(unsigned int* m, unsigned int n)
{
    unsigned int i = n >> 5;
    unsigned int* p = m + i;
    *p &= (1 << n) - 1;
    for (i++; i < 32; i++)
        m[i] = 0;
}