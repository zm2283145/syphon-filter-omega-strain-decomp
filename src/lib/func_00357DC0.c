typedef struct Blk { struct Blk* next; struct Blk* prev; unsigned int size; } Blk;
extern Blk* D_005335E0;
extern Blk* D_005335E4;
extern Blk* D_005335E8;
extern Blk* D_005335EC;
extern Blk* D_005335F4;
/* Block header accessors: plain pointer derefs (not struct member refs) so they
   alias the list-head globals under gcc 2.9 strict aliasing; b->next in the
   append path is a real member ref (no alias with D_005335E4) as in retail. */
#define NX(b) (*(Blk**)(b))
#define PV(b) (((Blk**)(b))[1])
#define SZ(b) (((unsigned int*)(b))[2])
void* mem_alloc(unsigned int size)
{
    Blk* p;
    Blk* b;
    unsigned int rem;
    size = (size + 3) & 0xFFFFFFFC;
    for (p = D_005335E8; p; p = NX(p)) {
        if (size < SZ(p)) break;
    }
    if (!p) return 0;
    rem = SZ(p) - (size + 0xC);
    b = p;
    if (rem) {
        p = (Blk*)((char*)b + (size + 0xC));
        SZ(b) = size;
        SZ(p) = rem;
        { Blk* n = NX(b); NX(p) = n; if (n) PV(n) = p; else D_005335EC = p; }
        { Blk* q = PV(b); PV(p) = q; if (q) NX(q) = p; else D_005335E8 = p; }
    } else {
        { Blk* n = NX(b); Blk* q = PV(b); if (n) PV(n) = q; else D_005335EC = q; }
        if (PV(p)) NX(PV(p)) = NX(p); else D_005335E8 = NX(p);
    }
    p = (Blk*)((char*)p + (SZ(p) + 0xC));
    if (!D_005335E0) {
        PV(b) = 0;
        NX(b) = 0;
        D_005335E4 = b;
        D_005335E0 = b;
    } else if (p >= D_005335F4) {
        Blk* t;
        b->next = 0;
        t = D_005335E4; PV(b) = t;
        NX(t) = b;
        D_005335E4 = b;
    } else {
        Blk* q;
        q = PV(p); PV(b) = q;
        if (q) NX(q) = b; else D_005335E0 = b;
        NX(b) = p;
        PV(p) = b;
    }
    return (char*)b + 0xC;
}
