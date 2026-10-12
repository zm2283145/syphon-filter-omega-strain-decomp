extern int D_004928E8;
extern int D_004928EC;
extern int func_00114C88(int fd, int a, int b, int *stat);
extern int func_00114E90(int fd);
int func_0033F608(void)
{
    int stat;
    if (D_004928EC == 1) {
        if (func_00114C88(D_004928E8, 0, 0, &stat) >= 0) {
            stat = func_00114E90(D_004928E8);
            if (stat >= 0) {
                D_004928EC = 0;
                stat = 0;
            }
        }
    }
    return stat;
}