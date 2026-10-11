#ifndef VSLOT_CLASSES_H
#define VSLOT_CLASSES_H

/*
 * Placeholder polymorphic classes for calling C++ virtual methods by slot
 * (slot N lives at vtable offset 8 + 4*N): VSlots67 has slots 0..66 taking
 * no arguments, VSlotsInt22 has slots 0..21 taking one int. Only
 * declarations: nothing (no vtable) is emitted.
 * C++ only (#pragma cplusplus on before including).
 */
class VSlots67 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
};

class VSlotsInt22 {
public:
    virtual void slot0(int);
    virtual void slot1(int);
    virtual void slot2(int);
    virtual void slot3(int);
    virtual void slot4(int);
    virtual void slot5(int);
    virtual void slot6(int);
    virtual void slot7(int);
    virtual void slot8(int);
    virtual void slot9(int);
    virtual void slot10(int);
    virtual void slot11(int);
    virtual void slot12(int);
    virtual void slot13(int);
    virtual void slot14(int);
    virtual void slot15(int);
    virtual void slot16(int);
    virtual void slot17(int);
    virtual void slot18(int);
    virtual void slot19(int);
    virtual void slot20(int);
    virtual void slot21(int);
};

#endif /* VSLOT_CLASSES_H */