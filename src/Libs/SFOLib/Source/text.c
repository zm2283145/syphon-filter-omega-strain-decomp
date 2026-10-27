/*
 * Libs/SFOLib/Source/text: 10 files, 003CF220-003D04C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CF220 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#ifndef TREE_INSERT_V8X_H
#define TREE_INSERT_V8X_H

/*
 * Red-black tree node insert for an 8-byte value (node: left, right,
 * parent|color, value at +0xC; tree: count, root, -, leftmost): count
 * overflow check, allocate the 0x14-byte node under the allocator guard,
 * placement-copy the value, link it under parent, bump the count and
 * rebalance (rebalanceFn). VT is TIValueFI (float, int) or TIValueII.
 * C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

struct TIValueFI { float f; int i; };
struct TIValueII { int a; int b; };

#define DEFINE_TREE_INSERT_V8X(name, VT, errSym, allocFile, allocLine, rebalanceFn) \
    struct name##_Node { name##_Node* left; name##_Node* right; unsigned int parentAndColor; VT value; }; \
    struct name##_Tree { unsigned int count; name##_Node* root; int pad; name##_Node* leftmost; }; \
    extern "C" {                                                              \
    extern char errSym[];                                                     \
    extern char allocFile[];                                                  \
    void rebalanceFn(void* node, void* root);                                 \
    }                                                                         \
    extern "C" name##_Node* name(name##_Tree* tree, name##_Node* parent,      \
                                 int left, int first, const VT* src)          \
    {                                                                         \
        if (tree->count > 0xFFFFFFFFU - 1) {                                  \
            Libc_Fprintf(D_00489738->stream, errSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        name##_Node* node = (name##_Node*)TStr_Alloc(sizeof(name##_Node), allocFile, (allocLine)); \
        VT* v = &node->value;                                                 \
        if (v)                                                                \
            *v = *src;                                                        \
        node->right = 0;                                                      \
        node->left = 0;                                                       \
        node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1); \
        if (left)                                                             \
            parent->left = node;                                              \
        else                                                                  \
            parent->right = node;                                             \
        tree->count++;                                                        \
        rebalanceFn(node, tree->root);                                        \
        if (first)                                                            \
            tree->leftmost = node;                                            \
        return node;                                                          \
    }

#endif /* TREE_INSERT_V8X_H */
struct TIV_003CF220 { int w0; int w1; int w2; };

extern "C" { char D_004BD230[] = "tree::insert length error\n"; }
DEFINE_TREE_INSERT_V8X(FrameTree_Insert, TIV_003CF220, D_004BD230, D_004BD300, 0x5C, std_red_black_tree_1_balance_insert)
static inline void merge_flush_func_003CF220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF220 */

/* merge_units: begin func_003CF3A0 */
#pragma push /* merge_units */
typedef int s32; typedef unsigned int u32; typedef char s8; typedef unsigned char u8; typedef float f32; typedef long long s64;
/* Text layout follows the matched line counter TextObj_GetLineCount. */
typedef struct { int x,y,w,h; unsigned char align,flip,center,pad13; char str[12]; void *font; char pad24[12]; float color[4]; float scroll,last,speed,alphaSpeed,alphaEnd,wrap; unsigned char noWrap,fade,done,ellipsis; } TextLayout;
extern char *std_basic_string_char_char_traits_char_c_str(void*);
extern void Libc_Strcpy(char*,const char*);
extern void Libc_Strncat(char*,const char*,int);
extern int cFont_GetCharH(void*);
extern int cFont_GetStringWidth(void*,const char*,int);
extern int strlen(const char*);
#if 0 /* merge_units */
extern int TextObj_GetLineCount(TextLayout*);
#endif /* merge_units */
int TextObj_GetLineCount(); /* merge_units */

extern char D_004BD310[];
s32 cTextArea_Render(TextLayout *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    char spE0[256];
    f32 *spDC;
    f32 *spD8;
    char* limit[1];
    f32 var_f23;
    f32 var_f22;
    f32 temp_f24;
    f32 temp_f21;
    f32 temp_f20_2;
    f32 temp_f20;
    f32 temp_f1_2;
    f32 temp_f1;
    int temp_f0;
    void* temp_a0;
    s8 *var_s4;
    s32 var_s3;
    s32 var_s2;
    s32 temp_s1_2;
    s32 var_s0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_6;
    s32 var_a0;
    s32 var_a2;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s8 *temp_fp;
    s8 *temp_v0_2;
    s8 *var_s1;
    s8 *var_s6;
    int temp_v1_2;
    s8 temp_v1_3;
    s8 temp_v1_4;
    u8 temp_v1_5;

    spDC = arg1;
    spD8 = arg2;
    temp_a0 = arg0->font;
    if (temp_a0 == 0) {
        return 0;
    }
    var_f23 = (float)arg0->x;
    var_f22 = (float)arg0->y;
    if (arg0->flip != 0) {
        var_f22 -= (f32) (arg0->h - cFont_GetCharH(temp_a0));
    }
    var_v0 = arg0->w;
    var_v0=var_v0>0?var_v0:-var_v0;
    temp_f21 = var_f23 + (f32) var_v0;
    if (arg0->center != 0) {
        temp_s1 = TextObj_GetLineCount(arg0);
        var_f22-=(float)(arg0->h/2-(temp_s1*cFont_GetCharH(arg0->font))/2);
    }
    temp_v0_2 = std_basic_string_char_char_traits_char_c_str(arg0->str);
    var_s4 = temp_v0_2;
    limit[0] = temp_v0_2 + arg3;
    if (arg0->align == 3) {
        return 0;
    }
loop_16:
    spE0[0] = 0;
    temp_fp = var_s4;
    if (arg0->ellipsis != 0) {
        if (TextObj_GetLineCount(arg0) != 1) {
            return 0;
        }
        temp_f1 = (f32) cFont_GetStringWidth(arg0->font, var_s4, strlen(var_s4));
        if ((var_f23 + temp_f1) < temp_f21) {
            var_f23 += temp_f1;
            Libc_Strcpy(spE0, var_s4);
        } else {
            temp_f20 = (f32) cFont_GetStringWidth(arg0->font, D_004BD310, 3);
            temp_f24 = temp_f21 - (var_f23 + temp_f20);
            if (temp_f24 <= 0.0f) {
                var_f23 += temp_f20;
                Libc_Strcpy(spE0, D_004BD310);
            } else {
                var_s2 = 0;
                var_s0 = 0;
                goto check31;
loop_31:
                if(temp_v1_2==10)goto end31;
                spE0[var_s2]=temp_v1_2;
                var_s2++;
                temp_s1_2=var_s0;
                var_s4++;
                var_s0=cFont_GetStringWidth(arg0->font,spE0,var_s2);
                if(!((float)var_s0<=temp_f24)){var_s0=temp_s1_2;var_s2--;}
check31:
                temp_v1_2=*var_s4;
                if(temp_v1_2!=0 && (float)var_s0<=temp_f24)goto loop_31;
end31:
                if (temp_v1_2 != 0xA) {
                    Libc_Strcpy(var_s2 + spE0, D_004BD310);
                } else {
                    spE0[var_s2] = 0;
                }
                var_f23 += temp_f20 + (f32) var_s0;
            }
        }
        var_s4 = 0;
        goto block_75;
    }
    if (arg0->noWrap != 0) {
        var_f23 += (f32) cFont_GetStringWidth(arg0->font, var_s4, strlen(var_s4));
        Libc_Strcpy(spE0, var_s4);
        var_s4 = 0;
    } else {
        temp_f20_2 = var_f23 + ((1.0f - arg0->wrap) * (temp_f21 - var_f23));
loop_44:
        if (*var_s4 != 0) {
            temp_v0_4 = strlen(var_s4 + 1);
            for(var_a2=0;var_a2<temp_v0_4;var_a2++){
                temp_v1_3=var_s4[var_a2+1];
                if(temp_v1_3==32 || temp_v1_3==10)break;
            }
            var_s1 = (char*)(var_a2+(int)var_s4+1);
        } else {
            var_s1 = 0;
        }
        if (var_s1 != 0) {
            var_s3 = var_s1 - var_s4;
        } else {
            var_s3 = strlen(var_s4) + 1;
        }
        var_s0 = cFont_GetStringWidth(arg0->font, var_s4, var_s3);
        if (((var_f23 + (f32) var_s0) < temp_f21) || ((var_f23 == (f32) (s32) arg0->x) && (arg0->wrap == 1.0f))) {
            Libc_Strncat(spE0, var_s4, var_s3);
            var_s4 = var_s1;
            var_f23 += (f32) var_s0;
            goto block_70;
        }
        if ((arg0->wrap != 1.0f) && (var_f23 <= temp_f20_2)) {
            int buflen;
            char* next;
            char* output;
            buflen=strlen(spE0); var_s7=0; next=var_s4;
            var_s0=0;
            if(var_s0<var_s3){output=spE0+buflen;
            do {
                temp_v0_6=cFont_GetStringWidth(arg0->font,var_s4,var_s0+1);
                if(!((var_f23+(float)temp_v0_6)<temp_f21))break;
                var_s7=temp_v0_6;buflen++;next++;
                *output=var_s4[var_s0];var_s0++;output++;
            }while(var_s0<var_s3);
            }
            spE0[buflen]=0;var_s4=next;var_f23+=(float)var_s7;
        } else {
block_70:
            if (((var_s1 == 0) || (*var_s1 != 0xA)) && (var_s4 != 0)) {
                if (!((var_f23 + (f32) var_s0) < temp_f21)) {

                } else {
                    goto loop_44;
                }
            }
        }
    }
block_75:
    temp_a0_2 = (s32) arg0->x;
    temp_v1_5 = arg0->align;
    temp_f1_2 = (f32) temp_a0_2;
    temp_f0 = var_f23 - temp_f1_2;
    if(temp_v1_5==0){
        var_f23 = temp_f1_2;
    }else if(temp_v1_5==1){
        var_f23 = temp_f21 - (f32) temp_f0;
    }else if(temp_v1_5==2){
        var_f23=(float)(temp_a0_2+(arg0->w-temp_f0)/2);
    }
    if (&temp_fp[strlen(spE0)] >= limit[0]) {
        *spD8 = var_f22;
        *spDC = var_f23 + (f32) cFont_GetStringWidth(arg0->font, spE0, limit[0] - temp_fp);
        return 1;
    }
    temp_s0 = (arg0->flip != 0) ? -1 : 1;
    var_f23 = (f32) (s32) arg0->x;
    var_f22 -= (f32) (temp_s0 * cFont_GetCharH(arg0->font));
    if ((var_s4 != 0) && (*var_s4 == 0x20)) {
        do {
            var_s4 += 1;
        } while (*var_s4 == 0x20);
    }
    if (var_s4 == 0) {
        return 0;
    }
    goto loop_16;
}
static inline void merge_flush_func_003CF3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CF3A0 */

/* merge_units: begin func_003CFAB0 */
#pragma push /* merge_units */
extern char *strchr(const char*,int); extern char *strncpy(char*,const char*,unsigned int);
extern int g_TimerAccum; extern long long g_TickCounter64;
extern void cFont_Display_charP_tRGBAR_float_float_etc(void*,const char*,float,float,float,float*,float,float,float);
static inline int DivTicks(long long n,int divisor){
 int bit=0x40000000;int result=0;
 long long d=divisor;int i=0;d<<=30;
 do {long long delta=n-d;if(delta>=0){n=delta;result+=bit;}i++;d>>=1;bit>>=1;}while(i<31);
 return result;
}
static inline float FadeAlpha(float a,float rate,float delta){return a+rate*delta;}
void TextObj_Draw(TextLayout *arg0) {
    float rgba[4];
    char spC0[256];
    int temp_f0_3;
    f32 var_f23;
    f32 var_f1;
    f32 temp_f2;
    f32 temp_f24;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20_3;
    f32 temp_f20_2;
    f32 temp_f20;
    f32 temp_f1_4;
    f32 temp_f1_3;
    f32 temp_f1_2;
    f32 temp_f1;
    f32 temp_f0_2;
    f32 temp_f0;
    void* temp_a0;
    s8 *var_s4;
    s32 var_s3;
    s32 var_s2;
    s32 temp_s1;
    s32 var_s0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_v0;
    s64 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v1_6;
    s32 var_a0;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a3;
    s32 var_fp;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s64 var_v1;
    s64 var_a1;
    s8 *temp_v0_4;
    s8 *var_s1;
    s8 *var_s6;
    int temp_v1;
    int temp_v1_2;
    s8 temp_v1_3;
    s8 temp_v1_4;
    u8 *var_a1_2;
    u8 temp_a0_3;
    u8 temp_v1_5;
    float *temp_a0_4;

    temp_a0 = arg0->font;
    if (temp_a0 != 0) {
        var_f23 = (f32) arg0->x;
        temp_f22 = (f32) arg0->y;
        if (arg0->flip != 0) {
            temp_f22-=(float)(arg0->h-cFont_GetCharH(temp_a0));
        }
        var_v0 = arg0->w;
        var_v0=var_v0>0?var_v0:-var_v0;
        var_fp = -1;
        temp_f21 = var_f23 + (f32) var_v0;
        if (arg0->center != 0) {
            var_fp = TextObj_GetLineCount(arg0);
            temp_f22-=(float)(arg0->h/2-(var_fp*cFont_GetCharH(arg0->font))/2);
        }
        var_s4 = std_basic_string_char_char_traits_char_c_str(arg0->str);
        temp_v0 = *(s32 *)0x10000800 + g_TimerAccum;
        var_f1=(float)(unsigned int)temp_v0;
        var_a2=DivTicks(g_TickCounter64+(int)(var_f1/5.76f),100);
        if (!arg0->last) {
            arg0->last = (f32) var_a2;
        }
        temp_f20=(float)var_a2-arg0->last;
        arg0->last=(float)var_a2;
        if (arg0->fade != 0) {
            arg0->color[3] = FadeAlpha(arg0->color[3],arg0->alphaSpeed,temp_f20);
            temp_f2 = arg0->alphaEnd;
            {u8 a=(temp_f2 - arg0->color[3]) > 0.0f; u8 b=arg0->alphaSpeed > 0.0f;
            if (a != b) {
                arg0->color[3] = temp_f2;
                arg0->fade = 0U;
            }}
        }
        if (arg0->align == 3) {
            temp_v0_3 = cFont_GetStringWidth(arg0->font, var_s4, 0x200);
            temp_f0_2 = arg0->speed;
            if (temp_f20 > arg0->speed) {
                arg0->scroll += temp_f20 / arg0->speed;
                if (arg0->scroll > (f32) temp_v0_3) {
                    arg0->done = 1;
                }
            }
            if (arg0->w < 0) {

            }
            var_f23-=arg0->scroll;
            cFont_Display_charP_tRGBAR_float_float_etc(arg0->font,var_s4,var_f23,temp_f22,0.001f,arg0->color,(float)arg0->x,temp_f21,(float)(arg0->w/4));
            return;
        }
        rgba[0] = arg0->color[0];
        rgba[1] = arg0->color[1];
        rgba[2] = arg0->color[2];
        rgba[3] = arg0->color[3];
        do {
            spC0[0] = 0;
            if (arg0->ellipsis != 0) {
                if (var_fp == -1) {
                    var_fp = TextObj_GetLineCount(arg0);
                }
                strncpy(spC0, var_s4, 0x100);
                temp_v0_4 = strchr(spC0, 0xA);
                if (temp_v0_4 != 0) {
                    *temp_v0_4 = 0;
                }
                temp_f1_3 = (f32) cFont_GetStringWidth(arg0->font, spC0, strlen(spC0));
                if ((var_f23 + temp_f1_3) < temp_f21) {
                    var_f23 += temp_f1_3;
                    var_s4=temp_v0_4?temp_v0_4+1:0;
                } else {
                    temp_f20_2 = (f32) cFont_GetStringWidth(arg0->font, D_004BD310, 3);
                    temp_f24 = temp_f21 - (var_f23 + temp_f20_2);
                    if (temp_f24 <= 0.0f) {
                        var_f23 += temp_f20_2;
                        Libc_Strcpy(spC0, D_004BD310);
                        var_s4=0;goto ellipse_done;
                    }
                    var_s2 = 0;
                    var_s0 = 0;
                    goto check55;
loop_55:
                    if(temp_v1==10)goto end55;
                    spC0[var_s2]=temp_v1;var_s2++;
                    temp_s1=var_s0;var_s4++;
                    var_s0=cFont_GetStringWidth(arg0->font,spC0,var_s2);
                    if(!((float)var_s0<=temp_f24)){var_s0=temp_s1;var_s2--;}
check55:
                    temp_v1=*var_s4;
                    if(temp_v1!=0 && (float)var_s0<=temp_f24)goto loop_55;
end55:
                    Libc_Strcpy(var_s2 + spC0, D_004BD310);
                    var_f23 += temp_f20_2 + (f32) var_s0;
                    if (1<var_fp) {
                        goto skipcheck;
skipbody: var_s4++;
skipcheck:
                        temp_v1_2=*var_s4;
                        if(temp_v1_2!=10 && temp_v1_2!=0)goto skipbody;
                        if (temp_v1_2 == 0xA) {
                            var_s4 += 1;
                        }
                        if (*var_s4 == 0) {
                            var_s4 = 0;
                        }
                    }
                }
ellipse_done:
                if (var_fp == 1) {
                    var_s4 = 0;
                }
            } else if (arg0->noWrap != 0) {
                var_f23 += (f32) cFont_GetStringWidth(arg0->font, var_s4, strlen(var_s4));
                Libc_Strcpy(spC0, var_s4);
                var_s4 = 0;
            } else {
                temp_f20_3 = var_f23 + ((1.0f - arg0->wrap) * (temp_f21 - var_f23));
loop_76:
                if (*var_s4 != 0) {
                    temp_v0_6 = strlen(var_s4 + 1);
                    for(var_a2_2=0;var_a2_2<temp_v0_6;var_a2_2++){
                      temp_v1_3=var_s4[var_a2_2+1];
                      if(temp_v1_3==32 || temp_v1_3==10)break;
                    }
                    var_s1=(char*)(var_a2_2+(int)var_s4+1);
                } else {
                    var_s1 = 0;
                }
                if (var_s1 != 0) {
                    var_s3 = var_s1 - var_s4;
                } else {
                    var_s3 = strlen(var_s4) + 1;
                }
                var_s0 = cFont_GetStringWidth(arg0->font, var_s4, var_s3);
                if (((var_f23 + (f32) var_s0) < temp_f21) || ((var_f23 == (f32) arg0->x) && (arg0->wrap == 1.0f))) {
                    Libc_Strncat(spC0, var_s4, var_s3);
                    var_s4 = var_s1;
                    var_f23 += (f32) var_s0;
                    goto block_102;
                }
                if ((arg0->wrap != 1.0f) && (var_f23 <= temp_f20_3)) {
            int buflen;
            char* next;
            char* output;
            buflen=strlen(spC0); var_s7=0; next=var_s4;
            var_s0=0;
            if(var_s0<var_s3){output=spC0+buflen;
            do {
                temp_v0_8=cFont_GetStringWidth(arg0->font,var_s4,var_s0+1);
                if(!((var_f23+(float)temp_v0_8)<temp_f21))break;
                var_s7=temp_v0_8;buflen++;next++;
                *output=var_s4[var_s0];var_s0++;output++;
            }while(var_s0<var_s3);
            }
            spC0[buflen]=0;var_s4=next;var_f23+=(float)var_s7;
                } else {
block_102:
                    if (((var_s1 == 0) || (*var_s1 != 0xA)) && (var_s4 != 0)) {
                        if (!((var_f23 + (f32) var_s0) < temp_f21)) {

                        } else {
                            goto loop_76;
                        }
                    }
                }
            }
            temp_a0_2 = arg0->x;
            temp_v1_5 = arg0->align;
            temp_f1_4 = (f32) temp_a0_2;
            temp_f0_3 = var_f23 - temp_f1_4;
            if(temp_v1_5==0){
                var_f23 = temp_f1_4;
            }else if(temp_v1_5==1){
                var_f23 = temp_f21 - (f32) temp_f0_3;
            }else if(temp_v1_5==2){
                var_f23=(float)(temp_a0_2+(arg0->w-temp_f0_3)/2);
            }
            cFont_Display_charP_tRGBAR_float_float_etc(arg0->font,spC0,var_f23,temp_f22,0.001f,rgba,0.0f,0.0f,0.0f);
            var_f23 = (f32) arg0->x;
            temp_s0 = (arg0->flip != 0) ? -1 : 1;
            temp_f22-=(float)(temp_s0*cFont_GetCharH(arg0->font));
            if ((var_s4 != 0) && (*var_s4 == 0x20)) {
                do {
                    var_s4 += 1;
                } while (*var_s4 == 0x20);
            }
            if ((var_s4 != 0) && (*var_s4 == 0)) {
                var_s4 = 0;
            }
            if (var_s4 != 0) {
                var_a2_3 = strlen(spC0) - 1;
                if (var_a2_3 >= 0) {
                    var_a1_2 = (unsigned char*)(var_a2_3 + spC0);
loop_125:
                    temp_a0_3 = *var_a1_2;
                    if (((s32) temp_a0_3 >= 0x10) && ((s32) temp_a0_3 < 0x18)) {
                        temp_a0_4 = (float*)((char*)arg0->font + ((temp_a0_3 - 0x10) * 0x10));
                        rgba[0] = temp_a0_4[4];
                        rgba[1] = temp_a0_4[5];
                        rgba[2] = temp_a0_4[6];
                        rgba[3] = temp_a0_4[7];
                    } else {
                        var_a2_3 -= 1;
                        var_a1_2 -= 1;
                        if (var_a2_3 < 0) {

                        } else {
                            goto loop_125;
                        }
                    }
                }
            }
        } while (var_s4 != 0);
    }
}
static inline void merge_flush_func_003CFAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CFAB0 */

/* merge_units: begin func_003D04C0 */
#pragma push /* merge_units */
typedef struct {
    int x0;
    int x4;
    int w;
    char pad0C[8];
    char str[0xC];
    void* font;
    char pad24[0x30];
    float align;
    unsigned char b58;
    unsigned char b59;
    unsigned char b5A;
    unsigned char b5B;
} T04C0;
extern int cString_Length(void* s);
#if 0 /* merge_units */
extern char* std_basic_string_char_char_traits_char_c_str(void* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((a0))) /* merge_units */

#if 0 /* merge_units */
extern char* strchr(const char* s, int c);
#endif /* merge_units */
#define strchr(a0, a1) (strchr((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int strlen(const char* s);
#endif /* merge_units */
#define strlen(a0) (strlen((a0))) /* merge_units */

#if 0 /* merge_units */
extern int cFont_GetStringWidth(void* font, const char* s, int n);
#endif /* merge_units */
#define cFont_GetStringWidth(a0, a1, a2) (cFont_GetStringWidth((a0), (a1), (a2))) /* merge_units */


int TextObj_GetLineCount(T04C0* t)
{
    float x, right, lim;
    char* p;
    char* next;
    char* q;
    int lines, cnt, wd, i, len, w;

    if (!cString_Length(t->str) || t->b58)
        return 1;
    if (t->b5B) {
        char* s = std_basic_string_char_char_traits_char_c_str(t->str);
        int n = 1;
        if (s) {
            do {
                s = strchr(s, '\n');
                if (s) {
                    n++;
                    s++;
                }
            } while (s);
        }
        return n;
    }
    x = (float)t->x0;
    w = t->w > 0 ? t->w : -t->w;
    right = x + (float)w;
    p = std_basic_string_char_char_traits_char_c_str(t->str);
    lines = 0;
    do {
        lim = x + (1.0f - t->align) * (right - x);
        do {
            if (*p) {
                len = strlen(p + 1);
                for (i = 0; i < len; i++) {
                    if (p[i + 1] == ' ' || p[i + 1] == '\n')
                        break;
                }
                next = (char*)(i + (int)p + 1);
            } else {
                next = 0;
            }
            if (next)
                cnt = next - p;
            else
                cnt = strlen(p) + 1;
            wd = cFont_GetStringWidth(t->font, p, cnt);
            if (x + wd < right || (x == (float)t->x0 && t->align == 1.0f)) {
                p = next;
                x += wd;
            } else if (t->align != 1.0f && x <= lim) {
                q = p;
                for (i = 0; i < cnt; i++) {
                    if (!(x + cFont_GetStringWidth(t->font, p, i + 1) < right))
                        break;
                    q++;
                }
                p = q;
                break;
            }
            if (next && *next == '\n')
                break;
        } while (p && x + wd < right);
        lines++;
        x = (float)t->x0;
        if (p && *p == ' ') {
            do {
                p++;
            } while (*p == ' ');
        }
    } while (p && *p);
    return lines;
}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef strchr /* merge_units */
#undef strlen /* merge_units */
#undef cFont_GetStringWidth /* merge_units */
static inline void merge_flush_func_003D04C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D04C0 */

/* merge_units: begin func_003D0810 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void cTextArea_SetColor(int arg0, int arg1) {
    if (F_(arg0, 0x59, unsigned char) == 0) {
        F_(arg0, 0x30, float) = F_(arg1, 0x0, float);
        F_(arg0, 0x34, float) = F_(arg1, 0x4, float);
        F_(arg0, 0x38, float) = F_(arg1, 0x8, float);
        F_(arg0, 0x3C, float) = F_(arg1, 0xC, float);
    }
}
static inline void merge_flush_func_003D0810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D0810 */

/* merge_units: begin func_003D0850 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; float f3C; char pad40[0xC]; float f4C; float f50; char pad54[5]; char b59; } S3D0850;
void cTextArea_FadeTo(S3D0850* s, float x, float t) {
    if (t == 0.0f) {
        s->f3C = x;
        s->b59 = 0;
    } else {
        s->f50 = x;
        s->f4C = (x - s->f3C) / (1000.0f * t);
        s->b59 = 1;
    }
}
static inline void merge_flush_func_003D0850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D0850 */

/* merge_units: begin func_003D08B0 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int std_basic_string_char_char_traits_char_ctor_charP();                      
typedef struct { char c; } Tag_08B0;
int std_basic_string_char_char_traits_char_do_replace(void*, int, int, int, int, Tag_08B0);                  
int String_Dtor();                            
int std_basic_string_char_char_traits_char_assign_basicstringR();                          

void cTextArea_SetText(char * arg0, int arg1) {
    int sp20[3];

    if (arg1 != 0) {
        std_basic_string_char_char_traits_char_ctor_charP(sp20);
        std_basic_string_char_char_traits_char_assign_basicstringR(arg0 + 0x14, sp20);
        String_Dtor(sp20, 0);
        F_(arg0, 0x44, int) = 0;
        F_(arg0, 0x40, float) = (float) -F_(arg0, 0x8, int);
        F_(arg0, 0x4C, int) = 0;
        F_(arg0, 0x59, signed char) = 0;
        F_(arg0, 0x5A, signed char) = 0;
        return;
    }
    { Tag_08B0 tag; std_basic_string_char_char_traits_char_do_replace(arg0 + 0x14, 0, -1, 0, 0, tag); }
}
static inline void merge_flush_func_003D08B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D08B0 */

/* merge_units: begin func_003D0940 */
#pragma push /* merge_units */
typedef struct { int f0; char f4[0xC]; char f10[0xC]; unsigned char b1C; } M3D1020;
extern signed char D_00543740;
extern M3D1020 D_00543760;
extern char D_00543764[];
extern char D_00543770[];
extern char D_00543748[];
extern char cTextSystem_dtor[];
extern int D_004937F0;
extern void std_list_deleter_cText_ctor(void* p);
extern void std_list_deleter_voidPtr_ctor_void(void* p);
extern void __register_global_object(void* o, void* d, void* l);
#pragma push
#pragma opt_propagation off
static inline M3D1020* Def_3D0940(void)
{
    if (!D_00543740) {
        M3D1020* m = &D_00543760;
        D_00543760.f0 = 0;
        std_list_deleter_cText_ctor(D_00543764);
        std_list_deleter_voidPtr_ctor_void(D_00543770);
        m->b1C = 1;
        __register_global_object(m, cTextSystem_dtor, D_00543748);
        D_00543740 = 1;
    }
    return &D_00543760;
}
typedef struct { float x, y, z, w; } V4_940;
typedef struct S3D0940 {
    int a0, a4, a8, aC;
    unsigned char b10, b11, b12;
    int i14, i18, i1C;
    int i20;
    char pad24[0xC];
    V4_940 v30;
    float f40;
    int i44;
    float f48;
    int i4C, i50;
    float f54;
    unsigned char b58, b59, b5A, b5B;
} S3D0940;
S3D0940* cTextArea_ctor(S3D0940* s, int a, int b, int c, int d, int e, V4_940* v)
{
    s->a0 = a;
    s->a4 = b;
    s->a8 = c;
    s->aC = d;
    s->b10 = 0;
    s->b11 = 0;
    s->b12 = 0;
    s->i14 = 0;
    s->i18 = 0;
    s->i1C = 0;
    s->i20 = e ? e : (Def_3D0940(), D_00543760.f0);
    s->v30.x = v->x;
    s->v30.y = v->y;
    s->v30.z = v->z;
    s->v30.w = v->w;
    s->f40 = (float)-s->a8;
    s->i44 = 0;
    s->f48 = (float)D_004937F0;
    s->i4C = 0;
    s->i50 = 0;
    s->f54 = 0.6f;
    s->b58 = 0;
    s->b59 = 0;
    s->b5A = 0;
    s->b5B = 0;
    return s;
}
#pragma pop
static inline void merge_flush_func_003D0940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D0940 */

/* merge_units: begin func_003D0A90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cTextAreaPtr_dtor)
static inline void merge_flush_func_003D0A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D0A90 */

/* merge_units: begin func_003D0B10 */
#pragma push /* merge_units */
typedef struct { int m0; int m4; int m8; } T0B10;
extern void std_list_deleter_cText_erase(int* out, T0B10* self, int* first, int* last);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

T0B10* std_list_cText_dtor(T0B10* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                int r;
                int first;
                int last;
                last = (int)&self->m4;
                first = self->m8;
                std_list_deleter_cText_erase(&r, self, &first, &last);
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
static inline void merge_flush_func_003D0B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D0B10 */
