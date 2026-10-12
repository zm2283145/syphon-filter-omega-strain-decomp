extern unsigned int func_00357150(void);

unsigned int func_00357640(void)
{
    unsigned int v = func_00357150();
    if ((v & 0x80000000) == 0) return v >> 24;
    if ((v & 0xC0000000) != 0x80000000) return v >> 8;
    return v >> 16;
}
