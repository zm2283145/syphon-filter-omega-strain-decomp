extern char D_004B0DE0[];
extern char D_004B0E18[];
extern char D_004B0EC0[];
extern char D_004B0F50[];
extern int printf(const char *, ...);
extern int Net_AllocZeroed(void **pp, unsigned long size);
typedef struct { void *ptr; unsigned int size; } Slot3111E0;
typedef struct { Slot3111E0 slot[0x1000]; unsigned int limit; unsigned int used; } Ctx3111E0;
int func_003111E0(Ctx3111E0 *c, void **pp, unsigned int size)
{
    unsigned int i;
    int r;
    if (c->used + size <= c->limit) {
        for (i = 0; i < 0x1000; i++) {
            if (c->slot[i].ptr == 0) {
                r = Net_AllocZeroed(pp, size);
                if (r != 0) {
                    printf(D_004B0DE0, D_004B0E18, 0x19A, D_004B0EC0);
                    return 2;
                }
                if (*pp == 0) {
                    printf(D_004B0DE0, D_004B0E18, 0x19B, D_004B0F50);
                    return 2;
                }
                c->slot[i].ptr = *pp;
                c->slot[i].size = size;
                c->used += size;
                return r;
            }
        }
    }
    return 2;
}
