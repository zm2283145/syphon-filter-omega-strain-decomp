/*
 * SFOGame/Source/GuiKeyboard: 10 files, 0032C110-0032CB40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032C110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0032C110(char* self) {
    return *(int*)(self + 68);
}
static inline void merge_flush_func_0032C110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C110 */

/* merge_units: begin func_0032C120 */
#pragma push /* merge_units */
typedef struct { unsigned short from; unsigned short to; } E32C120;
typedef struct { char p0[4]; E32C120* data; int count; } M32C120;
typedef struct { char p0[0x98]; M32C120* map; } O32C120;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C120;
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(O32C120* o, I32C120* it);
#endif /* merge_units */
int GuiKeyboard_GetModifierIndex(); /* merge_units */

extern int CharMap_Lookup(unsigned short key);
/* Maps the item's key through the object's remap table (0xFF when unmapped and strict). */
int func_0032C120(O32C120* o, I32C120* it, int strict)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    M32C120* m = o->map;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
        if (strict) return 0xFF;
    }
    return CharMap_Lookup(key);
}
static inline void merge_flush_func_0032C120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C120 */

/* merge_units: begin func_0032C1E0 */
#pragma push /* merge_units */
typedef struct { unsigned short key; char p2[10]; } E32C1E0;
typedef struct { char p0[8]; E32C1E0* data; int count; } T32C1E0;
typedef struct { char p0[0x90]; T32C1E0* tab; } O32C1E0;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C1E0;
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(O32C1E0* o, I32C1E0* it);
#endif /* merge_units */
int GuiKeyboard_GetModifierIndex(); /* merge_units */


/* Looks up the table entry for the item's key in its current mode. */
E32C1E0* func_0032C1E0(O32C1E0* o, I32C1E0* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    if (it->flags & (4 << k)) {
        T32C1E0* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}
static inline void merge_flush_func_0032C1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C1E0 */

/* merge_units: begin func_0032C290 */
#pragma push /* merge_units */
typedef struct { char pad[0xA]; unsigned char mask; } MaskObj;
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(void* self, MaskObj* obj);
#endif /* merge_units */
int GuiKeyboard_GetModifierIndex(); /* merge_units */



/* Tests the mask bit (4 << slot) of obj, where slot comes from GuiKeyboard_GetModifierIndex. */
int func_0032C290(void* self, MaskObj* obj)
{
    int slot = GuiKeyboard_GetModifierIndex(self, obj);
    return (obj->mask & (4 << slot)) != 0;
}
static inline void merge_flush_func_0032C290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C290 */

/* merge_units: begin func_0032C2D0 */
#pragma push /* merge_units */
typedef struct { char p0[0xE4]; unsigned int flags; } O32C2D0;
typedef struct { char p0[0xA]; unsigned char flags; } I32C2D0;
/* Picks which of the item's key slots (0-3) applies for the object's current mode bits. */
int GuiKeyboard_GetModifierIndex(O32C2D0* o, I32C2D0* it)
{
    unsigned int f = o->flags;
    int r;
    if (f & 4) {
        r = 2;
        if (f & 2) {
            if (it->flags & 2) r = 3;
            if (f & 1) r = (r == 3) ? 2 : 3;
        } else {
            if (f & 1) r = 3;
        }
    } else {
        r = 0;
        if (f & 2) {
            if (it->flags & 1) r = 1;
            if (f & 1) r = (r ^ 1) != 0;
        } else {
            if (f & 1) r = 1;
        }
    }
    return r;
}
static inline void merge_flush_func_0032C2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C2D0 */

/* merge_units: begin func_0032C390 */
#pragma push /* merge_units */
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS_C390;
typedef struct { union { SS_C390 s; unsigned int w; } h; int size; } Str_C390;
typedef struct { char p0[0x48]; Str_C390 name; char p50[0x3C]; int sel; } Menu_C390;
typedef struct { unsigned short from; unsigned short to; } Remap_C390;
typedef struct { unsigned short key; char p2[2]; Remap_C390* data; int count; } Entry_C390;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; char pB; } Item_C390;
typedef struct { Item_C390* items; int p4; Entry_C390* data; int count; } Table_C390;
typedef struct {
    char p0[0x4C];
    Menu_C390* menu;
    int max;
    char p54[0x24];
    int* types;
    char p7C[0xC];
    int* index;
    char p8C[4];
    Table_C390* tab;
    char p94[4];
    Entry_C390* cur;
    unsigned char b9C;
    char p9D[0x44];
    unsigned char bE1;
    char pE2[2];
    unsigned int flags;
} Self_C390;
typedef struct { char p0[0x10]; int id; } Arg_C390;

extern void GuiKeyboard_Close(Self_C390* self, int v);
extern void GuiKeyboard_Relabel(Self_C390* self, unsigned int flags);
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(Self_C390* self, Item_C390* it);
#endif /* merge_units */
#define GuiKeyboard_GetModifierIndex(a0, a1) (GuiKeyboard_GetModifierIndex((O32C2D0 *)(a0), (I32C2D0 *)(a1))) /* merge_units */


extern int GuiKeyboard_IsCharAllowed(Self_C390* self, unsigned char c);
extern void GuiTextEditWidget_SetCursorPos(Menu_C390* m, int sel);
extern void GuiTextEditWidget_RemoveCharAtCursor(Menu_C390* m, int sel);
extern void GuiTextEditWidget_InsertAtCursor(Menu_C390* m, char* s);
extern void GuiWidget_SendParentsMessage(Self_C390* self, int a, int b, int c);
extern int GuiWidget_onMessage(Self_C390* self, Arg_C390* arg, unsigned short msg, int a3, int param);

static inline int StrSize(Str_C390* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }

static inline Entry_C390* Lookup(Self_C390* o, Item_C390* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    if (it->flags & (4 << k)) {
        Table_C390* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}

static inline unsigned char Remap(Self_C390* o, Item_C390* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    Entry_C390* m = o->cur;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
        return 0xFF;
    }
    return CharMap_Lookup(key);
}

int GuiKeyboard_HandleEvent(Self_C390* self, Arg_C390* arg, unsigned short msg, int a3, int param)
{
    if (msg == 0x2000) {
        GuiKeyboard_Close(self, 0);
        return 1;
    }
    if (msg == 2) {
        int id = arg->id;
        unsigned char ok;
        Entry_C390* prev = self->cur;
        if (id != -1) {
            unsigned char ch = 0xFF;
            unsigned char found;
            int type;
            ok = 1;
            found = 0;
            type = self->types[id];
            switch (type) {
            case 0x3EC:
            case 0x428:
                if (self->b9C) {
                    GuiKeyboard_Relabel(self, (self->flags & 4) ? self->flags & ~4 : self->flags | 4);
                } else {
                    ok = 0;
                }
                break;
            case 0x39:
                GuiKeyboard_Relabel(self, (self->flags & 2) ? self->flags & ~2 : self->flags | 2);
                break;
            case 0x3EA:
            case 0x408:
                if (self->flags & 1) {
                    GuiKeyboard_Relabel(self, self->flags & ~1);
                    self->bE1 = 0;
                } else {
                    GuiKeyboard_Relabel(self, self->flags | 1);
                    self->bE1 = 1;
                }
                break;
            case 0x2A:
                if (self->menu) GuiTextEditWidget_RemoveCharAtCursor(self->menu, 0);
                self->cur = 0;
                break;
            case 0x28:
                GuiKeyboard_Close(self, 1);
                break;
            case 0x4F:
                GuiTextEditWidget_SetCursorPos(self->menu, self->menu->sel + 1);
                self->cur = 0;
                break;
            case 0x50:
                if (self->menu->sel != 0) GuiTextEditWidget_SetCursorPos(self->menu, self->menu->sel - 1);
                self->cur = 0;
                break;
            default:
                ok = 0;
                found = 1;
                {
                    int idx = self->index[id];
                    if (idx != -1) {
                        Item_C390* it = &self->tab->items[idx];
                        int slot = GuiKeyboard_GetModifierIndex(self, it);
                        if (it->flags & (4 << slot)) {
                            self->cur = Lookup(self, it);
                        } else {
                            ch = Remap(self, it);
                            self->cur = 0;
                        }
                    }
                }
                break;
            }
            if (prev != self->cur) GuiKeyboard_Relabel(self, self->flags);
            if (self->menu && found && ch != 0xFF) {
                if ((unsigned char)GuiKeyboard_IsCharAllowed(self, ch) && StrSize(&self->menu->name) < self->max) {
                    char buf[2];
                    buf[0] = ch;
                    buf[1] = 0;
                    GuiTextEditWidget_InsertAtCursor(self->menu, buf);
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (self->bE1) GuiKeyboard_Relabel(self, (self->flags & 1) ? self->flags & ~1 : self->flags | 1);
                self->bE1 = 0;
            }
            if (ok) {
                GuiWidget_SendParentsMessage(self, 0x10, 1, 0);
            } else {
                GuiWidget_SendParentsMessage(self, 0x10, 4, 0);
            }
            return 1;
        }
    }
    if (msg == 0x10 && a3 == 1) return 1;
    return GuiWidget_onMessage(self, arg, msg, a3, param);
}
#undef GuiKeyboard_GetModifierIndex /* merge_units */
static inline void merge_flush_func_0032C390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C390 */

/* merge_units: begin func_0032C860 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; int mods; } Kb_32C860;
typedef struct {
    char p0[0x9C];
    unsigned char b9C;
    char p9D[0x44];
    unsigned char bE1;
    char pE2[2];
    unsigned int flags;
    unsigned int mods;
} Self_32C860;
extern unsigned char D_0055A701;
extern Kb_32C860 D_0055A700;
extern void GuiWidget_onAdvanceTime(Self_32C860* self);
#if 0 /* merge_units */
extern void GuiKeyboard_Relabel(Self_32C860* self, unsigned int flags);
#endif /* merge_units */
#define GuiKeyboard_Relabel(a0, a1) (GuiKeyboard_Relabel((Self_C390 *)(a0), (a1))) /* merge_units */


extern void GuiKeyboard_UpdateStateKeys(Self_32C860* self);

void GuiKeyboard_Update(Self_32C860* self)
{
    Kb_32C860* k;
    GuiWidget_onAdvanceTime(self);
    k = &D_0055A700;
    if (D_0055A701) {
        int m = k->mods;
        unsigned int f = 0;
        unsigned char changed;
        if (self->b9C && ((m & 4) || (m & 0x40))) f |= 4;
        if ((m & 2) || (m & 0x20)) f |= 1;
        changed = 0;
        if ((f & self->flags) != f) {
            if (f & 1) self->bE1 = 0;
            self->flags |= f;
            changed = 1;
        }
        if (self->mods != f) {
            if (!(f & 1) && (self->mods & 1)) {
                self->bE1 = 0;
                self->flags &= ~1;
                changed = 1;
            }
            if (!(f & 4) && (self->mods & 4)) {
                self->flags &= ~4;
                changed = 1;
            }
        }
        self->mods = f;
        if (changed) GuiKeyboard_Relabel(self, self->flags);
    }
    GuiKeyboard_UpdateStateKeys(self);
}
#undef GuiKeyboard_Relabel /* merge_units */
static inline void merge_flush_func_0032C860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C860 */

/* merge_units: begin func_0032C9A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; unsigned int flags; } Mgr;
extern void GuiWidget_onSleep(void* self);
extern Mgr* Gui_Canvas(void);
extern void GuiWidget_SendMessage(void* self, Mgr* mgr, int a, int b, int c);

/* Runs base setup, clears manager flag 0x40, then registers self with the manager. */
void GuiKeyboard_Sleep(void* self)
{
    GuiWidget_onSleep(self);
    Gui_Canvas()->flags &= ~0x40;
    GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 3, 0);
}
static inline void merge_flush_func_0032C9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C9A0 */

/* merge_units: begin func_0032CA00 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VC_32CA00 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct W_32CA00;
struct Stack_32CA00 { char p0[0x20]; W_32CA00* focus; char p24[0x44]; unsigned int flags; };
struct Vec_32CA00 { int p0; int p4; W_32CA00** data; };
struct Menu_32CA00 { char p0[0x78]; char* slider; };
struct Self_32CA00 {
    char p0[0x20];
    W_32CA00* focus;
    char p24[0x28];
    Menu_32CA00* menu;
    char p50[0xC];
    int sel;
    Vec_32CA00 vec;
    char p6C[0x75];
    unsigned char bE1;
    char pE2[6];
    unsigned int mods;
};

extern "C" {
void GuiWidget_onWake(Self_32CA00* self);
#if 0 /* merge_units */
void GuiKeyboard_Relabel(Self_32CA00* self, unsigned int flags);
#endif /* merge_units */
#define GuiKeyboard_Relabel(a0, a1) (GuiKeyboard_Relabel((Self_C390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Stack_32CA00* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Stack_32CA00 *)Gui_Canvas()) /* merge_units */

W_32CA00*** std_vector_pod_int_data(Vec_32CA00* v);
#if 0 /* merge_units */
VC_32CA00* func_0032C110(W_32CA00* w);
#endif /* merge_units */
#define func_0032C110(a0) ((VC_32CA00 *)func_0032C110((char *)(a0))) /* merge_units */

int GuiKeyboard_IsSpecialKey(Self_32CA00* self, W_32CA00* w);
}

static inline float clamp01(float x) { float lo = 0.0f; float hi = 1.0f; asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }

static inline W_32CA00* At(Vec_32CA00* v, int i) { return (*std_vector_pod_int_data(v))[i]; }

static inline void Focus(Self_32CA00* self, W_32CA00* w)
{
    Stack_32CA00* ss = Gui_Canvas();
    if (w != ss->focus) {
        if (ss->focus) func_0032C110(ss->focus)->v8();
        ss->focus = w;
        if (w) {
            if (!GuiKeyboard_IsSpecialKey(self, w)) func_0032C110(w)->v7();
        }
    }
}

extern "C" void GuiKeyboard_Wake(Self_32CA00* self)
{
    GuiWidget_onWake(self);
    self->sel = 0;
    self->bE1 = 0;
    self->mods = 0;
    GuiKeyboard_Relabel(self, 0);
    Gui_Canvas();
    Focus(self, At(&self->vec, self->sel));
    self->focus = self->vec.data[self->sel];
    Gui_Canvas()->flags |= 0x40;
    {
        char* s = self->menu->slider;
        if (s) *(float*)(s + 0x54) = clamp01(0.2f);
    }
}
#undef GuiKeyboard_Relabel /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef func_0032C110 /* merge_units */
static inline void merge_flush_func_0032CA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032CA00 */

/* merge_units: begin func_0032CB40 */
#pragma push /* merge_units */
/* GuiKeyboard_onAdd: build the on-screen keyboard: collect the key widgets of the five rows, then fill the
 * up/down/left/right neighbour tables and the label table for every key. */
#pragma cplusplus on
#include "gui_traversal_types.h"

struct KW {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual int IsA(void* type);
    char pad4[0x10 - 4];
    int index;            /* 0x10 */
    unsigned short flags; /* 0x14 */
    char pad16[0x28 - 0x16];
    ChildList children;   /* 0x28 */
    char pad34[0x88 - 0x34];
    unsigned char b88;
};
struct PVec { unsigned int cap; unsigned int count; KW** data; int pad; };
struct PIt { KW** p; };
struct IVec { unsigned int cap; unsigned int count; int* data; int pad; };
struct KSelf {
    char pad0[0x48];
    KW* w48;
    KW* w4C;
    char pad50[4];
    int x54;
    int x58;
    char pad5C[4];
    PVec keys;     /* 0x60 */
    IVec labels;   /* 0x70 */
    char pad80[0xA0 - 0x80];
    IVec up;       /* 0xA0 */
    IVec down;     /* 0xB0 */
    IVec left;     /* 0xC0 */
    IVec right;    /* 0xD0 */
};

extern "C" {
void GuiWidget_onAdd(KSelf* self);
KW* GuiWidget_FindChild_charP(KSelf* self, char* name);
void std_list_deleter_voidPtr_begin_void(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
void func_0032D0B0(PVec* v, KW** w);
KW** func_0032D0A0(PVec* v);
void func_0032D090(PIt* out, PVec* v, KW*** p);
void func_0032D050(PIt* out, PVec* v);
void func_0032D040(PIt* out, PIt* in);
void std_vector_int_push_back(IVec* v, int* value);
int Loc_GetLanguage(void);
void GuiKeyboard_ApplyLayout(KSelf* self, int lang);
extern char* D_00492650;
extern char* D_00492648;
extern char* D_00492640;
extern char D_004A9870[];
extern char D_004A9880[];
extern char D_004A7520[];
extern int D_004B8970[5];
extern int* D_00492660[5];
extern int* D_00492680[5];
extern int* D_004926A0[5];
}

static inline bool Ne(KW** a, PIt* b) { return !(a == b->p); }

extern "C" void GuiKeyboard_onAdd(KSelf* self)
{
    ChildIterator end2, end;
    int t1, t2, t3, t4;
    PIt end3;
    ChildIterator begin, begin2;
    PIt it;
    ChildIterator rawBegin, rawBegin2, rawEnd2, rawEnd;
    KW** first;
    PIt rawEnd3;
    int start[5];
    GuiWidget_onAdd(self);
    self->x54 = 0;
    self->x58 = 0;
    KW* kb = GuiWidget_FindChild_charP(self, D_00492650);
    if (!kb)
        return;
    {
        ChildList* rows = &kb->children;
        /* declaration order picks the saved registers (keys s4, k s3, row s2, key s1) */
        ChildList* keys;
        KW* k;
        ChildNode* row;
        ChildNode* key;
        int ri;
        if (rows->count != 5)
            return;
        std_list_deleter_voidPtr_begin_void(&rawBegin, rows);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
        row = begin.node;
        std_list_GuiWidgetPtr_end(&rawEnd, rows);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
        ri = 0;
        while (row != end.node) {
            KW* rw = (KW*)row->widget;
            int n = D_004B8970[ri];
            keys = &rw->children;
            if (n != rw->children.count)
                return;
            std_list_deleter_voidPtr_begin_void(&rawBegin2, keys);
            std_list_GuiWidgetPtr_generic_iterator_ctor(&begin2, &rawBegin2);
            key = begin2.node;
            std_list_GuiWidgetPtr_end(&rawEnd2, keys);
            cLListIterator_GuiWidgetPtr_ctor_listR(&end2, &rawEnd2);
            while (key != end2.node) {
                k = (KW*)key->widget;
                k = (k && k->IsA(D_004A9870)) ? k : 0;
                if (!k)
                    return;
                func_0032D0B0(&self->keys, (KW**)&key->widget);
                key = key->next;
                std_list_GuiWidgetPtr_end(&rawEnd2, keys);
                cLListIterator_GuiWidgetPtr_ctor_listR(&end2, &rawEnd2);
            }
            row = row->next;
            ri++;
            std_list_GuiWidgetPtr_end(&rawEnd, rows);
            cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
        }
    }
    {
        int row, col;
        {
            int i, sum = 0;
            for (i = 0; i < 5; i++) {
                start[i] = sum;
                sum += D_004B8970[i];
            }
        }
        row = 0;
        col = 0;
        first = func_0032D0A0(&self->keys);
        func_0032D090(&it, &self->keys, &first);
        KW** p = it.p;
        func_0032D050(&rawEnd3, &self->keys);
        func_0032D040(&end3, &rawEnd3);
        if (Ne(p, &end3)) {
            do {
                int u, d, l, r, x, y;
                u = row == 0 ? 4 : row - 1;
                d = row == 4 ? 0 : row + 1;
                x = D_004926A0[row][col];
                y = D_00492680[row][col];
                t1 = y + start[u];
                std_vector_int_push_back(&self->up, &t1);
                t2 = x + start[d];
                std_vector_int_push_back(&self->down, &t2);
                l = col == 0 ? D_004B8970[row] - 1 : col - 1;
                r = col == D_004B8970[row] - 1 ? 0 : col + 1;
                t3 = l + start[row];
                std_vector_int_push_back(&self->left, &t3);
                t4 = r + start[row];
                std_vector_int_push_back(&self->right, &t4);
                (*p)->index = col + start[row];
                std_vector_int_push_back(&self->labels, &D_00492660[row][col]);
                col++;
                if (col == D_004B8970[row]) {
                    col = 0;
                    row++;
                }
                p++;
                func_0032D050(&rawEnd3, &self->keys);
                func_0032D040(&end3, &rawEnd3);
            } while (Ne(p, &end3));
        }
    }
    GuiKeyboard_ApplyLayout(self, Loc_GetLanguage());
    {
        KW* w = GuiWidget_FindChild_charP(self, D_00492648);
        w = (w && w->IsA(D_004A9880)) ? w : 0;
        self->w4C = w;
    }
    if (self->w4C) {
        self->w4C->flags &= ~0x80;
        self->w4C->b88 = 1;
    }
    {
        KW* w = GuiWidget_FindChild_charP(self, D_00492640);
        w = (w && w->IsA(D_004A7520)) ? w : 0;
        self->w48 = w;
    }
}
static inline void merge_flush_func_0032CB40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032CB40 */
