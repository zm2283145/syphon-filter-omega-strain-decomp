typedef struct {
    unsigned long code;
    unsigned long mask;
} VlcEnt;

extern VlcEnt D_00485FB0[];

unsigned long func_0010A128(unsigned int i, int v)
{
    unsigned long r = 0;
    int sh = 0;

    if (i < 10) {
        switch (D_00485FB0[i].mask) {
        case 0xFFFFFFFFFF:
            sh = 0;
            break;
        case 0xFFFF000000:
            sh = 24;
            break;
        case 0xFF00000000:
            sh = 32;
            break;
        }
        r = D_00485FB0[i].code | (unsigned long)v << sh;
    }
    return r;
}


