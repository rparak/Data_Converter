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
        USINT: Unsigned (short) INT  [0, 255]
        UINT : Unsigned INT          [0, 65535]
        UDINT: Unsigned (double) INT [0, 4294967295]
"""
CONST_ZERO = 0x00
CONST_USINT_UPPER_LIMIT = np.iinfo(np.uint8).max
CONST_UINT_UPPER_LIMIT  = np.iinfo(np.uint16).max 
CONST_UDINT_UPPER_LIMIT = np.iinfo(np.uint32).max 

def Convert_NUM_To_Multiple_BYTES(in_num, out_size):
    """
    Description:
        Conversion of input value (UINT/UDINT) into a vector of values (BYTES).

        Note:
            UINT: 16-bit -> 2-byte
            UDINT: 32-bit -> 4-byte
        
    Args:
        (1) in_num [UINT / UDINT]: Input number (2 -> possible values range from 0 to 65535 / 4 BYTEs -> possible values range from 0 to 4294967295).
        (2) out_size [USINT {Byte}]: The size of the output byte array.

                                     Identification number: 
                                        2 -> 2 BYTEs OUT, 4 -> BYTEs OUT
        
    Returns:
        (1) parameter [USINT {Byte} Array (2, 4)]: Vector of values (BYTES). Possible values range from 0 to 255 in each array index.
    """
 
    try:
        assert ((out_size == 2 and (0x00 <= in_num <= CONST_UINT_UPPER_LIMIT)) or \
                (out_size == 4 and (0x00 <= in_num <= CONST_UDINT_UPPER_LIMIT)))
        
        out_num_arr = np.empty(out_size, dtype=np.uint8)
        for i in range(out_size):
            out_num_arr[i] = (in_num >> i * 0x08) & 0xff
            
        return out_num_arr

        #return np.array([(in_num >> i * 0x08) & 0xff for i in range(type_id)], dtype=np.uint8)

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Multiple_BYTES_To_NUM(in_byte_arr):
    """
    Description:
        Conversion of a vector of values (BYTES) to a value (UINT/UDINT).

        Note:
            UINT: 16-bit -> 2-byte
            UDINT: 32-bit -> 4-byte
        
    Args:
        (1) in_byte_arr [USINT {Byte} Array (2, 4)]: Input multiple numbers. Possible values range from 0 to 255 in each array index.
        
    Returns:
        (1) parameter [UINT / UDINT]: Output number (2 -> possible values range from 0 to 65535 / 4 BYTEs -> possible values range from 0 to 4294967295).
    """
        
    try: 
        assert in_byte_arr.size == 2 or in_byte_arr.size == 4

        out_num = 0
        for i, in_byte_arr_i in enumerate(in_byte_arr):
            out_num |= in_byte_arr_i << i * 0x08
            
        return out_num

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_BYTE_To_Multiple_BITS(in_byte):
    """
    Description:
        Conversion of input value (BYTE) into a vector of logical values (BITS = Booleans).
        
        Note:
            1 BYTE [0 - 255] = 8 BITs [0 - 1]
    Args:
        (1) in_byte [USINT {Byte}]: Input number (BYTE -> possible values range from 0 to 255). 
        
    Returns:
        (1) parameter [BOOL {Bit} Array (0 .. 7)]: Output multiple bits (1 BYTE).
    """
        
    try: 
        assert CONST_ZERO <= in_byte <= CONST_USINT_UPPER_LIMIT

        out_bit_arr = np.empty(8, dtype=np.bool_)
        for i in range(8):
            out_bit_arr[i] = (in_byte >> i * 0x01) & 0x01 

        return out_bit_arr

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Multiple_BITS_To_BYTE(in_bit_arr):
    """
    Description:
        Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).

        Note:
            8 BITs [0 - 1] = 1 BYTE [0 - 255]
        
    Args:
        (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Input multiple bits (1 BYTE).
        
    Returns:
        (1) parameter [USINT {Byte}]: Output number (BYTE -> possible values range from 0 to 255). 
    """

    try: 
        assert in_bit_arr.size == 0x08

        out_byte = 0
        for i, in_bit_arr_i in enumerate(in_bit_arr):
            out_byte |= in_bit_arr_i << i * 0x01

        return out_byte

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')