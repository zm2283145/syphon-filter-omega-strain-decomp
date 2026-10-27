/*
 * SFOGame/Source/humanAnimData: 9 files, 00207260-00209510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00207260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* details_compressed_pair_imp_rep_s_2_first_void(void*);

char* std_basic_string_char_char_traits_char_long_size(void* self) {
    return details_compressed_pair_imp_rep_s_2_first_void(self) + 4;
}
static inline void merge_flush_func_00207260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207260 */

/* merge_units: begin func_00207280 */
#pragma push /* merge_units */
typedef union SsoHeader {
    unsigned char raw;
    struct { unsigned char isLong : 1; unsigned char len : 7; } bits;
} SsoHeader;

#if 0 /* merge_units */
extern SsoHeader* details_compressed_pair_imp_rep_s_2_first_void(void* self);
#endif /* merge_units */
#define details_compressed_pair_imp_rep_s_2_first_void(a0) ((SsoHeader *)details_compressed_pair_imp_rep_s_2_first_void((a0))) /* merge_units */



/* Returns the short-string length stored in the SSO header byte. */
unsigned char std_basic_string_char_char_traits_char_short_size(void* self)
{
    return details_compressed_pair_imp_rep_s_2_first_void(self)->bits.len;
}
#undef details_compressed_pair_imp_rep_s_2_first_void /* merge_units */
static inline void merge_flush_func_00207280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207280 */

/* merge_units: begin func_002072B0 */
#pragma push /* merge_units */
typedef struct { int words[4]; } Value16;
#if 0 /* merge_units */
extern void cString_ctor_cStringR(Value16* dst, void* src);
#endif /* merge_units */
int cString_ctor_cStringR(); /* merge_units */

#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_append_basicstringR(Value16* v, void* arg);
#endif /* merge_units */
void std_basic_string_char_char_traits_char_append_basicstringR(); /* merge_units */

extern void String_Dtor_138350(Value16* v, int flags);

/* Builds a temporary from src, applies arg to it, copies it into dst, then destroys it; returns 0. */
int opAdd_cStringR_cStringR(void* dst, void* src, void* arg)
{
    Value16 tmp;
    cString_ctor_cStringR(&tmp, src);
    std_basic_string_char_char_traits_char_append_basicstringR(&tmp, arg);
    cString_ctor_cStringR(dst, &tmp);
    String_Dtor_138350(&tmp, -1);
    return 0;
}
static inline void merge_flush_func_002072B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002072B0 */

/* merge_units: begin func_00207310 */
#pragma push /* merge_units */
extern int std_basic_string_char_char_traits_char_ctor_basicstringR(int, int);

int cString_ctor_cStringR(int a0, int a1) {
    std_basic_string_char_char_traits_char_ctor_basicstringR(a0, a1);
    return a0;
}
static inline void merge_flush_func_00207310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207310 */

/* merge_units: begin func_00207340 */
#pragma push /* merge_units */
typedef struct { char d[0x4]; } B4;
typedef struct { char d[0x8]; } B8;
typedef struct { char d[0xC]; } BC;
typedef struct { char d[0x10]; } B10;
typedef struct { char d[0x30]; } B30;
typedef struct { char d[0x40]; } B40;
typedef struct { char d[0x50]; } B50;
typedef struct { B8 m17E0; B10 m17E8; B10 m17F8; B8 m1808; } S17E0;
typedef struct { B8 m1780; B10 m1788; B10 m1798; B8 m17A8; } S1780;
typedef struct { B8 m1720; B10 m1728; B8 m1738; } S1720;
typedef struct { B8 m16C0; B10 m16C8; B8 m16D8; } S16C0;
typedef struct { B8 m1660; B10 m1668; B8 m1678; } S1660;
typedef struct { B8 m1600; B10 m1608; B8 m1618; } S1600;
typedef struct { B8 m1590; B10 m1598; B10 m15A8; B8 m15B8; } S1590;
typedef struct { B8 m1520; B10 m1528; B10 m1538; B8 m1548; } S1520;
typedef struct { B8 m14B0; B10 m14B8; B10 m14C8; B8 m14D8; } S14B0;
typedef struct { B8 m1440; B10 m1448; B10 m1458; B8 m1468; } S1440;
typedef struct { B8 m13D0; B10 m13D8; B10 m13E8; B8 m13F8; } S13D0;
typedef struct { B8 m1360; B10 m1368; B10 m1378; B8 m1388; } S1360;
typedef struct { B8 m12F0; B10 m12F8; B10 m1308; B8 m1318; } S12F0;
typedef struct { B8 m1280; B10 m1288; B10 m1298; B8 m12A8; } S1280;
typedef struct { B8 m1220; B10 m1228; B10 m1238; B8 m1248; } S1220;
#if 0 /* merge_units */
extern void cString_ctor_cStringR(void*, void*);
#endif /* merge_units */
#define cString_ctor_cStringR(a0, a1) ((void)cString_ctor_cStringR((int)(a0), (int)(a1))) /* merge_units */


extern void opAdd_cStringR_charP(void*, void*, void*);
extern void* cEulerAngle_T_1_2_ctor_float_float_float(void*, float, float, float);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(void*, void*, void*, int, int, void*, void*, int, float, float, int);
#if 0 /* merge_units */
extern void* cString16N_3_ctor_cStringR(void*, void*);
#endif /* merge_units */
char * cString16N_3_ctor_cStringR(); /* merge_units */

extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(void*, void*, void*, void*);
extern void cSkaAnim_dtor(void*, int);
#if 0 /* merge_units */
extern void String_Dtor_138350(void*, int);
#endif /* merge_units */
#define String_Dtor_138350(a0, a1) (String_Dtor_138350((Value16 *)(a0), (a1))) /* merge_units */

extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier(void*, void*, void*, int);
extern void cString16N_3_ctor_void(void*);
#if 0 /* merge_units */
extern void cString16N_3_opAssign(void*, void*);
#endif /* merge_units */
int cString16N_3_opAssign(); /* merge_units */

extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(void*, void*, void*, int, void*, int);
extern float Deg2Rad(float);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void*);
extern void cSkaBlendSequenceExtents_ctor_float_float(void*, float, float);
extern void cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(void*, void*, void*, void*);
extern void* cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(void*, void*);
extern void cQuaternion_GetIdentity(void*);
extern void cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(void*, int, void*, int, int, void*);
extern void cSkaSlider_dtor(void*, int);
extern void cSkaBlendSequenceItem_dtor(void*, int);
extern void cSkaBlendSequenceExtents_dtor(void*, int);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(void*, int);
/* Builds and registers one block of motion-graph nodes. */
#pragma optimization_level 1
int BuildAnimationNode_ForRotatingANonTranslatingAnimation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, float fp0, float fp1, void* p7)
{
    B4 v198C;
    B4 v1988;
    B4 v1984;
    B4 v1980;
    B4 v197C;
    B4 v1978;
    B4 v1974;
    B4 v1970;
    B4 v196C;
    B4 v1968;
    B4 v1964;
    B4 v1960;
    B4 v195C;
    B4 v1958;
    B4 v1954;
    B4 v1950;
    B4 v194C;
    B4 v1948;
    B4 v1944;
    B4 v1940;
    B4 v193C;
    BC v1930;
    B10 v1920;
    B10 v1910;
    B10 v1900;
    B10 v18F0;
    B10 v18E0;
    B10 v18D0;
    B10 v18C0;
    B10 v18B0;
    B10 v18A0;
    B10 v1890;
    B10 v1880;
    B10 v1870;
    B10 v1860;
    B10 v1850;
    B10 v1840;
    B10 v1830;
    B10 v1820;
    B10 v1810;
    S17E0 s17E0;
    B10 v17D0;
    B10 v17C0;
    B10 v17B0;
    S1780 s1780;
    B10 v1770;
    B10 v1760;
    B10 v1750;
    B10 v1740;
    S1720 s1720;
    B10 v1710;
    B10 v1700;
    B10 v16F0;
    B10 v16E0;
    S16C0 s16C0;
    B10 v16B0;
    B10 v16A0;
    B10 v1690;
    B10 v1680;
    S1660 s1660;
    B10 v1650;
    B10 v1640;
    B10 v1630;
    B10 v1620;
    S1600 s1600;
    B10 v15F0;
    B10 v15E0;
    B10 v15D0;
    B10 v15C0;
    S1590 s1590;
    B10 v1580;
    B10 v1570;
    B10 v1560;
    B10 v1550;
    S1520 s1520;
    B10 v1510;
    B10 v1500;
    B10 v14F0;
    B10 v14E0;
    S14B0 s14B0;
    B10 v14A0;
    B10 v1490;
    B10 v1480;
    B10 v1470;
    S1440 s1440;
    B10 v1430;
    B10 v1420;
    B10 v1410;
    B10 v1400;
    S13D0 s13D0;
    B10 v13C0;
    B10 v13B0;
    B10 v13A0;
    B10 v1390;
    S1360 s1360;
    B10 v1350;
    B10 v1340;
    B10 v1330;
    B10 v1320;
    S12F0 s12F0;
    B10 v12E0;
    B10 v12D0;
    B10 v12C0;
    B10 v12B0;
    S1280 s1280;
    B10 v1270;
    B10 v1260;
    B10 v1250;
    S1220 s1220;
    B10 v1210;
    B30 v11E0;
    B30 v11B0;
    B30 v1180;
    B10 v1170;
    B50 v1120;
    B30 v10F0;
    B30 v10C0;
    B50 v1070;
    B30 v1040;
    B30 v1010;
    B30 vFE0;
    B30 vFB0;
    B30 vF80;
    B30 vF50;
    B30 vF20;
    B10 vF10;
    B50 vEC0;
    B30 vE90;
    B10 vE80;
    B50 vE30;
    B30 vE00;
    B30 vDD0;
    B10 vDC0;
    B50 vD70;
    B30 vD40;
    B30 vD10;
    B10 vD00;
    B50 vCB0;
    B30 vC80;
    B30 vC50;
    B10 vC40;
    B40 vC00;
    B30 vBD0;
    B30 vBA0;
    B10 vB90;
    B40 vB50;
    B30 vB20;
    B30 vAF0;
    B10 vAE0;
    B40 vAA0;
    B30 vA70;
    B30 vA40;
    B10 vA30;
    B40 v9F0;
    B30 v9C0;
    B30 v990;
    B10 v980;
    B40 v940;
    B30 v910;
    B30 v8E0;
    B10 v8D0;
    B40 v890;
    B30 v860;
    B30 v830;
    B30 v800;
    B10 v7F0;
    B40 v7B0;
    B30 v780;
    B30 v750;
    B30 v720;
    B10 v710;
    B40 v6D0;
    B30 v6A0;
    B30 v670;
    B30 v640;
    B10 v630;
    B40 v5F0;
    B30 v5C0;
    B30 v590;
    B30 v560;
    B10 v550;
    B40 v510;
    B30 v4E0;
    B30 v4B0;
    B30 v480;
    B10 v470;
    B40 v430;
    B30 v400;
    B30 v3D0;
    B30 v3A0;
    B10 v390;
    B40 v350;
    B30 v320;
    B30 v2F0;
    B30 v2C0;
    B10 v2B0;
    B40 v270;
    B30 v240;
    B30 v210;
    B30 v1E0;
    B10 v1D0;
    B40 v190;
    B30 v160;
    B30 v130;
    B30 v100;
    B10 vF0;
    B40 vB0;
    void* t1;
    void* t2;
    void* t3;
    void* t4;
    void* t5;
    void* t6;
    void* t7;
    void* t8;
    void* t9;
    void* t10;
    void* t11;
    void* t12;
    void* t13;
    void* t14;
    void* t15;
    void* t16;
    void* t17;
    void* t18;
    void* t19;
    void* t20;
    void* t21;
    void* t22;
    void* t23;
    void* t24;
    void* t25;
    void* t26;
    void* t27;
    void* t28;
    void* t29;
    void* t30;
    cString_ctor_cStringR(&v1930, p2);
    cString_ctor_cStringR(&v1920, p2);
    opAdd_cStringR_charP(&v1910, &v1930, "Base_NotFlipped");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(&v1120, p3, p1, 0, 0, cEulerAngle_T_1_2_ctor_float_float_float(&v1170, 0.0f, 0.0f, 0.0f), p7, 2, 0.0f, 1.0f, 0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v198C, p1, cString16N_3_ctor_cStringR(&v1180, &v1910), &v1120);
    cSkaAnim_dtor(&v1120, -1);
    String_Dtor_138350(&v1910, -1);
    opAdd_cStringR_charP(&v1900, &v1930, "Base_Flipped");
    opAdd_cStringR_charP(&v18F0, &v1930, "Base_NotFlipped");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier(&v1070, cString16N_3_ctor_cStringR(&v10C0, &v18F0), p1, 3);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1988, p1, cString16N_3_ctor_cStringR(&v10F0, &v1900), &v1070);
    cSkaAnim_dtor(&v1070, -1);
    String_Dtor_138350(&v18F0, -1);
    String_Dtor_138350(&v1900, -1);
    cString16N_3_ctor_void(&v11E0);
    cString16N_3_ctor_void(&v11B0);
    if (p4) {
        opAdd_cStringR_charP(&v18E0, &v1930, "Base_NotFlipped");
        cString16N_3_opAssign(&v11E0, cString16N_3_ctor_cStringR(&v1040, &v18E0));
        String_Dtor_138350(&v18E0, -1);
        if (p5) {
            opAdd_cStringR_charP(&v18D0, &v1930, "Base_Flipped");
            cString16N_3_opAssign(&v11B0, cString16N_3_ctor_cStringR(&v1010, &v18D0));
            String_Dtor_138350(&v18D0, -1);
        } else {
            opAdd_cStringR_charP(&v18C0, &v1930, "Base_NotFlipped");
            cString16N_3_opAssign(&v11B0, cString16N_3_ctor_cStringR(&vFE0, &v18C0));
            String_Dtor_138350(&v18C0, -1);
        }
    } else {
        if (p5) {
            opAdd_cStringR_charP(&v18B0, &v1930, "Base_Flipped");
            cString16N_3_opAssign(&v11E0, cString16N_3_ctor_cStringR(&vFB0, &v18B0));
            String_Dtor_138350(&v18B0, -1);
        } else {
            opAdd_cStringR_charP(&v18A0, &v1930, "Base_NotFlipped");
            cString16N_3_opAssign(&v11E0, cString16N_3_ctor_cStringR(&vF80, &v18A0));
            String_Dtor_138350(&v18A0, -1);
        }
        opAdd_cStringR_charP(&v1890, &v1930, "Base_NotFlipped");
        cString16N_3_opAssign(&v11B0, cString16N_3_ctor_cStringR(&vF50, &v1890));
        String_Dtor_138350(&v1890, -1);
    }
    opAdd_cStringR_charP(&v1880, &v1930, "FaceLeft");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&vEC0, &v11E0, p1, 4, cEulerAngle_T_1_2_ctor_float_float_float(&vF10, 0.0f, 0.0f, fp0), 1);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1984, p1, cString16N_3_ctor_cStringR(&vF20, &v1880), &vEC0);
    cSkaAnim_dtor(&vEC0, -1);
    String_Dtor_138350(&v1880, -1);
    opAdd_cStringR_charP(&v1870, &v1930, "FaceRght");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&vE30, &v11B0, p1, 4, cEulerAngle_T_1_2_ctor_float_float_float(&vE80, 0.0f, 0.0f, -fp1), 1);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1980, p1, cString16N_3_ctor_cStringR(&vE90, &v1870), &vE30);
    cSkaAnim_dtor(&vE30, -1);
    String_Dtor_138350(&v1870, -1);
    opAdd_cStringR_charP(&v1860, &v1930, "FaceBack_LeftHemisphere");
    opAdd_cStringR_charP(&v1850, &v1930, "FaceLeft");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&vD70, cString16N_3_ctor_cStringR(&vDD0, &v1850), p1, 4, cEulerAngle_T_1_2_ctor_float_float_float(&vDC0, 0.0f, 0.0f, Deg2Rad(9e+01f)), 2);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v197C, p1, cString16N_3_ctor_cStringR(&vE00, &v1860), &vD70);
    cSkaAnim_dtor(&vD70, -1);
    String_Dtor_138350(&v1850, -1);
    String_Dtor_138350(&v1860, -1);
    opAdd_cStringR_charP(&v1840, &v1930, "FaceBack_RghtHemisphere");
    opAdd_cStringR_charP(&v1830, &v1930, "FaceRght");
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&vCB0, cString16N_3_ctor_cStringR(&vD10, &v1830), p1, 4, cEulerAngle_T_1_2_ctor_float_float_float(&vD00, 0.0f, 0.0f, Deg2Rad(-9e+01f)), 2);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1978, p1, cString16N_3_ctor_cStringR(&vD40, &v1840), &vCB0);
    cSkaAnim_dtor(&vCB0, -1);
    String_Dtor_138350(&v1830, -1);
    String_Dtor_138350(&v1840, -1);
    if (p6) {
        opAdd_cStringR_charP(&v1820, &v1920, "MoveBack_LeftHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1810);
        cSkaBlendSequenceExtents_ctor_float_float(&s17E0.m1808, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s17E0.m17F8, &v11B0, p1, &s17E0.m1808);
        opAdd_cStringR_charP(&s17E0.m17E8, &v1930, "FaceBack_LeftHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s17E0.m17E0, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v17D0, cString16N_3_ctor_cStringR(&vC50, &s17E0.m17E8), p1, &s17E0.m17E0);
        t1 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1810, &s17E0.m17F8);
        t2 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t1, &v17D0);
        cQuaternion_GetIdentity(&vC40);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&vC00, 8, t2, 0, 0, &vC40);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1974, p1, cString16N_3_ctor_cStringR(&vC80, &v1820), &vC00);
        cSkaSlider_dtor(&vC00, -1);
        cSkaBlendSequenceItem_dtor(&v17D0, -1);
        cSkaBlendSequenceExtents_dtor(&s17E0.m17E0, -1);
        String_Dtor_138350(&s17E0.m17E8, -1);
        cSkaBlendSequenceItem_dtor(&s17E0.m17F8, -1);
        cSkaBlendSequenceExtents_dtor(&s17E0.m1808, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1810, -1);
        String_Dtor_138350(&v1820, -1);
        opAdd_cStringR_charP(&v17C0, &v1920, "MoveBack_RghtHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v17B0);
        cSkaBlendSequenceExtents_ctor_float_float(&s1780.m17A8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1780.m1798, &v11E0, p1, &s1780.m17A8);
        opAdd_cStringR_charP(&s1780.m1788, &v1930, "FaceBack_RghtHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1780.m1780, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1770, cString16N_3_ctor_cStringR(&vBA0, &s1780.m1788), p1, &s1780.m1780);
        t3 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v17B0, &s1780.m1798);
        t4 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t3, &v1770);
        cQuaternion_GetIdentity(&vB90);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&vB50, 8, t4, 0, 0, &vB90);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1970, p1, cString16N_3_ctor_cStringR(&vBD0, &v17C0), &vB50);
        cSkaSlider_dtor(&vB50, -1);
        cSkaBlendSequenceItem_dtor(&v1770, -1);
        cSkaBlendSequenceExtents_dtor(&s1780.m1780, -1);
        String_Dtor_138350(&s1780.m1788, -1);
        cSkaBlendSequenceItem_dtor(&s1780.m1798, -1);
        cSkaBlendSequenceExtents_dtor(&s1780.m17A8, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v17B0, -1);
        String_Dtor_138350(&v17C0, -1);
        opAdd_cStringR_charP(&v1760, &v1920, "NonStrafing_LeftHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1750);
        opAdd_cStringR_charP(&v1740, &v1920, "MoveBack_LeftHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1720.m1738, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1720.m1728, cString16N_3_ctor_cStringR(&vAF0, &v1740), p1, &s1720.m1738);
        cSkaBlendSequenceExtents_ctor_float_float(&s1720.m1720, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1710, &v11E0, p1, &s1720.m1720);
        t5 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1750, &s1720.m1728);
        t6 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t5, &v1710);
        cQuaternion_GetIdentity(&vAE0);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&vAA0, 5, t6, 0, 0, &vAE0);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v196C, p1, cString16N_3_ctor_cStringR(&vB20, &v1760), &vAA0);
        cSkaSlider_dtor(&vAA0, -1);
        cSkaBlendSequenceItem_dtor(&v1710, -1);
        cSkaBlendSequenceExtents_dtor(&s1720.m1720, -1);
        cSkaBlendSequenceItem_dtor(&s1720.m1728, -1);
        cSkaBlendSequenceExtents_dtor(&s1720.m1738, -1);
        String_Dtor_138350(&v1740, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1750, -1);
        String_Dtor_138350(&v1760, -1);
        opAdd_cStringR_charP(&v1700, &v1920, "NonStrafing_RghtHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v16F0);
        opAdd_cStringR_charP(&v16E0, &v1920, "MoveBack_RghtHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s16C0.m16D8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s16C0.m16C8, cString16N_3_ctor_cStringR(&vA40, &v16E0), p1, &s16C0.m16D8);
        cSkaBlendSequenceExtents_ctor_float_float(&s16C0.m16C0, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v16B0, &v11B0, p1, &s16C0.m16C0);
        t7 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v16F0, &s16C0.m16C8);
        t8 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t7, &v16B0);
        cQuaternion_GetIdentity(&vA30);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v9F0, 5, t8, 0, 0, &vA30);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1968, p1, cString16N_3_ctor_cStringR(&vA70, &v1700), &v9F0);
        cSkaSlider_dtor(&v9F0, -1);
        cSkaBlendSequenceItem_dtor(&v16B0, -1);
        cSkaBlendSequenceExtents_dtor(&s16C0.m16C0, -1);
        cSkaBlendSequenceItem_dtor(&s16C0.m16C8, -1);
        cSkaBlendSequenceExtents_dtor(&s16C0.m16D8, -1);
        String_Dtor_138350(&v16E0, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v16F0, -1);
        String_Dtor_138350(&v1700, -1);
    } else {
        opAdd_cStringR_charP(&v16A0, &v1920, "NonStrafing_LeftHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1690);
        opAdd_cStringR_charP(&v1680, &v1930, "FaceBack_LeftHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1660.m1678, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1660.m1668, cString16N_3_ctor_cStringR(&v990, &v1680), p1, &s1660.m1678);
        cSkaBlendSequenceExtents_ctor_float_float(&s1660.m1660, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1650, &v11E0, p1, &s1660.m1660);
        t9 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1690, &s1660.m1668);
        t10 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t9, &v1650);
        cQuaternion_GetIdentity(&v980);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v940, 5, t10, 0, 0, &v980);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1964, p1, cString16N_3_ctor_cStringR(&v9C0, &v16A0), &v940);
        cSkaSlider_dtor(&v940, -1);
        cSkaBlendSequenceItem_dtor(&v1650, -1);
        cSkaBlendSequenceExtents_dtor(&s1660.m1660, -1);
        cSkaBlendSequenceItem_dtor(&s1660.m1668, -1);
        cSkaBlendSequenceExtents_dtor(&s1660.m1678, -1);
        String_Dtor_138350(&v1680, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1690, -1);
        String_Dtor_138350(&v16A0, -1);
        opAdd_cStringR_charP(&v1640, &v1920, "NonStrafing_RghtHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1630);
        opAdd_cStringR_charP(&v1620, &v1930, "FaceBack_RghtHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1600.m1618, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1600.m1608, cString16N_3_ctor_cStringR(&v8E0, &v1620), p1, &s1600.m1618);
        cSkaBlendSequenceExtents_ctor_float_float(&s1600.m1600, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v15F0, &v11B0, p1, &s1600.m1600);
        t11 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1630, &s1600.m1608);
        t12 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t11, &v15F0);
        cQuaternion_GetIdentity(&v8D0);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v890, 5, t12, 0, 0, &v8D0);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1960, p1, cString16N_3_ctor_cStringR(&v910, &v1640), &v890);
        cSkaSlider_dtor(&v890, -1);
        cSkaBlendSequenceItem_dtor(&v15F0, -1);
        cSkaBlendSequenceExtents_dtor(&s1600.m1600, -1);
        cSkaBlendSequenceItem_dtor(&s1600.m1608, -1);
        cSkaBlendSequenceExtents_dtor(&s1600.m1618, -1);
        String_Dtor_138350(&v1620, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1630, -1);
        String_Dtor_138350(&v1640, -1);
    }
    if (p6) {
        opAdd_cStringR_charP(&v15E0, &v1920, "MoveLeft_BackHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v15D0);
        opAdd_cStringR_charP(&v15C0, &v1930, "FaceRght");
        cSkaBlendSequenceExtents_ctor_float_float(&s1590.m15B8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1590.m15A8, cString16N_3_ctor_cStringR(&v830, &v15C0), p1, &s1590.m15B8);
        opAdd_cStringR_charP(&s1590.m1598, &v1930, "FaceLeft");
        cSkaBlendSequenceExtents_ctor_float_float(&s1590.m1590, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1580, cString16N_3_ctor_cStringR(&v800, &s1590.m1598), p1, &s1590.m1590);
        t13 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v15D0, &s1590.m15A8);
        t14 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t13, &v1580);
        cQuaternion_GetIdentity(&v7F0);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v7B0, 8, t14, 0, 0, &v7F0);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v195C, p1, cString16N_3_ctor_cStringR(&v860, &v15E0), &v7B0);
        cSkaSlider_dtor(&v7B0, -1);
        cSkaBlendSequenceItem_dtor(&v1580, -1);
        cSkaBlendSequenceExtents_dtor(&s1590.m1590, -1);
        String_Dtor_138350(&s1590.m1598, -1);
        cSkaBlendSequenceItem_dtor(&s1590.m15A8, -1);
        cSkaBlendSequenceExtents_dtor(&s1590.m15B8, -1);
        String_Dtor_138350(&v15C0, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v15D0, -1);
        String_Dtor_138350(&v15E0, -1);
        opAdd_cStringR_charP(&v1570, &v1920, "MoveRght_BackHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1560);
        opAdd_cStringR_charP(&v1550, &v1930, "FaceLeft");
        cSkaBlendSequenceExtents_ctor_float_float(&s1520.m1548, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1520.m1538, cString16N_3_ctor_cStringR(&v750, &v1550), p1, &s1520.m1548);
        opAdd_cStringR_charP(&s1520.m1528, &v1930, "FaceRght");
        cSkaBlendSequenceExtents_ctor_float_float(&s1520.m1520, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1510, cString16N_3_ctor_cStringR(&v720, &s1520.m1528), p1, &s1520.m1520);
        t15 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1560, &s1520.m1538);
        t16 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t15, &v1510);
        cQuaternion_GetIdentity(&v710);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v6D0, 8, t16, 0, 0, &v710);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1958, p1, cString16N_3_ctor_cStringR(&v780, &v1570), &v6D0);
        cSkaSlider_dtor(&v6D0, -1);
        cSkaBlendSequenceItem_dtor(&v1510, -1);
        cSkaBlendSequenceExtents_dtor(&s1520.m1520, -1);
        String_Dtor_138350(&s1520.m1528, -1);
        cSkaBlendSequenceItem_dtor(&s1520.m1538, -1);
        cSkaBlendSequenceExtents_dtor(&s1520.m1548, -1);
        String_Dtor_138350(&v1550, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1560, -1);
        String_Dtor_138350(&v1570, -1);
        opAdd_cStringR_charP(&v1500, &v1920, "StrafeLeft");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v14F0);
        opAdd_cStringR_charP(&v14E0, &v1920, "MoveLeft_BackHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s14B0.m14D8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s14B0.m14C8, cString16N_3_ctor_cStringR(&v670, &v14E0), p1, &s14B0.m14D8);
        opAdd_cStringR_charP(&s14B0.m14B8, &v1930, "FaceLeft");
        cSkaBlendSequenceExtents_ctor_float_float(&s14B0.m14B0, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v14A0, cString16N_3_ctor_cStringR(&v640, &s14B0.m14B8), p1, &s14B0.m14B0);
        t17 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v14F0, &s14B0.m14C8);
        t18 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t17, &v14A0);
        cQuaternion_GetIdentity(&v630);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v5F0, 5, t18, 0, 0, &v630);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1954, p1, cString16N_3_ctor_cStringR(&v6A0, &v1500), &v5F0);
        cSkaSlider_dtor(&v5F0, -1);
        cSkaBlendSequenceItem_dtor(&v14A0, -1);
        cSkaBlendSequenceExtents_dtor(&s14B0.m14B0, -1);
        String_Dtor_138350(&s14B0.m14B8, -1);
        cSkaBlendSequenceItem_dtor(&s14B0.m14C8, -1);
        cSkaBlendSequenceExtents_dtor(&s14B0.m14D8, -1);
        String_Dtor_138350(&v14E0, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v14F0, -1);
        String_Dtor_138350(&v1500, -1);
        opAdd_cStringR_charP(&v1490, &v1920, "StrafeRght");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1480);
        opAdd_cStringR_charP(&v1470, &v1920, "MoveRght_BackHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1440.m1468, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1440.m1458, cString16N_3_ctor_cStringR(&v590, &v1470), p1, &s1440.m1468);
        opAdd_cStringR_charP(&s1440.m1448, &v1930, "FaceRght");
        cSkaBlendSequenceExtents_ctor_float_float(&s1440.m1440, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1430, cString16N_3_ctor_cStringR(&v560, &s1440.m1448), p1, &s1440.m1440);
        t19 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1480, &s1440.m1458);
        t20 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t19, &v1430);
        cQuaternion_GetIdentity(&v550);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v510, 5, t20, 0, 0, &v550);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1950, p1, cString16N_3_ctor_cStringR(&v5C0, &v1490), &v510);
        cSkaSlider_dtor(&v510, -1);
        cSkaBlendSequenceItem_dtor(&v1430, -1);
        cSkaBlendSequenceExtents_dtor(&s1440.m1440, -1);
        String_Dtor_138350(&s1440.m1448, -1);
        cSkaBlendSequenceItem_dtor(&s1440.m1458, -1);
        cSkaBlendSequenceExtents_dtor(&s1440.m1468, -1);
        String_Dtor_138350(&v1470, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1480, -1);
        String_Dtor_138350(&v1490, -1);
    }
    if (p6) {
        opAdd_cStringR_charP(&v1420, &v1920, "LeftHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1410);
        opAdd_cStringR_charP(&v1400, &v1920, "NonStrafing_LeftHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s13D0.m13F8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s13D0.m13E8, cString16N_3_ctor_cStringR(&v4B0, &v1400), p1, &s13D0.m13F8);
        opAdd_cStringR_charP(&s13D0.m13D8, &v1920, "StrafeLeft");
        cSkaBlendSequenceExtents_ctor_float_float(&s13D0.m13D0, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v13C0, cString16N_3_ctor_cStringR(&v480, &s13D0.m13D8), p1, &s13D0.m13D0);
        t21 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1410, &s13D0.m13E8);
        t22 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t21, &v13C0);
        cQuaternion_GetIdentity(&v470);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v430, 3, t22, 0, 0, &v470);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v194C, p1, cString16N_3_ctor_cStringR(&v4E0, &v1420), &v430);
        cSkaSlider_dtor(&v430, -1);
        cSkaBlendSequenceItem_dtor(&v13C0, -1);
        cSkaBlendSequenceExtents_dtor(&s13D0.m13D0, -1);
        String_Dtor_138350(&s13D0.m13D8, -1);
        cSkaBlendSequenceItem_dtor(&s13D0.m13E8, -1);
        cSkaBlendSequenceExtents_dtor(&s13D0.m13F8, -1);
        String_Dtor_138350(&v1400, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1410, -1);
        String_Dtor_138350(&v1420, -1);
        opAdd_cStringR_charP(&v13B0, &v1920, "RghtHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v13A0);
        opAdd_cStringR_charP(&v1390, &v1920, "NonStrafing_RghtHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1360.m1388, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1360.m1378, cString16N_3_ctor_cStringR(&v3D0, &v1390), p1, &s1360.m1388);
        opAdd_cStringR_charP(&s1360.m1368, &v1920, "StrafeRght");
        cSkaBlendSequenceExtents_ctor_float_float(&s1360.m1360, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1350, cString16N_3_ctor_cStringR(&v3A0, &s1360.m1368), p1, &s1360.m1360);
        t23 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v13A0, &s1360.m1378);
        t24 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t23, &v1350);
        cQuaternion_GetIdentity(&v390);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v350, 3, t24, 0, 0, &v390);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1948, p1, cString16N_3_ctor_cStringR(&v400, &v13B0), &v350);
        cSkaSlider_dtor(&v350, -1);
        cSkaBlendSequenceItem_dtor(&v1350, -1);
        cSkaBlendSequenceExtents_dtor(&s1360.m1360, -1);
        String_Dtor_138350(&s1360.m1368, -1);
        cSkaBlendSequenceItem_dtor(&s1360.m1378, -1);
        cSkaBlendSequenceExtents_dtor(&s1360.m1388, -1);
        String_Dtor_138350(&v1390, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v13A0, -1);
        String_Dtor_138350(&v13B0, -1);
    } else {
        opAdd_cStringR_charP(&v1340, &v1920, "LeftHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1330);
        opAdd_cStringR_charP(&v1320, &v1920, "NonStrafing_LeftHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s12F0.m1318, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s12F0.m1308, cString16N_3_ctor_cStringR(&v2F0, &v1320), p1, &s12F0.m1318);
        opAdd_cStringR_charP(&s12F0.m12F8, &v1930, "FaceLeft");
        cSkaBlendSequenceExtents_ctor_float_float(&s12F0.m12F0, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v12E0, cString16N_3_ctor_cStringR(&v2C0, &s12F0.m12F8), p1, &s12F0.m12F0);
        t25 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1330, &s12F0.m1308);
        t26 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t25, &v12E0);
        cQuaternion_GetIdentity(&v2B0);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v270, 3, t26, 0, 0, &v2B0);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1944, p1, cString16N_3_ctor_cStringR(&v320, &v1340), &v270);
        cSkaSlider_dtor(&v270, -1);
        cSkaBlendSequenceItem_dtor(&v12E0, -1);
        cSkaBlendSequenceExtents_dtor(&s12F0.m12F0, -1);
        String_Dtor_138350(&s12F0.m12F8, -1);
        cSkaBlendSequenceItem_dtor(&s12F0.m1308, -1);
        cSkaBlendSequenceExtents_dtor(&s12F0.m1318, -1);
        String_Dtor_138350(&v1320, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1330, -1);
        String_Dtor_138350(&v1340, -1);
        opAdd_cStringR_charP(&v12D0, &v1920, "RghtHemisphere");
        cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v12C0);
        opAdd_cStringR_charP(&v12B0, &v1920, "NonStrafing_RghtHemisphere");
        cSkaBlendSequenceExtents_ctor_float_float(&s1280.m12A8, 0.0f, 0.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1280.m1298, cString16N_3_ctor_cStringR(&v210, &v12B0), p1, &s1280.m12A8);
        opAdd_cStringR_charP(&s1280.m1288, &v1930, "FaceRght");
        cSkaBlendSequenceExtents_ctor_float_float(&s1280.m1280, 1.0f, 1.0f);
        cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1270, cString16N_3_ctor_cStringR(&v1E0, &s1280.m1288), p1, &s1280.m1280);
        t27 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v12C0, &s1280.m1298);
        t28 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t27, &v1270);
        cQuaternion_GetIdentity(&v1D0);
        cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v190, 3, t28, 0, 0, &v1D0);
        cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1940, p1, cString16N_3_ctor_cStringR(&v240, &v12D0), &v190);
        cSkaSlider_dtor(&v190, -1);
        cSkaBlendSequenceItem_dtor(&v1270, -1);
        cSkaBlendSequenceExtents_dtor(&s1280.m1280, -1);
        String_Dtor_138350(&s1280.m1288, -1);
        cSkaBlendSequenceItem_dtor(&s1280.m1298, -1);
        cSkaBlendSequenceExtents_dtor(&s1280.m12A8, -1);
        String_Dtor_138350(&v12B0, -1);
        cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v12C0, -1);
        String_Dtor_138350(&v12D0, -1);
    }
    cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v1260);
    opAdd_cStringR_charP(&v1250, &v1920, "LeftHemisphere");
    cSkaBlendSequenceExtents_ctor_float_float(&s1220.m1248, 0.0f, 0.0f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s1220.m1238, cString16N_3_ctor_cStringR(&v130, &v1250), p1, &s1220.m1248);
    opAdd_cStringR_charP(&s1220.m1228, &v1920, "RghtHemisphere");
    cSkaBlendSequenceExtents_ctor_float_float(&s1220.m1220, 1.0f, 1.0f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&v1210, cString16N_3_ctor_cStringR(&v100, &s1220.m1228), p1, &s1220.m1220);
    t29 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v1260, &s1220.m1238);
    t30 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t29, &v1210);
    cQuaternion_GetIdentity(&vF0);
    cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&vB0, 6, t30, 0, 0, &vF0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v193C, p1, cString16N_3_ctor_cStringR(&v160, &v1920), &vB0);
    cSkaSlider_dtor(&vB0, -1);
    cSkaBlendSequenceItem_dtor(&v1210, -1);
    cSkaBlendSequenceExtents_dtor(&s1220.m1220, -1);
    String_Dtor_138350(&s1220.m1228, -1);
    cSkaBlendSequenceItem_dtor(&s1220.m1238, -1);
    cSkaBlendSequenceExtents_dtor(&s1220.m1248, -1);
    String_Dtor_138350(&v1250, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v1260, -1);
    cString16N_3_ctor_cStringR(p0, &v1920);
    String_Dtor_138350(&v1920, -1);
    String_Dtor_138350(&v1930, -1);
    return 0;
}
#pragma optimization_level reset
#undef cString_ctor_cStringR /* merge_units */
#undef String_Dtor_138350 /* merge_units */
static inline void merge_flush_func_00207340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00207340 */

/* merge_units: begin func_00209510 */
#pragma push /* merge_units */
extern void MEMCPY16(int, int, int);
extern int cString16N_3_Empty(int);

int cString16N_3_opAssign(int a0, int a1) {
    int a2, s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    v0 = cString16N_3_Empty(a0);
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00209548;
    v0 = cString16N_3_Empty(a0);
    cond = v0 != 0;
    if (cond) goto L00209558;
L00209548:;
    a1 = s0;
    a0 = s1;
    a2 = 0 + 3;
    MEMCPY16(a0, a1, a2);
L00209558:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00209510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209510 */

/* merge_units: begin func_00209570 */
#pragma push /* merge_units */
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#pragma optimization_level 1
char* cString16N_3_ctor_cStringR(char* dst, void* s)
{
    int i;
    for (i = 0; i < 47; i++) {
        dst[i] = (i < cString_Length(s)) ? cString_opCast_constcharPtr(s)[i] : 0;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
static inline void merge_flush_func_00209570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209570 */

/* merge_units: begin func_00209620 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int std_basic_string_char_char_traits_char_size(void* obj);
extern void std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(void* obj, int value, int zero, int arg);

/* Forwards std_basic_string_char_char_traits_char_size's result to std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR. */
void std_basic_string_char_char_traits_char_append_basicstringR(void* obj, int arg) {
    std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(obj, std_basic_string_char_char_traits_char_size(obj), 0, arg);
}

#pragma pop
static inline void merge_flush_func_00209620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209620 */

/* merge_units: begin func_00209680 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } E9680;
typedef struct { int x0; unsigned int count; } V9680;
extern int std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(E9680* first, E9680* last);
extern unsigned int std_vector_imp_cSkaBlendSequenceItem_max_size(V9680* v);
extern void std_msl_error(const char* msg);
extern char D_004A3E70[];
extern void* std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(V9680* v);
extern E9680* cAllocator_cSkaBlendSequenceItem_allocate(void* alloc, int n, int hint);
extern E9680** std_vector_deleter_cSkaBlendSequenceItem_data_void(V9680* v);
extern int* std_vector_deleter_cSkaBlendSequenceItem_cap_void(V9680* v);
extern E9680* std_vector_imp_cSkaBlendSequenceItem_begin_void_2(V9680* v);
extern void cAllocator_cSkaBlendSequenceItem_construct(void* alloc, E9680* p, E9680* src);
#pragma optimization_level 1
void std_vector_imp_cSkaBlendSequenceItem_init(V9680* v, E9680* first, E9680* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(first, last);
    if (v->count > std_vector_imp_cSkaBlendSequenceItem_max_size(v))
        std_msl_error(D_004A3E70);
    if (n != 0) {
        E9680* p;
        *std_vector_deleter_cSkaBlendSequenceItem_data_void(v) = cAllocator_cSkaBlendSequenceItem_allocate(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), n, 0);
        *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v) = n;
        for (p = std_vector_imp_cSkaBlendSequenceItem_begin_void_2(v); first != last; first++) {
            cAllocator_cSkaBlendSequenceItem_construct(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset
static inline void merge_flush_func_00209680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209680 */
