/*
 * main/character: 7 files, 003E60F0-003E63C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E60F0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
extern int func_003FF330(void* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf);
#define Event_PackHeader func_003FF330
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x30);

DEFINE_MESSAGE_PACK_NOTYPE(func_003E60F0, 20, D_0055A1F8, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003E60F0 */

/* merge_units: begin func_003E6170 */
#pragma push /* merge_units */
extern char D_0055A1F0[];
#if 0 /* merge_units */
extern int func_003FF330(int, int, int, int, int, int, int);
#endif /* merge_units */
#define func_003FF330(a0, a1, a2, a3, a4, a5, a6) (func_003FF330((void *)(a0), (a1), (int *)(a2), (a3), (a4), (unsigned int)(a5), (void *)(a6))) /* merge_units */


int func_003E6170(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int s0, s1, s2, s3, v0;
    int cond;

    v0 = (unsigned int)t1 < (unsigned int)16;
    s3 = a0;
    s2 = a2;
    s1 = t2;
    cond = v0 != 0;
    s0 = 0 + -1;
    if (cond) goto L003E61D0;
    cond = s1 == 0;
    a2 = 0;
    if (cond) goto L003E61D0;
    v0 = func_003FF330(a0, a1, a2, a3, t0, t1, t2);
    v0 = *(int*)((char*)s3 + 44);
    cond = s2 == 0;
    *(int*)((char*)s1 + 12) = v0;
    if (cond) goto L003E61D0;
    s0 = 0 + 16;
    v0 = *(int*)(char*)D_0055A1F0;
    *(int*)(char*)s2 = v0;
L003E61D0:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
#undef func_003FF330 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6170 */

/* merge_units: begin func_003E61F0 */
#pragma push /* merge_units */
extern char D_0055A1E0[];
#if 0 /* merge_units */
extern int func_003FF330(int, int, int, int, int, int, int);
#endif /* merge_units */
#define func_003FF330(a0, a1, a2, a3, a4, a5, a6) (func_003FF330((void *)(a0), (a1), (int *)(a2), (a3), (a4), (unsigned int)(a5), (void *)(a6))) /* merge_units */


int func_003E61F0(int a0, int a1, int a2, int a3, int t0, int t1, int t2) {
    int s0, s1, s2, s3, v0;
    float f0;
    int cond;

    v0 = (unsigned int)t1 < (unsigned int)16;
    s3 = a0;
    s2 = a2;
    s1 = t2;
    cond = v0 != 0;
    s0 = 0 + -1;
    if (cond) goto L003E6250;
    cond = s1 == 0;
    a2 = 0;
    if (cond) goto L003E6250;
    v0 = func_003FF330(a0, a1, a2, a3, t0, t1, t2);
    f0 = *(float*)((char*)s3 + 44);
    cond = s2 == 0;
    *(float*)((char*)s1 + 12) = f0;
    if (cond) goto L003E6250;
    s0 = 0 + 16;
    v0 = *(int*)(char*)D_0055A1E0;
    *(int*)(char*)s2 = v0;
L003E6250:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
#undef func_003FF330 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E61F0 */

/* merge_units: begin func_003E6270 */
#pragma push /* merge_units */
#undef PACK_BODY /* merge_units */
#define PACK_BODY(e, b) *(float*)(b + 0xC) = (float)MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK_NOTYPE(func_003E6270, 16, D_0055A220, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003E6270 */

/* merge_units: begin func_003E62F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_003E62F0(void) {
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E62F0 */

/* merge_units: begin func_003E6300 */
#pragma push /* merge_units */
typedef struct Obj {char pad[0x30];struct Obj*target;} Obj;
typedef struct ActionMsg {void*vt;char pad[0x18];int kind;char flag;char p21[3];int action;char on;char p29[3];int count;} ActionMsg;
extern char g_ActorActionMsgClass[],D_004E01E0[],D_004E0840[];extern int D_0055A840;
Obj*Script_ValueToObj(int);int*Receiver_GetOwner(Obj*);
void Event_Construct(ActionMsg*,void*);void Event_Send(ActionMsg*,Obj*,int);void cMessage_dtor(ActionMsg*,int);
int Script_StopPerformingAction(int*args){
 ActionMsg msg;Obj*obj=Script_ValueToObj(*args);
 int type=*Receiver_GetOwner(obj);if(type==D_0055A840)obj=obj->target;
 Event_Construct(&msg,g_ActorActionMsgClass);
 msg.action=0x28;msg.on=2;msg.vt=D_004E01E0;msg.count=1;msg.flag=8;msg.kind=0x40;
 Event_Send(&msg,obj,0);msg.vt=D_004E0840;cMessage_dtor(&msg,0);return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E6300 */

/* merge_units: begin func_003E63C0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
int Script_ValueToObj(int);
#endif /* merge_units */
#define Script_ValueToObj(a0) ((int)Script_ValueToObj((a0))) /* merge_units */
int GObj_IdentityB(int);
void Global_PerformAction_WithObject(int,signed char,int,float,int,int);
int Script_PerformAction_WithObject_4(int*args){
 int on;volatile int action;int timeBits;signed char kind;float time;int obj;on=args[5]!=0;timeBits=args[4];action=args[3];kind=(signed char)args[1];
 time=*(float*)&timeBits;
 obj=Script_ValueToObj(args[0]);
 Global_PerformAction_WithObject(obj,kind,GObj_IdentityB(args[2]),time,action,on);
 return 0;
}
#undef Script_ValueToObj /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E63C0 */
