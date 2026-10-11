#ifndef LINKED_TARGET_REFRESH_H
#define LINKED_TARGET_REFRESH_H

/*
 * When the object has a linked target and its state flags say
 * (flag 0x2D && flag 0x2C && !flag 0x2E), copy the value at 0x38 into the
 * target's field 0x38 and call the target's virtual slot 20 (refresh).
 * C++ only (#pragma cplusplus on before including).
 */
class LinkedTarget {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void refresh();
};

struct LinkedTargetOwner {
    char pad[0x2C];
    bool flag2C;
    bool flag2D;
    bool flag2E;
    char pad2F[9];
    int value;
    char pad3C[0x28];
    LinkedTarget* target;
};

#define DEFINE_LINKED_TARGET_REFRESH(name)                                    \
    extern "C" void name(LinkedTargetOwner* self)                             \
    {                                                                         \
        if (self->target) {                                                   \
            bool ok = self->flag2D && self->flag2C && !self->flag2E;          \
            if (ok) {                                                         \
                ((int*)self->target)[0x38 / 4] = self->value;                 \
                self->target->refresh();                                      \
            }                                                                 \
        }                                                                     \
    }

#endif /* LINKED_TARGET_REFRESH_H */