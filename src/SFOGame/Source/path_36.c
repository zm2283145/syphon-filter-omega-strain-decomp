/*
 * SFOGame/Source/path: 4 files, 00164180-001642E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00164180 */
#pragma push /* merge_units */
#include "types.h"
typedef struct CxRequest { char pad[0xC]; unsigned char kind; } CxRequest;
typedef struct CxQueueNode { char pad[8]; CxRequest* request; } CxQueueNode;
typedef struct CxRouter { char pad[0x20]; int count; int unk24; CxQueueNode* first; } CxRouter;
extern int* cMessage_Name(void*);
extern int cSystem_HandleMessage(CxRouter*, void*);
extern void cPathSystem_NextFrame(CxRouter*);
extern void cPathRequest_UpdateLOSResult(CxRequest*, void*);
extern void cNodeRequest_UpdateLOSResult(CxRequest*, void*);
extern int D_004ED9B8;
extern unsigned char D_004ED9D0;
extern int g_LosResultMsgClass;
extern int D_005436B0;

unsigned char cPathSystem_HandleMessage(CxRouter* self, char* event) {
    unsigned char handled=1;
    int type=*cMessage_Name(event);
    if(type==D_005436B0) {
        cPathSystem_NextFrame(self);
    } else {
        type=*cMessage_Name(event);
        if(type!=D_004ED9B8) {
            type=*cMessage_Name(event);
            if(type==g_LosResultMsgClass) {
                if(D_004ED9D0==2) {
                    D_004ED9D0=0;
                } else if(self->count>0) {
                    CxRequest* request=self->first->request;
                    D_004ED9D0=0;
                    if(request->kind==1) cPathRequest_UpdateLOSResult(request,event+0x30);
                    else cNodeRequest_UpdateLOSResult(request,event+0x30);
                }
            } else handled=cSystem_HandleMessage(self,event);
        }
    }
    return handled;
}
static inline void merge_flush_func_00164180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00164180 */

/* merge_units: begin func_001642B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver list insertion (push_back on listB).
 */

#include "path_types.h"

extern int std_list_cPathSystemRequestPtr_push_back(PathList* list, int* value);

void cPathSystem_FreeRequest(PathReceiver* self, int value) {
    volatile int tmp = value; /* original stack temporary */
    std_list_cPathSystemRequestPtr_push_back(&self->listB, (int*)&tmp);
}
static inline void merge_flush_func_001642B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001642B0 */

/* merge_units: begin func_001642E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

extern int std_list_deleter_voidPtr_erase_listdeleter(int, int, int);

int cPathSystem_GetRequest(int a0) {
    int loc[2];
    int a1, a2, s0, v0;
    int cond;

    v0 = *(int*)((char*)a0 + 44);
    cond = v0 <= 0;
    s0 = 0;
    if (cond) goto L00164318;
    v0 = *(int*)((char*)a0 + 52);
    a1 = a0 + 44;
    a2 = (int)loc;
    s0 = *(int*)((char*)v0 + 8);
    a0 = (int)((char*)loc + 4);
    *(int*)(char*)loc = v0;
    v0 = std_list_deleter_voidPtr_erase_listdeleter(a0, a1, a2);
L00164318:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001642E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001642E0 */

/* merge_units: begin func_00164330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int std_list_deleter_voidPtr_erase_listdeleter_listdeleter(...); 
int cPathSystem_ClearRequests(...);                                 
int std_vector_deleter_cBox_dtor(...);                            
extern int D_0049C1B8;
extern int D_004EE118;
extern unsigned char g_ProfileLockEnabled;
}
static inline int Identity(int p){return p;}
#define DECLS int sp48; int sp44; int sp40;
static inline void clr0(char *arg0) { int sp48; int sp44; int sp40; sp40 = (int)arg0 + 0x30; sp44 = F_(arg0, 0x34, int); std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&sp48, arg0 + 0x2C, &sp44, &sp40); }
static inline void fr0(int p) { AllocGuard g; cMemMan_Deallocate(0, p, &D_0049C1B8, 0x41); }
extern "C" void cPathSystem_Clear(char *arg0) {
    int temp_s0;
    int temp_s1;

    cPathSystem_ClearRequests(arg0, 0);
    temp_s1 = F_(arg0, 0x38, int);
    {
        AllocGuard g;
    cMemMan_Deallocate(0, temp_s1, &D_0049C1B8, 0x41);
    }
    { int sp48; int sp44; int sp40; sp40 = Identity((int)(arg0 + 0x30)); sp44 = F_(arg0, 0x34, int); std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&sp48, arg0 + 0x2C, &sp44, &sp40); }
    temp_s0 = D_004EE118;
    if (temp_s0 != 0) {
        {
            AllocGuard g;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            std_vector_deleter_cBox_dtor(temp_s0, 0);
        }
        cMemMan_Deallocate(0, temp_s0, &D_0049C1B8, 0xB2E);
        }
        D_004EE118 = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164330 */
