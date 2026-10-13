extern int RemoveIntcHandler(int, int);
int func_002FA480(int a, int b, int *c)
{
    if (b >= 0) {
        int n = RemoveIntcHandler(a, b);
        if (n > 0) *c += n;
    }
    return 0;
}