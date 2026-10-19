extern char D_00529740[];
extern char D_00529640[];
extern char D_005296C0[];
extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);

void func_002F80C0(int id, void *p)
{
    if (id == -1) {
        if (p)
            memcpy(D_00529740, p, 128);
        else
            memset(D_00529740, 0, 128);
    } else if (id == (int)0x80000000) {
        if (p)
            memcpy(D_00529640, p, 128);
        else
            memset(D_00529640, 0, 128);
    } else {
        if (p)
            memcpy(D_005296C0, p, 128);
        else
            memset(D_005296C0, 0, 128);
    }
}
