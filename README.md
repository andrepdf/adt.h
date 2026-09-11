## Usage

Define ASTs with the `datadef` macro.

```c
datadef (
    List
    , (Nil)
    , (Cons, int, List*)
)
```

The previous example is syntactic sugar for:

```c
typedef struct List List;
struct List {
    enum {
        _Nil,
        _Cons
    } tag;
    union {
        struct {} Nil;
        struct {
            int _0;
            List* _1;
        } Cons;
    } as;
};

static inline List Nil() {
    return (List){
        .tag = _Nil
    };
}

static inline List Cons(int _0, List* _1) {
    return (List){
        .tag = _Cons,
        .as.Cons._0 = _0,
        .as.Cons._1 = _1
    };
}
```

Here's a simple program that defines and uses the `List` AST:

```c
#include "adt.h"
#include <stdio.h>

datadef (
    List
    , (Nil)
    , (Cons, int, List*)
)

int length(const List* xs) {
    switch(xs->tag) {
        case _Nil:
            return 0;
        case _Cons:
            return 1 + length(xs->as.Cons._1);
    }
}

int main() {
    List xs = Nil();
    List ys = Cons(1, &xs);
    List zs = Cons(2, &ys);

    printf("length: %d\n", length(&zs));
}
```
