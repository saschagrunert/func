# func - Functional additions to C [![Build Status](https://travis-ci.org/saschagrunert/func.svg)](https://travis-ci.org/saschagrunert/func)

Func provides - header only - functional additions to the C language. For now,
the following features are included:

- [`Maybe` data type](./include/Maybe.h)
- [`Either` data type](./include/Either.h)

## Installation

Simply add the [`include`](./include) folder as a dependency to your project and
include the main header file:

```c
#include <Func.h>
```

## Usage

### Maybe

A Maybe type is a polymorphic type that represents encapsulation of an optional
value.

The type can be used like this:

```c
#include "include/Func.h"

MAYBE(int, foo);

/* Alternatively, if you dont need the 'foo' synonym:
 * MAYBE_TYPE(int); */

int main(void) {
    Maybe(foo) maybeFoo = Just_foo(2);

    /* check if the Maybe value contains nothing */
    if (isNothing(maybeFoo)) {
        /* wont be executed */
    }

    /* check if the Maybe value contains something */
    if (isJust(maybeFoo)) {
        /* will be executed */
    }

    /* Extract the content to `t`.
       Will evaluate to the default value '0'
       if the maybeFoo would be 'Nothing' */
    int t = fromJust(0, maybeFoo);

    /* t will be `2` now */

    return 0;
}
```

### Either

The Either type represents values with two possibilities: a value of type Either
a b is either Left a or Right b.

The Either type is sometimes used to represent a value which is either correct
or an error; by convention, the Left constructor is used to hold an error value
and the Right constructor is used to hold a correct value (mnemonic: "right"
also means "correct").

```c
#include "include/Func.h"

EITHER(int, foo, char, bar);

/* Alternatively, if you dont need the 'foo' and 'bar' synonyms:
 * EITHER_TYPE(int, char); */

int main(void) {
    Either(foo, bar) eitherFooOrBar = Right_foo_bar('a');

    if (isLeft(eitherFooOrBar)) {
        /* wont be executed */
    }

    if (isRight(eitherFooOrBar)) {
        /* will be executed */
    }

    /* Try to extract the Left content to `x`.
       Will evaluate to the default '1' if the
       Either type would be 'Right' */
    int x = fromLeft(1, eitherFooOrBar);

    /* x will be '1' */

    /* Try to extract the Right content to `y`.
       Will evaluate to the default ' ' if the
       Either type is 'Left' */
    char y = fromRight(' ', eitherFooOrBar);

    /* y will be 'a' */

    return 0;
}
```

## Contributing
You want to contribute to this project? Wow, thanks! So please just fork it and
send me a pull request.
