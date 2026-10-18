/*
 * main/gobj: 3 files, 003D1E90-003D1F50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D1E90 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Plain data in front of the vtable pointer (vptr at +0x10). */
struct ObjBase {
    int unk0;    /* +0x00 */
    float* pos;  /* +0x04 */
    int unk8;    /* +0x08 */
    int unkC;    /* +0x0C */
};

struct Obj : ObjBase {
    virtual void v00();
    virtual void Init(); /* +0xC */
    float x; /* +0x14 */
    float y; /* +0x18 */
};

extern char D_004E0080[];
extern "C" void UvScrollAnim_Update();
extern "C" void UvScrollAnim_Init();
extern "C" void func_003D2910();
void * const D_004E0090[6] = { (void*)0x0, (void*)0x0, (void*)UvScrollAnim_Update, (void*)UvScrollAnim_Init, (void*)func_003D2910, (void*)0x0 };

/* Constructor: installs the base vtable D_004E0080, stores the leading fields, installs vtable ((char*)D_004E0090), copies pos[0..1] and calls virtual +0xC. */
extern "C" Obj* UvScrollAnim_Construct(Obj* self, float* pos, int a2, int a3, int a0)
{
    *(void**)((char*)self + 0x10) = D_004E0080;
    self->unk0 = a0;
    self->pos = pos;
    self->unk8 = a2;
    self->unkC = a3;
    *(void**)((char*)self + 0x10) = ((char*)D_004E0090);
    self->x = pos[0];
    self->y = pos[1];
    self->Init();
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1E90 */

/* merge_units: begin func_003D1F00 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; void* vt; } T1F00;
extern void operator_delete(void* p);
T1F00* func_003D1F00(T1F00* self, short del)
{
    if (self) {
        self->vt = D_004E0080;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1F00 */

/* merge_units: begin func_003D1F50 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Tex_GetRecord(int, int);                        
int func_003797D0(char *);                             
int func_003D20F0(char *, int);                        
int func_003D2110(char *, int);                          
int func_003D2120(char *);                               
int func_003D2140(int);                             
int func_003D2150(char * );                          
void **func_003D2160(char *);                          
int func_003D2170(char *, char *);                        
int func_003D2180(char *, int);                          
int strcmp(int, int);                                 
extern char D_005381F0;
extern char * D_00539248;

#pragma push
#pragma opt_common_subs off
void Global_SetTexture(int arg0, int arg1, unsigned int arg2) {
    char * var_s0;
    int sp7C;
    int sp78;
    char * temp_s3;
    int sp74;
    char * temp_a0;
    int sp70;
    int temp_s2;

    var_s0 = NULL;
    func_003D2180(&sp78, arg0);
    func_003D2170(&sp7C, &sp78);
    func_003D2110(&sp70, arg0);
    if (func_003D20F0(&sp7C, func_003D2170(&sp74, &sp70)) != 0) {
loop_2:
        temp_s3 = *func_003D2160(&sp7C);
        temp_s2 = func_003797D0(&D_005381F0);
        if (strcmp(func_003D2140(Tex_GetRecord(temp_s2, func_003D2150(temp_s3))), arg1) == 0) {
            var_s0 = temp_s3;
        } else {
            func_003D2120(&sp7C);
            func_003D2110(&sp70, arg0);
            if (func_003D20F0(&sp7C, func_003D2170(&sp74, &sp70)) == 0) {

            } else {
                goto loop_2;
            }
        }
    }
    if ((var_s0 != NULL) && (arg2 < F_(var_s0, 0x14, unsigned int))) {
        temp_a0 = (char *)(*(int *)((char *)F_(D_00539248, 0x8, int) + (F_(var_s0, 0x0, int) * 4)));
        if ((arg2 != F_(temp_a0, 0x4C, int)) && (arg2 < F_(F_(temp_a0, 0x44, char *), 0x22, unsigned short))) {
            F_(temp_a0, 0x60, signed char) = 0;
            F_(temp_a0, 0x61, signed char) = 0;
            F_(temp_a0, 0x4C, int) = arg2;
        }
        F_(var_s0, 0x28, int) = arg2;
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003D1F50 */
