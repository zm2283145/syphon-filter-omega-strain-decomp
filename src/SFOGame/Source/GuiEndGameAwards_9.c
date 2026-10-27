/*
 * SFOGame/Source/GuiEndGameAwards: 6 files, 00460170-004603A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00460170 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_00460170, func_00299360)
static inline void merge_flush_func_00460170(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460170 */

/* merge_units: begin func_004601E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_004601E0, func_00299360)
static inline void merge_flush_func_004601E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004601E0 */

/* merge_units: begin func_00460240 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */


Rel* func_00460240(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00460240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460240 */

/* merge_units: begin func_00460260 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_00460260, func_00299360)
static inline void merge_flush_func_00460260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00460260 */

/* merge_units: begin func_004602C0 */
#pragma push /* merge_units */
typedef struct {
    void* obj;
    int val;
    char name[16];
} E_4602C0;
typedef struct {
    char pad0[0x48];
    E_4602C0 e[15];
    int pad1B0;
    int n;
} O_4602C0;
extern char D_004C24A8[];
extern char D_004C24B0[];
extern char D_004C24B8[];
extern char D_004C24C0[];
int sprintf(char* buf, const char* fmt, ...);
void Libc_Strcpy(char* d, const char* s);
void Libc_Strcat(char* d, const char* s);
void GuiBitmapWidget_SetBitmap(void* obj, char* name, int x);

void GuiEndGameAwards_AddAward(O_4602C0* o, int x, int type, int sub, int val)
{
    char buf[256];
    E_4602C0* e;
    if (o->n < 15) {
        e = &o->e[o->n];
        sprintf(buf, D_004C24A8, type, sub);
        Libc_Strcpy(e->name, D_004C24B0);
        if (type != 7) Libc_Strcat(buf, D_004C24B8);
        Libc_Strcat(buf, D_004C24C0);
        if (e->obj) GuiBitmapWidget_SetBitmap(e->obj, buf, x);
        e->val = val;
        o->n++;
    }
}
static inline void merge_flush_func_004602C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004602C0 */

/* merge_units: begin func_004603A0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Gui_Manager();                                
int Gui_Canvas();                                
int GuiCanvas_Transition(int, char * , int);                  
int GuiManager_Add(int, int);                          
int GuiWidget_onWake(char * );                            
int AbstractWidgetClassRep_Create(char *);                             
int GuiEndGameAwards_ActivateNextAward(char * );                            
int GuiEndGameAwards_PositionAwards(char * );                            
int GuiEndGameAwards_PopulateAwards();                                  
int GuiEndGameAwards_PlayQuips(char * );                            
extern char D_004C2460;

void GuiEndGameAwards_onWake(char * arg0) {
    int temp_v0;

    GuiEndGameAwards_PopulateAwards();
    if (F_(arg0, 0x1B4, int) == 0) {
        temp_v0 = AbstractWidgetClassRep_Create(&D_004C2460);
        if (temp_v0 != 0) {
            GuiManager_Add(Gui_Manager(), temp_v0);
            GuiCanvas_Transition(Gui_Canvas(), arg0, temp_v0);
        }
    } else {
        GuiWidget_onWake(arg0);
        GuiEndGameAwards_PlayQuips(arg0);
        F_(arg0, 0x204, signed char) = 0;
        GuiEndGameAwards_PositionAwards(arg0);
        GuiEndGameAwards_ActivateNextAward(arg0);
    }
}
static inline void merge_flush_func_004603A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004603A0 */
