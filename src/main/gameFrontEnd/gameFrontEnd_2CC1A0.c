/*
 * main/gameFrontEnd: range (4 files, 002CC1A0-002CC3E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
char *strncpy(void *, const void *, int);

/* merge_units: begin func_002CC1A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_002CC1A0, func_00299360)
#pragma pop /* merge_units */
/* merge_units: end func_002CC1A0 */

/* merge_units: begin func_002CC200 */
#pragma push /* merge_units */
extern void* D_004FFC04;
extern void func_002CBD40(void* p);
void func_002CC200(int mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_002CBD40(D_004FFC04);
        break;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC200 */

/* merge_units: begin func_002CC260 */
#pragma push /* merge_units */
struct ObjCC260 { char pad[0x310]; unsigned char b310; };
#if 0 /* merge_units */
extern struct ObjCC260* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(struct ObjCC260 **)&D_004FFC04) /* merge_units */

extern unsigned char D_0051EEB0;
extern char D_0055A300[];
void func_002CBAD0(struct ObjCC260*);
void func_002CBB30(struct ObjCC260*);
void Pad_Reset(void*);
void* Gui_GetScreenStack(void);
void func_00415870(void*);
void func_0041DF00(void*, int, int, int);

void func_002CC260(int arg0, int arg1)
{
    int i;

    if (D_0051EEB0 != 0) {
        return;
    }
    D_0051EEB0 = 1;
    if (arg0 == 0) {
        if (D_004FFC04->b310 == 0 || arg1 == 0x3039) {
            func_002CBB30(D_004FFC04);
            func_002CBAD0(D_004FFC04);
        }
    } else if (arg0 == 1) {
        Pad_Reset(D_0055A300);
        func_00415870(Gui_GetScreenStack());
        if (D_004FFC04->b310 == 0) {
            func_002CBB30(D_004FFC04);
            func_002CBAD0(D_004FFC04);
        }
    } else if (arg0 == 2) {
        if (arg1 == 2) {
            func_0041DF00(Gui_GetScreenStack(), 0x2001, 0, 0);
            if (D_004FFC04->b310 == 0) {
                for (i = 0; i < 3; i++) {
                    func_002CBB30(D_004FFC04);
                    func_002CBAD0(D_004FFC04);
                }
            }
        }
    } else if (arg0 == 3) {
        func_0041DF00(Gui_GetScreenStack(), 0x2002, arg1, 0);
    }
    D_0051EEB0 = 0;
}
#undef D_004FFC04 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC260 */

/* merge_units: begin func_002CC3E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; unsigned char b2C; char pad2[0x2AC - 0x2D]; char name[0x40]; } ObjC3E0;
typedef struct { char pad[0x250]; unsigned char mode; } HudC3E0;
static unsigned int dat_0048C248[2] = { 0x1, 0x0 };
extern void* D_004FFD2C;
extern char D_004ACFA8[];
extern int D_005383D4;
extern void func_0045A150(void* p);
extern void func_002CC980(void);
extern char* func_003CBA90(char* key);
extern void func_002CB3D0(ObjC3E0* o, int a);
extern HudC3E0* func_001698C0(void);
void func_002CC3E0(ObjC3E0* o)
{
    if ((*(unsigned char*)dat_0048C248)) {
        char* s;
        func_0045A150(D_004FFD2C);
        o->b2C = 0;
        func_002CC980();
        s = func_003CBA90(D_004ACFA8);
        if (s)
            strncpy(o->name, s, 0x40);
        (*(unsigned char*)dat_0048C248) = 0;
    }
    func_002CB3D0(o, 0);
    D_005383D4 = (func_001698C0()->mode == 2) ? 0x32 : 0x3C;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CC3E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CC3E0 */
