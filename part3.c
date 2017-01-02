#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

// Helper function
char* short_to_binary(unsigned short x);

// Write a function that determines a number
// is odd using only bitwise operators.
// Return 1 for true or 0 for false.
//
// This should only take a couple of lines.
int is_odd(int i)
{
    return i & 1;
}

// Write a function that determines the number of 1
// bits in the computers internal representation
// of a given unsigned long integer using only bitwise operators.
int count_bits(unsigned long l)
{
    int i, counter;
    counter = 0;
    for (i = 0; i < (sizeof(long) * 8); i ++)
    {
        if (is_odd(l))
        {
            counter ++;
        }
        l = l >> 1;
    }
    return counter;
}


// Write a function that takes two chars and
// 'interleaves' their bits into a short.
// Moreover, bits of x are in the even positions
// and y in the odd of the result.
// Ex. interleave_bits(1111, 0000) = 10101010
//     interleave_bits(0000, 1111) = 01010101
//     interleave_bits(0101, 1010) = 01100110
//     (fewer bits shown for clarity)
unsigned short interleave_bits(unsigned char x, unsigned char y)
{
    unsigned short z = 0;
    int i;
    unsigned char mask = 1;
    for (i = 0; i < (8 * sizeof(unsigned char)); i ++)
    {
        // builds from right and shifts left, x and y in the same iteration
        // of each loop
        z = z + ((y & mask) << i);
        z = z + ((x & mask) << i + 1);
        mask = mask << 1;
    }
    return z;
}

// You can use this function to print out the bit patterns
// for a given unsigned short. This should help in debugging.
char* short_to_binary(unsigned short x)
{
    static char b[17];
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

// feel free to write any other helper functions you require
