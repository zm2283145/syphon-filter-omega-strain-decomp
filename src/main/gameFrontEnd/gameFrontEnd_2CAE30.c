/*
 * main/gameFrontEnd: range (2 files, 002CAE30-002CB0E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002CAE30 */
#pragma push /* merge_units */
#pragma exceptions off
#pragma cplusplus on

class Mgr {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Add(void* p, int t);
};

struct Str;
extern "C" {
Mgr* Gui_GetScreenStack(void);
void* func_002CAC70(void* p);
void* func_002CAC60(void* p);
void func_002CAC50(void** it, void* n);
int String_CStr(Str* p);
void GuiMessageBox_Setup(void* o, int a, int b, int c, int d, int e);
void String_CtorEmpty(Str* s);
void String_CtorCStr_13B480(Str* s, const char* c);
void String_AssignString(Str* d, Str* s);
void String_Dtor(Str* s, int f);
void std_list_deleter_MessageBoxEntry_insert(void* ret, void* list, void** it, void* ent);
void GuiWidget_SendEvent(Mgr* a, Mgr* b, int c, int d, int e);
extern char D_004ACFE0[];
}

#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX

struct Str {
    int w;
    int l;
    char* d;
    Str() { String_CtorEmpty(this); }
    Str(const char* s) { Str* p = this; String_CtorCStr_13B480(p, s ? s : D_004ACFE0); }
    __declspec(weak) __declspec(DROPDTOR) ~Str() { String_Dtor(this, 0); }
    Str& operator=(const Str& o) { String_AssignString(this, (Str*)&o); return *this; }
};

struct Ent {
    int id;
    int a4;
    Str s8;
    Str s14;
    int a20;
    int a24;
    __declspec(weak) __declspec(DROPDTOR) ~Ent() {}
};

struct Node_002CAE30 {
    int pad0;
    Node_002CAE30* next;
    int pad8;
    int state;
};

struct Obj258 {
    char pad[0x10];
    int id;
    unsigned short flags;
};

struct SelfCAE30 {
    char pad[0x258];
    Obj258* obj;
    char pad2[0x2FC - 0x25C];
    int list;
    int list300;
    Node_002CAE30* head;
    int counter;
};

extern "C" int FrontEnd_OpenPopup(SelfCAE30* self, int a4, const char* n1, const char* n2, int a20, int a24)
{
    if (!self->obj)
        return -1;
    {
        Ent e;
        bool first;
        char ret[4];
        void* end;
        char ret2[4];
        void* tmp2;
        void* tmp;
        e.id = self->counter++;
        e.a4 = a4;
        e.s8 = Str(n1);
        e.s14 = Str(n2);
        e.a20 = a20;
        e.a24 = a24;
        first = 1;
        if (self->list) {
            Node_002CAE30* n = (Node_002CAE30*)((Node_002CAE30*)func_002CAC70(&self->list300))->next;
            for (;;) {
                func_002CAC50(&end, func_002CAC60(&self->list));
                if (n == end || n->state != 1) {
                    tmp = n;
                    std_list_deleter_MessageBoxEntry_insert(ret, &self->list, &tmp, &e);
                    break;
                }
                n = n->next;
                first = 0;
            }
        } else {
            tmp2 = self->head;
            std_list_deleter_MessageBoxEntry_insert(ret2, &self->list, &tmp2, &e);
        }
        if (first) {
            int c = String_CStr(&e.s14);
            GuiMessageBox_Setup(self->obj, e.a4, String_CStr(&e.s8), c, e.a20, e.a24);
            self->obj->id = e.id;
            {
                Obj258* o = self->obj;
                if (!(o->flags & 8)) {
                    Gui_GetScreenStack()->Add(o, 1000);
                    GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x10, 2, 0);
                }
            }
        }
        return e.id;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAE30 */

/* merge_units: begin func_002CB0E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void operator_delete(void* p);
#if 0 /* merge_units */
void String_Dtor(void* m, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str *)(a0), (a1))) /* merge_units */

}
extern "C" void* cGameFrontEnd_MessageBoxEntry_dtor(void* self, short deleteFlag)
{
    if (self) {
        void* m;
        m = (char*)self + 0x14;
        if (m) String_Dtor(m, 0);
        m = (char*)self + 0x8;
        if (m) String_Dtor(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef String_Dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CB0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CB0E0 */
