typedef struct { void *p0; void *p4; void *p8; void *pC; void *p10; void *p14; void *p18; } ObjF938;
extern int (*D_004E1D38)(void *p);
extern void func_00322128(ObjF938 *o);
int func_0031F938(ObjF938 **pp)
{
    ObjF938 *o = *pp;
    if (o != 0) {
        if (o->p4) { D_004E1D38(o->p4); o->p4 = 0; }
        func_00322128(o);
        if (o->pC) { D_004E1D38(o->pC); o->pC = 0; }
        if (o->p10) { D_004E1D38(o->p10); o->p10 = 0; }
        if (o->p14) { D_004E1D38(o->p14); o->p14 = 0; }
        if (o->p18) { D_004E1D38(o->p18); o->p18 = 0; }
        if (o->p8) { D_004E1D38(o->p8); o->p8 = 0; }
        D_004E1D38(o);
    }
    return 0;
}
