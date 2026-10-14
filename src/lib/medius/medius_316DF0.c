typedef struct BitW316DF0 {
    unsigned char* buf;
    unsigned short size;
    char pad6[0x10 - 6];
    unsigned short* pos;
    unsigned char* bit;
} BitW316DF0;
void func_00316DF0(BitW316DF0* w, short val, int n)
{
    unsigned short* pos = w->pos;
    unsigned char* bit = w->bit;
    unsigned char* p = w->buf + *pos;
    unsigned short size = w->size;
    if (*bit == 0) {
        *p = val;
    } else {
        *p |= val << *bit;
    }
    *bit += n;
    if (*bit > 8) {
        (*pos)++;
        p++;
        if (*pos >= size) {
            *pos = 0;
            p = w->buf;
        }
        *p = val >> (8 - (*bit - n));
        *bit -= 8;
    } else if (*bit == 8) {
        *bit = 0;
        (*pos)++;
        if (*pos >= size) {
            *pos = 0;
        }
    }
}
