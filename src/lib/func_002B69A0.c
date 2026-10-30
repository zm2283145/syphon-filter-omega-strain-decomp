typedef struct { int buf[0x200]; int f800; int f804; char cwd[0x80]; int f888; int f88C; int f890; int f894; } MC2Cache69A0;
extern MC2Cache69A0 D_00512C88[];
extern void* memcpy(void*, const void*, unsigned int);
extern char D_004AC1C8[2];
int _sceMcFatInit(void)
{
    int i;
    for (i = 0; i < 2; i++) {
        D_00512C88[i].f800 = -1;
        D_00512C88[i].f804 = -1;
        D_00512C88[i].f894 = 0;
        D_00512C88[i].f888 = 1;
        D_00512C88[i].f88C = 0;
        D_00512C88[i].f890 = 0;
        /* Reuse the shared root-directory string, including its terminator. */
        memcpy(D_00512C88[i].cwd, D_004AC1C8, 2);
    }
    return 1;
}
