int func_002F7CE8(int *a)
{
    unsigned int i;
    if (a != 0) {
        for (i = 0; i < 0x10; i++)
            if (a[i]) return 0;
    }
    return 1;
}