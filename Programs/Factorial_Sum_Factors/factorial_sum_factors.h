#define factorial(n) ({                    \
    int i, f = 1;                          \
    for (i = 1; i <= n; i++)               \
    {                                      \
        f = f * i;                         \
    }                                      \
    printf("Factorial of %d is %d", n, f); \
})

#define sumof(n) ({                                        \
    int i, sum = 0;                                        \
    for (i = 0; i <= n; i++)                               \
    {                                                      \
        sum = sum + i;                                     \
    }                                                      \
    printf("Sum of Natural Numbers till %d = %d", n, sum); \
})
 
#define factors(n) ({         \
    int i;                    \
    for (i = 1; i <= n; ++i)  \
    {                         \
        if (n % i == 0)       \
        {                     \
            printf("%d ", i); \
        }                     \
    }                         \
})
