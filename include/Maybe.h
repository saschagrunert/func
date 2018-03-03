// Copyright 2018 Sascha Grunert

#ifndef INCLUDE_MAYBE_H_
#define INCLUDE_MAYBE_H_

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
        .just = 0, .data = (t)NULL \
    }

/**
 * @brief Creates a new 'Maybe' type
 */
#define MAYBE_TYPE(t) \
    typedef struct {  \
        int just;     \
        t data;       \
    } Maybe(t)

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
 * @brief Retrieve the data if possible
 */
#define fromJust(o, x) (isJust(o) ? x = o.data : x)

#endif  // INCLUDE_MAYBE_H_
