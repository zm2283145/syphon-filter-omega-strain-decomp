typedef struct { int on; int w; int a; int b; } DbcBit;

int func_0026B9C0(unsigned char *bits, DbcBit *o)
{
    int i, bit = 0, a = 0, b = 0;
    for (i = 0; i < 40; i++, o++) {
        if ((*bits >> bit) & 1) {
            o->on = 1;
            o->a = a;
            o->b = b;
            if ((unsigned int)(i - 16) < 16 || (unsigned int)(i - 35) < 4) {
                o->w = 8;
                a++;
            } else {
                b++;
                o->w = 1;
                if ((b & 7) == 0) {
                    a++;
                    b = 0;
                }
            }
        } else {
            o->on = 0;
            o->a = 0;
            o->b = 0;
        }
        bit++;
        if ((bit & 7) == 0) {
            bits++;
            bit = 0;
        }
    }
    return 1;
}