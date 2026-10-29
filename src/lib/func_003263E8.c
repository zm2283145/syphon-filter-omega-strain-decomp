unsigned char frombcd(unsigned char x)
{
    unsigned char t = (x >> 4) * 6;
    return x - t;
}
