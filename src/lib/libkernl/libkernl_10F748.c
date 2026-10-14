/* SDK callback-table registration (stores handler, argument and caller $gp) */
typedef struct { void *func; void *arg; void *gp; } CbF748;
typedef struct { int f0; int f4; int f8; CbF748 *neg; int f10; CbF748 *pos; } CbTblF748;
extern CbTblF748 D_004E2D58;
void func_0010F748(int id, void *func, void *arg)
{
    void *gp;
    if (id < 0) {
        int i = id & 0x7FFFFFFF;
        D_004E2D58.neg[i].func = func;
        D_004E2D58.neg[i].arg = arg;
        /* read the caller's $gp (no C equivalent; memory clobber keeps the table reload) */
        __asm__ volatile("move %0, $gp" : "=r"(gp) : : "memory");
        D_004E2D58.neg[i].gp = gp;
    } else {
        D_004E2D58.pos[id].func = func;
        D_004E2D58.pos[id].arg = arg;
        /* read the caller's $gp (no C equivalent; memory clobber keeps the table reload) */
        __asm__ volatile("move %0, $gp" : "=r"(gp) : : "memory");
        D_004E2D58.pos[id].gp = gp;
    }
}
