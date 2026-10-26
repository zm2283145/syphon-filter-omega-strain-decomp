extern char D_004B0DE0[];
extern char D_004B0E18[];
extern void printf(const char *fmt, const char *file, int line, const char *msg);
extern int func_00312E28(void *p);
extern int rt_memory_free(void *pp);
int RtXml_DestroyParser(void *p)
{
    if (p == 0) {
        printf(D_004B0DE0, D_004B0E18, 0x116, "NULL != parser");
        return 3;
    }
    if (func_00312E28(p) != 0) printf(D_004B0DE0, D_004B0E18, 0x11A, "RT_XMLPARSE_OK == err");
    rt_memory_free(&p);
    return 0;
}