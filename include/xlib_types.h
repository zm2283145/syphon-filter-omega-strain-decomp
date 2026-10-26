#ifndef XLIB_TYPES_H
#define XLIB_TYPES_H

/* One-word wrapper object constructed by std_list_deleter_tDataDelRec_generic_iterator_ctor. */
typedef struct XlibWord {
    int value;      /* 0x00 */
    char data[1];   /* 0x04: payload returned by std_list_deleter_tDataDelRec_tail (size unknown) */
} XlibWord;

/* xlib object with a flag at 0xA78 (size unknown). */
typedef struct XlibObj {
    char pad000[0xA78];
    char unkA78;    /* 0xA78: set by XLib_Restore */
} XlibObj;

#endif
