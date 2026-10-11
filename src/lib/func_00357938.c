extern char D_004BB490[];
extern int sprintf(char* buf, const char* fmt, ...);
extern int* func_003583F0();
extern int func_00357D40();
extern int* func_00123320();
extern void String_Copy(char* d, char* s);
char* func_00357938(unsigned char* a, char* dst, unsigned int size)
{
    char buf[16];
    if (size < (unsigned int)sprintf(buf, D_004BB490, a[0], a[1], a[2], a[3])) {
        *func_003583F0() = 0x1C;
        if (func_00357D40()) {
            int* e = func_00123320();
            *e = *func_003583F0();
        }
        return 0;
    }
    String_Copy(dst, buf);
    return dst;
}