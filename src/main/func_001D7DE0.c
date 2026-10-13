typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
extern unsigned char D_004F47B8;
extern V4 D_004F2D90[];
extern char D_004F3030[], D_0048A3A0[], D_0048A400[], D_0048A460[], D_0048A4C0[], D_0048A520[], D_0048A580[], D_004F3180[], D_0048A5E0[], D_004F31E0[], D_0048A640[];
extern char D_0048A6A0[], D_0048A6C0[];
extern char D_0048A6E0[], D_0048A700[], D_0048A720[], D_0048A740[], D_0048A760[], D_0048A780[], D_0048A7A0[], D_0048A7C0[], D_0048A7E0[], D_0048A800[];
extern char D_0048A820[], D_0048A840[], D_0048A860[], D_0048A880[], D_0048A8A0[], D_0048A8C0[], D_0048A8E0[], D_0048A900[], D_0048A920[], D_0048A940[];
extern unsigned int D_0049F730[];
void func_001DE3B0(unsigned int, void*, unsigned int*);
void func_001DE5C0(unsigned int, void*, unsigned int*);
void func_001DE870(unsigned int, void*, unsigned int*);
void func_001DEAD0(unsigned int, void*, unsigned int*);
void func_001DED30(unsigned int, void*, unsigned int*);
void func_001DEF90(unsigned int, void*, unsigned int*);
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void func_001D7DE0(void) {
    int i;
    if (D_004F47B8) return;
    D_004F47B8 = 1;
    func_001DE3B0(21, D_004F2D90, D_0049F730);
    func_001DE5C0(21, D_004F3030, D_0049F730);
    func_001DE870(21, D_0048A3A0, D_0049F730);
    func_001DE870(21, D_0048A400, D_0049F730);
    func_001DE870(21, D_0048A460, D_0049F730);
    func_001DE870(21, D_0048A4C0, D_0049F730);
    func_001DE870(21, D_0048A520, D_0049F730);
    func_001DE870(21, D_0048A580, D_0049F730);
    func_001DE870(21, D_004F3180, D_0049F730);
    func_001DE870(21, D_0048A5E0, D_0049F730);
    func_001DE870(21, D_004F31E0, D_0049F730);
    func_001DE870(21, D_0048A640, D_0049F730);
    func_001DEAD0(21, D_0048A6A0, D_0049F730);
    func_001DEAD0(21, D_0048A6C0, D_0049F730);
    func_001DED30(21, D_0048A6E0, D_0049F730);
    func_001DED30(21, D_0048A700, D_0049F730);
    func_001DED30(21, D_0048A720, D_0049F730);
    func_001DED30(21, D_0048A740, D_0049F730);
    func_001DED30(21, D_0048A760, D_0049F730);
    func_001DED30(21, D_0048A780, D_0049F730);
    func_001DED30(21, D_0048A7A0, D_0049F730);
    func_001DED30(21, D_0048A7C0, D_0049F730);
    func_001DED30(21, D_0048A7E0, D_0049F730);
    func_001DED30(21, D_0048A800, D_0049F730);
    func_001DEF90(21, D_0048A820, D_0049F730);
    func_001DEF90(21, D_0048A840, D_0049F730);
    func_001DEF90(21, D_0048A860, D_0049F730);
    func_001DEF90(21, D_0048A880, D_0049F730);
    func_001DEF90(21, D_0048A8A0, D_0049F730);
    func_001DEF90(21, D_0048A8C0, D_0049F730);
    func_001DEF90(21, D_0048A8E0, D_0049F730);
    func_001DEF90(21, D_0048A900, D_0049F730);
    func_001DEF90(21, D_0048A920, D_0049F730);
    func_001DEF90(21, D_0048A940, D_0049F730);
    for (i = 0; i < 21; i++) {
        if (D_004F2D90[i].w < 0.0f) {
            V4* p = &D_004F2D90[i];
            asm {
                lqc2 vf1, 0x0(p)
                vmulax.xyzw ACC, vf0, vf0x
                vmsubw.xyzw vf1, vf1, vf0w
                sqc2 vf1, 0x0(p)
            }
        }
    }
}
#pragma pop