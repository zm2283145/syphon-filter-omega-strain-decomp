#include "types.h"
typedef struct { char pad[0x40]; int value; char pad44; unsigned char id; } Info;
typedef struct { char pad[0xE8]; void* valueLabel; void* nameLabel; char pad2[4]; Info* info; } Panel;
extern char D_004AB018[];
extern char D_004AB028[];
extern char D_004AAFF0[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(const char* key);
extern void func_0041BEB0(void* label, const char* text, int flags);
/* Fills the panel's name (localised, with fallback) and value labels. */
void func_002A1670(Panel* p)
{
    char buf[0x20];
    char* text;
    sprintf(buf, D_004AB018, p->info->id);
    text = Loc_LookupText(buf);
    func_0041BEB0(p->nameLabel, text ? text : D_004AAFF0, 0);
    sprintf(buf, D_004AB028, p->info->value);
    func_0041BEB0(p->valueLabel, buf, 0);
}
