extern unsigned char D_0055D450;
extern unsigned char* D_0055D050[];

unsigned char func_003FD6B0(unsigned short c)
{
    unsigned char* t;
    unsigned char r;
    if (!D_0055D450)
        return 0xFF;
    t = D_0055D050[(c >> 8) & 0xFF];
    r = t ? t[c & 0xFF] : 0xFF;
    if (r != 0xFF) {
        return c < 0x20 ? r : (unsigned char)(r + 0x20);
    }
    return 0xFF;
}


