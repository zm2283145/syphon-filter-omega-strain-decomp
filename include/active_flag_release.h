#ifndef ACTIVE_FLAG_RELEASE_H
#define ACTIVE_FLAG_RELEASE_H

/*
 * When the object's active flag (+0x80) is set: run the common stop
 * routine GuiMissionLobbyScreen_ExitLobbyScreen(self), hand the current manager object (if any)
 * to releaseFn, then clear the flag.
 */
typedef struct ActiveFlagObj {
    char pad[0x80];
    unsigned char active;
} ActiveFlagObj;

extern void GuiMissionLobbyScreen_ExitLobbyScreen(ActiveFlagObj* self);
extern void* DME_GetLobby(void);

#define DEFINE_ACTIVE_FLAG_RELEASE(name, releaseFn)                           \
    extern void releaseFn(void* p);                                           \
    void name(ActiveFlagObj* self)                                            \
    {                                                                         \
        if (self->active) {                                                   \
            void* p;                                                          \
            GuiMissionLobbyScreen_ExitLobbyScreen(self);                                              \
            p = DME_GetLobby();                                               \
            if (p)                                                            \
                releaseFn(p);                                                 \
            self->active = 0;                                                 \
        }                                                                     \
    }

#endif /* ACTIVE_FLAG_RELEASE_H */