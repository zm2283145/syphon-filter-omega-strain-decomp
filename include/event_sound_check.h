#ifndef EVENT_SOUND_CHECK_H
#define EVENT_SOUND_CHECK_H

/*
 * Event handlers: when the event is type 1 / sub 0 / id 0x10 / arg 0,
 * look up a sound by two names and play it on self; returns whether the
 * event was handled. C++ only (#pragma cplusplus on before including).
 */
typedef struct EvtSndEvent {
    unsigned short type;
    unsigned short sub;
    short pad4;
    unsigned short arg6;
    unsigned short id;
} EvtSndEvent;

extern "C" {
void* Gui_Manager(void);
void* Gui_Canvas(void);
int GuiManager_OpenGui(void* mgr, char* a, char* b);
void GuiCanvas_Transition(void* mgr, void* self, int snd);
}

#define DEFINE_EVENT_SOUND_CHECK(name, nameA, nameB)                          \
    extern "C" char nameA[];                                                  \
    extern "C" char nameB[];                                                  \
    extern "C" bool name(void* self, EvtSndEvent* e)                          \
    {                                                                         \
        bool b = e->type == 1 && e->sub == 0 && e->id == 0x10 && e->arg6 == 0; \
        if (b) {                                                              \
            int s = GuiManager_OpenGui(Gui_Manager(), nameA, nameB);             \
            GuiCanvas_Transition(Gui_Canvas(), self, s);                          \
            return 1;                                                         \
        }                                                                     \
        return 0;                                                             \
    }

#endif /* EVENT_SOUND_CHECK_H */