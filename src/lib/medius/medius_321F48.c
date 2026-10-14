/* Park-Miller minimal standard RNG step. Register-pinned locals reproduce retail register allocation. */
void func_00321F48(int *seed)
{
    register int s asm("$5") = *seed;
    register unsigned int k asm("$6") = 16807;
    unsigned int hi = (s >> 16) * k;
    unsigned int lo = (s & 0xFFFF) * k;
    unsigned int sh;
    register unsigned int l2 asm("$3");
    register unsigned int m asm("$6");
    register unsigned int q asm("$3");
    unsigned int t;
    sh = (hi << 17) >> 1;
    l2 = sh + lo;
    m = l2 << 1;
    q = l2 >> 31;
    t = (hi >> 15) + q;
    q = m >> 1;
    t += q;
    t += t >> 31;
    *seed = (t << 1) >> 1;
}

