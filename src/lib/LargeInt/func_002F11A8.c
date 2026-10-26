static const unsigned int dat_0048C738[2] = { 0x0, 0x0 };
extern void setNewSeed(int);
extern unsigned int randomMT(void);
typedef struct { unsigned int v[32]; } T2F11A8;
void lintRandomize(unsigned int *buf, unsigned int bits)
{
    unsigned int n = 0;
    unsigned int *p;
    if (bits > 0x400) bits = 0x400;
    if (!(*(signed char*)dat_0048C738)) {
        (*(signed char*)dat_0048C738) = 1;
        setNewSeed(0x2EB3AE77);
    }
    if (bits > 0x20) {
        p = buf;
        do {
        bits -= 0x20;
        *p ^= randomMT();
        n++;
        p++;
        } while (bits > 0x20);
    }
    ((T2F11A8 *)buf)->v[n] = (randomMT() | 0x80000000) >> -bits;
    n++;
    for (; n < 0x20; n++) buf[n] = 0;
}
