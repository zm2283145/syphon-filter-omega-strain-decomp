extern int D_00492C30;
extern int D_00492C34;
extern int func_00114C88(int fd, int a, int b, int *stat);
extern int func_00114E90(int fd);
int func_00352DD0(void)
{
    int stat;
    if (D_00492C34 == 1) {
        if (func_00114C88(D_00492C30, 0, 0, &stat) >= 0) {
            stat = func_00114E90(D_00492C30);
            if (stat >= 0) {
                D_00492C34 = 0;
                stat = 0;
            }
        }
    }
    return stat;
}