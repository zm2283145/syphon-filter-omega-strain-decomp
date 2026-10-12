#include "types.h"
struct Script { char pad[0x4E88]; int line; char* module; };
extern char D_00559FE0[],D_004BD868[],D_004BD878[],D_004BD888[];
char*strrchr(char*,int);int sprintf(char*,char*,...);
void String_Copy(char*,char*);void func_00128F58(char*,char*);
char*func_003E11C0(struct Script*self,char*name,char*extension,int moduleOnly){
 char*last;
 last=strrchr(name,'\\');if(last)name=last+1;
 if(moduleOnly)sprintf(D_00559FE0,D_004BD868,self->module,name);
 else sprintf(D_00559FE0,D_004BD878,self->module,self->line,name);
 last=strrchr(D_00559FE0,'.');
 if(last)String_Copy(last+1,extension);
 else {func_00128F58(D_00559FE0,D_004BD888);func_00128F58(D_00559FE0,extension);}
 return D_00559FE0;
}
