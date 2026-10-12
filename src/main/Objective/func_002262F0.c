typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char active;
    char pad26[0x3A];
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

extern signed char D_004F7560;
extern signed char D_0048AB20;
extern char D_004A5D08[];
extern char D_004A5D10[];
extern char D_004F7580[];
extern char D_004F75B0[];
extern FontMgr* func_001698C0(void);
extern int func_0036A2F0(int font);
extern void* func_003D1020(void);
extern void func_003D0EF0(void* ctx, char* text, int font, char* color, int x, int y);

static inline int GetFont(signed char i)
{
    return *(int*)((char*)func_001698C0()->fonts + ((unsigned char)i << 2));
}

void func_002262F0(ObjMgr* self, int* x, int* y, int* count, char* color)
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
    c = color ? color : D_004F7580;
    func_003D0EF0(func_003D1020(), D_004A5D10, titleFont, c, *x, *y);
    *y -= step;
    *count = 0;
    for (i = 0; i < self->n; i++) {
        ObjEnt* e = self->ents[i];
        if (e->active && e->state == 2) {
            char* name = e->name;
            c = color ? color : D_004F75B0;
            func_003D0EF0(func_003D1020(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    for (i = 0; i < self->counts[self->cur]; i++) {
        ObjEnt* e = ((ObjMgrHdr*)((char*)self + self->cur * 128))->lists[i];
        if (e->active && e->state == 2) {
            char* name = e->name;
            c = color ? color : D_004F75B0;
            func_003D0EF0(func_003D1020(), name, font, c, *x + 15, *y);
            *y -= step;
            (*count)++;
        }
    }
    if (*count == 0) {
        color = color ? color : D_004F75B0;
        func_003D0EF0(func_003D1020(), none, font, color, *x + 15, *y);
        *y -= step;
    }
}



