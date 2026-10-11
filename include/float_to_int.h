#ifndef FLOAT_TO_INT_H
#define FLOAT_TO_INT_H

/* Float to int conversion (cvt.w.s) helper, one clone per unit. Plain C. */
#define DEFINE_FLOAT_TO_INT(name) \
    int name(float x) { return (int)x; }

#endif /* FLOAT_TO_INT_H */