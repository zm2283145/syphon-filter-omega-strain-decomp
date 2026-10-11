extern int D_00497E34;
extern int func_004700F8(char *, int);
extern int func_00470120(char *, int, int, char *);
int func_0046AE58(char *a, int b, char *c)
{
    func_004700F8(a, 0x11);
    func_004700F8(c, 0x15);
    func_00470120(a, D_00497E34, b, c);
    if (D_00497E34 >= 0x3E7) D_00497E34 = 0;
    else D_00497E34 = D_00497E34 + 1;
    return 0;
}
