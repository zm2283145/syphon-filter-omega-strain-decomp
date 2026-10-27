#ifndef TRIPLE_MEMBER_DTOR_DE8A0_H
#define TRIPLE_MEMBER_DTOR_DE8A0_H

/*
 * Deleting destructor of the class with vtable D_004DE8A0 (one clone per
 * translation unit): member at +0x104 (String_Dtor), three members at
 * +0xE4/+0xC8/+0xAC (SFOLobbyList_dtor), base GuiLobbyScreen_dtor, then delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" {
extern char D_004DE8A0[];
void* String_Dtor(void* self, short flags);
void* SFOLobbyList_dtor(void* self, short flags);
void* GuiLobbyScreen_dtor(void* self, short flags);
void operator_delete(void* allocation);
}

struct TripleMemberObject {
    void* vtable;
};

#define DEFINE_TRIPLE_MEMBER_DTOR_DE8A0(name)                                 \
    extern "C" TripleMemberObject* name(TripleMemberObject* self,             \
                                        short deleteFlag)                     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = D_004DE8A0;                                        \
            char* m = (char*)self + 0x104;                                    \
            if (m)                                                            \
                String_Dtor(m, 0);                                          \
            SFOLobbyList_dtor((char*)self + 0xE4, -1);                            \
            SFOLobbyList_dtor((char*)self + 0xC8, -1);                            \
            SFOLobbyList_dtor((char*)self + 0xAC, -1);                            \
            GuiLobbyScreen_dtor(self, 0);                                           \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* TRIPLE_MEMBER_DTOR_DE8A0_H */