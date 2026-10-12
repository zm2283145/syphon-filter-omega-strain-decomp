typedef struct { char pad[8]; void *buf; } ObjA090;
extern void (*D_004E1D38)(void *p);
void func_0031A090(ObjA090 **pp)
{
    if (*pp == 0) return;
    if ((*pp)->buf) {
        D_004E1D38((*pp)->buf);
        (*pp)->buf = 0;
    }
    if (*pp) {
        D_004E1D38(*pp);
        *pp = 0;
    }
}
