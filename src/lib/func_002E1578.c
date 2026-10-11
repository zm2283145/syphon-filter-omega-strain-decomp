extern int func_002E15E0(int *);
int func_002E1578(int *a, int *st)
{
    int r;
    if (st == 0) return 0x17;
    st[1] = 0x1E;
    st[0] = 1;
    if (a == 0) {
        st[1] = 0x17;
        return 0x17;
    }
    if (*a != 1) return 0x26;
    r = func_002E15E0(a);
    st[1] = r;
    return r;
}