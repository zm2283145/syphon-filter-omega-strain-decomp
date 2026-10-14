extern void (*D_00497D04)(int, int, int, char *);
extern void func_00467D18(char *);
int func_0046C9A0(int a, int b, int c, char *d)
{
    if (*(int *)(d + 0x18) == 0) func_00467D18(d + 0x44);
    if (D_00497D04) D_00497D04(a, b, c, d);
    return 0xC4;
}
