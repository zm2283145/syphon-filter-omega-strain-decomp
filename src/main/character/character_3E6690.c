/*
 * main/character: 2 files, 003E6690-003E6750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E6690 */
#pragma push /* merge_units */
#include "types.h"
typedef struct Obj {char pad[0x30];struct Obj*target;} Obj;
typedef struct ActionMsg {void*vt;char pad[0x18];int kind;char flag;char p21[3];int action;char on;char p29[3];int count;} ActionMsg;
extern char g_ActorActionMsgClass[],D_004E01E0[],D_004E0840[];extern int D_0055A840;
Obj*cSystem_SOBJ_convert(int);int*cSystem_GetName(Obj*);
void cMessage_ctor_cMessageNameR(ActionMsg*,void*);void QueueMessage_cMessageR_cSystemP_int(ActionMsg*,Obj*,int);void cMessage_dtor(ActionMsg*,int);
void func_003E6690(Obj*obj,unsigned char count){
 ActionMsg msg;
 int type=*cSystem_GetName(obj);if(type==D_0055A840)obj=obj->target;
 cMessage_ctor_cMessageNameR(&msg,g_ActorActionMsgClass);
 msg.count=count;msg.action=0x28;msg.on=2;msg.vt=D_004E01E0;msg.flag=8;msg.kind=0x40;
 QueueMessage_cMessageR_cSystemP_int(&msg,obj,0);msg.vt=D_004E0840;cMessage_dtor(&msg,0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003E6690 */

/* merge_units: begin func_003E6750 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(int obj, int action, int target, int arg, float time);

/* PerformAction without a target object. */
int nCAS_PerformAction_cSystemP_eAction(int obj, int action) {
    return nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(obj, action, 0, 0, -1.0f);
}
#pragma pop /* merge_units */
/* merge_units: end func_003E6750 */
