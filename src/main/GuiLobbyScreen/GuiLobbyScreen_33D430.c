/*
 * main/GuiLobbyScreen: range (2 files, 0033D430-0033D580)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_0033D430 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O33D430 { void* vt; };
extern "C" {
extern char D_004DE830[];
extern char D_004E1220[];
extern int D_00532FD8;
extern void* D_00532FE0;
void String_Dtor(void* p, int f);
void GuiWidget_Destroy(void* p, int f);
void operator_delete(void* p);
}
extern "C" O33D430* func_0033D430(O33D430* self, short del)
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
                    Mem_Free(0, p, "GuiLobbyScreen.cc", 0x6F);
                }
                D_00532FE0 = 0;
            }
        }
        if (self) {
            self->vt = D_004E1220;
            GuiWidget_Destroy(self, 0);
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
char * Mem_Alloc(...);                      
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

extern unsigned char D_00533880;
}
extern "C" char * GuiScreen_ctor(char * arg0) {
    char * temp_s1;

    GuiWidget_ctor();
    F_(arg0, 0x0, int) = (int)(&D_004E1220);
    F_(arg0, 0x48, int) = -2;
    F_(arg0, 0x0, int) = (int)(&D_004DE830);
    if ((D_00532FD8 == 0) && (D_00532FE0 == NULL)) {
        {
            AllocGuard g;
        temp_s1 = Mem_Alloc(0, 0xC, &D_004B9BB0, 0x5B);
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
#undef D_004DE830 /* merge_units */
#undef D_004E1220 /* merge_units */
#undef D_00532FE0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033D580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0033D580 */
