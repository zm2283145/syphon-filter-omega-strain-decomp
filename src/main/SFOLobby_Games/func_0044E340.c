#include "SFOLobby.h"
#define NULL 0
#pragma mpwc_relax on
int Net_ParseIPv4(char * );
int func_00444040(int);
int func_00444050(int);
int func_00444060();
int func_00444070(int);
int func_0044C940(SFOLobby * , int);
int func_004505E0(SFOLobby * , char *);
int func_00452F30(SFOLobby * , int, char *);
extern char D_00585E90;          /* own LobbyPlayerInfo (0xFC bytes); the fields below live inside it */
extern int D_00585F78;           /* .wE8 */
extern int D_00585F7C;           /* .wEC */
extern int D_00585F80;           /* .wF0 */
extern int D_00585F84;           /* .ip */
extern signed char D_00585F88;   /* .bF8 */
extern signed char D_00585F89;   /* .bF9 */

#pragma opt_common_subs off
/* Leaves state 10 for IDLE (9) and republishes our own player info with our
 * IP address (func_004505E0). */
void func_0044E340(SFOLobby * arg0) {
    if (arg0->state == SFOLOBBY_STATE_10) {
        arg0->state = SFOLOBBY_STATE_IDLE;
    }
    func_00452F30(arg0, 3, &D_00585E90);
    D_00585F78 = arg0->unk2484;
    D_00585F84 = Net_ParseIPv4(arg0->myIp);
    D_00585F88 = 5;
    D_00585F7C = 0;
    D_00585F89 = 0;
    D_00585F80 = 0;
    func_004505E0(arg0, &D_00585E90);
    func_0044C940(arg0, 2);
    func_0044C940(arg0, 1);
    if ((func_00444060() != 0) && (func_00444070(1) == 0)) {
        func_00444050(0);
        func_00444040(0);
    }
}
