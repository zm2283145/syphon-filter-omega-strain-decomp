#pragma cplusplus on
#include "alloc_guard.h"

struct GuiTextChild {
    char pad00[0x10];
    char value;           /* 0x10 */
    unsigned char right;  /* 0x11 */
    unsigned char left;   /* 0x12 */
    char pad13[0x45];
    unsigned char s58;    /* 0x58 */
    char pad59[2];
    unsigned char s5B;    /* 0x5B */
};

struct GuiText {
    char pad00[0x34];
    float x;              /* 0x34 */
    float y;              /* 0x38 */
    float w;              /* 0x3C */
    float h;              /* 0x40 */
    char pad44[4];
    char text[0xC];       /* 0x48 */
    int resource;         /* 0x54 */
    char pad58[8];
    float color[4];       /* 0x60 */
    int value;            /* 0x70 */
    unsigned char align;  /* 0x74 */
    unsigned char s75;    /* 0x75 */
    unsigned char s76;    /* 0x76 */
    char pad77;
    GuiTextChild* child;  /* 0x78 */
};

extern "C" {
extern char D_004BF2D0[];
void func_0041EFA0(GuiText* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
GuiTextChild* func_003D0940(void* p, int x, int y, int w, int h, int resource, float* color);
char* String_CStr(void* s);
void func_003D08B0(GuiTextChild* child, char* text);
}

static inline void* Alloc_C3E0(unsigned int size)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BF2D0, 0x45);
}

static inline void Set75(GuiText* self, unsigned char v)
{
    self->s75 = v;
    if (self->child)
        self->child->s58 = v;
}

static inline void Set76(GuiText* self, unsigned char v)
{
    self->s76 = v;
    if (self->child)
        self->child->s5B = v;
}

extern "C" void func_0041C3E0(GuiText* self)
{
    func_0041EFA0(self);
    if (!self->child) {
        void* p = Alloc_C3E0(0x60);
        if (p)
            p = func_003D0940(p, (int)self->x, (int)self->y, (int)self->w, (int)self->h, self->resource, self->color);
        self->child = (GuiTextChild*)p;
    }
    if (self->child) {
        self->child->left = self->align == 0;
        self->child->right = self->align == 2;
    }
    Set75(self, self->s75);
    Set76(self, self->s76);
    func_003D08B0(self->child, String_CStr(self->text));
    self->child->value = self->value;
}

