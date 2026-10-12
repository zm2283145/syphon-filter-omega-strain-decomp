typedef struct { unsigned long long a,b; unsigned short c; } S7840;
extern S7840 D_004BB478;
extern S7840 D_005335C0;
extern int func_003578A0(int,int*,S7840*,int);
S7840 *func_00357840(int x) {
 int v[1];
 __builtin_memcpy(&D_005335C0,&D_004BB478,18);
 v[0]=x;
 func_003578A0(2,v,&D_005335C0,0x12);
 return &D_005335C0;
}

