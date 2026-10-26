typedef struct { unsigned int mt[625]; int mti; } MT1DC8;
extern MT1DC8 D_00490910;
extern void setNewSeed(unsigned int seed);
#define hiBit(u)       ((u) & 0x80000000U)
#define loBit(u)       ((u) & 0x00000001U)
#define loBits(u)      ((u) & 0x7FFFFFFFU)
#define mixBits(u, v)  (hiBit(u) | loBits(v))
#define K 0x9908B0DFU
void reloadMT(void)
{
    unsigned int *p0 = D_00490910.mt, *p2 = D_00490910.mt + 2, *pM = D_00490910.mt + 397, s0, s1;
    int j;
    if (D_00490910.mti >= 625)
        setNewSeed(0x3579ABCD);
    D_00490910.mti = 0;
    for (s0 = D_00490910.mt[0], s1 = D_00490910.mt[1], j = 624 - 397 + 1; --j; s0 = s1, s1 = *p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
    for (pM = D_00490910.mt, j = 397; --j; s0 = s1, s1 = *p2++)
        *p0++ = *pM++ ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
    s1 = D_00490910.mt[0], *p0 = *pM ^ (mixBits(s0, s1) >> 1) ^ (loBit(s1) ? K : 0U);
}
