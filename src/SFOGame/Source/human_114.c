/*
 * SFOGame/Source/human: 3 files, 001B3120-001B31B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B3120 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void std_tree_pair_int_value_compare_find_intR(int*, int, int);
extern int std_tree_pair_int_value_compare_erase_tree(void*, int*);

/* Erase by key: pass a local copy of the key to the tree erase routine. */
int cAssocArray_int_netSystemField_Erase(void* map, int* key) {
    int k[1];

    k[0] = *key;
    return std_tree_pair_int_value_compare_erase_tree(map, k);
}

int cAssocArray_int_netSystemField_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_int_netSystemField_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_int_value_compare_find_intR(it, a1, a2);
    *out = it[0];
}

void cAssocArray_int_netSystemField_End(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_001B3120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B3120 */

/* merge_units: begin func_001B31B0 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
typedef struct { char d[0x9C]; } Str;
struct Snd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct Snd2 {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str s78;
    Str s114;
    char pad1B0[0x20];
} __attribute__((aligned(16)));
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Act {
    char pad0[0x14];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x33B9 - 0x5C];
    unsigned char b33B9;
    char pad33BA[0x346E - 0x33BA];
    unsigned char b346E;
    unsigned char b346F;
    signed char b3470;
};
extern "C" {
extern char D_004F1FD0[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004DADF0[];
extern void* g_VisionFxMan;
extern void* g_Hud;
extern unsigned char D_0053B540;
void cPlaySoundMsg_ctor_cSndFxR(Snd* e, void* r, void* owner);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Snd2* e, void* r, void* owner);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void cFileMan_dtor(Str* s, int flag);
void cVisionFxMan_SetMode(void*, int, int);
void cHud_UseNightVisionColors(void*, int);
}
extern "C" void cHuman_SetVisionEffect(Act* a)
{
    signed char v = 0;
    unsigned char s;
    if (a->b346F) v = *(signed char*)&a->b346F;
    else if (a->b346E) v = *(signed char*)&a->b346E;
    s = v;
    if (s != (unsigned char)a->b3470) {
        a->b3470 = v;
        if (a->b14) {
            bool ok = 0;
            if (a->p58 && a->p58->IsOn()) ok = 1;
            if (ok) {
                int m = 0;
                switch (s) {
                case 1: m = 1; break;
                case 2: m = 2; break;
                case 3: m = 3; break;
                }
                cVisionFxMan_SetMode(g_VisionFxMan, m, 0);
                cHud_UseNightVisionColors(g_Hud, s == 1);
                D_0053B540 = s == 1;
            }
        }
    }
    if (s == 2) {
        if (!a->b33B9) {
            Snd ev;
            cPlaySoundMsg_ctor_cSndFxR(&ev, D_004F1FD0, a);
            ev.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
            a->b33B9 = 1;
            ev.vt = D_004DAE30;
            cFileMan_dtor(&ev.s114, -1);
            cFileMan_dtor(&ev.s78, -1);
            cMessage_dtor(&ev, 0);
        }
    } else if (a->b33B9) {
        Snd2 ev;
        cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, D_004F1FD0, a);
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
        a->b33B9 = 0;
        ev.vt = D_004DADF0;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B31B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B31B0 */

/* merge_units: begin func_001B33D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x352C]; float t; } O_1B33D0;
const float D_0048A208[2] = { 5.0f, 0.0f };
static const float dat_0048A210[2] = { 0.2f, 0.0f };
float cHuman_GetRecoilAimAdjust(O_1B33D0* o)
{
    return 1.0f + ((*(float*)dat_0048A210) - 1.0f) * (o->t / (*(float*)D_0048A208));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B33D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B33D0 */
