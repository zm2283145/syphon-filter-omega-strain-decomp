#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void);
/* Connect callback (SFOLobby_ConnectDir/SFOLobby_ConnectAuth/SFOLobby_ConnectLobby): flags gotConnect
 * and stores the connection handle when it is valid. */
void func_00447220(int handle) {
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotConnect = 1;
        if (handle > 0) {
            D_00585E60->connHandle = handle;
        }
    }
}
