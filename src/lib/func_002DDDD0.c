void func_002DDDD0(unsigned char *o, int bit)
{
    if (o == 0 || (unsigned int)bit >= 0x100) return;
    if (bit < *(int *)(o + 0x24)) *(int *)(o + 0x24) = bit;
    if (*(int *)(o + 0x28) < bit) *(int *)(o + 0x28) = bit;
    o[bit >> 3] |= 1 << (bit & 7);
}