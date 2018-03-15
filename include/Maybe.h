// Copyright 2018 Sascha Grunert

#ifndef INCLUDE_MAYBE_H_
#define INCLUDE_MAYBE_H_

#include "Func.h"

/**
 * @brief The 'Maybe' type declaration
 */
#define Maybe(t) maybe_##t##_type

/**
 * @brief The 'Just' type declaration
 */
#define Just(t, d)           \
    (Maybe(t)) {             \
        .just = 1, .data = d \
    }

/**
 * @brief The 'Nothing' type declaration
 */
#define Nothing(t)                 \
    (Maybe(t)) {                   \
        .just = 0, .data = null(t) \
    }

/**
 * @brief Creates a new 'Maybe' type
 */
#define MAYBE_TYPE(t)            \
    typedef struct {             \
        int just;                \
        t data;                  \
    } Maybe(t);                  \
    static                       \
    Maybe(t) Just_##t(t val);    \
    static                       \
    Maybe(t) Just_##t(t val) {   \
        return Just(t, val);     \
    }                            \
    static                       \
    Maybe(t) Nothing_##t(void);  \
    static                       \
    Maybe(t) Nothing_##t(void) { \
        return Nothing(t);       \
    }

/**
 * @brief Creates a new named 'Maybe'
 */
#define MAYBE(t, n) \
    typedef t n;    \
    MAYBE_TYPE(n)

/**
 * @brief Check if the Maybe contains any data
 */
#define isJust(o) ((o).just)

/**
 * @brief Check if the Maybe contains nothing
 */
#define isNothing(o) (!isJust(o))

/**
 * @brief Takes a default value and a Maybe value. If the Maybe is Nothing,
 *        it returns the default values; otherwise, it returns the value
 *        contained in the Maybe.
 */
#define fromMaybe(x, o) (isJust(o) ? o.data : x)

#endif  // INCLUDE_MAYBE_H_
