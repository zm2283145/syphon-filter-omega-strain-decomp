#include "types.h"
struct Script { char pad[0x4E88]; int line; char* module; };
extern char D_00559FE0[];
char D_004BD868[] = "%s\\common\\%s";
char D_004BD878[] = "%s\\%s\\%s";
char D_004BD888[] __attribute__((aligned(8))) = "."; /* 8-aligned in the original data */


char*strrchr(char*,int);int sprintf(char*,char*,...);
void String_Copy(char*,char*);void Libc_Strcat(char*,char*);
char*ScriptMgr_BuildScriptPath(struct Script*self,char*name,char*extension,int moduleOnly){
 char*last;
 last=strrchr(name,'\\');if(last)name=last+1;
 if(moduleOnly)sprintf(D_00559FE0,D_004BD868,self->module,name);
 else sprintf(D_00559FE0,D_004BD878,self->module,self->line,name);
 last=strrchr(D_00559FE0,'.');
 if(last)String_Copy(last+1,extension);
 else {Libc_Strcat(D_00559FE0,D_004BD888);Libc_Strcat(D_00559FE0,extension);}
 return D_00559FE0;
}
