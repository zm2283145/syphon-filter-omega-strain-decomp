/* htonl-style byte swap (libinsck). The do-while(0) keeps the first shift ahead of the masked term (loop notes block scheduling). */
unsigned int func_00357150(unsigned int x)
{
    unsigned int r, t;
    do { r = x << 24; } while (0);
    t = x & 0xFF00;
    t <<= 8;
    r |= t;
    t = x >> 8;
    t &= 0xFF00;
    r |= t;
    t = x >> 24;
    r |= t;
    return r;
}

