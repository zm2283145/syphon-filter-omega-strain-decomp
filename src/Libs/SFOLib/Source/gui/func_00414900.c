#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Str414900 { int a; int b; int c; };
struct Canvas414900 { int pad0; Str414900 name; };

extern "C" {
extern char D_004BEFB0[];
extern char D_004BEFB8[];
extern void* D_00571FB8;
extern Canvas414900* D_00571FB0;
extern unsigned char D_00571FC0;
void* cMemMan_Allocate(int pool, int size, void* file, int line);
void* GuiManager_ctor(void* p);
Canvas414900* AbstractWidgetClassRep_Create(const char* name);
void std_basic_string_char_char_traits_char_ctor_charP(Str414900* s, const char* cs);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str414900* dst, Str414900* src);
void String_Dtor(Str414900* s, int flags);
}

static inline void* Alloc414900(int n, int line) { AllocGuard g; return cMemMan_Allocate(0, n, D_004BEFB0, line); }

/* Gui::Init(const char* canvasClass). The second name check written as a
 * ternary (rather than an if) switches mw38 to the retail delay-slot policy. */
extern "C" void Gui_Init(const char* name)
{
    if (!D_00571FC0) {
        void* p = Alloc414900(0x38, 0x17);
        if (p) p = GuiManager_ctor(p);
        D_00571FB8 = p;
        D_00571FB0 = AbstractWidgetClassRep_Create((name && *name) ? name : D_004BEFB8);
        name = (name && *name) ? name : D_004BEFB8;
        {
            Str414900 s;
            std_basic_string_char_char_traits_char_ctor_charP(&s, name);
            std_basic_string_char_char_traits_char_assign_basicstringR(&D_00571FB0->name, &s);
            String_Dtor(&s, 0);
        }
    }
    D_00571FC0 = 1;
}
