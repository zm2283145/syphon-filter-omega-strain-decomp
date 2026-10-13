extern int func_002E51B8(unsigned int, void **);
void *func_002E54A0(unsigned int slot)
{
    void *p = 0;
    if (slot >= 4) return 0;
    if (func_002E51B8(slot, &p) == 0 && p != 0) return (char *)p + 0x408;
    return 0;
}
