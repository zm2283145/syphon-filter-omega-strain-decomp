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
extern "C" void cAnimator_NextFrame(I_417790* i, float dt);

inline bool O_417790::Done()
{
    if (cur == 0 || inst == 0 || cur->kind != 1 || (float)cur->y == inst->t) return true;
    return false;
}

extern "C" void GuiInterfaceDecorator_onAdvanceTime(O_417790* o, float dt)
{
    if (o->inst) cAnimator_NextFrame(o->inst, dt);
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
extern "C" void cInterfaceElement_Destroy(void* p);
extern "C" void cInterfaceManager_RemoveInterface(void* mgr, int handle);

/* Notifies the child (virtual +0x10); if a handle (+0x20) is held, releases it (cInterfaceElement_Destroy on +0x24, cInterfaceManager_RemoveInterface) and resets it to -1. */
extern "C" void GuiInterfaceDecorator_onRemove(GuiWidget* self)
{
    self->child->Method10();
    if (self->handle != -1) {
    if (self->unk24)
    cInterfaceElement_Destroy(self->unk24);
    cInterfaceManager_RemoveInterface(D_00571DC0, self->handle);
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
char* std_basic_string_char_char_traits_char_c_str(Str_4178E0* s);
int cString_Length(Str_4178E0* s);
int cInterfaceManager_AddInterface(void* db, char* name);
int* cInterfaceManager_GetInterface(void* db, int id);
void* cInterfaceModel_FindChild(int scene, char* name);
void* cInterfaceModel_CreateInstance(void* n);
void cInterfaceElement_Activate(void* i, int a);
void cInterfaceElement_SetView(void* i, void* p);
extern char D_004BF070[];
}
static inline bool Empty_4178E0(Str_4178E0* s) { return cString_Length(s) == 0; }

extern "C" void GuiInterfaceDecorator_onAdd(O_4178E0* o)
{
    int* rec;
    o->w->Reset();
    o->id = cInterfaceManager_AddInterface(D_00571DC0, std_basic_string_char_char_traits_char_c_str(&o->file));
    if (o->id == -1) return;
    rec = cInterfaceManager_GetInterface(D_00571DC0, o->id);
    if (rec && *rec) {
        PStr_4178E0 buf;
        void* n;
        const char* s;
        Empty_4178E0(&o->text) ? (s = std_basic_string_char_char_traits_char_c_str(&o->w->name)) : (s = std_basic_string_char_char_traits_char_c_str(&o->text));
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
        n = cInterfaceModel_FindChild(*rec, (char*)&buf + 1);
        if (n) {
            o->inst = cInterfaceModel_CreateInstance(n);
            cInterfaceElement_Activate(o->inst, 0);
            cInterfaceElement_SetView(o->inst, o->f30);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004178E0 */
