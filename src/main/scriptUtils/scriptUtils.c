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
int cMessage_ctor_cMessageNameR(char **, char *);                       
int Global_SetPersonalTimer(float, int, int);           
int nGlobalization_GetString_int(int);                           
int cNetMsg_GetFloat_floatR(float *);                             
int cNetMsg_GetInt(int *);                            
int cMessage_dtor(char **, int);                           
extern char D_004DCB90;
extern char D_004DCF10;
extern char D_004F8580;

void cNetLocalTimerMsg_NetReceive(int arg0) {
    struct { char * f40[9]; float f64; int f68[2]; } sl;

    cMessage_ctor_cMessageNameR(sl.f40, &D_004F8580);
    sl.f40[0] = &D_004DCB90;
    cNetMsg_GetFloat_floatR(&sl.f64);
    cNetMsg_GetInt(sl.f68);
    Global_SetPersonalTimer(sl.f64, arg0, nGlobalization_GetString_int(sl.f68[0]));
    sl.f40[0] = &D_004DCF10;
    cMessage_dtor(sl.f40, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_002679F0 */

/* merge_units: begin func_00267A90 */
#pragma push /* merge_units */
typedef union { int i; float f; void* p; } ScriptArg;

extern void* cNPC_SOBJ_convert(void* p);
extern float nScriptUtils_Distance_cNPCP_cNPCP(void* a, void* b);

/* Script native: returns the distance between two resolved objects, as raw float bits. */
int Script_Distance_5(ScriptArg* args)
{
    ScriptArg result[1];
    void* a = cNPC_SOBJ_convert(args[0].p);
    void* b = cNPC_SOBJ_convert(args[1].p);
    result[0].f = nScriptUtils_Distance_cNPCP_cNPCP(a, b);
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
extern void* cNPC_SOBJ_convert(void*);
#endif /* merge_units */
#define cNPC_SOBJ_convert(a0) (cNPC_SOBJ_convert((a0))) /* merge_units */


extern void* cGOBJ_SOBJ_convert(void*);
extern float nScriptUtils_Distance_cNPCP_cGOBJP(void*, void*);
/* Script native: distance between two script objects. */
int Script_Distance_4(ScriptArg_00267AE0* args)
{
    volatile float result;
    void* a = cNPC_SOBJ_convert(args[0].p);
    result = nScriptUtils_Distance_cNPCP_cGOBJP(a, cGOBJ_SOBJ_convert(args[1].p));
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267AE0(void) {}
#undef cNPC_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267AE0 */

/* merge_units: begin func_00267B30 */
#pragma push /* merge_units */
typedef union ScriptArg_00267B30 { int i; float f; void* p; } ScriptArg_00267B30;
extern void* cPlayer_SOBJ_convert(void* object);
extern float nScriptUtils_Distance_cPlayerP_cNPCP(void* a, void* b);

/* Script native: distance between the objects of args[0] and args[1], returned as float bits. */
int Script_Distance_3(ScriptArg_00267B30* args)
{
    void* a = cPlayer_SOBJ_convert(args[0].p);
    void* b = cNPC_SOBJ_convert(args[1].p);
    float result = nScriptUtils_Distance_cPlayerP_cNPCP(a, b);
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
extern void* cGOBJ_SOBJ_convert(void* object);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) (cGOBJ_SOBJ_convert((a0))) /* merge_units */


extern float nScriptUtils_Distance_cPlayerP_cGOBJP(void* a, void* b);

/* Script native: distance between the two objects, returned as float bits. */
int Script_Distance_2(ScriptArg_00267B80* args)
{
    void* a = cPlayer_SOBJ_convert(args[0].p);
    float d[1];
    d[0] = nScriptUtils_Distance_cPlayerP_cGOBJP(a, cGOBJ_SOBJ_convert(args[1].p));
    return *(int*)d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267B80(void) {}
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267B80 */

/* merge_units: begin func_00267BD0 */
#pragma push /* merge_units */
typedef struct ScriptArgs2 {
    int a;
    int b;
} ScriptArgs2;

#if 0 /* merge_units */
extern int cGOBJ_SOBJ_convert(int handle);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((int)cGOBJ_SOBJ_convert((void *)(a0))) /* merge_units */


extern float nScriptUtils_Distance_cGOBJP_cGOBJP(int a, int b);

/* Script native: Distance(a, b) - returns the float distance as its raw bits. */
int Script_Distance(ScriptArgs2* args) {
    int a = cGOBJ_SOBJ_convert(args->a);
    volatile float dist = nScriptUtils_Distance_cGOBJP_cGOBJP(a, cGOBJ_SOBJ_convert(args->b));
    return *(int*)&dist;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00267BD0(void) {}
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267BD0 */
