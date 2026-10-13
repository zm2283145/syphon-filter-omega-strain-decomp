#pragma cplusplus on
#include "types.h"

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
extern int func_00251350;
extern int func_00251290;
extern void func_00251060(Item_253070* it, int kind, int id, int flag);
extern Widget_253070* func_002535E0(void* root, char* name);
extern int func_002553E0(Owner_253070* o, int* out, int a, int n);
extern int func_00255E50(Owner_253070* o);
extern int func_00255D90(Owner_253070* o);
extern int func_003EEB30(void* root, char* name);
extern void func_003F45A0(Widget_253070* w, float v);
extern void func_003F44E0(Widget_253070* w, float v);
extern void func_003E7EC0(Widget_253070* w, char* text);
extern char* Loc_LookupText(char* key);
extern int Agent_GetSelected(void* list, int idx);
extern char* func_00336170(int agent);
extern void func_003D0810(Lbl_253070* l, void* color);

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
extern char D_004F7E70[];
extern int D_004F7E90;
extern int D_004F7E98;
extern char D_004FFB50[];
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

extern "C" Self_253070* func_00253070(Self_253070* self, void* root, Owner_253070* owner, Ctx_253070* ctx, int optA, unsigned char optB) {
    int ids[5];
    Item_253070* it;
    int n;
    int i;
    unsigned char a;
    unsigned char b;
    Target_253070* t;

    self->owner = owner;
    __construct_array(self->items, &func_00251350, &func_00251290, 0x1C, 5);
    self->count = 0;
    it = self->items;
    self->unk94 = 0;
    self->unk98 = optB ? D_0048AF00 : 0;
    self->w9C = func_002535E0(root, D_004A7A40);
    self->wA0 = func_002535E0(root, D_004A7A50);
    self->wA4 = func_002535E0(root, D_004A7A60);
    self->wA8 = func_002535E0(self->w9C->unk70, D_004A7A70);
    self->wAC = func_002535E0(self->w9C->unk70, D_004A7A90);
    if (optB) {
        self->wB0 = func_002535E0(root, D_004A7AA0);
        self->wB4 = func_002535E0(root, D_004A7AB0);
    } else {
        self->wB4 = 0;
        self->wB0 = 0;
    }
    n = func_002553E0(self->owner, ids, ctx->unk3524, 5);
    {
        void* r = self->w9C->unk70;
        D_004F7E90 = func_003EEB30(r, D_004A7AB8);
        D_004F7E98 = func_003EEB30(r, D_004A7AC0);
    }
    for (i = 0; i < n; i++) {
        func_00251060(it, 0, ids[i], self->unk98);
        it++;
        self->count++;
    }
    a = optA && func_00255E50(self->owner);
    b = optA && func_00255D90(self->owner);
    if (self->count + a + b < 5 && Owner_Get2E8(self->owner) > 0) {
        func_00251060(it, 2, -1, optB);
        it++;
        self->count++;
    }
    if (a) {
        func_00251060(it, 3, -1, 0);
        it++;
        self->count++;
    }
    if (b) {
        func_00251060(it, 4, -1, 0);
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
                    func_00251060(it, 5, e->id, 0);
                    it->unk8 = 0;
                    it++;
                    self->count++;
                }
            }
        }
    }
    func_003F45A0(self->w9C, self->unk98);
    func_003F44E0(self->w9C, self->unk98 + D_0048AEF8 * (self->count - 1));
    func_003F45A0(self->wA0, self->unk98);
    func_003F44E0(self->wA0, self->unk98 + D_0048AEF0);
    if (optB) {
        func_003E7EC0(self->wA4, D_004A79E8);
        func_003E7EC0(self->wB4, Loc_LookupText(D_004A7AC8));
        func_003E7EC0(self->wB0, Loc_LookupText(D_004A7AD0));
        func_003E7EC0(self->wA0, D_004A79E8);
        func_003E7EC0(self->wA8, D_004A79E8);
        func_003E7EC0(self->wAC, D_004A79E8);
    } else {
        Lbl_253070* l;
        func_003E7EC0(self->wA0, Loc_LookupText(D_004A7AD8));
        func_003E7EC0(self->wA4, Loc_LookupText(D_004A7AE0));
        func_003E7EC0(self->wA8, func_00336170(Agent_GetSelected(D_004FFB50, -1)));
        l = self->wA8->unk74;
        l->unk10 = 2;
        func_003D0810(l, D_004F7E70);
        l->unk5B = 1;
        func_003E7EC0(self->wAC, Loc_LookupText(D_004A7AE8));
        l = self->wAC->unk74;
        l->unk10 = 2;
        func_003D0810(l, D_004F7E70);
    }
    func_003F45A0(self->wA4, self->unk98);
    func_003F44E0(self->wA4, self->unk98 + D_0048AEF0);
    return self;
}



