// Copyright 2018 Sascha Grunert

#ifndef INCLUDE_EITHER_H_
#define INCLUDE_EITHER_H_

/**
 * @brief The 'Either' type declaration
 */
#define Either(a, b) either_##a##_##b##_type

/**
 * @brief The 'Left' type declaration
 */
#define Left(a, b, d)                                  \
    (Either(a, b)) {                                   \
        .left = 1, .leftData = d, .rightData = (b)NULL \
    }

/**
 * @brief The 'Right' type declaration
 */
#define Right(a, b, d)                                 \
    (Either(a, b)) {                                   \
        .left = 0, .leftData = (a)NULL, .rightData = d \
    }

/**
 * @brief Creates a new 'Either' type
 */
#define EITHER_TYPE(a, b) \
    typedef struct {      \
        int left;         \
        a leftData;       \
        b rightData;      \
    } Either(a, b)

/**
 * @brief Creates a new named 'Either'
 */
#define EITHER(a, b, c, d) \
    typedef a b;           \
    typedef c d;           \
    EITHER_TYPE(b, d)

/**
 * @brief Check if the Either contains Left data
 */
#define isLeft(o) ((o).left)

/**
 * @brief Check if the Either contains Right data
 */
#define isRight(o) (!isLeft(o))

/**
 * @brief Retrieve the Left data if possible
 */
#define fromLeft(o, x) (isLeft(o) ? x = o.leftData : x)

/**
 * @brief Retrieve the Right data if possible
 */
#define fromRight(o, x) (isRight(o) ? x = o.rightData : x)

#endif  // INCLUDE_EITHER_H_
