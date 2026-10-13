typedef struct { unsigned char key; char pad; unsigned short val; } K223F10;
extern K223F10 D_004A5A50[2][21];
unsigned int func_00223F10(int set, unsigned char k)
{
    unsigned int c = k;
    unsigned int i;
    int t = set & 1;
    for (i = 0; i < 21; i++) {
        if (k == D_004A5A50[t][i].key) {
            c = D_004A5A50[t][i].val | 0x4000;
            break;
        }
    }
    return c;
}

