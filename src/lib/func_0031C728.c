typedef struct BitW316DF0 {
    unsigned char* buf;
    unsigned short size;
    char pad6[0x10 - 6];
    unsigned short* pos;
    unsigned char* bit;
} BitW316DF0;
extern short D_004B5440[];
extern void func_00316DF0(BitW316DF0* w, short val, int n);
void func_0031C728(unsigned int* p, unsigned char* buf, unsigned short* pos, unsigned char* bit, unsigned short size, unsigned short v)
{
    BitW316DF0 w;
    short* t;
    int i; unsigned int* q;
    w.size = size;
    w.pos = pos;
    w.bit = bit;
    w.buf = buf;
    p[16] = v;
    p[15] = 0;
    t = D_004B5440; q = p;
    for (i = 16; i >= 0; i--) {
        func_00316DF0(&w, (unsigned char)*q++, *t++);
    }
}
