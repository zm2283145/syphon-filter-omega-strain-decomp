typedef struct { int n; int b; unsigned char data[1]; } KB223478;
extern unsigned char D_004F58C0[];
extern KB223478* D_004F5818;
int func_00223478(void)
{
    int i;
    KB223478* p = D_004F5818;
    unsigned char* s = D_004F58C0;
    p->n = s[0];
    p->b = s[1];
    for (i = 0; i < p->n; i++) {
        p->data[i] = s[i + 2];
    }
    return 0;
}
