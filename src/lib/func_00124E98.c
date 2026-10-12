typedef struct { char p[0x30]; int _current_category; const char *_current_locale; } R00124E98;
extern int strcmp(const char *, const char *);
extern char D_00499E10[];
char *func_00124E98(R00124E98 *p, int category, const char *locale)
{
    if (locale) {
        if (strcmp(locale, "C") && strcmp(locale, D_00499E10)) return 0;
        p->_current_category = category;
        p->_current_locale = locale;
    }
    return "C";
}
