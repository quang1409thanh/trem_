
#include <stdio.h>
#include <time.h> // Include time.h for logging

// 1. Object-like Macro
#define PI 3.14

// 2. Function-like Macro
#define SQUARE(x) ((x) * (x))

#define MAX_LENGTH 100
#define FLOWS MAX_LENGTH

// 3. Macro Arguments
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// 4. Stringizing
#define TO_STRING(x) #x

// 5. Concatenation
#define CONCAT(a, b) a##b

// 6. Variadic Macro
#define PRINTF(format, ...) printf(format, __VA_ARGS__)

// 7. Predefined Macros
#define DEBUG() printf("File: %s, Line: %d, Date: %s, Time: %s\n", __FILE__, __LINE__, __DATE__, __TIME__)

// 8. Undefining and Redefining Macros
#define TEMP 100
#undef TEMP
#define TEMP 200

#define MY_INT int
#define YOUR_INT MY_INT

struct TEST1
{
    int a;
    TEST1(int a) : a(a) {}
};

#define MY_TEST TEST1

// 9. Directives Within Macro Arguments
#define CHECK_POSITIVE(x)                     \
    do                                        \
    {                                         \
        if ((x) > 0)                          \
        {                                     \
            printf(#x " is positive.\n");     \
        }                                     \
        else                                  \
        {                                     \
            printf(#x " is not positive.\n"); \
        }                                     \
    } while (0)

// 10. Multi-line Macros
// Logging with Timestamp
#define LOG(message)                              \
    do                                            \
    {                                             \
        time_t now = time(NULL);                  \
        char *timestamp = ctime(&now);            \
        printf("[%s]: %s\n", timestamp, message); \
    } while (0)

// Array Initialization
#define INIT_ARRAY(arr, size, value)   \
    do                                 \
    {                                  \
        for (int i = 0; i < size; ++i) \
        {                              \
            arr[i] = value;            \
        }                              \
    } while (0)

// Debugging Condition
#define DEBUG_IF(condition, message)        \
    do                                      \
    {                                       \
        if (condition)                      \
        {                                   \
            printf("DEBUG: %s\n", message); \
        }                                   \
    } while (0)

void unitest1(int x)
{
    if (SQUARE(x) == 10)
    {
        printf("x is equal to 10\n");
    }
    else if (SQUARE(x) > 10)
    {
        printf("x is greater than 10\n");
    }
    else
    {
        printf("x is not equal to 10\n");
    }
}

void test_logging_and_initialization()
{
    LOG("Starting unit tests...");

    int myArray[5];
    INIT_ARRAY(myArray, 5, 0); // Initialize myArray with 0

    // Check the array initialization
    for (int i = 0; i < 5; ++i)
    {
        if (myArray[i] != 0)
        {
            LOG("Array initialization failed!");
            return;
        }
    }

    LOG("Array initialized successfully!");
    DEBUG_IF(myArray[0] == 0, "First element is zero.");
}

int main()
{
    // Example usage of macros
    printf("Value of PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));
    printf("Max of 10 and 20: %d\n", MAX(10, 20));
    CHECK_POSITIVE(10);
    CHECK_POSITIVE(-5);

    // Run the test
    test_logging_and_initialization();

    return 0;
}
