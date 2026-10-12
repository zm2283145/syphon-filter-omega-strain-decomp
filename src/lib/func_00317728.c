typedef struct { char pad[8]; void *buf; } Obj7728;
extern void (*D_004E1D38)(void *p);
int func_00317728(Obj7728 **pp)
{
    Obj7728 *o = *pp;
    if (o != 0) {
        if (o->buf) {
            D_004E1D38(o->buf);
            o->buf = 0;
        }
        D_004E1D38(o);
    }
    return 0;
}
