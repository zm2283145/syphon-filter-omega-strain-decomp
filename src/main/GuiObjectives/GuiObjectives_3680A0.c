#pragma cplusplus on

#include "types.h"

struct T3680A0 { char pad[0xC]; int serial; };
struct H3680A0 {
    T3680A0* p;
    int serial;
    bool Valid() { return !p || p->serial == serial; }
    T3680A0* Get() { return Valid() ? p : 0; }
};
struct I3680A0 { char pad[0x14]; H3680A0 h; };
struct N3680A0 { int pad0; N3680A0* next; I3680A0* item; };
struct S3680A0 { char pad[0x48]; void* w48; char pad4C[0x5C - 0x4C]; int sel; };
struct Hud3680A0 { char pad[0x6A0]; int a6A0; };

extern "C" {
extern Hud3680A0* D_004FFC2C;
extern char D_00587C90[];
void* ObjMan_GetService(void);
T3680A0* ObjMan_GetObjective(void* mgr, int id);
void List_Begin_16E880(void* out, void* list);
void func_0026C390(void* out, void* raw);
void func_0026C320(void* out, void* list);
void func_0026C350(void* out, void* in);
void func_00272AD0(void* a, I3680A0* item);
void func_0026C570(int a);
char* func_002749B0(I3680A0* item, char* buf);
void Notify_Insert(void* list, char* text, void* color, int a, int b);
int GuiTextListWidget_GetItemId(void* list, int a);
int GuiWidget_OnEvent(void* self, void* sender, unsigned short msg, int a3, int a4);
}

/* Tab list message handler: on select (0x13) announce every tracked item bound to the chosen objective. */
extern "C" int GuiObjectives_HandleEvent(S3680A0* self, void* sender, unsigned short msg, int a3, int a4)
{
    if (msg == 0x10 && a3 == 1 && sender != self->w48) return 1;
    if (sender == self->w48) {
        int idx = GuiTextListWidget_GetItemId(self->w48, a4);
        if (msg == 0x14) {
            self->sel = idx;
            return 1;
        }
        if (msg == 0x13) {
            if (idx != -1) {
                T3680A0* obj = ObjMan_GetObjective(ObjMan_GetService(), idx);
                if (obj) {
                    N3680A0* end[1];
                    N3680A0* it[1];
                    void* b[1];
                    int t[1];
                    char buf[0x100];
                    char* base = (char*)D_004FFC2C + 0x90;
                    void* list = base + 0x24;
                    I3680A0* item;
                    N3680A0* n;
                    List_Begin_16E880(b, list);
                    func_0026C390(it, b[0]);
                    for (n = it[0]; func_0026C320(t, list), func_0026C350(end, t), n != end[0]; n = n->next) {
                        item = n->item;
                        if (item->h.Get() != 0 && item->h.Get() == obj) {
                            char* name;
                            func_00272AD0(base, item);
                            func_0026C570(D_004FFC2C->a6A0);
                            name = func_002749B0(item, buf);
                            if (name)
                                Notify_Insert((char*)D_004FFC2C + 0x100, name, D_00587C90, 2, 1);
                        }
                    }
                }
            }
            return 1;
        }
    }
    return GuiWidget_OnEvent(self, sender, msg, a3, a4);
}
