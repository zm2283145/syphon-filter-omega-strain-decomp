typedef struct { int f0; int f4; int arg; int fc; char s1[0x100]; char s2[0x100]; } M0027CDA8;
extern M0027CDA8 D_005040C0;
extern char D_00504080[];
extern void sceNetcnfifInit(char* s);
extern void Libc_Strcpy(char* d, char* s);
extern void sce_call_rpc(char* a, M0027CDA8* b, int n);void sceNetcnfifDeleteAll(char* s)
{
    M0027CDA8* m;
    sceNetcnfifInit(s);
    m = &D_005040C0;
    Libc_Strcpy(m->s1, s);
    sce_call_rpc(D_00504080, m, 7);
    __asm__ __volatile__("");
}
