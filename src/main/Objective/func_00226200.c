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

extern signed char D_004F7560;
extern signed char D_0048AB20;
extern char D_004A5D08[];
extern char D_004A5D30[];
extern char D_004F7580[];
extern char D_004F75A0[];
extern FontMgr* func_001698C0(void);
extern int func_0036A2F0(int font);
extern void* func_003D1020(void);
extern void func_003D0EF0(void* ctx, char* text, int font, char* color, int x, int y);

static inline int GetFont(signed char i)
{
    return *(int*)((char*)func_001698C0()->fonts + ((unsigned char)i << 2));
}
extern void func_00226D60(ObjMgr* self, int* x, int* y, int* count, char* color);
extern void func_002265F0(ObjMgr* self, int* x, int* y, int* count, char* color);
extern void func_002262F0(ObjMgr* self, int* x, int* y, int* count, char* color);
extern void func_00226910(ObjMgr* self, int* x, int* y, int* count, char* color);

void func_00226200(ObjMgr* self, char* color)
{
    int y = 0x8C;
    int x = -0x69;
    int count = 0;
    int step;
    int font;

    font = GetFont(D_0048AB20);
    step = func_0036A2F0(font) + 2;
    func_00226D60(self, &x, &y, &count, color);
    y -= step;
    func_002265F0(self, &x, &y, &count, color);
    y -= step;
    func_002262F0(self, &x, &y, &count, color);
    y -= step;
    func_00226910(self, &x, &y, &count, color);
}

