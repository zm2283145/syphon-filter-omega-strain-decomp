/*
 * SFOGame/Source/GuiEquipmentSetup: 5 files, 002A53A0-002A5570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A53A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_array_member_dtor.h"

/* Destructor: vector and array members, optionally delete. */
DEFINE_VECTOR_ARRAY_MEMBER_DTOR(func_002A53A0)
static inline void merge_flush_func_002A53A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A53A0 */

/* merge_units: begin func_002A5440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiEquipmentSetup_types.h"

extern void* D_00506550;
extern int GuiEquipmentSetup_ManRender(void* p);

void func_002A5440(EquipSetupState* self, int value) {
    EquipSlot* slot = self->slot;

    if (slot != 0) {
        slot->unk32 = value;
    }
}

int ES_ManRenderWrapper(void) {
    return GuiEquipmentSetup_ManRender(D_00506550);
}
static inline void merge_flush_func_002A5440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5440 */

/* merge_units: begin func_002A5470 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Vec2 { float x, y; Vec2() {} Vec2(float ax, float ay) { x = ax; y = ay; } Vec2& operator+=(const Vec2& o) { x += o.x; y += o.y; return *this; } };
typedef struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    struct Widget* data;
} ListNode;
typedef struct ListIter { ListNode* node; } ListIter;
typedef struct NodeList { int unk0; } NodeList;
typedef struct Widget {
    char pad[0x28];
    NodeList children;
    char pad2C[0x34 - 0x2C];
    float x, y;
} Widget;
extern "C" void std_list_deleter_voidPtr_begin_void(ListIter* out, NodeList* list);
extern "C" void std_list_GuiWidgetPtr_generic_iterator_ctor(ListIter* out, ListIter* in);
extern "C" void std_list_GuiWidgetPtr_end(ListIter* out, NodeList* list);
extern "C" void cLListIterator_GuiWidgetPtr_ctor_listR(ListIter* out, ListIter* in);
extern "C" void GuiWidget_SetPosition(Widget* w, float x, float y);
static inline void SetPos(Widget* w, Vec2 v) { GuiWidget_SetPosition(w, v.x, v.y); }
extern "C" void func_002A5470(Widget* w, Vec2 off)
{
    ListIter last;
    ListIter it;
    ListIter beginIt;
    ListIter endIt;
    NodeList* list;
    ListNode* node;
    if (w) {
        Vec2 p(w->x, w->y);
        p += off;
        SetPos(w, p);
        list = &w->children;
        std_list_deleter_voidPtr_begin_void(&beginIt, list);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&it, &beginIt);
        node = it.node;
        std_list_GuiWidgetPtr_end(&endIt, list);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
        if (node != last.node) {
            do {
                func_002A5470(node->data, off);
                node = node->next;
                std_list_GuiWidgetPtr_end(&endIt, list);
                cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
            } while (node != last.node);
        }
    }
}
static inline void merge_flush_func_002A5470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5470 */

/* merge_units: begin func_002A5570 */
#pragma push /* merge_units */
/* Byte of per-slot flags; bit 0 is the "set" flag. */
typedef struct SlotFlags {
    unsigned char set : 1;
} SlotFlags;

extern char* D_004EE620; /* table of 16-byte rows of flag bytes */

/* Clears flag bit 0 of byte `col` in row `row` of the D_004EE620 table. */
void TeamDelEnemy_int_int(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A5570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A5570 */

/* merge_units: begin func_002A55A0 */
#pragma push /* merge_units */
typedef struct CellFlags {
    unsigned char set : 1;
    unsigned char rest : 7;
} CellFlags;

typedef struct CellRow {
    CellFlags cells[16];
} CellRow;

#if 0 /* merge_units */
extern CellRow* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(CellRow **)&D_004EE620) /* merge_units */



/* Marks cell (row, col) in the D_004EE620 grid. */
void TeamSetEnemy_int_int(int row, int col) {
    D_004EE620[row].cells[col].set = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A55A0(void) {}
#undef D_004EE620 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A55A0 */
