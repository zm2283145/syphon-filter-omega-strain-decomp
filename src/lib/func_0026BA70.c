extern char D_004A87D8[];
extern char D_004A87E0[];
extern char D_004A87E8[];
extern char D_004A87F0[];
static void * const dat_0048B260[4] = { (void*)D_004A87F0, (void*)D_004A87E8, (void*)D_004A87E0, (void*)D_004A87D8 };
extern char D_004A87F8[];
extern void String_Copy(char* d, char* s);
void func_0026BA70(unsigned int i, char* dst)
{
    if (i < 4) {
        String_Copy(dst, ((char**)dat_0048B260)[i]);
        return;
    }
    dst[0] = D_004A87F8[0];
}