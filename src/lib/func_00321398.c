typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; char inner[0x14]; void *buf30; void *buf34; } H321;
extern unsigned short D_004E1D4C;
extern void *(*D_004E1D34)(int n, int size);
extern int func_00322E60(int);
extern int func_00323248(void);
extern int func_0031F7C8(void *p);
extern int func_003214C0(H321 **pp);
extern int printf(const char *fmt, ...);
int func_00321398(H321 **pp)
{
    H321 *h;
    int r;
    if (pp == 0) return 0x181A;
    *pp = 0;
    r = func_00322E60(0);
    if (r == 1) {
        printf("\nEvaluation period has expired.\nExiting...\n\n");
        return 0x1965;
    }
    if (r == -1) {
        printf("\nClock incorrectly set.  Please adjust to correct date and time.\nExiting...\n\n");
        return 0x1965;
    }
    h = D_004E1D34(1, 0x38);
    if (h == 0) return 0x1770;
*pp = h; h->state = 11; h->magic = 0xFACE;
    if (func_00323248() == 3) {
        h->buf30 = D_004E1D34(0x1000, 1);
        if (h->buf30 == 0) return 0x1770;
        h->buf34 = D_004E1D34(0x1000, 1);
        if (h->buf34 == 0) return 0x1770;
    }
    r = func_0031F7C8(h->inner);
    if (r) {
        func_003214C0(pp);
        return 0x1770;
    }
    D_004E1D4C++;
    return r;
}

