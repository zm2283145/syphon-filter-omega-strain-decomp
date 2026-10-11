int func_002F7D28(unsigned char *s)
{
    unsigned int i;
    if (s != 0) {
        for (i = 0; i < 0x40; i++)
            if (s[i]) return 0;
    }
    return 1;
}