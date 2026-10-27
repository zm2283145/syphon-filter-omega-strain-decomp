int IsOne(int *a)
{
    int i;
    if (a[0] != 1) return 0;
    for (i = 1; i < 0x20; i++)
        if (a[i]) return 0;
    return 1;
}