/*
 * SFOGame/Source/GuiLobbyScreen: 3 files, 0033D430-0033D6A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033D430 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
struct O33D430 { void* vt; };
extern "C" {
extern char D_004DE830[];
extern char D_004E1220[];
extern int D_00532FD8;
extern void* D_00532FE0;
void String_Dtor(void* p, int f);
void GuiWidget_dtor(void* p, int f);
void operator_delete(void* p);
}
extern "C" O33D430* GuiLobbyScreen_dtor(O33D430* self, short del)
{
    if (self) {
        self->vt = D_004DE830;
        if (D_00532FD8) {
            D_00532FD8--;
            if (D_00532FD8 == 0) {
                void* p = D_00532FE0;
                if (p) {
                    AllocGuard g;
                    if (p)
                        String_Dtor(p, 0);
                    cMemMan_Deallocate(0, p, "GuiLobbyScreen.cc", 0x6F);
                }
                D_00532FE0 = 0;
            }
        }
        if (self) {
            self->vt = D_004E1220;
            GuiWidget_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033D430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0033D430 */

/* merge_units: begin func_0033D580 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int GuiWidget_ctor(...);                                 
char * cMemMan_Allocate(...);                      
extern char D_004B9BB0;
#if 0 /* merge_units */
extern char D_004DE830;
#endif /* merge_units */
#define D_004DE830 (*(char*)&D_004DE830) /* merge_units */


#if 0 /* merge_units */
extern char D_004E1220;
#endif /* merge_units */
#define D_004E1220 (*(char*)&D_004E1220) /* merge_units */


#if 0 /* merge_units */
extern char * D_00532FE0;
#endif /* merge_units */
#define D_00532FE0 (*(char **)&D_00532FE0) /* merge_units */


extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * GuiLobbyScreen_ctor(char * arg0) {
    char * temp_s1;

    GuiWidget_ctor();
    F_(arg0, 0x0, int) = (int)(&D_004E1220);
    F_(arg0, 0x48, int) = -2;
    F_(arg0, 0x0, int) = (int)(&D_004DE830);
    if ((D_00532FD8 == 0) && (D_00532FE0 == NULL)) {
        {
            AllocGuard g;
        temp_s1 = cMemMan_Allocate(0, 0xC, &D_004B9BB0, 0x5B);
        }
        if (temp_s1 != NULL) {
            F_(temp_s1, 0x0, int) = 0;
            F_(temp_s1, 0x4, int) = 0;
            F_(temp_s1, 0x8, int) = 0;
        }
        D_00532FE0 = temp_s1;
    }
    D_00532FD8 += 1;
    F_(arg0, 0x78, signed char) = 0;
    F_(arg0, 0x80, signed char) = 0;
    return arg0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033D580(void) {}
#undef D_004DE830 /* merge_units */
#undef D_004E1220 /* merge_units */
#undef D_00532FE0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033D580 */

/* merge_units: begin func_0033D6A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char* begin; char* end; char* cap; } String;
extern "C" {
void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* list, String* s);
#if 0 /* merge_units */
void String_Dtor(String* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */


void FormatString(void* self, const char* fmt, const char* a0, const char* a1, const char* a2, const char* a3) {
    String s;
    const char* args[4] = {0};
    char buf[0x400];
    int n;

    args[1] = a1;
    args[0] = a0;
    n = 0;
    args[2] = a2;
    args[3] = a3;
    while (!((fmt != 0) ^ 1) && n < 0x3FF) {
        char c = fmt[0];
        if (c == '$' && fmt[1] >= '1' && fmt[1] < '5') {
            const char* a = args[fmt[1] - '1'];
            if (a != 0) {
                buf[n++] = fmt[1] - 0x20;
                while (!((*a != 0) ^ 1) && n < 0x3FF) {
                    buf[n++] = *a++;
                }
                buf[n++] = 0x10;
            }
            fmt += 2;
        } else {
            buf[n] = c;
            fmt++;
            n++;
        }
    }
    buf[n] = 0;
    std_basic_string_char_char_traits_char_ctor_charP(&s, buf);
    std_basic_string_char_char_traits_char_assign_basicstringR(self, &s);
    String_Dtor(&s, 0);
}
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_0033D6A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033D6A0 */
