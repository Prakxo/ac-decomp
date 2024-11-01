#include "dolphin/string.h" /* strchr */

#include "libultra/xprintf.h"

#define ATOI(i, a)                           \
    for (i = 0; *a >= '0' && *a <= '9'; a++) \
        if (i < 999)                         \
            i = *a + i * 10 - '0';

#define _PROUT(fmt, _size)          \
    if (_size > 0) {                \
        arg = pfn(arg, fmt, _size); \
        if (arg != NULL)            \
            x.nchar += _size;       \
        else                        \
            return x.nchar;         \
    }
#define _PROUT2(fmt, _size)                \
    if ((u32)(_size) != 0) {               \
        arg = pfn(arg, fmt, (u32)(_size)); \
        if (arg != NULL)                   \
            x.nchar += _size;              \
        else                               \
            return x.nchar;                \
    }
#define _PAD(m, src, extracond)      \
    if (extracond && m > 0) {        \
        s32 i;                       \
        s32 j;                       \
        for (j = m; j > 0; j -= i) { \
            if (j > 32)              \
                i = 32;              \
            else                     \
                i = j;               \
            _PROUT(src, i);          \
        }                            \
    }

static char spaces[] = "                                ";
static char zeroes[] = "00000000000000000000000000000000";

void _Putfld(_Pft*, va_list, u8, u8*);

int _Printf(void* (*pfn)(void*, const char*, int), void* arg, const char* fmt, va_list ap) {
    static const char fchar[] = " +-#0";
    static const u32 fbit[6] = { FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0 };

    _Pft x;
    x.nchar = 0;

    while (TRUE) {
        u8 qual;
        const u8* s = (u8*)fmt;
        u8 c;
        const char* t;
        u8 ac[0x20];
        u8* temp;

        for (c = *s; c != 0 && c != '%';) {
            c = *++s;
        }
        temp = (u8*)fmt;
        _PROUT2(fmt, s - temp);
        if (c == 0) {
            return x.nchar;
        }
        fmt = (char*)++s;
        x.flags = 0;
        for (; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }
        if (*s == '*') {
            x.width = va_arg(ap, s32);
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else {
            ATOI(x.width, s);
        }
        if (*s != '.') {
            x.prec = -1;
        } else {
            s++;
            if (*s == '*') {
                x.prec = va_arg(ap, s32);
                s++;
            } else {
                ATOI(x.prec, s);
            }
        }
        if (strchr("hlL", *s) != NULL) {
            qual = *s++;
        } else {
            qual = 0;
        }
        x.qual = qual;

        if (qual == 'l' && *s == 'l') {
            x.qual = 'L';
            s++;
        }
        _Putfld(&x, ap, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;
        _PAD(x.width, spaces, !(x.flags & FLAGS_MINUS));
        _PROUT((char*)ac, x.n0);
        _PAD(x.nz0, zeroes, 1);
        _PROUT(x.s, x.n1);
        _PAD(x.nz1, zeroes, 1);
        _PROUT((char*)(&x.s[x.n1]), x.n2)
        _PAD(x.nz2, zeroes, 1);
        _PAD(x.width, spaces, x.flags & FLAGS_MINUS);
        fmt = (char*)s + 1;
    }
}

void _Putfld(_Pft* px, va_list ap, u8 code, u8* ac) {
    px->n0 = px->nz0 = px->n1 = px->nz1 = px->n2 = px->nz2 = 0;

    switch ((u8)code) {
        case 'c':
            ac[px->n0++] = va_arg(ap, u32);
            break;

        case 'd':
        case 'i':
            if (px->qual == 'l') {
                px->v.ll = va_arg(ap, s32);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(ap, s64);
            } else {
                px->v.ll = va_arg(ap, s32);
            }

            if (px->qual == 'h') {
                px->v.ll = (s16)px->v.ll;
            }

            if (px->v.ll < 0) {
                ac[px->n0++] = '-';
            } else if (px->flags & FLAGS_PLUS) {
                ac[px->n0++] = '+';
            } else if (px->flags & FLAGS_SPACE) {
                ac[px->n0++] = ' ';
            }

            px->s = (char*)&ac[px->n0];

            _Litob(px, code);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            if (px->qual == 'l') {
                px->v.ll = va_arg(ap, s32);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(ap, s64);
            } else {
                px->v.ll = va_arg(ap, s32);
            }

            if (px->qual == 'h') {
                px->v.ll = (u16)px->v.ll;
            } else if (px->qual == 0) {
                px->v.ll = (u32)px->v.ll;
            }

            if (px->flags & FLAGS_HASH) {
                ac[px->n0++] = '0';
                if (code == 'x' || code == 'X') {

                    ac[px->n0++] = code;
                }
            }
            px->s = (char*)&ac[px->n0];
            _Litob(px, code);
            break;
        case 'e':
        case 'f':
        case 'g':
        case 'E':
        case 'G':
            px->v.ld = px->qual == 'L' ? va_arg(ap, f64) : va_arg(ap, f64);

            if (*(u16*)&px->v.ll & 0x8000) {
                ac[px->n0++] = '-';
            } else {
                if (px->flags & FLAGS_PLUS) {
                    ac[px->n0++] = '+';
                } else if (px->flags & FLAGS_SPACE) {
                    ac[px->n0++] = ' ';
                }
            }

            px->s = (char*)&ac[px->n0];
            _Ldtob(px, code);
            break;
        case 'n':
            if (px->qual == 'h') {
                *(va_arg(ap, s16*)) = px->nchar;
            } else if (px->qual == 'l') {
                *va_arg(ap, s32*) = px->nchar;
            } else if (px->qual == 'L') {
                *va_arg(ap, s64*) = px->nchar;
            } else {
                *va_arg(ap, s32*) = px->nchar;
            }
            break;

        case 'p':
            px->v.ll = (s32)va_arg(ap, void*);
            px->s = (char*)&ac[px->n0];
            _Litob(px, 'x');
            break;
        case 's':
            px->s = va_arg(ap, char*);
            px->n1 = strlen(px->s);
            if (px->prec >= 0 && px->n1 > px->prec) {
                px->n1 = px->prec;
            }
            break;
        case '%':
            ac[px->n0++] = '%';
            break;
        default:
            ac[px->n0++] = code;
            break;
    }
}

