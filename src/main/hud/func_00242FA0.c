#include "types.h"
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
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
void* Mem_Alloc(int pool, int size, char* file, int line);
void* func_0013D5C0(int size, int pool, char* file, int line);
void func_0016F7E0(void* dst, void* src);
void func_00242E30(It_242FA0* out, char* l);
void CalloutList_End(It_242FA0* out, char* l);
void func_002426A0(It_242FA0* out, It_242FA0* in);
void CalloutList_PushBack(char* l, Ent_242FA0** v);
void func_00243460(float f, int h);
void func_00243480(int h, int v);
void func_00243490(int h, int v);
int func_002434A0(int c);
int func_002434B0(void* self, int c, int* key);
int func_003E99B0(void* self, int c, int* key);
void Hud_GetLockColour(Buf_242FA0* out, float t);
int func_003D04C0(int h);
void func_003D0810(int a, char* b);
void func_003E7EC0(int c, int a);
void func_003E7EE0(int c, void* b);
void func_003E8DE0(int c, int a);
void func_003E97B0(int d, Ent_242FA0* e, int id);
int func_003EF010(int a);
void func_003F44E0(float f, int c);

static inline void BeginI_(It_242FA0* out, char* l) { It_242FA0 t; func_00242E30(&t, l); func_002426A0(out, &t); }
static inline void Begin_(It_242FA0* out, char* l) { BeginI_(out, l); }
static inline void EndI_(It_242FA0* out, char* l) { It_242FA0 t; CalloutList_End(&t, l); func_002426A0(out, &t); }
static inline void End_(It_242FA0* out, char* l) { EndI_(out, l); }

#pragma opt_dead_assignments off
int Hud_ShowCallout(char* o, float scale, float fade, int* key, int a2, int id, int big, signed char kind)
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
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        e = Mem_Alloc(0, 0x1C, D_004A7210, 0x505);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        if (e) {
            func_0016F7E0(e, key);
            e->f4 = scale;
            e->x18 = kind;
            if (big) {
                void* m;
                int h;
                e->c = func_003EF010(D_004F7DB0);
                m = func_0013D5C0(0x90, 0, D_004A7518, 0x8E);
                if (m) m = (void*)func_002434B0(m, e->c, key);
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
                    e->c = func_003EF010(D_004F7DAC);
                    m = func_0013D5C0(0x90, 0, D_004A7510, 0x9E);
                    if (m) m = (void*)func_003E99B0(m, e->c, key);
                    e->d = (int)m;
                } else {
                    void* m;
                    e->c = func_003EF010(D_004F7D90);
                    m = func_0013D5C0(0x90, 0, D_004A7508, 0xA3);
                    if (m) m = (void*)func_003E99B0(m, e->c, key);
                    e->d = (int)m;
                }
                h = func_002434A0(e->c);
                if (h) func_00243460(1.0f, h);
            }
            e->id = id;
            if (e->c) {
                float t;
                int n;
                func_003E7EC0(e->c, a2);
                t = 10.0f;
                n = func_003D04C0(func_002434A0(e->c));
                if (n > 1) t += (float)(n - 1);
                func_003F44E0(t, e->c);
                func_003E97B0(e->d, e, e->id);
            }
            e->x14 = 0;
        }
        p = e;
        if (p->c) func_003E8DE0(p->c, 0);
        CalloutList_PushBack(o + 0x6E8, &p);
    } else {
        p = it.n->ent;
        func_003E7EC0(p->c, a2);
        p->f4 = scale;
    }
    if (fade == 0.0f) {
        func_003E7EE0(p->c, D_00587D90);
    } else if (fade < 0.0f) {
        ((char*)p->c)[0x19] = 0;
        func_003D0810(*(int*)((char*)p->c + 0x74), D_00587DB0);
    } else {
        Hud_GetLockColour(&buf, fade);
        func_003E7EE0(p->c, &buf);
        func_003D0810(*(int*)((char*)p->c + 0x74), D_00587DA0);
    }
    return 1;
}

