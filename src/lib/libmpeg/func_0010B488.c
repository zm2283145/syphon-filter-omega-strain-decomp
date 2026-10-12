/* SDK callback dispatch: runs a handler with its own $gp */
typedef struct { int (*func)(void *, int *, void *); void *arg; void *gp; } CbB488;
typedef struct { int f0; int f4; int f8; CbB488 cb[1]; } CbTblB488;
typedef struct { char pad[0x40]; CbTblB488 *tbl; } ObjB488;
static __inline__ void *ChangeGP_B488(void *gp)
{
    void *old;
    /* $gp swap: register moves only expressible in asm */
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(gp) : "memory");
    return old;
}
static __inline__ void SetGP_B488(void *gp)
{
    /* $gp restore: register move only expressible in asm */
    __asm__ volatile("move $gp, %0" : : "r"(gp) : "memory");
}
int func_0010B488(ObjB488 *o, int *id)
{
    int r = 0;
    if (o != 0) {
        CbTblB488 *t = o->tbl;
        if (t != 0) {
            int (*f)(void *, int *, void *) = t->cb[*id].func;
            if (f != 0) {
                void *save = ChangeGP_B488(t->cb[*id].gp);
                r = f(o, id, t->cb[*id].arg);
                SetGP_B488(save);
            }
        }
    }
    return r;
}
