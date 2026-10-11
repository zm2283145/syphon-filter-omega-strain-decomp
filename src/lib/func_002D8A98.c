extern void func_002F3F00(int, int);
extern void func_002D8E40(char *);
void func_002D8A98(char *o)
{
    int v = *(int *)(o + 0x60);
    if (v) {
        func_002F3F00(*(int *)(o + 0x5C), v);
        *(int *)(o + 0x60) = 0;
        *(int *)(o + 0x90) = 0;
    }
    func_002D8E40(o);
}