/*
 * main/Checkpoint: range (4 files, 0022E680-0022E900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "message_pack.h"
#pragma push
#pragma cplusplus on
#include "net_recv_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0022E680 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(MP_P(e, 0x24), 0xC); strncpy(b + 0xC, MP_P(e, 0x28), 0x40);

DEFINE_MESSAGE_PACK(cAddCheckpointMsg_v02, 76, D_004F7948, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0022E680 */

/* merge_units: begin func_0022E710 */
#pragma push /* merge_units */
typedef struct { char pad[8]; int id; char name[1]; } CkSrc_f4;
typedef struct { void* vt; char pad4[0x20]; void* node; char* label; } CkMsg_f4;
CkMsg_f4* cAddCheckpointMsg_ctor(CkMsg_f4* self, CkSrc_f4* src); /* gsynth: defined below */
#pragma cplusplus on
typedef struct { char pad[0x10]; void* val; } Node0022E710;
typedef struct { void* vt; char p4[0x28]; } Evt0022E710;
typedef struct { char q0[0x4]; int a4; } Arg0022E710;
extern "C" {
extern void Event_Construct(Evt0022E710* e, void* type);
extern void MsgQueue_QueueClone(Evt0022E710* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0022E710* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0022E710** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0022E710** out, void* in);
extern char D_004DB8D0[];
#if 0 /* merge_units */
extern void cAddCheckpointMsg_ctor(Evt0022E710* e, Arg0022E710* a);
#endif /* merge_units */
#define cAddCheckpointMsg_ctor(a0, a1) ((void)cAddCheckpointMsg_ctor((CkMsg_f4 *)(a0), (CkSrc_f4 *)(a1))) /* merge_units */

extern unsigned char D_005721D0;
}
static inline int Eq0022E710(Node0022E710* a, Node0022E710* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0022E710(int a0, int a1, int a2, Arg0022E710* arg) {
    NetRecvGuard g;
    Arg0022E710* a; a = arg;
    if (D_005721D0) {
        Evt0022E710 e;
        int k[1];
        Node0022E710* end[1];
        Node0022E710* it[1];
        int tmp[1];
        Node0022E710* n;
        
        cAddCheckpointMsg_ctor(&e, a);
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0022E710(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB8D0;
        cMessage_dtor(&e, 0);
    }
    return 0x4C;
}
#pragma pop
#undef cAddCheckpointMsg_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E710 */

/* merge_units: begin func_0022E800 */
#pragma push /* merge_units */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004F7930[];
extern char D_004A6698[];
#if 0 /* merge_units */
extern void Event_Construct(void*, void*);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

extern void* Object_LookupById(int*);
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
static inline void* AllocL_f4(int size, char* file, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = Mem_Alloc(0, size, file, line);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    return p;
}
CkMsg_f4* cAddCheckpointMsg_ctor(CkMsg_f4* self, CkSrc_f4* src)
{
    int id[1];
    int n;
    Event_Construct(self, D_004F7930);
    self->vt = D_004DB8D0;
    id[0] = src->id;
    self->node = Object_LookupById(id);
    n = strlen(src->name) + 1;
    self->label = AllocL_f4(n, D_004A6698, 0x81);
    strncpy(self->label, src->name, n);
    return self;
}
#undef Event_Construct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E800 */

/* merge_units: begin func_0022E900 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; float timer; int text; } B8_Ckpt;
typedef struct { char pad[0x280]; int fonts[1]; } B8_Res;
extern char D_004F7960;
extern B8_Res* App_GetInstance(void);
extern int Font_GetStringWidth(int font, int text, int flags);
extern int TextManager_Get(void);
extern void TextManager_QueueText(int ctx, int text, int font, float* col, int x, int y);
void cCheckpoint_v10(B8_Ckpt* p, float dt) {
    float col[4];
    int w;
    int font;
    char idx;
    float a;
    if (p->text == 0 || p->timer < 0.0f) return;
    a = (p->timer < 1.0f) ? p->timer : 1.0f;
    col[0] = 0.65f;
    col[1] = 0.7f;
    col[2] = 1.0f;
    col[3] = a;
    idx = D_004F7960;
    font = *(int*)((unsigned char)idx * 4 + (int)App_GetInstance() + 0x280);
    w = Font_GetStringWidth(font, p->text, 0x200);
    TextManager_QueueText(TextManager_Get(), p->text, font, col, -(w / 2), 0);
    p->timer -= dt;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E900 */
