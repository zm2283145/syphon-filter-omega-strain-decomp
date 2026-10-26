#pragma cplusplus on
/* IeElement_Construct (interface_element.cc): base IfItem fields, then derived vtable,
 * identity matrix, optional text object from info->rD0, and RGBA bytes from info->colA0. */
#include "types.h"
#include "alloc_guard.h"
struct V4_9000 { float x, y, z, w; V4_9000(const V4_9000& o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct C4_9000 { unsigned char r, g, b, a; C4_9000() {} C4_9000(V4_9000 v) : r(255.0f * v.x), g(255.0f * v.y), b(255.0f * v.z), a(255.0f * v.w) {} };
typedef struct { float f0, f4; char pad8[8]; float f10, f14; char pad18[4]; float f1C; } Rect_9000;
typedef struct { char pad[0xA0]; V4_9000 colA0; char padB0[0x20]; Rect_9000* rD0; } Info_9000;
typedef struct { char pad[0x20]; int font; } Text_9000;
typedef struct { __int128 q[4]; } M4_9000;
struct Ie_9000 {
    void* vt;
    float f4;
    float f8;
    float fC;
    int f10;
    unsigned char b14;
    char pad15[3];
    unsigned char b18;
    unsigned char b19;
    C4_9000 col;
    char pad1E[2];
    int f20;
    int f24;
    int f28;
    float f2C;
    M4_9000 m30;
    Info_9000* info;
    Text_9000* text;
    int f78;
};
extern "C" {
extern char D_004E0800[];
extern char D_004E0220[];
extern char D_004BDFB0[];
extern int g_InterfaceFont;
extern V4_9000 g_TextColourBlock;
void* Mem_Alloc(int pool, int size, char* file, int line);
Text_9000* TextObj_Construct(Text_9000* s, int a, int b, int c, int d, int e, V4_9000* v);
char* TextManager_Get(void);
void TextManager_AddText(void* list, int* id);
}
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void* NewMem(unsigned int size) { AllocGuard g; return Mem_Alloc(0, size, D_004BDFB0, 0x31); }
static inline void AddText(Text_9000* t) { TextManager_AddText(TextManager_Get() + 0x10, (int*)&t); }
extern "C" Ie_9000* IeElement_Construct(Ie_9000* self, Info_9000* info)
{
    Rect_9000* r;
    self->vt = D_004E0800;
    self->f4 = 0.0f;
    self->f8 = -1.0f;
    self->fC = -1.0f;
    self->f10 = 0;
    self->b14 = 0;
    self->vt = D_004E0220;
    self->b18 = 1;
    self->b19 = 1;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    self->f2C = 1.0f;
    UM(&self->m30);
    self->info = info;
    self->text = 0;
    self->f78 = 0;
    r = self->info->rD0;
    if (r) {
        float w, h;
        Text_9000* t;
        if (r->f1C > 0.0f) {
            w = r->f10 - r->f0;
            h = r->f4 - r->f14;
        } else {
            h = 1000.0f;
            w = h;
        }
        t = (Text_9000*)NewMem(0x60);
        if (t)
            t = TextObj_Construct(t, (int)r->f0, (int)r->f4, (int)w, (int)h, 0, &g_TextColourBlock);
        self->text = t;
        { Text_9000* tt = self->text; tt->font = g_InterfaceFont; }
        AddText(self->text);
    }
    self->col = C4_9000(info->colA0);
    return self;
}



