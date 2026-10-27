#ifndef GUI_WIDGET_VSLOTS_H
#define GUI_WIDGET_VSLOTS_H

/*
 * GuiWidgetV: virtual-call view of the GUI widget classes (guiWidget and
 * subclasses; ~40 src files declare a local W/Widget/Ui struct for it).
 * C++ only (#pragma cplusplus on before including). No data members and no
 * defined virtuals, so no vtable is emitted; derive to add fields
 * (struct MyW : GuiWidgetV { char pad4[0x5C]; int f60; };  vptr is +0).
 * Slot n sits at vtable offset 8 + 4*n.
 *   20 +0x58  IsA(type)        nonzero if the widget is (derived from) type
 *   21 +0x5C  SetCount(n, a)
 *   23 +0x64 / 24 +0x68  differ by subclass: Detach(int,int)/Release(int)
 *             on list widgets, Show(void*,int)/Hide(void*) on Ui screens -
 *             declare those in a derived local class.
 *   66 +0x110 Draw()
 * Not the same as the 'GuiWidget' structs in loose02/04/05_types.h (data
 * views) or the WidgetChild helper (Activate +0x14 .. LoseFocus +0x28).
 *
 * GuiWidget_FindChild_charP(self, name) finds a child widget by name; GuiFindAs() is the
 * common "find child then IsA-check" inline (matches FindAs_* in callers).
 * #define GUI_WIDGET_NO_PROTOS to keep a typed local declaration of
 * GuiWidget_FindChild_charP (then GuiFindAs is not provided).
 */
#ifndef __cplusplus
#error "gui_widget_vslots.h needs #pragma cplusplus on"
#endif

struct GuiWidgetV {
    virtual void _v00(); virtual void _v01(); virtual void _v02(); virtual void _v03(); virtual void _v04();
    virtual void _v05(); virtual void _v06(); virtual void _v07(); virtual void _v08(); virtual void _v09();
    virtual void _v0A(); virtual void _v0B(); virtual void _v0C(); virtual void _v0D(); virtual void _v0E();
    virtual void _v0F(); virtual void _v10(); virtual void _v11(); virtual void _v12(); virtual void _v13();
    virtual int IsA(const void* type);    /* 20 +0x58 */
    virtual void SetCount(int n, int a);  /* 21 +0x5C */
    virtual void _v16(); virtual void _v17(); virtual void _v18(); virtual void _v19(); virtual void _v1A();
    virtual void _v1B(); virtual void _v1C(); virtual void _v1D(); virtual void _v1E(); virtual void _v1F();
    virtual void _v20(); virtual void _v21(); virtual void _v22(); virtual void _v23(); virtual void _v24();
    virtual void _v25(); virtual void _v26(); virtual void _v27(); virtual void _v28(); virtual void _v29();
    virtual void _v2A(); virtual void _v2B(); virtual void _v2C(); virtual void _v2D(); virtual void _v2E();
    virtual void _v2F(); virtual void _v30(); virtual void _v31(); virtual void _v32(); virtual void _v33();
    virtual void _v34(); virtual void _v35(); virtual void _v36(); virtual void _v37(); virtual void _v38();
    virtual void _v39(); virtual void _v3A(); virtual void _v3B(); virtual void _v3C(); virtual void _v3D();
    virtual void _v3E(); virtual void _v3F(); virtual void _v40(); virtual void _v41();
    virtual void Draw();                  /* 66 +0x110 */
};

#ifndef GUI_WIDGET_NO_PROTOS
extern "C" void* GuiWidget_FindChild_charP(void* self, char* name); /* find child widget by name */

static inline GuiWidgetV* GuiFindAs(void* self, char* name, const void* type)
{
    GuiWidgetV* w = (GuiWidgetV*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
#endif

#endif /* GUI_WIDGET_VSLOTS_H */
