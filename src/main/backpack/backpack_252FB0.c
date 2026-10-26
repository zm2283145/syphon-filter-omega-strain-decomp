/*
 * main/backpack: range (2 files, 00252FB0-00253070)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00252FB0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int __destroy_array(int , int *, int, int);               
int Backpack_Finish(int);                               
int IeElement_Release(int);                               
int operator_delete(int );                          
extern int PickupMenuEntry_dtor;

int PickupMenu_Destroy(int arg0, long long arg1) {
    int temp_a0;
    int temp_a0_2;

    if (arg0 != NULL) {
        Backpack_Finish(F_(arg0, 0x0, int));
        IeElement_Release(F_(arg0, 0x9C, int));
        IeElement_Release(F_(arg0, 0xA0, int));
        IeElement_Release(F_(arg0, 0xA4, int));
        IeElement_Release(F_(arg0, 0xA8, int));
        IeElement_Release(F_(arg0, 0xAC, int));
        temp_a0 = F_(arg0, 0xB0, int);
        if (temp_a0 != 0) {
            IeElement_Release(temp_a0);
        }
        temp_a0_2 = F_(arg0, 0xB4, int);
        if (temp_a0_2 != 0) {
            IeElement_Release(temp_a0_2);
        }
        __destroy_array(arg0 + 4, &PickupMenuEntry_dtor, 0x1C, 5);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00252FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00252FB0 */

/* merge_units: begin func_00253070 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct Item_253070 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} Item_253070;

typedef struct ListEnt_253070 {
    int id;
    int enabled;
} ListEnt_253070;

typedef struct List_253070 {
    int unk0;
    int count;
    ListEnt_253070* data;
} List_253070;

typedef struct Target_253070 {
    char pad0[0xC];
    int serial;
    char pad10[0x3528 - 0x10];
    List_253070* list;
} Target_253070;

typedef struct Handle_253070 {
    Target_253070* p;
    int serial;
} Handle_253070;

typedef struct Owner_253070 {
    char pad0[0x2E4];
    int has2E8;
    int unk2E8;
    char pad2EC[0x300 - 0x2EC];
    Handle_253070 hTarget;
} Owner_253070;

typedef struct Ctx_253070 {
    char pad0[0x3524];
    int unk3524;
} Ctx_253070;

typedef struct Lbl_253070 {
    char pad0[0x10];
    unsigned char unk10;
    char pad11[0x5B - 0x11];
    unsigned char unk5B;
} Lbl_253070;

typedef struct Widget_253070 {
    char pad0[0x70];
    void* unk70;
    Lbl_253070* unk74;
} Widget_253070;

typedef struct Self_253070 {
    Owner_253070* owner;
    Item_253070 items[5];
    int count;
    int unk94;
    int unk98;
    Widget_253070* w9C;
    Widget_253070* wA0;
    Widget_253070* wA4;
    Widget_253070* wA8;
    Widget_253070* wAC;
    Widget_253070* wB0;
    Widget_253070* wB4;
} Self_253070;

extern "C" {
extern void __construct_array(void* p, void* ctor, void* dtor, int size, int n);
extern int PickupMenuEntry_ctor;
extern void PickupMenu_AddEntry(Item_253070* it, int kind, int id, int flag);
extern Widget_253070* PickupMenu_FindElement(void* root, char* name);
extern int Backpack_ListItems(Owner_253070* o, int* out, int a, int n);
extern int cBackpack_BodyIsPickupable(Owner_253070* o);
extern int cBackpack_BodyHasDisguise(Owner_253070* o);
extern int IeNode_FindChild(void* root, char* name);
extern void IeElement_EvaluateAt(Widget_253070* w, float v);
extern void IeElement_Fade(Widget_253070* w, float v);
extern void IeElement_SetText(Widget_253070* w, char* text);
extern char* Loc_LookupText(char* key);
extern int Agent_GetSelected(void* list, int idx);
extern char* AgentData_GetName(int agent);
extern void TextObj_SetColour(Lbl_253070* l, void* color);

extern int D_0048AEF0;
extern int D_0048AEF8;
extern int D_0048AF00;
extern char D_004A79E8[];
extern char D_004A7A40[];
extern char D_004A7A50[];
extern char D_004A7A60[];
extern char D_004A7A70[];
extern char D_004A7A90[];
extern char D_004A7AA0[];
extern char D_004A7AB0[];
extern char D_004A7AB8[];
extern char D_004A7AC0[];
extern char D_004A7AC8[];
extern char D_004A7AD0[];
extern char D_004A7AD8[];
extern char D_004A7AE0[];
extern char D_004A7AE8[];
extern char g_PickupTextColour[];
extern int D_004F7E90;
extern int D_004F7E98;
extern char g_Game[];
}

static inline int Owner_Get2E8(Owner_253070* o) {
    if (o->has2E8)
        return o->unk2E8;
    return 0;
}

static inline ListEnt_253070* List_At(List_253070* l, unsigned int i) {
    return &l->data[i];
}

static inline Target_253070* Handle_Get(Owner_253070* h) {
    bool isNull;
    bool ok;
    Target_253070* t;
    t = h->hTarget.p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->serial != h->hTarget.serial) ok = false;
    return ok ? t : 0;
}

extern "C" Self_253070* PickupMenu_Build(Self_253070* self, void* root, Owner_253070* owner, Ctx_253070* ctx, int optA, unsigned char optB) {
    int ids[5];
    Item_253070* it;
    int n;
    int i;
    unsigned char a;
    unsigned char b;
    Target_253070* t;

    self->owner = owner;
    __construct_array(self->items, &PickupMenuEntry_ctor, &PickupMenuEntry_dtor, 0x1C, 5);
    self->count = 0;
    it = self->items;
    self->unk94 = 0;
    self->unk98 = optB ? D_0048AF00 : 0;
    self->w9C = PickupMenu_FindElement(root, D_004A7A40);
    self->wA0 = PickupMenu_FindElement(root, D_004A7A50);
    self->wA4 = PickupMenu_FindElement(root, D_004A7A60);
    self->wA8 = PickupMenu_FindElement(self->w9C->unk70, D_004A7A70);
    self->wAC = PickupMenu_FindElement(self->w9C->unk70, D_004A7A90);
    if (optB) {
        self->wB0 = PickupMenu_FindElement(root, D_004A7AA0);
        self->wB4 = PickupMenu_FindElement(root, D_004A7AB0);
    } else {
        self->wB4 = 0;
        self->wB0 = 0;
    }
    n = Backpack_ListItems(self->owner, ids, ctx->unk3524, 5);
    {
        void* r = self->w9C->unk70;
        D_004F7E90 = IeNode_FindChild(r, D_004A7AB8);
        D_004F7E98 = IeNode_FindChild(r, D_004A7AC0);
    }
    for (i = 0; i < n; i++) {
        PickupMenu_AddEntry(it, 0, ids[i], self->unk98);
        it++;
        self->count++;
    }
    a = optA && cBackpack_BodyIsPickupable(self->owner);
    b = optA && cBackpack_BodyHasDisguise(self->owner);
    if (self->count + a + b < 5 && Owner_Get2E8(self->owner) > 0) {
        PickupMenu_AddEntry(it, 2, -1, optB);
        it++;
        self->count++;
    }
    if (a) {
        PickupMenu_AddEntry(it, 3, -1, 0);
        it++;
        self->count++;
    }
    if (b) {
        PickupMenu_AddEntry(it, 4, -1, 0);
        it++;
        self->count++;
    }
    t = Handle_Get(self->owner);
    if (t) {
        List_253070* l = t->list;
        int cnt = l->count;
        int j;
        for (j = 0; j < cnt; j++) {
            if (self->count < 5) {
                ListEnt_253070* e = List_At(l, j);
                if (e->enabled) {
                    PickupMenu_AddEntry(it, 5, e->id, 0);
                    it->unk8 = 0;
                    it++;
                    self->count++;
                }
            }
        }
    }
    IeElement_EvaluateAt(self->w9C, self->unk98);
    IeElement_Fade(self->w9C, self->unk98 + D_0048AEF8 * (self->count - 1));
    IeElement_EvaluateAt(self->wA0, self->unk98);
    IeElement_Fade(self->wA0, self->unk98 + D_0048AEF0);
    if (optB) {
        IeElement_SetText(self->wA4, D_004A79E8);
        IeElement_SetText(self->wB4, Loc_LookupText(D_004A7AC8));
        IeElement_SetText(self->wB0, Loc_LookupText(D_004A7AD0));
        IeElement_SetText(self->wA0, D_004A79E8);
        IeElement_SetText(self->wA8, D_004A79E8);
        IeElement_SetText(self->wAC, D_004A79E8);
    } else {
        Lbl_253070* l;
        IeElement_SetText(self->wA0, Loc_LookupText(D_004A7AD8));
        IeElement_SetText(self->wA4, Loc_LookupText(D_004A7AE0));
        IeElement_SetText(self->wA8, AgentData_GetName(Agent_GetSelected(g_Game, -1)));
        l = self->wA8->unk74;
        l->unk10 = 2;
        TextObj_SetColour(l, g_PickupTextColour);
        l->unk5B = 1;
        IeElement_SetText(self->wAC, Loc_LookupText(D_004A7AE8));
        l = self->wAC->unk74;
        l->unk10 = 2;
        TextObj_SetColour(l, g_PickupTextColour);
    }
    IeElement_EvaluateAt(self->wA4, self->unk98);
    IeElement_Fade(self->wA4, self->unk98 + D_0048AEF0);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00253070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00253070 */
