extern unsigned char D_004F58C0[];
extern unsigned char* D_004F5818;
int func_00223A48(void)
{
    unsigned char* s = D_004F58C0;
    unsigned char* d = D_004F5818;
    int i;
    if (s[6]) return -1;
    for (i = 6; i >= 0; i--) *d++ = *s++;
    return 0;
}