#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct W_418E00 {
    virtual ~W_418E00();
    char pad4[0x10];
    unsigned short f14;
};
struct M_418E00 {
    char pad0[0x14];
    char list[0xC];
    char pending[0xC];
};
struct NI_418 { void* n; };
extern "C" {
int func_002A8890(void* a, void* b);
void func_002A88B0(void* out, void* list);
void func_002CCDE0(void* dst, void* src);
void func_002CCDF0(void* it);
int* func_002CCE10(void* it);
void func_002CCE20(void* dst, void* src);
void func_002CCE30(void* out, void* list);
void func_002CCE40(void* it);
void func_002CCE50(void* list, W_418E00** v);
NI_418 func_0028C0A0(void* list);
void func_0028C090(void* dst, const NI_418& src);
void GuiManager_RemoveWidget(M_418E00* m, W_418E00* w);
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BF138[];
}

/* list.end() converted to the const iterator (by-value temporary). */
static inline void End_418(char** out, M_418E00* m) { func_0028C090(out, func_0028C0A0(m->list)); }
/* Linear search for w; locals live at inline depth (stack slot order). */
static inline void Find_418(char** out, M_418E00* m, W_418E00*& w)
{
    int it;
    int b;
    int e;
    func_002CCE40(&it);
    func_002CCE30(&b, m->list);
    func_002CCE20(&it, &b);
    func_002A88B0(&e, m->list);
    if (func_002A8890(&it, &e) != 0) {
loopf:
        if ((W_418E00*)*func_002CCE10(&it) != w) {
            func_002CCDF0(&it);
            func_002A88B0(&e, m->list);
            if (func_002A8890(&it, &e) != 0) goto loopf;
        }
    }
    func_002CCDE0(out, &it);
}

extern "C" void func_00418E00(M_418E00* m, W_418E00* w, int del)
{
    char* pos;
    char* end;

    Find_418(&pos, m, w);
    End_418(&end, m);
    if (pos != end) {
        if (!(w->f14 & 0x40) || del) {
            w->f14 |= 0x40;
            if (del) {
                GuiManager_RemoveWidget(m, w);
                {
                    W_418E00* p = w;
                    AllocGuard g;
                    p->~W_418E00();
                    Mem_Free(0, p, D_004BF138, 0xDB);
                }
            } else {
                func_002CCE50(m->pending, &w);
            }
        }
    }
}
