/*
 * lib/medius: 31 files, 00466A28-00467D18
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00466A28 */
int D_00497CC0 = 0;
int D_00497CC4 = -1;
extern int D_00598670;
extern int D_0059842C;
extern int Medius_TerminateString(char *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int func_00466A28(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059842C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598670, 0x4C, a) ? -5 : 0;
}
/* merge_units: end func_00466A28 */

/* merge_units: begin func_00466AD0 */
extern int D_00497CC0;
extern int D_00497CC4;
extern int D_00598678;
extern int D_00598430;
int func_00466AD0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598430 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598678, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00466AD0 */

/* merge_units: begin func_00466B70 */
extern int D_00598688;
extern int D_00598434;
int func_00466B70(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598434 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598688, 0x4C, a) ? -5 : 0;
}
/* merge_units: end func_00466B70 */

/* merge_units: begin func_00466C18 */
extern int D_00598680;
extern int D_00598438;
int func_00466C18(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598438 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598680, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00466C18 */

/* merge_units: begin func_00466CB8 */
extern int D_00598690;
extern int D_0059843C;
int func_00466CB8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059843C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598690, 0x4C, a) ? -5 : 0;
}
/* merge_units: end func_00466CB8 */

/* merge_units: begin func_00466D60 */
extern int D_00598698;
extern int D_00598440;
int func_00466D60(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598440 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598698, 0xF4, a) ? -5 : 0;
}
/* merge_units: end func_00466D60 */

/* merge_units: begin func_00466E08 */
extern int D_005986A0;
extern int D_00598444;
int func_00466E08(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598444 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986A0, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00466E08 */

/* merge_units: begin func_00466EA8 */
extern int D_005986A8;
extern int D_00598448;
int func_00466EA8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598448 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986A8, 0xF4, a) ? -5 : 0;
}
/* merge_units: end func_00466EA8 */

/* merge_units: begin func_00466F50 */
extern int D_005986B0;
extern int D_0059844C;
int func_00466F50(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059844C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986B0, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00466F50 */

/* merge_units: begin func_00466FF0 */
extern int D_005986B8;
extern int D_00598450;
int func_00466FF0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598450 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986B8, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00466FF0 */

/* merge_units: begin func_00467090 */
extern int D_005986C0;
extern int D_00598454;
int func_00467090(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x30, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598454 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986C0, 0xF8, a) ? -5 : 0;
}
/* merge_units: end func_00467090 */

/* merge_units: begin func_00467138 */
extern int D_005986C8;
extern int D_00598458;
int func_00467138(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598458 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986C8, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00467138 */

/* merge_units: begin func_004671D8 */
extern int D_005986D8;
extern int D_0059845C;
int func_004671D8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059845C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986D8, 0x34, a) ? -5 : 0;
}
/* merge_units: end func_004671D8 */

/* merge_units: begin func_00467278 */
extern int D_005986E0;
extern int D_00598460;
int func_00467278(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x26, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598460 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986E0, 0xEE, a) ? -5 : 0;
}
/* merge_units: end func_00467278 */

/* merge_units: begin func_00467320 */
extern int D_005986E8;
extern int D_00598464;
int func_00467320(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598464 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986E8, 0xF4, a) ? -5 : 0;
}
/* merge_units: end func_00467320 */

/* merge_units: begin func_004673C8 */
extern int D_005986F0;
extern int D_00598468;
int func_004673C8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598468 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986F0, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_004673C8 */

/* merge_units: begin func_00467468 */
extern int D_005986D0;
extern int D_0059846C;
int func_00467468(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059846C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986D0, 0xF4, a) ? -5 : 0;
}
/* merge_units: end func_00467468 */

/* merge_units: begin func_00467510 */
extern int D_005986F8;
extern int D_00598470;
int func_00467510(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x30, 0xC8);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598470 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005986F8, 0xF8, a) ? -5 : 0;
}
/* merge_units: end func_00467510 */

/* merge_units: begin func_004675B8 */
extern int D_00598700;
extern int D_00598474;
int func_004675B8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598474 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598700, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_004675B8 */

/* merge_units: begin func_00467658 */
extern int D_00598710;
extern int D_00598478;
int func_00467658(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598478 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598710, 0x3C, a) ? -5 : 0;
}
/* merge_units: end func_00467658 */

/* merge_units: begin func_004676F8 */
extern int D_00598708;
extern int D_0059847C;
int func_004676F8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059847C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598708, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_004676F8 */

/* merge_units: begin func_00467798 */
extern int D_00598718;
extern int D_00598480;
int func_00467798(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598480 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598718, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00467798 */

/* merge_units: begin func_00467838 */
extern int D_00598720;
extern int D_00598484;
int func_00467838(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598484 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598720, 0x30, a) ? -5 : 0;
}
/* merge_units: end func_00467838 */

/* merge_units: begin func_004678D8 */
extern int D_00598728;
extern int D_00598488;
int func_004678D8(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598488 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598728, 0x38, a) ? -5 : 0;
}
/* merge_units: end func_004678D8 */

/* merge_units: begin func_00467978 */
extern int D_00598730;
extern int D_0059848C;
int func_00467978(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    Medius_TerminateString(a + 0x2C, 0x100);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059848C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598730, 0x12C, a) ? -5 : 0;
}
/* merge_units: end func_00467978 */

/* merge_units: begin func_00467A20 */
extern int D_00598758;
extern int D_00598490;
int func_00467A20(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x15, 0x11);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598490 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598758, 0x2C, a) ? -5 : 0;
}
/* merge_units: end func_00467A20 */

/* merge_units: begin func_00467AC0 */
extern int D_005987BC;
extern int D_00598494;
int func_00467AC0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598494 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987BC, 0x28, a) ? -5 : 0;
}
/* merge_units: end func_00467AC0 */

/* merge_units: begin func_00467B50 */
extern int D_005987C4;
extern int D_00598498;
int func_00467B50(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598498 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987C4, 0x24, a) ? -5 : 0;
}
/* merge_units: end func_00467B50 */

/* merge_units: begin func_00467BE0 */
extern int D_005987E4;
extern int D_0059849C;
int func_00467BE0(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_0059849C = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_005987E4, 0x24, a) ? -5 : 0;
}
/* merge_units: end func_00467BE0 */

/* merge_units: begin func_00467C70 */
extern int D_00598808;
int func_00467C70(char *a, int b)
{
    Medius_TerminateString(a, 0x15);
    Medius_TerminateString(a + 0x35, 0xC8);
    Medius_TerminateString(a + 0x15, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00598448 = b;
    return Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598808, 0xFD, a) ? -5 : 0;
}
/* merge_units: end func_00467C70 */

/* merge_units: begin func_00467D18 */
typedef struct { unsigned char b[24]; } B467D18;
extern B467D18 D_00587DC0;
void func_00467D18(B467D18 x) { D_00587DC0 = x; }
/* merge_units: end func_00467D18 */
