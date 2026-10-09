/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_0055C7B8;
extern int func_003E5060(void);
extern int func_003E5120(void);
extern int func_003E51E0(void);
extern int func_003E52A0(void);
extern int func_003E5360(void);
extern int func_003E53F0(void);
extern int func_003E5470(void);
extern int func_003E5530(void);
extern int func_003E55B0(void);
extern int func_003FF210(void);
extern int func_003FF4F0(void);
extern int func_003FF7D0(void);
extern int func_00408100(void);
extern int func_00428DE0(void);
extern int func_004290F0(void);
extern int func_0042B1A0(int);
extern int func_0042CBB0(void);
extern int func_00431890(void);
extern int func_00431B10(void);
extern int func_00431E00(void);
extern int func_00432040(void);
extern int func_004335F0(void);
extern int func_004378A0(void);
extern int func_00438AE0(void);
extern int func_00440070(void);
extern int func_004402E0(void);

/*
 * Runs the per-class registration functions of the message/event types (each
 * callee registers one class), then stores func_0042B1A0(0) in D_0055C7B8.
 */
void NetMsgTypes_RegisterAll(void) {
    func_003FF210();
    func_003E5530();
    func_003E55B0();
    func_003E5470();
    func_003E53F0();
    func_003E5360();
    func_003E52A0();
    func_003E51E0();
    func_003E5120();
    func_003E5060();
    func_0042CBB0();
    func_00431890();
    func_00431B10();
    func_00432040();
    func_00431E00();
    func_00408100();
    func_004290F0();
    func_00428DE0();
    func_003FF4F0();
    func_003FF7D0();
    func_00440070();
    func_004378A0();
    func_004335F0();
    func_00438AE0();
    func_004402E0();
    D_0055C7B8 = func_0042B1A0(0);
}
