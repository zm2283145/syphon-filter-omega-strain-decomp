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
extern "C" void UvScrollAnim_dtor();
void * const D_004E0090[6] = { (void*)0x0, (void*)0x0, (void*)UvScrollAnim_Update, (void*)UvScrollAnim_Init, (void*)UvScrollAnim_dtor, (void*)0x0 };

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
T1F00* cAnimTexture_dtor(T1F00* self, short del)
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
int XLib_GetTexMan(char *);                             
int opNe_cConstLListIteratorR_cConstLListIteratorR_5(char *, int);                        
int cLList_cAnimTexturePtr_End(char *, int);                          
int cConstLListIterator_cAnimTexturePtr_opInc(char *);                               
int cTexture_GetName(int);                             
int cAnimTexture_GetTextureId(char * );                          
void **cConstLListIterator_cAnimTexturePtr_opMul(char *);                          
int cConstLListIterator_cAnimTexturePtr_ctor(char *, char *);                        
int cLList_cAnimTexturePtr_Begin(char *, int);                          
int strcmp(int, int);                                 
extern char g_Video;
extern char * g_TextureMgr;

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
    cLList_cAnimTexturePtr_Begin(&sp78, arg0);
    cConstLListIterator_cAnimTexturePtr_ctor(&sp7C, &sp78);
    cLList_cAnimTexturePtr_End(&sp70, arg0);
    if (opNe_cConstLListIteratorR_cConstLListIteratorR_5(&sp7C, cConstLListIterator_cAnimTexturePtr_ctor(&sp74, &sp70)) != 0) {
loop_2:
        temp_s3 = *cConstLListIterator_cAnimTexturePtr_opMul(&sp7C);
        temp_s2 = XLib_GetTexMan(&g_Video);
        if (strcmp(cTexture_GetName(Tex_GetRecord(temp_s2, cAnimTexture_GetTextureId(temp_s3))), arg1) == 0) {
            var_s0 = temp_s3;
        } else {
            cConstLListIterator_cAnimTexturePtr_opInc(&sp7C);
            cLList_cAnimTexturePtr_End(&sp70, arg0);
            if (opNe_cConstLListIteratorR_cConstLListIteratorR_5(&sp7C, cConstLListIterator_cAnimTexturePtr_ctor(&sp74, &sp70)) == 0) {

            } else {
                goto loop_2;
            }
        }
    }
    if ((var_s0 != NULL) && (arg2 < F_(var_s0, 0x14, unsigned int))) {
        temp_a0 = (char *)(*(int *)((char *)F_(g_TextureMgr, 0x8, int) + (F_(var_s0, 0x0, int) * 4)));
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
