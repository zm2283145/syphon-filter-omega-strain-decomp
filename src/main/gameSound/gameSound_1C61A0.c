/*
 * main/gameSound: range (2 files, 001C61A0-001C6200)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop

/* merge_units: begin func_001C61A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern "C" void func_00177E20();
extern "C" void func_001C80B0();
extern void * const D_004DAC30[];
extern char D_004D9DE0[];
}
extern "C" Vt8Object* func_001C61A0(Vt8Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAC30);
        if (self)
            self->vtable = D_004D9DE0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAC30[8] = { (void*)0x0, (void*)0x0, (void*)func_001C61A0, (void*)func_00177E20, (void*)func_001C80B0, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C61A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C61A0 */

/* merge_units: begin func_001C6200 */
#pragma push /* merge_units */
#define AND &&
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; } Msg_1C6200;
extern unsigned char D_005721C8;
extern void* D_004FFC2C;
extern char D_0049F490[];
extern char D_0051F098[];
extern char D_004DE280[];
extern void func_00241DA0(void* hud, char* a, char* b);
extern void* Loc_LookupText(char* key);
extern void Hud_PostNotification(void* hud, void* text);
extern void Event_Construct(Msg_1C6200* m, void* type);
extern int Loc_FindKeyThunk(char* s);
extern void Transport_Send(int a, Msg_1C6200* m, int b, int c);
extern void cMessage_dtor(Msg_1C6200* m, int f);
/* add a PDA quip (name, text); broadcast it unless silent */

#pragma opt_propagation off
void func_001C6200(char* name, char* text0, int silent)
{
    
    if (name) {
        char* text = (!text0 || !*text0) ? D_0049F490 : text0;
        func_00241DA0(D_004FFC2C, name, text);
        {
            void* hud = D_004FFC2C;
            Hud_PostNotification(hud, Loc_LookupText(D_0049F490));
        }
        if (!silent AND D_005721C8) {
            Msg_1C6200 m;
            Msg_1C6200* p = &m;
            Event_Construct(p, D_0051F098);
            m.w24 = 0;
            m.vt = D_004DE280;
            m.b28 = 2;
            p->key0 = name ? Loc_FindKeyThunk(name) : -1;
            p->key1 = text ? Loc_FindKeyThunk(text) : -1;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6200 */
