typedef struct { unsigned int mt[625]; int mti; } MT1D58;
extern MT1D58 D_00490910;
void seedMTUsingArray(unsigned int *key, unsigned int len)
{
    unsigned int s;
unsigned int *p;
int i;
    s = -1;
    p = D_00490910.mt;
    D_00490910.mti = 0x26F;
    if (len > 0x26F) len = 0x26F;
    *p++ = s;
    for (i = 0x270; i != 0; i--) {
        if (len) { s ^= *key++; len--; }
        s = (s << 5) | (s >> 27); s *= 0x10DCD;
        *p++ = s;
    }
}