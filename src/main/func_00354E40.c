#pragma cplusplus on
#include "types.h"

struct W4E40 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char* begin; char* end; char* cap; int pad; } Str4E40;
typedef struct { int id; char pad4[4]; unsigned char flag; char pad9[0x14 - 9]; } E4E40;
struct L4E40 {
    int a0;
    int count;
    E4E40* data;
    unsigned char aC;
    int size() const { return count; }
};
typedef struct { char pad[0x14]; unsigned short flags; } P4E40;
typedef struct {
    char pad0[0x6C]; char s6C[0xC]; char s78[0xC];
    unsigned char kind; char pad85[3]; int arg; int f8C; int f90; bool on;
    char pad95[0xA4 - 0x95]; P4E40* fA4;
} O4E40;

extern "C" {
extern char D_004BB088[];
static char* D_00492C48 = D_004BB088;
extern char D_004A7520[];
extern char D_004FFB50[];
extern const char* D_0048C160[];
void String_CtorCStr_13B480(Str4E40* s, const char* text);
void func_0013D680(void* dst, Str4E40* s);
void String_Dtor(Str4E40* s, int flags);
W4E40* GuiWidget_FindChildByName(void* o, char* name);
void* Agent_GetSelected(void* p, int i);
void func_00296FA0(L4E40* l);
void func_00299360(L4E40* l, int flags);
void func_003334C0(void* ag, unsigned char kind, L4E40* l);
void func_0041C0F0(W4E40* w, int v);
void func_0041BEB0(W4E40* w, int text, int f);
int Loc_LookupText(const char* key);
enum E4E40on { ON0, ON1 };
void func_00355490(O4E40* o, unsigned char on);
void func_00354E40(O4E40* self, const char* a, const char* b, unsigned char kind, int arg, int c, int d);
}

/* The &l.data local and the re-derived element pointer reproduce retail register allocation; the enum ternary keeps the movz/andi argument. */
static inline W4E40* Cast(W4E40* w, void* t) { return w && w->IsA(t) ? w : 0; }

void func_00354E40(O4E40* self, const char* a, const char* b, unsigned char kind, int arg, int c, int d)
{
    W4E40* w;
    {
        Str4E40 s;
        String_CtorCStr_13B480(&s, a);
        func_0013D680(self->s6C, &s);
        String_Dtor(&s, 0);
    }
    {
        Str4E40 s;
        String_CtorCStr_13B480(&s, b);
        func_0013D680(self->s78, &s);
        String_Dtor(&s, 0);
    }
    self->kind = kind;
    self->arg = arg;
    self->f8C = c;
    self->f90 = d;
    w = Cast(GuiWidget_FindChildByName(self, D_00492C48), D_004A7520);
    if (w) {
        void* ag = Agent_GetSelected(D_004FFB50, -1);
        if (self->kind != 6) {
            L4E40 l;
            func_00296FA0(&l);
            l.aC = 1;
            func_003334C0(ag, kind, &l);
            if (arg < l.size()) {
                func_0041C0F0(w, 1);
                E4E40** pd = &l.data;
                E4E40* e = *pd + arg;
                func_0041BEB0(w, e->id, 0);
                e = *pd + arg;
                self->on = e->flag != 0;
                func_00355490(self, self->on ? ON1 : ON0);
            }
            func_00299360(&l, 0);
        } else {
            const char* name = 0;
            if (self->arg >= 0 && self->arg < 17)
                name = D_0048C160[self->arg];
            if (name) {
                func_0041BEB0(w, Loc_LookupText(name), 0);
                func_0041C0F0(w, 1);
            }
            self->on = false;
            func_00355490(self, ON0);
        }
    }
    if (self->fA4) {
        if (self->on)
            self->fA4->flags |= 2;
        else
            self->fA4->flags &= ~2;
    }
}

