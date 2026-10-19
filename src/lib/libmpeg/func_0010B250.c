typedef struct { char pad[0xC8]; int xC8; char pad2[0xF0-0xCC]; unsigned int xF0; int xF4; int xF8; int xFC; } X_0010B250;
typedef struct { char pad[0x40]; X_0010B250* x; } O_0010B250;
extern void func_0010B690(O_0010B250* o);
void sceMpegGetPicture(O_0010B250* o, unsigned int a, int b)
{
    X_0010B250* x = o->x;
    x->xC8 = 1;
    x->xF0 = (a & 0x0FFFFFFF) | 0x20000000;
    x->xFC = b;
    x->xF8 = 0;
    x->xF4 = 0;
    func_0010B690(o);
}
