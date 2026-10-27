/*
 * main/gobj: 2 files, 003CF3A0-003CFAB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CF3A0 */
#pragma push /* merge_units */
#include "types.h"
typedef int s32; typedef unsigned int u32; typedef char s8; typedef unsigned char u8; typedef float f32; typedef long long s64;
/* Text layout follows the matched line counter TextObj_GetLineCount. */
typedef struct { int x,y,w,h; unsigned char align,flip,center,pad13; char str[12]; void *font; char pad24[12]; float color[4]; float scroll,last,speed,alphaSpeed,alphaEnd,wrap; unsigned char noWrap,fade,done,ellipsis; } TextLayout;
extern char *std_basic_string_char_char_traits_char_c_str(void*);
extern void Libc_Strcpy(char*,const char*);
extern void Libc_Strncat(char*,const char*,int);
extern int cFont_GetCharH(void*);
extern int cFont_GetStringWidth(void*,const char*,int);
extern int strlen(const char*);
extern int TextObj_GetLineCount(TextLayout*);
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
#pragma pop /* merge_units */
/* merge_units: end func_003CFAB0 */
