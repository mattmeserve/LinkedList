#include <stdio.h>
#include <assert.h>
#include <math.h>

// Extract the 8-bit exponent field of single precision
// floating point number f and return it as an unsigned byte
unsigned char get_exponent_field(float f)
{
    unsigned int* int_float;
    // overlay int_float on float and shift exponent to least significant bits
    int_float = (unsigned int*) &f;
    *int_float = *int_float >> 23;
    unsigned int mask = 1;
    unsigned char ret = 0;
    int i;
    for (i = 0; i < 8; i ++)
    {
        ret = ret + (*int_float & mask);
        mask = mask << 1;
    }
    return ret;
}

// Clear the most significant b bits of unsigned integer number
// and return the resulting value.
// As an example, suppose
//   unsigned int number = 0xffff0000;
//   int b = 15;
// then the correct return value is 65536
// if b = 30, then the return value is 0
// if b = 40, the return value should also be 0
unsigned int clear_msb(unsigned int number, int b)
{
    // mask will always be all 1's, and the number of 1's is 32 (size of int)
    // minus the number of bits you want cleared minus 1
    unsigned int mask = (pow(2, 32 - b)) - 1;
    return mask & number;
}

// Given an array of bytes whose length is array_size (bytes), treat it as a bitmap (i.e. an array of bits),
// and return the bit value at index i (from the left) of the bitmap.
//
// As an example, suppose char array[3] = {0x00, 0x1f, 0x12}, the corresponding
// bitmap is 0x001f12, thus,
// the bit at index 0 is bitmap[0] = 0
// the bit at index 1 is bitmap[1] = 0
// ...
// the bit at index 11 is bitmap[11] = 1
// the bit at index 12 is bitmap[12] = 1
// ...
// the bit at index 16 is bitmap[16] = 0
// ...
unsigned char bit_at_index(unsigned char *array, int array_size, int i)
{
    // index is the element of the array containing the bit
    unsigned int index = i / 8;
    // create mask to isolate desired bit
    unsigned char mask = pow(2, 7 - (i % 8));
    // right shift bit to least significant bit
    return ((unsigned char) array[index] & mask) >> (7 - (i % 8));
}