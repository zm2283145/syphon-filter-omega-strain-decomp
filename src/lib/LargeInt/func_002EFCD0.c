int LargeInt_IsZero(int *a)
{
    int i;
    for (i = 0; i < 0x20; i++)
        if (a[i]) return 0;
    return 1;
}