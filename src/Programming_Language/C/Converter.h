/****************************************************************************
MIT License
Copyright(c) 2022 Roman Parak
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************
Author   : Roman Parak
Email    : Roman.Parak @outlook.com
Github   : https://github.com/rparak
File Name: Converter.h
****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

/*
Description:
    Library to converts base data types to an array of bytes, and an array of bytes to base data types as well as 
    byte to an array of bits, and an array of bits to byte.

Note 1: 
    A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 

Note 2:
    BOOL (Bit)  : Boolean               [0, 1]          | 1-bit  | 0-Byte |
    USINT (Byte): Unsigned char         [0, 255]        | 8-bit  | 1-Byte |
    UINT        : Unsigned INT          [0, 65535]      | 16-bit | 2-Byte |
    UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit | 4-Byte |

Note 3:
    Bitwise Operators:
        &	Bitwise AND
        |	Bitwise OR
        <<	Shift left
        >>	Shift right
*/


/*
Description:
    Initialization of constants.
*/
const unsigned char CONST_BYTE_ONE = 0x01;
// Number of bits in byte: 1 BYTE = 8 BIT
const unsigned char CONST_BYTE_EIGHT = 0x08;
const unsigned char CONST_BYTE_MAX_VALUE = 0xff;
// Macro (Utilities).
#define Arr_Length(x) (sizeof(x) / sizeof((x)[0]))

unsigned char* Convert_Number_To_Byte_Array(unsigned int in_num, unsigned char out_size)
{
    /*
    Description:
        Conversion of input value (UINT/UDINT) into a vector of values (BYTES).

    Args:
        (1) in_num [UINT]: A real number greater than or equal to zero.
        (2) out_size [USINT {Byte}]: The size of the output byte array.
                                     Identification number: 
                                        out_size = 2 (BYTEs OUT)
                                        out_size = 4 (BYTEs OUT)

    Returns:
        (1) parameter [USINT {Byte} Array]: Vector of values (BYTES). Possible values range from 0 to 255 in each array index.
                                            Note:
                                                sizeof(parameter)/sizeof(parameter[0]) = 2 (UINT)
                                                sizeof(parameter)/sizeof(parameter[0]) = 4 (UDINT)
    */
   
    static unsigned char* out_num_arr = (unsigned char*)malloc(sizeof(unsigned char) * out_size);
    for(unsigned char i = 0; i < out_size; ++i){
        out_num_arr[i] = (in_num >> i * CONST_BYTE_EIGHT) & CONST_BYTE_MAX_VALUE;
    }

    return out_num_arr;
}

unsigned int Convert_Byte_Array_To_Number(unsigned char* in_byte_arr)
{
    /*
    Description:
        Conversion of a vector of values (BYTES) to a value (UINT/UDINT).
        
    Args:
        (1) in_byte_arr [USINT {Byte} Array (2, 4)]: Vector of bytes.
                                                     Note:
                                                        sizeof(parameter)/sizeof(parameter[0]) = 2 (UINT)
                                                        sizeof(parameter)/sizeof(parameter[0]) = 4 (UDINT)
                                                        
    Returns:
        (1) parameter [UINT]: A real number greater than or equal to zero.  
     */

    unsigned int out_num = 0;
    for (unsigned char i = 0; i < Arr_Length(in_byte_arr); ++i){
        out_num |= in_byte_arr[i] << i * CONST_BYTE_EIGHT;
    }

    return out_num;
}

bool* Convert_Byte_To_Bit_Array(unsigned short in_byte){
    /*
    Description:
        Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
        
        Note:
            1 BYTE [0 - 255] = 8 BITs [0 - 1]
    Args:
        (1) in_byte [USINT {Byte}]: A real number greater than or equal to zero. 
    
    Returns:
        (1) parameter [BOOL {Bit} Array (0 .. 7)]: Vector of bits (1 BYTE).
     */

    static bool out_bit_arr[CONST_BYTE_EIGHT];
    for(unsigned char i = 0; i < Arr_Length(out_bit_arr); ++i){
        out_bit_arr[i] = (in_byte >> i * CONST_BYTE_ONE) & CONST_BYTE_ONE;
    }
 
    return out_bit_arr;
}

unsigned short Convert_Bit_Array_To_Byte(bool* in_bit_array){
    /*
    Description:
        Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).

        Note:
            8 BITs [0 - 1] = 1 BYTE [0 - 255]
        
    Args:
        (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Vector of bits (1 BYTE).
        
    Returns:
        (1) parameter [USINT {Byte}]: A real number greater than or equal to zero. 
     */

    unsigned short out_byte = 0;
    for (unsigned char i = 0; i < Arr_Length(in_bit_array); ++i){
        out_byte |= in_bit_array[i] << i * CONST_BYTE_ONE;
    }

    return out_byte;
}