/*
 * main/GuiGameScreen: range (2 files, 0045EBC0-0045EC60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiGameScreen_types.h"

/* merge_units: begin func_0045EBC0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Stream_ReadU32(int *);                            
int cMessage_dtor(char **, int);                           
int Loc_GetStoredKey(int);                             
int func_0045ECA0(int, unsigned char);                           
extern char D_004DCF10;
extern char D_004E1680;
extern char D_00586158;

void func_0045EBC0(void) {
    struct { char * f30[9]; int f54; int f58[2]; } sl;
    int temp_a0;

    Event_Construct(sl.f30, &D_00586158);
    sl.f30[0] = &D_004E1680;
    Stream_ReadU32(&sl.f54);
    Stream_ReadU32(sl.f58);
    temp_a0 = sl.f54;
    if (temp_a0 != -1) {
        func_0045ECA0(Loc_GetStoredKey(temp_a0), sl.f58[0]);
    }
    sl.f30[0] = &D_004DCF10;
    cMessage_dtor(sl.f30, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045EBC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045EBC0 */

/* merge_units: begin func_0045EC60 */
#pragma push /* merge_units */
extern GameHudOwner* D_004FFC2C;
extern void func_0045CFB0(void* hud, int enable);

/* Enable the interaction prompt when both the owner and its HUD are present. */
void func_0045EC60(void)
{
    if (D_004FFC2C && D_004FFC2C->hud)
        func_0045CFB0(D_004FFC2C->hud, 1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045EC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045EC60 */
