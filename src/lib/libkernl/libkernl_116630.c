int kCopy_void_4(volatile unsigned char* d, volatile unsigned char* s, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++) *d++ = *s++;
    return 0;
}