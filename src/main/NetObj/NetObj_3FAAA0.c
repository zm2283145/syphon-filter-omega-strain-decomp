/*
 * main/NetObj: 3 files, 003FAAA0-003FAC40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FAAA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003FAAA0(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FAAA0 */

/* merge_units: begin func_003FAAB0 */
#pragma push /* merge_units */
#include "net_local_id.h"
typedef struct { int busy; int addr; int slot; } Join_AAB0;
extern char D_00493A10[];
extern char D_00572418[];
extern char D_0055C7C0[];
extern char D_0055C7D0[];
extern char D_0055C7D4[];
extern unsigned char D_005724B0;
void printf(void* fmt, int a, int b);
int func_002EB9A8(void* slot, int addr, int idx);
void Net_OnRemoteClientJoined(Join_AAB0* j)
{
    if (j->busy == 0) {
        int s;
        int off;
        printf("\n\n\n\tRemote client joined the game: %d[%d]\n", j->addr, j->slot);
        {
            int ok = 1;
            if (g_IsMultiplayer) ok = D_005721C0;
            if (ok) D_005724B0 = 10; else if (D_005724B0 == 9) D_005724B0 = 10; else D_005724B0 = 9;
        }
        D_00493A10[j->slot] = 0;
        s = j->slot;
        s = s < NetLocalId() ? s : s - 1;
        D_00572418[j->slot] = 0;
        off = s * 0x98;
        if (func_002EB9A8(D_0055C7C0 + off, j->addr, j->slot) == 0) {
            *(unsigned char*)(D_0055C7D4 + off) = 1;
            *(int*)(D_0055C7D0 + off) = j->slot;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003FAAB0 */

/* merge_units: begin func_003FAC40 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern unsigned char D_00493A10[];
#endif /* merge_units */
#define D_00493A10 ((unsigned char*)&D_00493A10) /* merge_units */

extern unsigned char D_0055C780[];
extern unsigned int D_0055C990;
extern unsigned char D_005721D0;
extern unsigned int Net_GetClock(int);
extern void func_003FA940(int i);

void func_003FAC40(unsigned char* flag)
{
    unsigned char f = flag ? *flag : 0;
    unsigned int t = D_0055C990;
    int i;
    if (t > Net_GetClock(1)) return;
    D_0055C990 = Net_GetClock(1) + 100;
    for (i = 0; i != 4; i++) {
        unsigned char s = D_00493A10[i];
        if (s == 0 || (f && s == 1)) {
            if (D_005721D0) {
                D_00493A10[i] = 1;
                func_003FA940(i);
                if (flag) *flag = 0;
                break;
            }
            if (!flag) D_0055C780[i] = 1;
        }
    }
}
#undef D_00493A10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FAC40 */
