/*
 * main/GuiGameScreen: range (2 files, 0045BD30-0045BDF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0045BD30 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4 {
    __int128 q;
    V4() {}
};
struct Scr {
    char pad[0x100];
    V4 last;
    unsigned char have;
};
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" int GuiGameScreen_CloseChooseMenu(Scr* s);
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void func_0045BD30(Scr* s, V4* p)
{
    if (!s->have) {
        GQ(&s->last, p);
        s->have = 1;
        return;
    }
    {
        V4 d;
        V4 r;
        float ret;
        {
            V4* pr = &r; V4* pa = &s->last;
            asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(p); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
        }
        {
V4* dd; V4* ss; int t; __int128 x; V4* pv;
ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
            asm {
                lqc2 vf1, 0(pv)
                vmul.xyz vf2, vf1, vf1
                vmulax.w ACC, vf0, vf2x
                vmadday.w ACC, vf0, vf2y
                vmaddz.w vf3, vf0, vf2z
                vsqrt Q, vf3w
                vwaitq
                vaddq.x vf4, vf0, Q
                qmfc2.ni t, vf4
                mtc1 t, ret
            }
        }
        if (!(ret <= 3.0f))
            GuiGameScreen_CloseChooseMenu(s);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045BD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045BD30 */

/* merge_units: begin func_0045BDF0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Event_Construct();                       
int Event_Send();                         
int cMessage_dtor();                           
int GuiGameScreen_CloseChooseMenu();                            
extern char D_004DC330;
extern char D_004F7E48;

#pragma push
#pragma opt_common_subs off
void func_0045BDF0(char * arg0) {
    struct { char * f40[9]; int f64; unsigned int f68[2]; } sl;
    int temp_s2;
    unsigned int temp_s0;
    char * temp_v0;

    if (F_(arg0, 0xE0, int) != 0) {
        temp_v0 = (char *)(F_(arg0, 0xE8, int));
        temp_s0 = F_(temp_v0, 0x54, int);
        if ((temp_s0 < (unsigned int) (F_(temp_v0, 0x94, int) - 1)) && (F_(arg0, 0xEC, int) != 0)) {
            temp_s2 = F_(arg0, 0xF0, int);
            Event_Construct(sl.f40, &D_004F7E48);
            sl.f64 = temp_s2;
            sl.f68[0] = temp_s0;
            sl.f40[0] = &D_004DC330;
            Event_Send(sl.f40, F_(arg0, 0xEC, int), 0);
            sl.f40[0] = &D_004DC330;
            cMessage_dtor(sl.f40, 0);
        }
        GuiGameScreen_CloseChooseMenu(arg0);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0045BDF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0045BDF0 */
