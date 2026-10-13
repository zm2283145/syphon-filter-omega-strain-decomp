typedef struct { char pad[0x68]; unsigned int flags; } G3F050;
typedef struct { char d[0x1C]; } L3F050;
typedef struct {
    char p0[0x78]; unsigned char b78; char p79[0x88 - 0x79];
    void* p88; char p8c[0xA8 - 0x8C]; int fA8;
    L3F050 l0, l1, l2;
} T3F050;
extern void func_0033D360(T3F050* self);
extern void func_002ACC80(void* p, int f);
extern void func_0044F6B0(L3F050* l);
extern G3F050* Gui_GetScreenStack(void);
void func_0033F050(T3F050* self)
{
    func_0033D360(self);
    self->fA8 = 0;
    if (self->p88)
        func_002ACC80(self->p88, 0);
    func_0044F6B0(&self->l0);
    func_0044F6B0(&self->l1);
    func_0044F6B0(&self->l2);
    self->b78 = 0;
    Gui_GetScreenStack()->flags &= ~3;
}