extern char *strncpy(char *, const char *, unsigned int);
extern char D_00497CD0[];
extern void (*D_00497CF8)(int, int, int, char *);
int MediusUniqueCallbackSessionBeginResponseHandler(int a, int b, int c, char *d)
{
    if (*(int *)(d + 0x18) == 0) strncpy(D_00497CD0, d + 0x1C, 0x11);
    if (D_00497CF8) D_00497CF8(a, b, c, d);
    return 0x30;
}
