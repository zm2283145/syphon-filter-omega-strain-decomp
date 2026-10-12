extern char D_004B0DE0[];
extern char D_004B0E18[];
extern int func_00127358(const char *, ...);
extern int func_002FB3C0(void *p);
typedef struct { void *ptr; int size; } Slot311320;
typedef struct { Slot311320 slot[0x1000]; int count; int used; } Ctx311320;
int func_00311320(Ctx311320 *c, void **pp)
{
    unsigned int i;
    for (i = 0; i < 0x1000; i++) {
        if (*pp == c->slot[i].ptr) {
            func_002FB3C0(pp);
            c->used -= c->slot[i].size;
            *pp = 0;
            c->slot[i].ptr = 0;
            c->slot[i].size = 0;
            break;
        }
    }
    if (*pp) {
        if ("Freeing a pointer that wasn't alloc'd by me!")
            func_00127358(D_004B0DE0, D_004B0E18, 0x1BB, "!\"Freeing a pointer that wasn't alloc'd by me!\"");
        func_002FB3C0(pp);
    }
    return 0;
}