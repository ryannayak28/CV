#define fibbSeries(a) ({                          \
    int t1 = 0, t2 = 1, nextTerm = 0, n;          \
    printf("Enter a positive number: ");          \
    scanf("%d", &n);                              \
    printf("Fibonacci Series: %d, %d, ", t1, t2); \
    nextTerm = t1 + t2;                           \
    while (nextTerm <= n)                         \
    {                                             \
        printf("%d, ", nextTerm);                 \
        t1 = t2;                                  \
        t2 = nextTerm;                            \
        nextTerm = t1 + t2;                       \
    }                                             \
    return 0;                                     \
})
 
#define PrimeNumbers(n) ({           \
    int n, i, fact, j;               \
    printf("Enter the Number: ");    \
    scanf("%d", &n);                 \
    printf("Prime Numbers are: \n"); \
    for (i = 1; i <= n; i++)         \
    {                                \
        fact = 0;                    \
        for (j = 1; j <= n; j++)     \
        {                            \
            if (i % j == 0)          \
                fact++;              \
        }                            \
        if (fact == 2)               \
            printf("%d ", i);        \
    }                                \
    return 0;                        \
})
 
#define LeapYear(r) ({                                      \
    if (((r % 4 == 0) && (r % 100 != 0)) || (r % 400 == 0)) \
    {                                                       \
        printf("This year is a leap year");                 \
    }                                                       \
    else                                                    \
    {                                                       \
        printf("This year is not a leap year");             \
    }                                                       \
})
