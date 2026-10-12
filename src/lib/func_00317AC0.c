typedef struct { void *p0; char a4[0xC]; char a10[4]; char a14[4]; char a18[0x30]; void *buf; } Obj7AC0;
extern void (*D_004E1D38)(void *p);
extern void func_0031A090(void *p);
extern void func_0031C898(void *p);
extern void func_00318AC8(void *p);
extern void func_00317728(void *p);
extern int func_003186E0(void *p);
int func_00317AC0(Obj7AC0 **pp)
{
    Obj7AC0 *o = *pp;
    if (o != 0) {
        func_0031A090(o);
        func_0031C898(o->a4);
        func_00318AC8(o->a10);
        func_00317728(o->a14);
        func_003186E0(o->a18);
        if (o->buf) {
            D_004E1D38(o->buf);
            o->buf = 0;
        }
        D_004E1D38(o);
    }
    return 0;
}
