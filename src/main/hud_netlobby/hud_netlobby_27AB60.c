#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int std_list_deleter_voidPtr_begin_void();                       
int std_list_GameInfoPtr_generic_iterator_ctor();                      
int cLListIterator_GameInfoPtr_ctor();                        
int std_list_GameInfoPtr_end();                       
int cHudNetLobby_DeactivateControls();                                  
int cHudNetLobby_SetActive();                            
int cInterfaceElement_Activate();                            

void cHudNetLobby_InitCurrentScreen(char * arg0) {
    int sp3C;
    char * sp38;
    int sp34;
    int sp30;
    int temp_v0;
    char * var_s0;

    cHudNetLobby_DeactivateControls();
    temp_v0 = F_(arg0, 0x3C, int);
    if (temp_v0 == 0) {
        F_(arg0, 0x38, int) = 0;
        cInterfaceElement_Activate(F_(arg0, 0x4, int), 1);
        cInterfaceElement_Activate(F_(arg0, 0x8, int), 1);
        cInterfaceElement_Activate(F_(arg0, 0xC, int), 1);
        cInterfaceElement_Activate(F_(arg0, 0x10, int), 1);
    } else if (temp_v0 == 1) {
        F_(arg0, 0x38, int) = 0;
        cInterfaceElement_Activate(F_(arg0, 0x28, int), 1);
        std_list_deleter_voidPtr_begin_void(&sp34, arg0 + 0x2C);
        std_list_GameInfoPtr_generic_iterator_ctor(&sp38, &sp34);
        var_s0 = sp38;
        std_list_GameInfoPtr_end(&sp30, arg0 + 0x2C);
        cLListIterator_GameInfoPtr_ctor(&sp3C, &sp30);
        if ((int)var_s0 != (int)sp3C) {
            do {
                cInterfaceElement_Activate(F_(F_(var_s0, 0x8, int), 0x14, int), 1);
                var_s0 = (char *)(F_(var_s0, 0x4, int));
                std_list_GameInfoPtr_end(&sp30, arg0 + 0x2C);
                cLListIterator_GameInfoPtr_ctor(&sp3C, &sp30);
            } while ((int)var_s0 != (int)sp3C);
        }
    }
    cHudNetLobby_SetActive(arg0);
}
