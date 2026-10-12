static const unsigned int dat_00490908[2] = { 0x0, 0x0 };
extern int func_002F8908(int, int);
int func_002FB5C8(void)
{
    if ((*(int*)dat_00490908) == 0) {
        if (func_002F8908(0, 0) == 0) (*(int*)dat_00490908) = 1;
        else (*(int*)dat_00490908) = 2;
    }
    return (*(int*)dat_00490908);
}
