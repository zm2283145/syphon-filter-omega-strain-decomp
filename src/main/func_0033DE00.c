typedef struct { char pad[0x28]; char key[4]; char p2c[0x68 - 0x2C]; unsigned int flags; } G3DE00;
typedef struct { int id; char a[0x20]; char b[0x40]; unsigned char c; } E3DE00;
typedef struct { char d[0x4]; int count; } L3DE00;
typedef struct {
    char p0[0x8C]; void* p8C; char p90[0xAC - 0x90];
    char lAC[4]; int count;
} T3DE00;
extern void func_0033D310(T3DE00* self);
extern G3DE00* Gui_GetScreenStack(void);
extern T3DE00** func_0033DEF0(void* key);
extern int func_004294C0(void);
extern E3DE00* func_0044F290(void* list, int i);
extern void func_002AEC90(void* p, char* a, char* b, unsigned char c);
extern void func_0044F7E0(void* list);
void func_0033DE00(T3DE00* self)
{
    G3DE00* g;
    int on;
    int i;
    func_0033D310(self);
    on = *func_0033DEF0(Gui_GetScreenStack()->key) == self;
    g = Gui_GetScreenStack();
    if (on)
        g->flags |= 3;
    else
        g->flags &= ~3;
    if (func_004294C0() && self->count) {
        for (i = 0; i < self->count; i++) {
            E3DE00* e = func_0044F290(self->lAC, i);
            if (e)
                func_002AEC90(self->p8C, e->a, e->b, e->c);
        }
        func_0044F7E0(self->lAC);
    }
}