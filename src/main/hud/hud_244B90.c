/*
 * main/hud: range (3 files, 00244B90-00244EE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00244B90 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Mgr_244B90 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void Refresh(); };
struct W_244B90 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void Draw(); };
extern "C" {
extern unsigned char g_LoadoutPending;
extern char g_Video[];
void HudRadar_ComputeMarkerMatrix(char* o);
void XLib_ClearZBuffer(void* a);
Mgr_244B90* Gui_GetScreenStack(void);
void List_Begin_16E880(Word* w, void* l);
int* std_list_tCalloutPtr_generic_iterator_1_ctor(int* dst, int value);
void std_list_tCalloutPtr_end_void_2(Word* w, void* l);
Word* cConstLListIterator_tCalloutPtr_ctor(Word* dst, Word* src);
void IeScreen_Draw(int a);
void Hud_DrawCallouts(char* o);
}
#define Begin_244B90(l) (List_Begin_16E880(&tmp, l), std_list_tCalloutPtr_generic_iterator_1_ctor(&r, tmp.value), (char*)r)
#define End_244B90(l) (std_list_tCalloutPtr_end_void_2(&e, l), cConstLListIterator_tCalloutPtr_ctor(&e2, &e), (char*)e2.value)

extern "C" void Hud_Draw(char* o)
{
    char* n;
    char* v;
    W_244B90* a;
    Word e2; int r; Word tmp; Word e;
    HudRadar_ComputeMarkerMatrix(o);
    if (!g_LoadoutPending) {
        XLib_ClearZBuffer(g_Video);
        if (F_(o, 0x6A0, int) && F_(o, 0x6A9, unsigned char)) {
            Gui_GetScreenStack()->Refresh();
            for (n = Begin_244B90(o + 0x6E8); n != End_244B90(o + 0x6E8); n = F_(n, 4, char*)) {
                v = F_(n, 8, char*);
                a = F_(v, 0x10, W_244B90*);
                if (a && F_(v, 0xC, int) && F_(a, 0x64, unsigned char)) {
                    a->Draw();
                }
            }
            IeScreen_Draw(F_(o, 0x54, int));
            XLib_ClearZBuffer(g_Video);
        } else {
            Hud_DrawCallouts(o);
            IeScreen_Draw(F_(o, 0x54, int));
            Gui_GetScreenStack()->Refresh();
        }
    } else {
        Gui_GetScreenStack()->Refresh();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244B90 */

/* merge_units: begin func_00244D10 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x14]; unsigned short flags; } Tx_244D10;
typedef struct { char pad[0x14]; unsigned short flags; char pad16[0x32]; char sub[4]; } Ob_244D10;
typedef struct { float time; unsigned char b4; char pad5[3]; float f8; unsigned char bC; char padD[3]; Ob_244D10* obj; Tx_244D10* text; } T_244D10;
typedef struct { float r, g, b, a; } Col_244D10;
extern "C" int ScriptEvent_TimeFormat(char* buf, float seconds);
extern "C" void GuiTextWidget_SetColour(Tx_244D10* t, Col_244D10* c);
extern "C" void GuiTextWidget_SetText(Tx_244D10* t, char* text, int zero);
extern "C" int String_Length(void* p);

extern "C" bool HudTimer_Update(T_244D10* t, float now)
{
    unsigned char running = t->time > now;
    bool expired = 0;
    if (t->b4 && !running) {
        t->b4 = 0;
        t->f8 = 5.0f + now;
        expired = 1;
    }
    t->b4 = running;
    if (t->text && t->obj) {
        t->text->flags &= ~2;
        t->obj->flags &= ~2;
        if (t->b4 || t->f8 > now) {
            char buf[16];
            Col_244D10 c;
            bool show;
            ScriptEvent_TimeFormat(buf, t->b4 ? t->time - now : 0.0f);
            c.r = 1.0f;
            c.g = 1.0f;
            c.b = 1.0f;
            c.a = 1.0f;
            show = 1;
            if (t->f8 > now) {
                if ((int)((t->f8 - now) / 0.25f) & 1) {
                    c.b = 0.3f;
                    c.g = 0.3f;
                } else {
                    show = 0;
                }
            }
            if (show) {
                GuiTextWidget_SetColour(t->text, &c);
                GuiTextWidget_SetText(t->text, buf, 0);
                t->text->flags |= 2;
                if (String_Length(t->obj->sub))
                    t->obj->flags |= 2;
            }
            t->bC = show;
        } else {
            t->f8 = 0.0f;
        }
    }
    return expired;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244D10 */

/* merge_units: begin func_00244EE0 */
#pragma push /* merge_units */
typedef struct { float time; unsigned char b4; char pad5[3]; int f8; int pad; void* target; } T4EE0;
extern char D_004A7218[];
#if 0 /* merge_units */
extern void GuiTextWidget_SetText(void* target, const char* text, int zero);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (void *)(a1), (a2))) /* merge_units */

void HudTimer_Start(T4EE0* t, char* text, float time) {
    t->time = time;
    t->f8 = 0;
    t->b4 = 0;
    if (t->target)
        GuiTextWidget_SetText(t->target, text ? text : D_004A7218, 0);
}
#undef GuiTextWidget_SetText /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244EE0 */
