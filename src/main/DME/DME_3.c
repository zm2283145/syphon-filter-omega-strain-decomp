/*
 * main/DME: 5 files, 00429770-00429A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);

int func_00429770(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00429770 */

/* merge_units: begin func_00429790 */
#pragma push /* merge_units */
typedef struct NetConnInfo_h5 { int session; int status; } NetConnInfo_h5;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern int D_00572470;
extern int D_00572478;
extern signed char D_005724B0;
extern int Gui_GetScreenStack(void);
extern void func_0041E0F0(int a, int b, int c, int d, int e);
extern void func_002EBAF8(int* out, int session);
extern void func_002EBBA0(int session, int* out);
static inline int LocalSlot_h5(int session)
{
    if (D_005721C8) {
        if (D_00494178 == -1) {
            func_002EBAF8(&D_00494178, session);
        }
        return D_00494178;
    }
    return 0;
}
void func_00429790(NetConnInfo_h5* info)
{
    int slot[2];
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    D_005721A8 = info->session;
    if (info->status == 3) {
        D_005724B0 = 7;
        if (Gui_GetScreenStack()) {
            func_0041E0F0(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)"F_TO_CONNECT");
        }
    } else {
        D_005724B0 = 6;
        D_005721C8 = 1;
        func_002EBAF8(slot, info->session);
        D_00494178 = slot[0];
        func_002EBBA0(info->session, slot);
        if (slot[0] == LocalSlot_h5(D_005721A8) && Gui_GetScreenStack()) {
            func_0041E0F0(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 1, 0);
        }
    }
    D_00572470 = 0;
    D_00572478 = 0;
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429790 */

/* merge_units: begin func_00429920 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int kind; int id; } Pk429920;
extern "C" {
extern int D_005723F0;
extern unsigned char D_00572410;
extern unsigned char D_005721D8;
extern char D_005721E0[];
extern char D_004BF9D0[];
#if 0 /* merge_units */
extern unsigned char D_005724B0;
#endif /* merge_units */
#define D_005724B0 (*(unsigned char*)&D_005724B0) /* merge_units */

extern unsigned char D_00572418[];
extern int D_00572424[];
extern unsigned char D_005721C0;
extern int snprintf(char* buf, int n, const char* fmt, ...);
extern void func_0043B190(void* p);
extern void func_0043ACB0(void* p, int id);
}

#pragma define_section GUARD_DTOR_9920 ".dtors_drop" far_absolute RX
/* Scoped busy flag; the guard object also reserves the top stack slot retail has. */
struct Guard_9920 {
    char c;
    Guard_9920() { if (!D_005723C8) D_005723C8 = 1; }
    /* order matters: weak first, then the section (see alloc_guard.h) */
    __declspec(weak) __declspec(GUARD_DTOR_9920) ~Guard_9920() { D_005723C8 = 0; }
};
extern "C" void func_00429920(Pk429920* p)
{
    Guard_9920 g;
    int buf;
    int slot;
    unsigned char ok;
    D_005723F0--;
    func_002EBBA0(D_005721A8, &slot);
    if (p->id == slot) {
        D_00572410 = 1;
        D_005721D8 = 1;
        snprintf(D_005721E0, 0x10, D_004BF9D0);
        D_005724B0 = 7;
    }
    D_00572418[p->id] = 1;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok) {
        if (D_00572424[3] == -1) D_00572424[3] = 0;
        else if (D_00572424[2] == -1) D_00572424[2] = 0;
        else if (D_00572424[1] == -1) D_00572424[1] = 0;
    }
    func_0043B190(&buf);
    func_0043ACB0(&buf, p->id);
}
#undef D_005724B0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429920 */

/* merge_units: begin func_00429A60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_005721E0[16];
#endif /* merge_units */
#define D_005721E0 ((char*)&D_005721E0) /* merge_units */

extern int snprintf(char* buf, int size, const char* fmt, ...); /* snprintf-like */

/* Sets two flags and formats the default string into a 16-byte buffer. */
void func_00429A60(void)
{
    D_00572410 = 1;
    D_005721D8 = 1;
    snprintf(D_005721E0, 16, D_004BF9D0);
}
#undef D_005721E0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429A60 */

/* merge_units: begin func_00429A90 */
#pragma push /* merge_units */
typedef struct { int kind; int id; } Pk429A90;
#pragma push

void func_00429A90(Pk429A90* p) {
    unsigned char ok;
    if (!D_005723C8) D_005723C8 = 1;
    D_005723F0++;
    D_00572418[p->id] = 0;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok && p->id) D_00572424[p->id] = 0x0FFFFFFE;
    D_005723C8 = 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00429A90 */
