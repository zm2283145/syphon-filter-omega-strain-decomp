int func_00319BE0(int* a, int n, int v)
{
    int i;
    int found = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == v) {
            found = 1;
            break;
        }
    }
    return found;
}