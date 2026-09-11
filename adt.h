#ifndef ADT_H
#define ADT_H

#define _ADT_CAT(a, b) a##_##b
#define ADT_CAT(a, b) _ADT_CAT(a, b)
#define _ADT_HEAD(x, ...) x
#define ADT_HEAD(xs) _ADT_HEAD xs
#define _ADT_TAIL(_, ...) __VA_ARGS__
#define ADT_TAIL(xs) _ADT_TAIL xs

#define _ADT_NARG(_0, _1, _2, _3, _4, _5, _6, _7, _8, n, ...) n
#define ADT_NARG(...) _ADT_NARG(_, ##__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define ADT_TAGS_1(d, xs) ADT_CAT(d, ADT_HEAD(xs))
#define ADT_TAGS_2(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_1(d, __VA_ARGS__)
#define ADT_TAGS_3(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_2(d, __VA_ARGS__)
#define ADT_TAGS_4(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_3(d, __VA_ARGS__)
#define ADT_TAGS_5(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_4(d, __VA_ARGS__)
#define ADT_TAGS_6(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_5(d, __VA_ARGS__)
#define ADT_TAGS_7(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_6(d, __VA_ARGS__)
#define ADT_TAGS_8(d, xs, ...) ADT_TAGS_1(d, xs), ADT_TAGS_7(d, __VA_ARGS__)
#define ADT_TAGS(d, ...) \
    ADT_CAT(ADT_TAGS, ADT_NARG(__VA_ARGS__))(d, __VA_ARGS__)

#define ADT_BODY_0(...)
#define ADT_BODY_1(t) t _0;
#define ADT_BODY_2(t, ...) ADT_BODY_1(__VA_ARGS__) t _1;
#define ADT_BODY_3(t, ...) ADT_BODY_2(__VA_ARGS__) t _2;
#define ADT_BODY_4(t, ...) ADT_BODY_3(__VA_ARGS__) t _3;
#define ADT_BODY_5(t, ...) ADT_BODY_4(__VA_ARGS__) t _4;
#define ADT_BODY_6(t, ...) ADT_BODY_5(__VA_ARGS__) t _5;
#define ADT_BODY_7(t, ...) ADT_BODY_6(__VA_ARGS__) t _6;
#define ADT_BODY_8(t, ...) ADT_BODY_7(__VA_ARGS__) t _7;
#define ADT_BODY(...) \
    ADT_CAT(ADT_BODY, ADT_NARG(__VA_ARGS__))(__VA_ARGS__)

#define ADT_FIELDS_1(xs) struct { ADT_BODY(ADT_TAIL(xs)) } ADT_HEAD(xs);
#define ADT_FIELDS_2(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_1(__VA_ARGS__)
#define ADT_FIELDS_3(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_2(__VA_ARGS__)
#define ADT_FIELDS_4(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_3(__VA_ARGS__)
#define ADT_FIELDS_5(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_4(__VA_ARGS__)
#define ADT_FIELDS_6(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_5(__VA_ARGS__)
#define ADT_FIELDS_7(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_6(__VA_ARGS__)
#define ADT_FIELDS_8(xs, ...) ADT_FIELDS_1(xs) ADT_FIELDS_7(__VA_ARGS__)
#define ADT_FIELDS(...) \
    ADT_CAT(ADT_FIELDS, ADT_NARG(__VA_ARGS__))(__VA_ARGS__)

#define ADT_PARAMS_0(...)
#define ADT_PARAMS_1(t) t _0
#define ADT_PARAMS_2(t, ...) ADT_PARAMS_1(__VA_ARGS__), t _1
#define ADT_PARAMS_3(t, ...) ADT_PARAMS_2(__VA_ARGS__), t _2
#define ADT_PARAMS_4(t, ...) ADT_PARAMS_3(__VA_ARGS__), t _3
#define ADT_PARAMS_5(t, ...) ADT_PARAMS_4(__VA_ARGS__), t _4
#define ADT_PARAMS_6(t, ...) ADT_PARAMS_5(__VA_ARGS__), t _5
#define ADT_PARAMS_7(t, ...) ADT_PARAMS_6(__VA_ARGS__), t _6
#define ADT_PARAMS_8(t, ...) ADT_PARAMS_7(__VA_ARGS__), t _7
#define ADT_PARAMS(...) \
    ADT_CAT(ADT_PARAMS, ADT_NARG(__VA_ARGS__))(__VA_ARGS__)

#define ADT_BINDS_0(d, c) .tag = d##_##c
#define ADT_BINDS_1(d, c) ADT_BINDS_0(d, c), .as.c._0 = _0
#define ADT_BINDS_2(d, c) ADT_BINDS_1(d, c), .as.c._1 = _1
#define ADT_BINDS_3(d, c) ADT_BINDS_2(d, c), .as.c._2 = _2
#define ADT_BINDS_4(d, c) ADT_BINDS_3(d, c), .as.c._3 = _3
#define ADT_BINDS_5(d, c) ADT_BINDS_4(d, c), .as.c._4 = _4
#define ADT_BINDS_6(d, c) ADT_BINDS_5(d, c), .as.c._5 = _5
#define ADT_BINDS_7(d, c) ADT_BINDS_6(d, c), .as.c._6 = _6
#define ADT_BINDS_8(d, c) ADT_BINDS_7(d, c), .as.c._7 = _7
#define ADT_BINDS(d, c, ...) \
    ADT_CAT(ADT_BINDS, ADT_NARG(__VA_ARGS__))(d, c)

#define ADT_CONS_1(d, xs)                                    \
    static inline d ADT_HEAD(xs)(ADT_PARAMS(ADT_TAIL(xs))) { \
        return (d){                                          \
            ADT_BINDS(d, ADT_HEAD(xs), ADT_TAIL(xs))         \
        };                                                   \
    }
#define ADT_CONS_2(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_1(d, __VA_ARGS__)
#define ADT_CONS_3(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_2(d, __VA_ARGS__)
#define ADT_CONS_4(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_3(d, __VA_ARGS__)
#define ADT_CONS_5(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_4(d, __VA_ARGS__)
#define ADT_CONS_6(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_5(d, __VA_ARGS__)
#define ADT_CONS_7(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_6(d, __VA_ARGS__)
#define ADT_CONS_8(d, xs, ...) ADT_CONS_1(d, xs) ADT_CONS_7(d, __VA_ARGS__)
#define ADT_CONS(d, ...) \
    ADT_CAT(ADT_CONS, ADT_NARG(__VA_ARGS__))(d, __VA_ARGS__)

#define datadef(d, ...)                \
    typedef enum {                     \
        ADT_TAGS(d, __VA_ARGS__)       \
    } _##d##_Tag;                      \
    typedef struct d d;                \
    struct d {                         \
        _##d##_Tag tag;                \
        union {                        \
            ADT_FIELDS(__VA_ARGS__)    \
        } as;                          \
    };                                 \
    ADT_CONS(d, __VA_ARGS__)

#endif
