extern int D_00490908;
extern int func_002F8908(int, int);
int func_002FB5C8(void)
{
    if (D_00490908 == 0) {
        if (func_002F8908(0, 0) == 0) D_00490908 = 1;
        else D_00490908 = 2;
    }
    return D_00490908;
}
