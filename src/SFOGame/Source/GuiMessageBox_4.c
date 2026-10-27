/*
 * SFOGame/Source/GuiMessageBox: 6 files, 002A8410-002A8890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiMessageBox_2A8410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct W_002A8410 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct Row_002A8410 { void* text; W_002A8410* a; W_002A8410* b; W_002A8410* c; W_002A8410* d; };
struct Self_002A8410 { char pad0[0x58]; Row_002A8410 rows[3]; };
extern "C" {
extern char* D_0048BB58;
extern char* D_0048BB60;
extern char* D_0048BB68;
extern char* D_0048BB70;
extern char* D_0048BB78;
extern char D_004A7520[];
extern char D_004A9880[];
extern char D_004A9870[];
int sprintf(char* buf, const char* fmt, ...);
void* GuiWidget_FindChildPartial(Self_002A8410* self, char* name);
void* GuiWidget_FindChild_charP(Self_002A8410* self, char* name);
void GuiTextWidget_SetVerticleJustify(W_002A8410* w, int a);
void GuiWidget_onAdd(Self_002A8410* self);
}
static inline W_002A8410* FindAs_002A8410(Self_002A8410* self, char* name, char* type)
{
    W_002A8410* w = (W_002A8410*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void GuiMessageBox_onAdd(Self_002A8410* self)
{
    char buf[0x80];
    int i;
    for (i = 0; i < 3; i++) {
        sprintf(buf, "%s%d", D_0048BB58, i);
        self->rows[i].text = GuiWidget_FindChildPartial(self, buf);
        sprintf(buf, "%s%d", D_0048BB60, i);
        self->rows[i].a = FindAs_002A8410(self, buf, D_004A7520);
        if (i == 2) {
            sprintf(buf, "%s%d", D_0048BB68, i);
            self->rows[i].b = FindAs_002A8410(self, buf, D_004A9880);
        } else {
            sprintf(buf, "%s%d", D_0048BB68, i);
            self->rows[i].b = FindAs_002A8410(self, buf, D_004A7520);
        }
        if (i == 1 && self->rows[i].b)
            GuiTextWidget_SetVerticleJustify(self->rows[i].b, 0);
        sprintf(buf, "%s%d", D_0048BB70, i);
        self->rows[i].c = FindAs_002A8410(self, buf, D_004A9870);
        sprintf(buf, "%s%d", D_0048BB78, i);
        self->rows[i].d = FindAs_002A8410(self, buf, D_004A9870);
    }
    GuiWidget_onAdd(self);
}
static inline void merge_flush_GuiMessageBox_2A8410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMessageBox_2A8410 */

/* merge_units: begin func_002A86A0 */
#pragma push /* merge_units */
extern void GuiWidget_onSleep(void* self);
extern int Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* self, int a, int b, int c, int d);

/* Runs the base setup, then calls GuiWidget_SendMessage with Gui_Canvas's result and constants 0x10, 3, 0. */
void GuiMessageBox_onSleep(void* self)
{
    GuiWidget_onSleep(self);
    GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 3, 0);
}
static inline void merge_flush_func_002A86A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A86A0 */

/* merge_units: begin func_002A86F0 */
#pragma push /* merge_units */
typedef struct Entry20 {
    int value;
    int pad[4];
} Entry20;

typedef struct Selector {
    char pad[0x20];
    int current;
    char pad2[0x48 - 0x24];
    int state;
    char pad3[0x54 - 0x4C];
    int index;
    char pad4[0x68 - 0x58];
    Entry20 entries[1];
} Selector;

extern void GuiWidget_onWake(Selector* self);

/* Updates the base, then in state 5 copies the selected entry's value to current. */
void GuiMessageBox_onWake(Selector* self) {
    GuiWidget_onWake(self);
    if (self->state == 5) {
        self->current = self->entries[self->index].value;
    }
}
static inline void merge_flush_func_002A86F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A86F0 */

/* merge_units: begin func_002A8740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern char D_004AB5B0[];   /* "%s%d" */
extern char D_004DD9D0[];   /* GuiMessageBox vtable */
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void GuiWidget_ctor(GuiWidget* self);

/* Formats prefix followed by a number into buf; returns buf. */
char* CreateWidgetName(char* prefix, int n, char* buf) {
    sprintf(buf, D_004AB5B0, prefix, n);
    return buf;
}

/* GuiMessageBox constructor. */
GuiMessageBox* GuiMessageBox_ctor(GuiMessageBox* self) {
    GuiWidget_ctor(&self->base);
    self->base.vtable = D_004DD9D0;
    self->unk58 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unk6C = 0;
    self->unk70 = 0;
    self->unk74 = 0;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk80 = 0;
    self->unk84 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    self->unk90 = 0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    return self;
}
static inline void merge_flush_func_002A8740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A8740 */

/* merge_units: begin func_002A8800 */
#pragma push /* merge_units */
typedef struct { char p0[0x14]; char set[1]; } Mgr2A8800;
#if 0 /* merge_units */
extern void* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((void *)Gui_Canvas()) /* merge_units */



extern Mgr2A8800* Gui_Manager(void);
extern void cLList_GuiWidgetPtr_Find(int* it, void* set, int* key);
#if 0 /* merge_units */
extern void cLList_GuiWidgetPtr_End(int* it, void* set);
#endif /* merge_units */
void cLList_GuiWidgetPtr_End(); /* merge_units */

#if 0 /* merge_units */
extern int opNe_cLListIteratorR_cLListIteratorR_6(int* a, int* b);
#endif /* merge_units */
int opNe_cLListIteratorR_cLListIteratorR_6(); /* merge_units */

/* Returns o when it is the root widget or is registered with the manager, else 0. */
void* ValidateWidget_GuiWidgetP(void* o)
{
    Mgr2A8800* m;
int key[1];
int it[1];
int end[1];
    if (!o) return 0;
    if (o == Gui_Canvas()) return o;
    key[0] = (int)o;
    m = Gui_Manager();
    cLList_GuiWidgetPtr_Find(it, m->set, key);
    cLList_GuiWidgetPtr_End(end, m->set);
    return opNe_cLListIteratorR_cLListIteratorR_6(it, end) ? o : 0;
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_002A8800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A8800 */

/* merge_units: begin func_002A8890 */
#pragma push /* merge_units */
/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_6(Iter* a, Iter* b) {
    return a->p != b->p;
}

void cLList_GuiWidgetPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_002A8890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A8890 */
