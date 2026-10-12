#pragma always_inline on
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
typedef struct { int version; int size; unsigned int base; char* cur; } Pop_23C3C0;
struct Obj_23C3C0 { char pad[0xA0]; };
struct Self_23C3C0;
struct Info_23C3C0 {
    Obj_23C3C0* a;
    Obj_23C3C0* b;
    int c;
    int d;
    char* name;
    Info_23C3C0(Obj_23C3C0* o, int cc, int dd, char* n) : a(o), b(o), c(cc), d(dd), name(n) {}
};
struct D_23C3C0 { int v; D_23C3C0(int x) : v(x) {} };
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
class Tgt_23C3C0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void Set40(int v);
    virtual void Set44(const Info_23C3C0& i);
    static void* operator new(unsigned int sz, char* file, int line) { AllocGuard g; return Mem_Alloc(0, sz, file, line); }
    char pad4[0x68];
    Self_23C3C0* owner;
    char padE[0x1F4 - 0x70];
};
struct Self_23C3C0 {
    char pad0[0x2F];
    unsigned char b2F;
    char pad30[0x140 - 0x30];
    Tgt_23C3C0* tgt;
};
static inline char* ReadStr_23C3C0(Pop_23C3C0* r)
{
    char* s = r->cur;
    int mis;
    while (*r->cur++)
        ;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}
extern "C" {
extern char D_004A6FA8[];
extern char D_004A6FB8[];
extern char D_004FFB50[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_0036E5D0(Obj_23C3C0* o);
void func_0036E220(Obj_23C3C0* o, int f);
void Hog_Register(Obj_23C3C0* o, char* path, int a, int b);
int func_0036DEF0(Obj_23C3C0* o);
void func_0036DEC0(Obj_23C3C0* o);
void sprintf(char* buf, char* fmt, ...);
int func_00131010(char* mgr, char* name, char* buf, int* out);
void func_00130F40(char* mgr, char* buf, int* out);
void func_00130D10(char* mgr, Tgt_23C3C0* t, char* name, char* buf);
void* cVUM_GOBJ_ctor2(void* p, const D_23C3C0& d);
}
static inline Tgt_23C3C0* NewTgt_23C3C0() { void* m = Tgt_23C3C0::operator new(0x1F4, D_004A6FA8, 0x350); if (m) m = cVUM_GOBJ_ctor2(m, D_23C3C0(0)); return (Tgt_23C3C0*)m; }
extern "C" void func_0023C3C0(Self_23C3C0* self, int mode, Pop_23C3C0* r, int id)
{
    int a;
    int b;
    Obj_23C3C0 obj;
    char buf[0x40];
    char* name;
    func_0036E5D0(&obj);
    name = ReadStr_23C3C0(r);
    sprintf(buf, D_004A6FB8, id);
    Hog_Register(&obj, buf, mode, 1);
    if (!(unsigned char)func_0036DEF0(&obj)) {
        unsigned char found;
        a = 0;
        b = 0;
        found = func_00131010(D_004FFB50, name, buf, &a);
        func_00130F40(D_004FFB50, buf, &b);
        self->tgt = NewTgt_23C3C0();
        self->tgt->owner = self;
        if (!found) {
            func_00130D10(D_004FFB50, self->tgt, name, buf);
            a = 0;
        }
        self->tgt->Set40(0);
        self->tgt->Set44(Info_23C3C0(&obj, a, b, name));
        self->b2F = 1;
        func_0036DEC0(&obj);
    } else {
        self->tgt = 0;
    }
    func_0036E220(&obj, -1);
}








