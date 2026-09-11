## Usage

Define ASTs with the `datadef` macro and pattern match with the `match` macro.

```c
datadef (
    List
    , (Nil)
    , (Cons, int, List*)
)

int sum(List* list) {
    match (
        list
        , (Nil)
            , return 0;
        , (Cons, x, xs)
            , return x + sum(xs);
    )
}
```
