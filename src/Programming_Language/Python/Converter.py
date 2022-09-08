"""
## =========================================================================== ## 
MIT License
Copyright (c) 2022 Roman Parak
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
## =========================================================================== ## 
Author   : Roman Parak
Email    : Roman.Parak@outlook.com
Github   : https://github.com/rparak
File Name: Converter.py
## =========================================================================== ## 
"""

# Numpy (Array computing Lib.) [pip3 install numpy]
import numpy as np

"""
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
"""

"""
Description:
    Initialization of constants.
"""
CONST_HEX_ZERO = 0x00
CONST_HEX_ONE  = 0x01
# Number of bits in byte: 1 BYTE = 8 BIT
CONST_HEX_EIGHT = 0x08
# Upper limit of required data types.
CONST_USINT_UPPER_LIMIT = np.iinfo(np.uint8).max
CONST_UINT_UPPER_LIMIT  = np.iinfo(np.uint16).max
CONST_UDINT_UPPER_LIMIT = np.iinfo(np.uint32).max 
# The size of the required data types in number of bytes.
CONST_UINT_SIZE  = 2
CONST_UDINT_SIZE = 4

def Convert_Number_To_Byte_Array(in_num, out_size):
    """
    Description:
        Conversion of input value (UINT/UDINT) into a vector of values (BYTES).
        
    Args:
        (1) in_num [UINT / UDINT]: A real number greater than or equal to zero.
        (2) out_size [USINT {Byte}]: The size of the output byte array.
                                     Identification number: 
                                        out_size = 2 (BYTEs OUT)
                                        out_size = 4 (BYTEs OUT)
        
    Returns:
        (1) parameter [USINT {Byte} Array (2, 4)]: Vector of values (BYTES).                                       
                                                   Note:
                                                        parameter.size = 2 (UINT) 
                                                        parameter.size = 4 (UDINT)
    """
 
    try:
        assert ((out_size == CONST_UINT_SIZE and (CONST_HEX_ZERO <= in_num <= CONST_UINT_UPPER_LIMIT)) or \
                (out_size == CONST_UDINT_SIZE and (CONST_HEX_ZERO <= in_num <= CONST_UDINT_UPPER_LIMIT)))
        
        out_num_arr = np.empty(out_size, dtype=np.uint8)
        for i in range(out_size):
            out_num_arr[i] = (in_num >> i * CONST_HEX_EIGHT) & CONST_USINT_UPPER_LIMIT
            
        return out_num_arr

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Byte_Array_To_Number(in_byte_arr):
    """
    Description:
        Conversion of a vector of values (BYTES) to a value (UINT/UDINT).
        
    Args:
        (1) in_byte_arr [USINT {Byte} Array (2, 4)]: Vector of values (BYTES). 
                                                     Note:
                                                        in_byte_arr.size = 2 (UINT)
                                                        in_byte_arr.size = 4 (UDINT)
                                                        
    Returns:
        (1) parameter [UINT / UDINT]: A real number greater than or equal to zero.                
    """
        
    try: 
        assert in_byte_arr.size == CONST_UINT_SIZE or in_byte_arr.size == CONST_UDINT_SIZE

        out_num = 0
        for i, in_byte_arr_i in enumerate(in_byte_arr):
            out_num |= in_byte_arr_i << i * CONST_HEX_EIGHT
            
        return out_num

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Byte_To_Bit_Array(in_byte):
    """
    Description:
        Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
        
        Note:
            1 BYTE [0 - 255] = 8 BITs [0 - 1]
    Args:
        (1) in_byte [USINT {Byte}]: A real number greater than or equal to zero. 
    
    Returns:
        (1) parameter [BOOL {Bit} Array (0 .. 7)]: Vector of bits (1 BYTE).
    """
        
    try: 
        assert CONST_HEX_ZERO <= in_byte <= CONST_USINT_UPPER_LIMIT

        out_bit_arr = np.empty(CONST_HEX_EIGHT, dtype=np.bool_)
        for i in range(out_bit_arr.size):
            out_bit_arr[i] = (in_byte >> i * CONST_HEX_ONE) & CONST_HEX_ONE 

        return out_bit_arr

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Bit_Array_To_BYTE(in_bit_arr):
    """
    Description:
        Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).

        Note:
            8 BITs [0 - 1] = 1 BYTE [0 - 255]
        
    Args:
        (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Vector of bits (1 BYTE).
        
    Returns:
        (1) parameter [USINT {Byte}]: A real number greater than or equal to zero. 
    """

    try: 
        assert in_bit_arr.size == CONST_HEX_EIGHT

        out_byte = 0
        for i, in_bit_arr_i in enumerate(in_bit_arr):
            out_byte |= in_bit_arr_i << i * CONST_HEX_ONE

        return out_byte

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')