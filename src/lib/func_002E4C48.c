typedef struct { unsigned char b[24]; } B2E4C48;
extern B2E4C48 D_00520340;
int func_002E4C48(B2E4C48* p)
{
    if (p == 0) return 10;
    if (*(int*)p != 0x18) return 0x27;
    *p = D_00520340;
    return 0;
}