#ifndef GOBJ_V07_REGISTER_H
#define GOBJ_V07_REGISTER_H

/*
 * Virtual method 7 shared by pathed GOBJ classes: notify the attached
 * object at +0x64 (its int slot 22 with 1), run func_003CE7D0 on self,
 * then register self with TargetVis_Unregister(g_TargetVisMgr, self).
 * C++ only (#pragma cplusplus on before including).
 */
class VSlotsInt23 {
public:
    virtual void slot0(int); virtual void slot1(int); virtual void slot2(int);
    virtual void slot3(int); virtual void slot4(int); virtual void slot5(int);
    virtual void slot6(int); virtual void slot7(int); virtual void slot8(int);
    virtual void slot9(int); virtual void slot10(int); virtual void slot11(int);
    virtual void slot12(int); virtual void slot13(int); virtual void slot14(int);
    virtual void slot15(int); virtual void slot16(int); virtual void slot17(int);
    virtual void slot18(int); virtual void slot19(int); virtual void slot20(int);
    virtual void slot21(int); virtual void slot22(int);
};

struct GobjV07 {
    void* vtable;
    char pad04[0x60];
    VSlotsInt23* attached;
};

extern "C" {
extern char g_TargetVisMgr[];
void func_003CE7D0(GobjV07* self);
void TargetVis_Unregister(void* list, GobjV07* self);
}

#define DEFINE_GOBJ_V07_REGISTER(name)                                        \
    extern "C" void name(GobjV07* self)                                       \
    {                                                                         \
        VSlotsInt23* a = self->attached;                                      \
        if (a)                                                                \
            a->slot22(1);                                                     \
        func_003CE7D0(self);                                                  \
        TargetVis_Unregister(g_TargetVisMgr, self);                                      \
    }

#endif /* GOBJ_V07_REGISTER_H */