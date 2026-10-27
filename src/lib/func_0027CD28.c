typedef struct { int f0; int f4; int arg; int fc; char s1[0x100]; char s2[0x100]; } M0027CD28;
extern M0027CD28 D_005040C0;
extern char D_00504080[];
extern void sceNetcnfifInit();
extern void Libc_Strcpy(char* d, char* s);
extern void sce_call_rpc(char* a, M0027CD28* b, int n);void sceNetcnfifSetLatestEntry(char* s, int b, char* t)
{
    M0027CD28* m;
    sceNetcnfifInit();
    m = &D_005040C0;
    Libc_Strcpy(m->s1, s);
    m->arg = b;
    Libc_Strcpy(m->s2, t);
    sce_call_rpc(D_00504080, m, 6);
    __asm__ __volatile__("");
}
