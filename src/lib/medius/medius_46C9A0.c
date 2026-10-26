extern void (*D_00497D04)(int, int, int, char *);
extern void MediusSetNatServiceAddress(char *);
int MediusUniqueCallbackAccountLoginResponseHandler(int a, int b, int c, char *d)
{
    if (*(int *)(d + 0x18) == 0) MediusSetNatServiceAddress(d + 0x44);
    if (D_00497D04) D_00497D04(a, b, c, d);
    return 0xC4;
}
