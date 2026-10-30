typedef struct Blk { struct Blk* next; struct Blk* prev; unsigned int size; } Blk;
extern Blk* D_005335E8;
extern Blk* D_005335EC;
extern Blk* D_005335F0;
extern Blk* D_005335F4;
extern void* (*D_005335D8)(unsigned int);
extern void (*D_005335DC)(void*);
#define NX(b) (*(Blk**)(b))
#define PV(b) (((Blk**)(b))[1])
#define SZ(b) (((unsigned int*)(b))[2])
void* mem_alloc(unsigned int size);
void mem_free(void* ptr);

int sceInsockInitMemory(char* p, unsigned int n)
{
    unsigned int m = (unsigned int)p & 3;

    if (m != 0) {
        if (n < m) {
        fail:
            return -1;
        }
        p += m;
        n -= m;
    }
    if (n < 12) {
        goto fail;
    }
    D_005335EC = D_005335E8 = (Blk*)p;
    NX(p) = PV(p) = 0;
    {
        /* last resort: keeps n - 12 in n's register (t0) so the size store precedes the F0 store */
        register unsigned int sz asm("$8") = n - 12;
        ((Blk*)p)->size = sz;
    }
    D_005335F0 = (Blk*)p;
    D_005335F4 = (Blk*)(p + n);
    D_005335D8 = mem_alloc;
    D_005335DC = mem_free;
    return 0;
}