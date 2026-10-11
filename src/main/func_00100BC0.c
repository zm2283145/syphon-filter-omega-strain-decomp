unsigned char* func_00100BC0(unsigned char* p, unsigned int* out)
{
    unsigned int b = p[0];
    unsigned int b1, b2;
    unsigned char* r;
    if (!(b & 1)) {
        *out = b >> 1;
        r = p + 1;
    } else {
        b1 = p[1];
        if (!(b & 2)) {
            *out = ((b >> 2) << 8) | b1;
            r = p + 2;
        } else {
            b2 = p[2];
            if (!(b & 4)) {
                *out = b2 | (((b >> 3) << 16) | (b1 << 8));
                r = p + 3;
            } else {
                *out = p[3] | ((b2 << 8) | (((b >> 3) << 24) | (b1 << 16)));
                r = p + 4;
            }
        }
    }
    return r;
}