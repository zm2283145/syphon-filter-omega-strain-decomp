/*
 * main/NIEvent: range (2 files, 00237A20-00237AD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00237A20 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int NiRotationTrack_Update(float, char * );                       
int func_0023E5D0(char * );                            

void cNIEventLight_v48(char * arg0) {
    F_(arg0, 0x18C, signed char) = 1;
    if (F_(arg0, 0x184, int) == -1) {
        NiRotationTrack_Update(*(float *)((char *)F_(arg0, 0x17C, int) + ((F_(arg0, 0x178, int) - 1) * 0x10)) - F_(arg0, 0x188, float), arg0 + 0x170);
    }
    F_(arg0, 0x1AC, signed char) = 1;
    if (F_(arg0, 0x1A4, int) == -1) {
        NiRotationTrack_Update(*(float *)((char *)F_(arg0, 0x19C, int) + ((F_(arg0, 0x198, int) - 1) * 0x10)) - F_(arg0, 0x1A8, float), arg0 + 0x190);
    }
    func_0023E5D0(arg0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237A20 */

/* merge_units: begin func_00237AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Light00237AD0 {
public:
    int id;
    virtual void dtor(int flag);
    VPAD8(a) VPAD1(b)
    virtual void stop();
};
struct Ev00237AD0 { char pad[0x140]; Light00237AD0* light; };
extern "C" void Object_Deactivate(Ev00237AD0* self);
extern "C" void cNIEventLight_v16(Ev00237AD0* self)
{
    Object_Deactivate(self);
    if (self->light) {
        self->light->stop();
        if (self->light)
            self->light->dtor(1);
        self->light = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237AD0 */
