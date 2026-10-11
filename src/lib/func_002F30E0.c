extern void func_002D7768(int);
extern void func_00315EB0(int);
extern int func_002D8AD8(int);
extern void func_002F4180(int, int);
extern void func_002F3F00(int, int);
extern void func_002FB3C0(void *);
void func_002F30E0(char *s)
{
    if (s == 0) return;
    if (*(int *)(s + 0x840)) {
        func_002D7768(*(int *)(s + 0x840));
        *(int *)(s + 0x840) = 0;
    }
    if (*(int *)(s + 0x844)) {
        func_00315EB0(*(int *)(s + 0x844));
        *(int *)(s + 0x844) = 0;
    }
    if (*(int *)(s + 0x848)) {
        func_002F4180(func_002D8AD8(*(int *)(s + 8)), *(int *)(s + 0x848));
        *(int *)(s + 0x848) = 0;
    }
    if (*(int *)(s + 0x84C)) {
        func_002F3F00(func_002D8AD8(*(int *)(s + 8)), *(int *)(s + 0x84C));
        *(int *)(s + 0x84C) = 0;
    }
    func_002FB3C0(&s);
}
