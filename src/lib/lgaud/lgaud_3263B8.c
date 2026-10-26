unsigned char tobcd(unsigned char x)
{
    return (x / 10) * 6 + x;
}