#ifndef ACTIVE_FLAG_RELEASE_H
#define ACTIVE_FLAG_RELEASE_H

/*
 * When the object's active flag (+0x80) is set: run the common stop
 * routine func_0033F0C0(self), hand the current manager object (if any)
 * to releaseFn, then clear the flag.
 */
typedef struct ActiveFlagObj {
    char pad[0x80];
    unsigned char active;
} ActiveFlagObj;

extern void func_0033F0C0(ActiveFlagObj* self);
extern void* func_004294C0(void);

#define DEFINE_ACTIVE_FLAG_RELEASE(name, releaseFn)                           \
    extern void releaseFn(void* p);                                           \
    void name(ActiveFlagObj* self)                                            \
    {                                                                         \
        if (self->active) {                                                   \
            void* p;                                                          \
            func_0033F0C0(self);                                              \
            p = func_004294C0();                                              \
            if (p)                                                            \
                releaseFn(p);                                                 \
            self->active = 0;                                                 \
        }                                                                     \
    }

#endif /* ACTIVE_FLAG_RELEASE_H */