static const unsigned int dat_0048C738[2] = { 0x0, 0x0 };
extern void func_00302088(int);
extern unsigned int func_00301F40(void);
typedef struct { unsigned int v[32]; } T2F11A8;
void func_002F11A8(unsigned int *buf, unsigned int bits)
{
    unsigned int n = 0;
    unsigned int *p;
    if (bits > 0x400) bits = 0x400;
    if (!(*(signed char*)dat_0048C738)) {
        (*(signed char*)dat_0048C738) = 1;
        func_00302088(0x2EB3AE77);
    }
    if (bits > 0x20) {
        p = buf;
        do {
        bits -= 0x20;
        *p ^= func_00301F40();
        n++;
        p++;
        } while (bits > 0x20);
    }
    ((T2F11A8 *)buf)->v[n] = (func_00301F40() | 0x80000000) >> -bits;
    n++;
    for (; n < 0x20; n++) buf[n] = 0;
}
