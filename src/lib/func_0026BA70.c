extern char* D_0048B260[];
extern char D_004A87F8[];
extern void String_Copy(char* d, char* s);
void func_0026BA70(unsigned int i, char* dst)
{
    if (i < 4) {
        String_Copy(dst, D_0048B260[i]);
        return;
    }
    dst[0] = D_004A87F8[0];
}