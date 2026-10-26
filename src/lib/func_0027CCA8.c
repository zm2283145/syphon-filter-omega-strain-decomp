typedef struct { int f0; int f4; int arg; int fc; char s1[0x100]; char s2[0x100]; } M0027CCA8;
extern M0027CCA8 D_005040C0;
extern char D_00504080[];
extern void sceNetcnfifInit();
extern void String_Copy(char* d, char* s);
extern void sce_call_rpc(char* a, M0027CCA8* b, int n);void sceNetcnfifDeleteEntry(char* s, int b, char* t)
{
    M0027CCA8* m;
    sceNetcnfifInit();
    m = &D_005040C0;
    String_Copy(m->s1, s);
    m->arg = b;
    String_Copy(m->s2, t);
    sce_call_rpc(D_00504080, m, 5);
    __asm__ __volatile__("");
}
