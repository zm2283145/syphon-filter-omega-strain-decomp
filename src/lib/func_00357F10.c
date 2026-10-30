typedef struct Blk { struct Blk* next; struct Blk* prev; unsigned int size; } Blk;
extern Blk* D_005335E0;
extern Blk* D_005335E4;
extern Blk* D_005335E8;
extern Blk* D_005335EC;
extern Blk* D_005335F4;
/* Block header accessors: plain pointer derefs (not struct member refs) so they
   alias the list-head globals under gcc 2.9 strict aliasing; b->next in the
   append path is a real member ref (no alias with D_005335EC) as in retail. */
#define NX(b) (*(Blk**)(b))
#define PV(b) (((Blk**)(b))[1])
#define SZ(b) (((unsigned int*)(b))[2])
void mem_free(void* ptr)
{
    Blk* b;
    Blk* nb;
    Blk* pr;
    if (!ptr) return;
    b = (Blk*)((char*)ptr - 0xC);
    { Blk* n = NX(b); Blk* q = PV(b); if (n) PV(n) = q; else D_005335E4 = q; }
    { Blk* q = PV(b); Blk* n = NX(b); if (q) NX(q) = n; else D_005335E0 = n; }
    for (nb = b; NX(nb) == (Blk*)((char*)nb + (SZ(nb) + 0xC)); nb = NX(nb)) ;
    nb = (Blk*)((char*)nb + (SZ(nb) + 0xC));
    if (nb < D_005335F4) {
        Blk* q = PV(nb); PV(b) = q;
        if (q) NX(q) = b; else D_005335E8 = b;
        NX(b) = nb;
        PV(nb) = b;
    } else {
        Blk* t;
        b->next = 0;
        t = D_005335EC; PV(b) = t;
        if (t) NX(t) = b; else D_005335E8 = b;
        D_005335EC = b;
    }
    pr = PV(b);
    if (pr) {
        unsigned int s = SZ(pr) + 0xC;
        if ((Blk*)((char*)pr + s) == b) {
            SZ(pr) = s + SZ(b);
            b = pr;
            NX(b) = NX(NX(b));
            if (NX(b)) PV(NX(b)) = b; else D_005335EC = b;
        }
    }
    if (NX(b)) {
        unsigned int s = SZ(b) + 0xC;
        Blk* nx = (Blk*)((char*)b + s);
        if (nx == NX(b)) {
            Blk* t;
            SZ(b) = s + SZ(nx);
            t = NX(nx);
            NX(b) = t;
            if (t) PV(t) = b; else D_005335EC = b;
        }
    }
}