typedef struct { int f0; int f4; int arg; int fc; char s1[0x100]; char s2[0x100]; } M0027CD28;
extern M0027CD28 D_005040C0;
extern char D_00504080[];
extern void func_0027C3D0();
extern void String_Copy(char* d, char* s);
extern void func_0027D3A8(char* a, M0027CD28* b, int n);void func_0027CD28(char* s, int b, char* t)
{
    M0027CD28* m;
    func_0027C3D0();
    m = &D_005040C0;
    String_Copy(m->s1, s);
    m->arg = b;
    String_Copy(m->s2, t);
    func_0027D3A8(D_00504080, m, 6);
    __asm__ __volatile__("");
}
