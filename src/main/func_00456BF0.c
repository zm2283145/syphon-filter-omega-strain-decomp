#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"

struct LNode { LNode* prev; LNode* next; int* obj; };
struct O456 {
    char pad[0x8C]; void* f8C; void* arr[7]; char* acc; int fB0;
};

extern "C" {
extern char* D_00497960;
extern char* D_00497978;
extern char D_004A7520[];
extern char D_004C1A38[];
extern char D_004C1C60[];
extern char D_004C1C70[];
char* Loc_LookupText(char*);
void func_0013B180(void*, void*);
void func_0028C090(void*, void*);
void func_0028C0A0(void*, void*);
void func_0028C0B0(void*, void*);
void func_003688C0(void*);
void func_0041BEB0(void*, char*, int);
int sprintf(char*, const char*, ...);
void func_00456BF0(O456* o);
}

void func_00456BF0(O456* o)
{
    LNode* end;
    LNode* it;
    int a;
    int t;
    char buf[16];
    GuiWidgetV* w;

    o->acc = (char*)GuiWidget_FindChildByName(o, D_00497960);
    if (o->acc) {
        int i = 0;
        LNode* n;
        func_0013B180(&a, o->acc + 0x28);
        func_0028C0B0(&it, &a);
        n = it;
        while ((func_0028C0A0(&t, o->acc + 0x28), func_0028C090(&end, &t), n != end) && i < 7) {
            n->obj[4] = i;
            o->arr[i] = n->obj;
            i++;
            n = n->next;
        }
    }
    o->f8C = GuiWidget_FindChildByName(o, D_00497978);
    func_003688C0(o);
    o->fB0 = 0;
    w = GuiFindAs(o, D_004C1C60, D_004A7520);
    if (w) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = Loc_LookupText(buf);
        if (s) func_0041BEB0(w, s, 0);
        else func_0041BEB0(w, D_004C1A38, 0);
    }
}