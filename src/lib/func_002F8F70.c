extern void *memset(void *, int, unsigned int);
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
void func_002F8F70(int a, int b)
{
    char *s;
    int h = func_002F7D68(a);
    if (h == 0) return;
    s = func_002F7ED8(h, b);
    if (s == 0) return;
    if (*(void **)(s + 0x18)) memset(*(void **)(s + 0x18), 0, 0x40);
    if (*(void **)(s + 0x10)) memset(*(void **)(s + 0x10), 0, 0x10C);
    if (*(void **)(s + 0x14) == 0) memset(*(void **)(s + 0x14), 0, 0x10C);
}
