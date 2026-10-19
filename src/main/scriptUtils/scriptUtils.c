/*
 * main/scriptUtils: 6 files, 002679F0-00267A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002679F0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Event_Construct(char **, char *);                       
int Global_SetPersonalTimer(float, int, int);           
int Loc_GetTextById(int);                           
int NetRead_Float(float *);                             
int Stream_ReadU32(int *);                            
int cMessage_dtor(char **, int);                           
extern char D_004DCB90;
extern char D_004DCF10;
extern char D_004F8580;

void cNetLocalTimerMsg_NetReceive(int arg0) {
    struct { char * f40[9]; float f64; int f68[2]; } sl;

    Event_Construct(sl.f40, &D_004F8580);
    sl.f40[0] = &D_004DCB90;
    NetRead_Float(&sl.f64);
    Stream_ReadU32(sl.f68);
    Global_SetPersonalTimer(sl.f64, arg0, Loc_GetTextById(sl.f68[0]));
    sl.f40[0] = &D_004DCF10;
    cMessage_dtor(sl.f40, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002679F0 */

/* merge_units: begin func_00267A90 */
#pragma push /* merge_units */
typedef union { int i; float f; void* p; } ScriptArg;

extern void* NpcScript_GetReceiver(void* p);
extern float Global_Distance_5(void* a, void* b);

/* Script native: returns the distance between two resolved objects, as raw float bits. */
int Script_Distance_5(ScriptArg* args)
{
    ScriptArg result[1];
    void* a = NpcScript_GetReceiver(args[0].p);
    void* b = NpcScript_GetReceiver(args[1].p);
    result[0].f = Global_Distance_5(a, b);
    return result[0].i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267A90 */

/* merge_units: begin func_00267AE0 */
#pragma push /* merge_units */
typedef union ScriptArg_00267AE0 { int i; float f; void* p; } ScriptArg_00267AE0;
#if 0 /* merge_units */
extern void* NpcScript_GetReceiver(void*);
#endif /* merge_units */
#define NpcScript_GetReceiver(a0) (NpcScript_GetReceiver((a0))) /* merge_units */


extern void* GObj_IdentityB(void*);
extern float Global_Distance_4(void*, void*);
/* Script native: distance between two script objects. */
int Script_Distance_4(ScriptArg_00267AE0* args)
{
    volatile float result;
    void* a = NpcScript_GetReceiver(args[0].p);
    result = Global_Distance_4(a, GObj_IdentityB(args[1].p));
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267AE0(void) {}
#undef NpcScript_GetReceiver /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267AE0 */

/* merge_units: begin func_00267B30 */
#pragma push /* merge_units */
typedef union ScriptArg_00267B30 { int i; float f; void* p; } ScriptArg_00267B30;
extern void* func_00175FA0(void* object);
extern float Global_Distance_3(void* a, void* b);

/* Script native: distance between the objects of args[0] and args[1], returned as float bits. */
int Script_Distance_3(ScriptArg_00267B30* args)
{
    void* a = func_00175FA0(args[0].p);
    void* b = NpcScript_GetReceiver(args[1].p);
    float result = Global_Distance_3(a, b);
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267B30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00267B30 */

/* merge_units: begin func_00267B80 */
#pragma push /* merge_units */
typedef union ScriptArg_00267B80 { int i; float f; void* p; } ScriptArg_00267B80;
#if 0 /* merge_units */
extern void* GObj_IdentityB(void* object);
#endif /* merge_units */
#define GObj_IdentityB(a0) (GObj_IdentityB((a0))) /* merge_units */


extern float Global_Distance_2(void* a, void* b);

/* Script native: distance between the two objects, returned as float bits. */
int Script_Distance_2(ScriptArg_00267B80* args)
{
    void* a = func_00175FA0(args[0].p);
    float d[1];
    d[0] = Global_Distance_2(a, GObj_IdentityB(args[1].p));
    return *(int*)d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267B80(void) {}
#undef GObj_IdentityB /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267B80 */

/* merge_units: begin func_00267BD0 */
#pragma push /* merge_units */
typedef struct ScriptArgs2 {
    int a;
    int b;
} ScriptArgs2;

#if 0 /* merge_units */
extern int GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((int)GObj_IdentityB((void *)(a0))) /* merge_units */


extern float Global_Distance(int a, int b);

/* Script native: Distance(a, b) - returns the float distance as its raw bits. */
int Script_Distance(ScriptArgs2* args) {
    int a = GObj_IdentityB(args->a);
    volatile float dist = Global_Distance(a, GObj_IdentityB(args->b));
    return *(int*)&dist;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267BD0(void) {}
#undef GObj_IdentityB /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267BD0 */
