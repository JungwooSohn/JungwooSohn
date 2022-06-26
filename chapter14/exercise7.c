#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

typedef unsigned long u_long;




long long_max(long x, long y)
{
    return x > y ? x : y;
}

