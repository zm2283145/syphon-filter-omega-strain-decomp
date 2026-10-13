#pragma cplusplus on
typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char active;
    signed char kind;
    char pad27[0x39];
    char* name;
} ObjEnt;

typedef struct {
    char pad0[0x280];
    int fonts[1];
} FontMgr;

typedef struct {
    char pad0[0xB0];
    ObjEnt* lists[1];
} ObjMgrHdr;

typedef struct {
    char pad0[0xA4];
    int cur;
    char pad_a8[0x10B0 - 0xA8];
    ObjEnt* ents[0x20];
    int counts[0x20];
    int n;
} ObjMgr;

extern "C" {
extern signed char D_004F7560;
extern signed char D_0048AB20;
extern char D_004A5D08[];
extern char D_004A5D50[];
extern char D_004F7580[];
extern char D_004F7590[];
extern FontMgr* func_001698C0(void);
extern int func_0036A2F0(int font);
extern void* func_003D1020(void);
extern void func_003D0EF0(void* ctx, char* text, int font, char* color, int x, int y);
}

static inline bool Finished(ObjEnt* e) { return e->state == 1 || e->state == 2; }
static inline int GetFont(signed char i)
{
    return *(int*)((char*)func_001698C0()->fonts + ((unsigned char)i << 2));
}

static inline int CountKind5(ObjMgr* self)
{
    int n = 0;
    for (int i = 0; i < self->n; i++) {
        if (self->ents[i]->active && !Finished(self->ents[i]) && self->ents[i]->kind == 5)
            n++;
    }
    for (int i = 0; i < self->counts[self->cur]; i++) {
        if (((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]->active && !Finished(((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]) && ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i]->kind == 5)
            n++;
    }
    return n;
}
extern "C" void func_00226910(ObjMgr* self, int* x, int* y, int* count, char* color)
{
    int titleFont;
    int font;
    int step;
    char* none;
    int i;
    char* c;

    titleFont = GetFont(D_004F7560);
    font = GetFont(D_0048AB20);
    step = func_0036A2F0(font) + 2;
    none = D_004A5D08;
    if (CountKind5(self) == 0)
        return;
    c = color ? color : D_004F7580;
    func_003D0EF0(func_003D1020(), D_004A5D50, titleFont, c, *x, *y);
    *y -= step;
    for (i = 0; i < self->n; i++) {
        ObjEnt* e = self->ents[i];
        if (e->active && !Finished(e) && e->kind == 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            func_003D0EF0(func_003D1020(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt* e = ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && !Finished(e) && e->kind == 5) {
            char* name = e->name;
            c = color ? color : D_004F7590;
            func_003D0EF0(func_003D1020(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F7590;
        func_003D0EF0(func_003D1020(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}







