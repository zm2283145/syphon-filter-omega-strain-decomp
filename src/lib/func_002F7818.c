extern unsigned char D_004908A0;
extern char D_00525600[];
extern int func_0034C890(char* p);
int func_002F7818(void)
{
    if (D_004908A0 != 1)
        return 5;
    return func_0034C890(D_00525600) != 0;
}
