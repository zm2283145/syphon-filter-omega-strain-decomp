int IsEqual(int *a, int *b)
{
    int i;
    for (i = 0; i < 0x20; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}