#include "types.h"
typedef int s32; typedef unsigned int u32; typedef char s8; typedef unsigned char u8; typedef float f32; typedef long long s64;
/* Text layout follows the matched line counter func_003D04C0. */
typedef struct { int x,y,w,h; unsigned char align,flip,center,pad13; char str[12]; void *font; char pad24[12]; float color[4]; float scroll,last,speed,alphaSpeed,alphaEnd,wrap; unsigned char noWrap,fade,done,ellipsis; } TextLayout;
extern char *String_CStr(void*);
extern void String_Copy(char*,const char*);
extern void func_00129708(char*,const char*,int);
extern int func_0036A2F0(void*);
extern int func_0036AA50(void*,const char*,int);
extern int strlen(const char*);
extern int func_003D04C0(TextLayout*);
extern char D_004BD310[];
s32 func_003CF3A0(TextLayout *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
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
        var_f22 -= (f32) (arg0->h - func_0036A2F0(temp_a0));
    }
    var_v0 = arg0->w;
    var_v0=var_v0>0?var_v0:-var_v0;
    temp_f21 = var_f23 + (f32) var_v0;
    if (arg0->center != 0) {
        temp_s1 = func_003D04C0(arg0);
        var_f22-=(float)(arg0->h/2-(temp_s1*func_0036A2F0(arg0->font))/2);
    }
    temp_v0_2 = String_CStr(arg0->str);
    var_s4 = temp_v0_2;
    limit[0] = temp_v0_2 + arg3;
    if (arg0->align == 3) {
        return 0;
    }
loop_16:
    spE0[0] = 0;
    temp_fp = var_s4;
    if (arg0->ellipsis != 0) {
        if (func_003D04C0(arg0) != 1) {
            return 0;
        }
        temp_f1 = (f32) func_0036AA50(arg0->font, var_s4, strlen(var_s4));
        if ((var_f23 + temp_f1) < temp_f21) {
            var_f23 += temp_f1;
            String_Copy(spE0, var_s4);
        } else {
            temp_f20 = (f32) func_0036AA50(arg0->font, D_004BD310, 3);
            temp_f24 = temp_f21 - (var_f23 + temp_f20);
            if (temp_f24 <= 0.0f) {
                var_f23 += temp_f20;
                String_Copy(spE0, D_004BD310);
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
                var_s0=func_0036AA50(arg0->font,spE0,var_s2);
                if(!((float)var_s0<=temp_f24)){var_s0=temp_s1_2;var_s2--;}
check31:
                temp_v1_2=*var_s4;
                if(temp_v1_2!=0 && (float)var_s0<=temp_f24)goto loop_31;
end31:
                if (temp_v1_2 != 0xA) {
                    String_Copy(var_s2 + spE0, D_004BD310);
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
        var_f23 += (f32) func_0036AA50(arg0->font, var_s4, strlen(var_s4));
        String_Copy(spE0, var_s4);
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
        var_s0 = func_0036AA50(arg0->font, var_s4, var_s3);
        if (((var_f23 + (f32) var_s0) < temp_f21) || ((var_f23 == (f32) (s32) arg0->x) && (arg0->wrap == 1.0f))) {
            func_00129708(spE0, var_s4, var_s3);
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
                temp_v0_6=func_0036AA50(arg0->font,var_s4,var_s0+1);
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
        *spDC = var_f23 + (f32) func_0036AA50(arg0->font, spE0, limit[0] - temp_fp);
        return 1;
    }
    temp_s0 = (arg0->flip != 0) ? -1 : 1;
    var_f23 = (f32) (s32) arg0->x;
    var_f22 -= (f32) (temp_s0 * func_0036A2F0(arg0->font));
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
