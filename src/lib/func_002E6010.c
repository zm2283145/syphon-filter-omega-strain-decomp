extern int func_002E51B8(unsigned int, char **);
extern void func_002E4CA8(unsigned int);
int func_002E6010(void)
{
    char *p = 0;
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (func_002E51B8(i, &p) == 0 && p != 0 && *(int *)(p + 0x438) == 3)
            func_002E4CA8(i);
    }
    return 0;
}
