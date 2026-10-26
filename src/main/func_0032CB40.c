/* GuiKeyboard_Init: build the on-screen keyboard: collect the key widgets of the five rows, then fill the
 * up/down/left/right neighbour tables and the label table for every key. */
#pragma cplusplus on
#include "types.h"
#include "gui_traversal_types.h"

struct KW {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual int IsA(void* type);
    char pad4[0x10 - 4];
    int index;            /* 0x10 */
    unsigned short flags; /* 0x14 */
    char pad16[0x28 - 0x16];
    ChildList children;   /* 0x28 */
    char pad34[0x88 - 0x34];
    unsigned char b88;
};
struct PVec { unsigned int cap; unsigned int count; KW** data; int pad; };
struct PIt { KW** p; };
struct IVec { unsigned int cap; unsigned int count; int* data; int pad; };
struct KSelf {
    char pad0[0x48];
    KW* w48;
    KW* w4C;
    char pad50[4];
    int x54;
    int x58;
    char pad5C[4];
    PVec keys;     /* 0x60 */
    IVec labels;   /* 0x70 */
    char pad80[0xA0 - 0x80];
    IVec up;       /* 0xA0 */
    IVec down;     /* 0xB0 */
    IVec left;     /* 0xC0 */
    IVec right;    /* 0xD0 */
};

extern "C" {
void GuiWidget_Init(KSelf* self);
KW* GuiWidget_FindChildByName(KSelf* self, char* name);
void List_Begin(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
void func_0032D0B0(PVec* v, KW** w);
KW** func_0032D0A0(PVec* v);
void func_0032D090(PIt* out, PVec* v, KW*** p);
void func_0032D050(PIt* out, PVec* v);
void func_0032D040(PIt* out, PIt* in);
void PtrVec_PushBack_1C1080(IVec* v, int* value);
int Loc_GetLanguage(void);
void GuiKeyboard_ApplyLayout(KSelf* self, int lang);
extern char* D_00492650;
extern char* D_00492648;
extern char* D_00492640;
extern char D_004A9870[];
extern char D_004A9880[];
extern char D_004A7520[];
extern int D_004B8970[5];
extern int* D_00492660[5];
extern int* D_00492680[5];
extern int* D_004926A0[5];
}

static inline bool Ne(KW** a, PIt* b) { return !(a == b->p); }

extern "C" void GuiKeyboard_Init(KSelf* self)
{
    ChildIterator end2, end;
    int t1, t2, t3, t4;
    PIt end3;
    ChildIterator begin, begin2;
    PIt it;
    ChildIterator rawBegin, rawBegin2, rawEnd2, rawEnd;
    KW** first;
    PIt rawEnd3;
    int start[5];
    GuiWidget_Init(self);
    self->x54 = 0;
    self->x58 = 0;
    KW* kb = GuiWidget_FindChildByName(self, D_00492650);
    if (!kb)
        return;
    {
        ChildList* rows = &kb->children;
        /* declaration order picks the saved registers (keys s4, k s3, row s2, key s1) */
        ChildList* keys;
        KW* k;
        ChildNode* row;
        ChildNode* key;
        int ri;
        if (rows->count != 5)
            return;
        List_Begin(&rawBegin, rows);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
        row = begin.node;
        std_list_GuiWidgetPtr_end(&rawEnd, rows);
        cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
        ri = 0;
        while (row != end.node) {
            KW* rw = (KW*)row->widget;
            int n = D_004B8970[ri];
            keys = &rw->children;
            if (n != rw->children.count)
                return;
            List_Begin(&rawBegin2, keys);
            std_list_GuiWidgetPtr_generic_iterator_ctor(&begin2, &rawBegin2);
            key = begin2.node;
            std_list_GuiWidgetPtr_end(&rawEnd2, keys);
            cLListIterator_GuiWidgetPtr_ctor_listR(&end2, &rawEnd2);
            while (key != end2.node) {
                k = (KW*)key->widget;
                k = (k && k->IsA(D_004A9870)) ? k : 0;
                if (!k)
                    return;
                func_0032D0B0(&self->keys, (KW**)&key->widget);
                key = key->next;
                std_list_GuiWidgetPtr_end(&rawEnd2, keys);
                cLListIterator_GuiWidgetPtr_ctor_listR(&end2, &rawEnd2);
            }
            row = row->next;
            ri++;
            std_list_GuiWidgetPtr_end(&rawEnd, rows);
            cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
        }
    }
    {
        int row, col;
        {
            int i, sum = 0;
            for (i = 0; i < 5; i++) {
                start[i] = sum;
                sum += D_004B8970[i];
            }
        }
        row = 0;
        col = 0;
        first = func_0032D0A0(&self->keys);
        func_0032D090(&it, &self->keys, &first);
        KW** p = it.p;
        func_0032D050(&rawEnd3, &self->keys);
        func_0032D040(&end3, &rawEnd3);
        if (Ne(p, &end3)) {
            do {
                int u, d, l, r, x, y;
                u = row == 0 ? 4 : row - 1;
                d = row == 4 ? 0 : row + 1;
                x = D_004926A0[row][col];
                y = D_00492680[row][col];
                t1 = y + start[u];
                PtrVec_PushBack_1C1080(&self->up, &t1);
                t2 = x + start[d];
                PtrVec_PushBack_1C1080(&self->down, &t2);
                l = col == 0 ? D_004B8970[row] - 1 : col - 1;
                r = col == D_004B8970[row] - 1 ? 0 : col + 1;
                t3 = l + start[row];
                PtrVec_PushBack_1C1080(&self->left, &t3);
                t4 = r + start[row];
                PtrVec_PushBack_1C1080(&self->right, &t4);
                (*p)->index = col + start[row];
                PtrVec_PushBack_1C1080(&self->labels, &D_00492660[row][col]);
                col++;
                if (col == D_004B8970[row]) {
                    col = 0;
                    row++;
                }
                p++;
                func_0032D050(&rawEnd3, &self->keys);
                func_0032D040(&end3, &rawEnd3);
            } while (Ne(p, &end3));
        }
    }
    GuiKeyboard_ApplyLayout(self, Loc_GetLanguage());
    {
        KW* w = GuiWidget_FindChildByName(self, D_00492648);
        w = (w && w->IsA(D_004A9880)) ? w : 0;
        self->w4C = w;
    }
    if (self->w4C) {
        self->w4C->flags &= ~0x80;
        self->w4C->b88 = 1;
    }
    {
        KW* w = GuiWidget_FindChildByName(self, D_00492640);
        w = (w && w->IsA(D_004A7520)) ? w : 0;
        self->w48 = w;
    }
}
