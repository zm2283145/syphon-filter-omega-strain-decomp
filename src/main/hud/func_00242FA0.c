#include "types.h"
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
typedef struct { int key; float f4; int id; int c; int d; int x14; signed char x18; } Ent_242FA0;
typedef struct Node_242FA0 { struct Node_242FA0* prev; struct Node_242FA0* next; Ent_242FA0* ent; } Node_242FA0;
typedef struct { Node_242FA0* n; } It_242FA0;
typedef struct { float v[4]; } Buf_242FA0;

extern char D_004A7210[];
extern char D_004A7508[];
extern char D_004A7510[];
extern char D_004A7518[];
extern int D_004F7D90;
extern int D_004F7DAC;
extern int D_004F7DB0;
extern char D_00587D90[];
extern char D_00587DA0[];
extern char D_00587DB0[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void* opNew_uint_int_charP_int(int size, int pool, char* file, int line);
void cObjectId_ctor_cObjectIdR(void* dst, void* src);
void std_list_tCalloutPtr_begin(It_242FA0* out, char* l);
void std_list_tCalloutPtr_end_void(It_242FA0* out, char* l);
void cLListIterator_tCalloutPtr_ctor(It_242FA0* out, It_242FA0* in);
void std_list_tCalloutPtr_push_back(char* l, Ent_242FA0** v);
void func_00243460(float f, int h);
void func_00243480(int h, int v);
void func_00243490(int h, int v);
int func_002434A0(int c);
int cPROJECTED_GOBJ_ctor(void* self, int c, int* key);
int cIE_GOBJ_ctor(void* self, int c, int* key);
void nHud_ComputeColor(Buf_242FA0* out, float t);
int TextObj_GetLineCount(int h);
void cTextArea_SetColor(int a, char* b);
void cInterfaceElement_SetText(int c, int a);
void cInterfaceElement_SetFilterColor(int c, void* b);
void cInterfaceElement_Activate(int c, int a);
void cIE_GOBJ_SetHost(int d, Ent_242FA0* e, int id);
int cInterfaceModel_CreateInstance(int a);
void cAnimator_AnimateTo(float f, int c);

static inline void BeginI_(It_242FA0* out, char* l) { It_242FA0 t; std_list_tCalloutPtr_begin(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void Begin_(It_242FA0* out, char* l) { BeginI_(out, l); }
static inline void EndI_(It_242FA0* out, char* l) { It_242FA0 t; std_list_tCalloutPtr_end_void(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void End_(It_242FA0* out, char* l) { EndI_(out, l); }

#pragma opt_dead_assignments off
int cHud_SetCallout(char* o, float scale, float fade, int* key, int a2, int id, int big, signed char kind)
{
    It_242FA0 it;
    Ent_242FA0* p;
    It_242FA0 b8;
    It_242FA0 b4;
    It_242FA0 e2;
    int gap;
    Buf_242FA0 buf;
    { int* q = &gap; }
    Begin_(&b8, o + 0x6E8);
    for (it = b8; End_(&b4, o + 0x6E8), it.n != b4.n; it.n = it.n->next) {
        if (it.n->ent->key == *key && id == it.n->ent->id)
            break;
    }
    End_(&e2, o + 0x6E8);
    if (it.n == e2.n) {
        Ent_242FA0* e;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        e = cMemMan_Allocate(0, 0x1C, D_004A7210, 0x505);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (e) {
            cObjectId_ctor_cObjectIdR(e, key);
            e->f4 = scale;
            e->x18 = kind;
            if (big) {
                void* m;
                int h;
                e->c = cInterfaceModel_CreateInstance(D_004F7DB0);
                m = opNew_uint_int_charP_int(0x90, 0, D_004A7518, 0x8E);
                if (m) m = (void*)cPROJECTED_GOBJ_ctor(m, e->c, key);
                e->d = (int)m;
                h = func_002434A0(e->c);
                if (h) {
                    func_00243490(h, 1);
                    func_00243480(h, 2);
                }
            } else {
                int h;
                if (kind) {
                    void* m;
                    e->c = cInterfaceModel_CreateInstance(D_004F7DAC);
                    m = opNew_uint_int_charP_int(0x90, 0, D_004A7510, 0x9E);
                    if (m) m = (void*)cIE_GOBJ_ctor(m, e->c, key);
                    e->d = (int)m;
                } else {
                    void* m;
                    e->c = cInterfaceModel_CreateInstance(D_004F7D90);
                    m = opNew_uint_int_charP_int(0x90, 0, D_004A7508, 0xA3);
                    if (m) m = (void*)cIE_GOBJ_ctor(m, e->c, key);
                    e->d = (int)m;
                }
                h = func_002434A0(e->c);
                if (h) func_00243460(1.0f, h);
            }
            e->id = id;
            if (e->c) {
                float t;
                int n;
                cInterfaceElement_SetText(e->c, a2);
                t = 10.0f;
                n = TextObj_GetLineCount(func_002434A0(e->c));
                if (n > 1) t += (float)(n - 1);
                cAnimator_AnimateTo(t, e->c);
                cIE_GOBJ_SetHost(e->d, e, e->id);
            }
            e->x14 = 0;
        }
        p = e;
        if (p->c) cInterfaceElement_Activate(p->c, 0);
        std_list_tCalloutPtr_push_back(o + 0x6E8, &p);
    } else {
        p = it.n->ent;
        cInterfaceElement_SetText(p->c, a2);
        p->f4 = scale;
    }
    if (fade == 0.0f) {
        cInterfaceElement_SetFilterColor(p->c, D_00587D90);
    } else if (fade < 0.0f) {
        ((char*)p->c)[0x19] = 0;
        cTextArea_SetColor(*(int*)((char*)p->c + 0x74), D_00587DB0);
    } else {
        nHud_ComputeColor(&buf, fade);
        cInterfaceElement_SetFilterColor(p->c, &buf);
        cTextArea_SetColor(*(int*)((char*)p->c + 0x74), D_00587DA0);
    }
    return 1;
}

