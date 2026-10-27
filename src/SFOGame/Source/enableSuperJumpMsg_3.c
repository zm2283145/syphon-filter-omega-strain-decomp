/*
 * SFOGame/Source/enableSuperJumpMsg: 3 files, 00326C00-00326CC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326C00 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int QueueMessage_cMessageR_cSystemP_int(char **, int, int);                         
int cMessage_dtor(char **, int);                           
extern char D_004DCF10;
extern char D_004DE6F0;
extern signed char *D_005061D0;
extern char D_0052AF10;

void func_00326C00(int arg0) {
    struct { char * f20[8]; signed char f40[4]; signed char f44[12]; } sl;
    signed char temp_v1;

    cMessage_ctor_cMessageNameR(sl.f20, &D_0052AF10);
    sl.f20[0] = &D_004DE6F0;
    temp_v1 = *D_005061D0;
    D_005061D0 += 1;
    sl.f44[0] = temp_v1 != 0;
    if (arg0 != 0) {
        sl.f40[0] = 1;
        QueueMessage_cMessageR_cSystemP_int(sl.f20, arg0, 1);
    }
    sl.f20[0] = &D_004DCF10;
    cMessage_dtor(sl.f20, 0);
}
static inline void merge_flush_func_00326C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326C00 */

/* merge_units: begin func_00326C90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Network stream cursor shared by message serializers. */
#if 0 /* merge_units */
extern unsigned char* D_005061D0;
#endif /* merge_units */
#define D_005061D0 (*(unsigned char **)&D_005061D0) /* merge_units */


/* Serialize: write the payload byte. */
void cEnableSuperJumpMsg_Pack(EnableSuperJumpMsg* msg) {
    *D_005061D0 = msg->enable;
    D_005061D0 = D_005061D0 + 1;
}
#undef D_005061D0 /* merge_units */
static inline void merge_flush_func_00326C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326C90 */

/* merge_units: begin func_00326CC0 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M326CC0;
typedef struct { void* vt; char pad[0x44]; char m48[0x24]; char m6C[0xC]; char m78[0x18]; M326CC0 m90; } O326CC0;
extern void GuiSlideShow_GetClassName();
extern void GuiSlideShow_IsClass();
extern void GuiSlideShow_onRender();
extern void GuiSlideShow_onInput();
extern void GuiSlideShow_onSleep();
extern void GuiSlideShow_onWake();
extern void GuiSlideShow_onAdd();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_FindFirstFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onAdvanceTime();
extern void GuiWidget_onMessage();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void * const D_004DE710[];
extern void cFileMan_dtor(void* p, int f);
extern void String_Dtor(void* p, int f);
extern void std_vector_deleter_Section_dtor(void* p, int f);
extern void GuiWidget_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void M326CC0_dtor(M326CC0* m)
{
    if (m) {
        cFileMan_dtor(m->mE4, -1);
        cFileMan_dtor(m->m48, -1);
    }
}
static inline void C326CC0(void* p) { if (p) std_vector_deleter_Section_dtor(p, 0); }
static inline void B326CC0(void* p) { if (p) C326CC0(p); }
static inline void A326CC0(void* p) { if (p) B326CC0(p); }
O326CC0* GuiSlideShow_dtor(O326CC0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DE710);
        M326CC0_dtor(&self->m90);
        if (self->m78)
            String_Dtor(self->m78, 0);
        if (self->m6C)
            String_Dtor(self->m6C, 0);
        A326CC0(self->m48);
        GuiWidget_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE710[24] = { (void*)0x0, (void*)0x0, (void*)GuiSlideShow_dtor, (void*)GuiSlideShow_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiSlideShow_onWake, (void*)GuiSlideShow_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiSlideShow_onInput, (void*)GuiSlideShow_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiSlideShow_GetClassName, (void*)GuiSlideShow_IsClass, (void*)0x0 };
static inline void merge_flush_func_00326CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326CC0 */
