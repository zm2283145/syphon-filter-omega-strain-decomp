/*
 * main/guiManager: 3 files, 00417790-004178E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00417790 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct E_417790 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; };
struct I_417790 { int f0; float t; };
struct W_417790 {
    VPAD8(p) VPAD4(q)
    virtual void Update(float dt);
    char pad[0x10];
    unsigned short flags;
};
struct O_417790 {
    int f0;
    W_417790* w;
    char pad[0x1C];
    I_417790* inst;
    char pad28[0x58];
    E_417790* cur;
    bool Done();
};
extern "C" void IeElement_UpdateAnimation(I_417790* i, float dt);

inline bool O_417790::Done()
{
    if (cur == 0 || inst == 0 || cur->kind != 1 || (float)cur->y == inst->t) return true;
    return false;
}

extern "C" void GuiInterfaceDecorator_Update(O_417790* o, float dt)
{
    if (o->inst) IeElement_UpdateAnimation(o->inst, dt);
    {
        unsigned short& f = o->w->flags;
        if ((f & 0x10) && (f & 8)) {
            if (o->Done()) f &= ~8;
        }
    }
    o->w->Update(dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_00417790 */

/* merge_units: begin func_00417870 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct WidgetChild {
    virtual void v00(); virtual void v01();
    virtual void Method10(); /* +0x10 */
};

typedef struct GuiWidget {
    int unk0;
    WidgetChild* child; /* +0x04 */
    char pad08[0x20 - 8];
    int handle;  /* +0x20 */
    void* unk24; /* +0x24 */
} GuiWidget;

extern char D_00571DC0[];
extern "C" void IeElement_Release(void* p);
extern "C" void func_00412CF0(void* mgr, int handle);

/* Notifies the child (virtual +0x10); if a handle (+0x20) is held, releases it (IeElement_Release on +0x24, func_00412CF0) and resets it to -1. */
extern "C" void func_00417870(GuiWidget* self)
{
    self->child->Method10();
    if (self->handle != -1) {
    if (self->unk24)
    IeElement_Release(self->unk24);
    func_00412CF0(D_00571DC0, self->handle);
    self->handle = -1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00417870 */

/* merge_units: begin func_004178E0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Str_4178E0 { int w0; int len; char* data; };
struct PStr_4178E0 {
    signed char len;
    char text[0x80];
};
static inline void Cat_4178E0(PStr_4178E0* p, const char* s)
{
    char* d;
    const char* t;
    int n;
    t = s;
    n = p->len;
    d = &p->text[n];
    if (n < 0x7E) {
        while ((*d++ = *t++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    p->len = n;
}
struct W_4178E0 {
    VPAD1(p)
    virtual void Reset();
    Str_4178E0 name;
    char pad10[0xC];
    int f1C;
};
struct O_4178E0 {
    int f0;
    W_4178E0* w;
    Str_4178E0 file;
    Str_4178E0 text;
    int id;
    void* inst;
    char pad28[8];
    char f30[4];
};
extern "C" {
char* String_CStr(Str_4178E0* s);
int String_Length(Str_4178E0* s);
int GuiManager_FindInterface(void* db, char* name);
int* GuiManager_ResolveInterface(void* db, int id);
void* IeNode_FindNode(int scene, char* name);
void* IeElement_Create(void* n);
void IeElement_SetShown(void* i, int a);
void IeElement_SetMatrix(void* i, void* p);
extern char D_004BF070[];
}
static inline bool Empty_4178E0(Str_4178E0* s) { return String_Length(s) == 0; }

extern "C" void GuiInterfaceDecorator_Init(O_4178E0* o)
{
    int* rec;
    o->w->Reset();
    o->id = GuiManager_FindInterface(D_00571DC0, String_CStr(&o->file));
    if (o->id == -1) return;
    rec = GuiManager_ResolveInterface(D_00571DC0, o->id);
    if (rec && *rec) {
        PStr_4178E0 buf;
        void* n;
        const char* s;
        Empty_4178E0(&o->text) ? (s = String_CStr(&o->w->name)) : (s = String_CStr(&o->text));
        {
            char* d = buf.text;
            int n = 0;
            while ((*d++ = *s++) != 0) {
                if (++n >= 0x7E) {
                    n++;
                    d[0] = '\n';
                    d[1] = 0;
                    break;
                }
            }
            buf.len = n;
        }
        if (o->w->f1C == 0) Cat_4178E0(&buf, D_004BF070);
        n = IeNode_FindNode(*rec, (char*)&buf + 1);
        if (n) {
            o->inst = IeElement_Create(n);
            IeElement_SetShown(o->inst, 0);
            IeElement_SetMatrix(o->inst, o->f30);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004178E0 */
