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

#define ADT_TAGS_1(d, xs) ADT_CAT(, ADT_HEAD(xs))
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
#define ADT_BODY_1(t0) \
    t0 _0;
#define ADT_BODY_2(t0, t1) \
    t0 _0; t1 _1;
#define ADT_BODY_3(t0, t1, t2) \
    t0 _0; t1 _1; t2 _2;
#define ADT_BODY_4(t0, t1, t2, t3) \
    t0 _0; t1 _1; t2 _2; t3 _3;
#define ADT_BODY_5(t0, t1, t2, t3, t4) \
    t0 _0; t1 _1; t2 _2; t3 _3; t4 _4;
#define ADT_BODY_6(t0, t1, t2, t3, t4, t5) \
    t0 _0; t1 _1; t2 _2; t3 _3; t4 _4; t5 _5;
#define ADT_BODY_7(t0, t1, t2, t3, t4, t5, t6) \
    t0 _0; t1 _1; t2 _2; t3 _3; t4 _4; t5 _5; t6 _6;
#define ADT_BODY_8(t0, t1, t2, t3, t4, t5, t6, t7) \
    t0 _0; t1 _1; t2 _2; t3 _3; t4 _4; t5 _5; t6 _6; t7 _7;
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
#define ADT_PARAMS_1(t0) \
    t0 _0
#define ADT_PARAMS_2(t0, t1) \
    t0 _0, t1 _1
#define ADT_PARAMS_3(t0, t1, t2) \
    t0 _0, t1 _1, t2 _2
#define ADT_PARAMS_4(t0, t1, t2, t3) \
    t0 _0, t1 _1, t2 _2, t3 _3
#define ADT_PARAMS_5(t0, t1, t2, t3, t4) \
    t0 _0, t1 _1, t2 _2, t3 _3, t4 _4
#define ADT_PARAMS_6(t0, t1, t2, t3, t4, t5) \
    t0 _0, t1 _1, t2 _2, t3 _3, t4 _4, t5 _5
#define ADT_PARAMS_7(t0, t1, t2, t3, t4, t5, t6) \
    t0 _0, t1 _1, t2 _2, t3 _3, t4 _4, t5 _5, t6 _6
#define ADT_PARAMS_8(t0, t1, t2, t3, t4, t5, t6, t7) \
    t0 _0, t1 _1, t2 _2, t3 _3, t4 _4, t5 _5, t6 _6, t7 _7
#define ADT_PARAMS(...) \
    ADT_CAT(ADT_PARAMS, ADT_NARG(__VA_ARGS__))(__VA_ARGS__)

#define ADT_BINDS_0(d, c) .tag = _##c
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

#define ADT_LOCAL_0(...)
#define ADT_LOCAL_1(x, c, a0)                                           \
    typeof(x->as.c._0) a0 = x->as.c._0;
#define ADT_LOCAL_2(x, c, a0, a1)                                       \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1;
#define ADT_LOCAL_3(x, c, a0, a1, a2)                                   \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2;
#define ADT_LOCAL_4(x, c, a0, a1, a2, a3)                               \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2; typeof(x->as.c._3) a3 = x->as.c._3;
#define ADT_LOCAL_5(x, c, a0, a1, a2, a3, a4)                           \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2; typeof(x->as.c._3) a3 = x->as.c._3; \
    typeof(x->as.c._4) a4 = x->as.c._4;
#define ADT_LOCAL_6(x, c, a0, a1, a2, a3, a4, a5)                       \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2; typeof(x->as.c._3) a3 = x->as.c._3; \
    typeof(x->as.c._4) a4 = x->as.c._4; typeof(x->as.c._5) a5 = x->as.c._5;
#define ADT_LOCAL_7(x, c, a0, a1, a2, a3, a4, a5, a6)                   \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2; typeof(x->as.c._3) a3 = x->as.c._3; \
    typeof(x->as.c._4) a4 = x->as.c._4; typeof(x->as.c._5) a5 = x->as.c._5; \
    typeof(x->as.c._6) a6 = x->as.c._6;
#define ADT_LOCAL_8(x, c, a0, a1, a2, a3, a4, a5, a6, a7)               \
    typeof(x->as.c._0) a0 = x->as.c._0; typeof(x->as.c._1) a1 = x->as.c._1; \
    typeof(x->as.c._2) a2 = x->as.c._2; typeof(x->as.c._3) a3 = x->as.c._3; \
    typeof(x->as.c._4) a4 = x->as.c._4; typeof(x->as.c._5) a5 = x->as.c._5; \
    typeof(x->as.c._6) a6 = x->as.c._6; typeof(x->as.c._7) a7 = x->as.c._7;
#define ADT_LOCAL(x, c, ...) \
    ADT_CAT(ADT_LOCAL, ADT_NARG(__VA_ARGS__))(x, c, __VA_ARGS__)

#define ADT_MATCH_2(x, a, b)                   \
    case ADT_CAT(,ADT_HEAD(a)): {              \
        ADT_LOCAL(x, ADT_HEAD(a), ADT_TAIL(a)) \
        b                                      \
        break;                                 \
    }
#define ADT_MATCH_4(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_2(x, __VA_ARGS__)
#define ADT_MATCH_6(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_4(x, __VA_ARGS__)
#define ADT_MATCH_8(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_6(x, __VA_ARGS__)
#define ADT_MATCH_10(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_8(x, __VA_ARGS__)
#define ADT_MATCH_12(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_10(x, __VA_ARGS__)
#define ADT_MATCH_14(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_12(x, __VA_ARGS__)
#define ADT_MATCH_16(x, a, b, ...) ADT_MATCH_2(x, a, b) ADT_MATCH_14(x, __VA_ARGS__)
#define ADT_MATCH(x, ...) \
    ADT_CAT(ADT_MATCH, ADT_NARG(__VA_ARGS__))(x, __VA_ARGS__)

/*----------------------------------------------------------------------------*/

#define datadef(d, ...)                \
    typedef struct d d;                \
    struct d {                         \
        enum {                         \
            ADT_TAGS(d, __VA_ARGS__)   \
        } tag;                         \
        union {                        \
            ADT_FIELDS(__VA_ARGS__)    \
        } as;                          \
    };                                 \
    ADT_CONS(d, __VA_ARGS__)

#define match(x, ...)             \
    switch (x->tag) {             \
        ADT_MATCH(x, __VA_ARGS__) \
    }

#endif
