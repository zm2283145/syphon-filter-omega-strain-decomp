int *func_001162B0(int *p, int *end, int val)
{
    while (*p != val && p < end) p++;
    return p < end ? p : 0;
}
