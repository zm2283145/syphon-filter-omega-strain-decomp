#ifndef PLAYER_CTL_LEVEL_H
#define PLAYER_CTL_LEVEL_H

/*
 * Player virtual (slot 18 clones): when the global feature flag is set,
 * return the 7-bit level in bits 24-30 of the player data flags minus one
 * if the data's controller exists and reports active (its virtual slot 19),
 * else -1; return 0 when the flag is clear.
 * C++ only (#pragma cplusplus on before including).
 */
class PlyCtlLevelIf {
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
    virtual bool isActive();
};

struct PlyCtlLevelData {
    char pad[0xC];
    unsigned int flags;
    char pad10[0x48];
    PlyCtlLevelIf* ctl;
};

struct PlyCtlLevelObj {
    char pad[0x30];
    PlyCtlLevelData* data;
};

extern "C" unsigned char g_IsMultiplayer;

static inline bool PlyCtlLevel_Has(PlyCtlLevelData* d)
{
    return d->ctl && d->ctl->isActive();
}

#define DEFINE_PLAYER_CTL_LEVEL(name)                                         \
    extern "C" int name(PlyCtlLevelObj* self)                                 \
    {                                                                         \
        PlyCtlLevelData* d = self->data;                                      \
        int r;                                                                \
        if (g_IsMultiplayer) {                                                     \
            if (PlyCtlLevel_Has(d))                                           \
                r = ((d->flags & 0x7F000000) >> 24) - 1;                      \
            else                                                              \
                r = -1;                                                       \
        } else                                                                \
            r = 0;                                                            \
        return r;                                                             \
    }

#endif /* PLAYER_CTL_LEVEL_H */