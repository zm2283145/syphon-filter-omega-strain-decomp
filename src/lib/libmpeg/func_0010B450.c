typedef void *(*CbFnB450)(void *, int *, void *);
typedef struct { CbFnB450 func; void *arg; void *gp; } CbB450;
typedef struct { int f0; int f4; int f8; CbB450 cb[1]; } CbTblB450;
typedef struct { char pad[0x40]; CbTblB450 *tbl; } ObjB450;
static __inline__ void *GetGP_B450(void)
{
    void *gp;
    /* reading $gp is only expressible in asm */
    __asm__ volatile("move %0, $gp" : "=r"(gp));
    return gp;
}
CbFnB450 func_0010B450(ObjB450 *o, int type, CbFnB450 func, void *arg)
{
    CbTblB450 *t = o->tbl;
    CbFnB450 old = t->cb[type].func;
    t->cb[type].func = func;
    t->cb[type].arg = arg;
    t->cb[type].gp = GetGP_B450();
    return old;
}
