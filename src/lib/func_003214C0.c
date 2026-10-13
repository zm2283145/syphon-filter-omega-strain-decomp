typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; char inner[0x14]; void *buf30; void *buf34; } H321;
extern unsigned short D_004E1D4C;
extern void (*D_004E1D38)(void *p);
extern void func_0031F938(void *p);
int func_003214C0(H321 **pp)
{
    H321 *h;
    if (pp == 0) return 0x181A;
    if (*pp == 0 || (*pp)->magic != 0xFACE) return 0x17D4;
    if ((*pp)->state != 11) return 0x17E3;
    D_004E1D4C--;
    h = *pp;
    h->magic = 0;
    func_0031F938(h->inner);
    if (h->buf30) { D_004E1D38(h->buf30); h->buf30 = 0; }
    if (h->buf34) { D_004E1D38(h->buf34); h->buf34 = 0; }
    D_004E1D38(h);
    return 0;
}
