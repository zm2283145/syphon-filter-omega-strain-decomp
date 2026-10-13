extern char D_00525600[];
extern char D_00525640[];
extern int D_00525580[];
extern int D_004908D4;
extern int func_0034B230(void *a, void *b, int *list, int max);
extern int func_0034B2C0(void *a, void *b, int sock, int opt, int *out, int len);
extern int func_003060C0(void *t);
extern int func_003060F0(void *t, unsigned int *elapsed);
extern int func_003061F8(int ms);

/* Polls the socket list until one reports state 3 (stores it in D_004908D4) or ~95 s pass. */
int func_002F78D0(void)
{
    int timer[4];
    int info;
    unsigned int elapsed = 0;
    int found = 0;
    int n;
    int i;

    n = func_0034B230(D_00525600, D_00525640, D_00525580, 0x20);
    if (n <= 0) return 1;
    if (func_003060C0(timer)) return 1;
    for (;;) {
        for (i = 0; i < n; i++) {
            int sock = D_00525580[i];
            if (func_0034B2C0(D_00525600, D_00525640, sock, 8, &info, 4)) return 1;
            if ((info & 3) == 3) {
                found = 1;
                D_004908D4 = sock;
                break;
            }
        }
        if (found) break;
        if (func_003060F0(timer, &elapsed)) return 1;
        if (elapsed > 0x17318) return 1;
        if (func_003061F8(2)) return 1;
    }
    return 0;
}

