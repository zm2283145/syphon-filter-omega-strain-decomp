void func_002EFE68(unsigned int *a, unsigned int n)
{
    unsigned int i;
    i = 0;
    goto first;
borrow:
    a[i] = -1;
    goto next;
first:
    if (a[i] < n) {
        a[i] -= n;
        goto next;
    }
    a[i] -= n;
    return;
next:
    i++;
    if (i >= 32) return;
    if (i == 0) goto first;    if (a[i] != 0) a[i] -= 1;
    else goto borrow;
}
