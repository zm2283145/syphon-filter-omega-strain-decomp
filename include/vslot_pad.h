#ifndef R5_VPAD_H
#define R5_VPAD_H
/* virtual slot padding: VPAD1(x) .. VPAD32(x) declare that many dummy slots */
#define VPAD1(x) virtual void x##_0();
#define VPAD2(x) VPAD1(x) virtual void x##_1();
#define VPAD4(x) VPAD2(x) virtual void x##_2(); virtual void x##_3();
#define VPAD8(x) VPAD4(x) virtual void x##_4(); virtual void x##_5(); virtual void x##_6(); virtual void x##_7();
#define VPAD16(x) VPAD8(x##a) VPAD8(x##b)
#define VPAD32(x) VPAD16(x##a) VPAD16(x##b)
#endif