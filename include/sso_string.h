#ifndef SSO_STRING_H
#define SSO_STRING_H

/*
 * SsoString: the game's 12-byte short-string-optimised basic_string
 * (~100 src files re-derive it as String/Str/SsoString/StrObj).
 * Plain C or C++; MW kinds.
 *   short form: bit 0 of byte 0 clear, length in bits 1..7 of byte 0,
 *               characters in place from +1 (max 10 + NUL)
 *   long form:  bit 0 of word 0 set (capacity in bits 1..31),
 *               length at +4, heap data at +8
 * Same layout as ShortStrData (short_string_data.h), StreamStringStorage
 * (stream_string_dtor.h), ShortStr/TStr (C++ only); those headers DEFINE
 * the string functions themselves - use this one in callers.
 *
 * Usual caller idiom:
 *   SsoString s;  std_basic_string_char_char_traits_char_ctor_charP(&s, "text");
 *   ... std_basic_string_char_char_traits_char_c_str(&s) (data) ...;  String_Dtor(&s, 0);  (dtor)
 *
 * Prototypes take void* so local string types still convert; define
 * SSO_STRING_NO_PROTOS to keep typed local declarations instead.
 */
#include "layout_assert.h"

typedef struct SsoString {
    union {
        unsigned int word;                 /* bit 0: long (heap) form */
        struct {
            unsigned char isLong : 1;
            unsigned char len : 7;         /* short length */
        } s;
        char bytes[4];                     /* short chars from bytes[1] */
    } h;
    int longLen;                           /* +4 long length */
    char* longData;                        /* +8 long data */
} SsoString; /* 0xC */
LAYOUT_SIZE(SsoString, 0xC);

#define SSO_IS_LONG(str) ((str)->h.word & 1)

#ifndef SSO_STRING_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
void* std_basic_string_char_char_traits_char_ctor_charP(void* str, const char* cstr);      /* ctor from C string */
void* String_Dtor(void* str, int flags);                      /* dtor (frees long data) */
char* std_basic_string_char_char_traits_char_c_str(void* str);                                 /* data() / c_str() */
void* std_basic_string_char_char_traits_char_assign_basicstringR(void* dst, const void* src);                /* operator= */
void std_basic_string_char_char_traits_char_reserve(void* str, unsigned int n);                 /* 0x0013B970 */
#ifdef __cplusplus
}
#endif
#endif

#endif /* SSO_STRING_H */
