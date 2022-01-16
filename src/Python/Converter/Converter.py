"""
## =========================================================================== ## 
MIT License
Copyright (c) 2020 Roman Parak
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

# System (Default Lib.)
import sys

# Numpy (Array computing Lib.) [pip3 install numpy]
import numpy as np

"""
Description:
    A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 
"""
NUM_OF_VALUES_IN_BYTE = 256
NUM_OF_BIT_IN_BYTE    = 8

"""
Notes:
    USINT: Unsigned (short) INT  [0, 255]
    UINT : Unsigned INT          [0, 65535]
    UDINT: Unsigned (double) INT [0, 4294967295]
"""
BOOL_UPPER_LIMIT      = 1
USINT_UPPER_LIMIT     = 255
UINT_UPPER_LIMIT      = 65535
UDINT_UPPER_LIMIT     = 4294967295
DATA_TYPE_LOWER_LIMIT = 0

def convert_num_to_multiple_bytes(in_num, type_id):
    """
    Description:
        Function for for converting uint/udint (16-bit -> 2-byte / 32-bit -> 4-byte) to multiple bytes.
        
    Args:
        (1) in_num [UINT / UDINT]: Input number (2 -> possible values range from 0 to 65535 / 4 BYTEs -> possible values range from 0 to 4294967295).
        (2) type_id [USINT {Byte}]: Type of calculation. Identification number: 2 -> 2 BYTEs OUT, 4 -> BYTEs OUT
        
    Returns:
        (1) out [USINT {Byte} Array (2, 4)]: Output multiple numbers. Possible values range from 0 to 255 in each array index.
    """
 
    try:
        assert type_id == 2 or type_id == 4
        assert (type_id == 2 and (in_num >= DATA_TYPE_LOWER_LIMIT and in_num <= UINT_UPPER_LIMIT)) or (type_id == 4 and (in_num >= DATA_TYPE_LOWER_LIMIT and in_num <= UDINT_UPPER_LIMIT))

        # Create aux. variable
        aux_var = int(in_num/NUM_OF_VALUES_IN_BYTE)

        out = np.zeros(type_id)
        # Initialize the first index of the output array
        out[0] = int(in_num) % NUM_OF_VALUES_IN_BYTE
        
        for i in range(1, type_id):
            out[i]   = int(aux_var) % NUM_OF_VALUES_IN_BYTE
            aux_var /= NUM_OF_VALUES_IN_BYTE
        
        return out

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')

def convert_multiple_bytes_to_num(in_byte_arr):
    """
    Description:
        Function for converting multiple bytes to an uint/udint (16-bit -> 2-byte / 32-bit -> 4-byte).
        
    Args:
        (1) in_byte_arr [USINT {Byte} Array (2, 4)]: Input multiple numbers. Possible values range from 0 to 255 in each array index.
        
    Returns:
        (1) out [UINT / UDINT]: Output number (2 -> possible values range from 0 to 65535 / 4 BYTEs -> possible values range from 0 to 4294967295).
    """
        
    try: 
        assert len(in_byte_arr) == 2 or len(in_byte_arr) == 4

        for _, value in enumerate(in_byte_arr):
            if value > USINT_UPPER_LIMIT or value < DATA_TYPE_LOWER_LIMIT:
                assert False

        out = 0

        for i, value in enumerate(in_byte_arr):
            out += value*(NUM_OF_VALUES_IN_BYTE**i)
            
        return out

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')

def convert_byte_to_multiple_bits(in_byte):
    """
    Description:
        Function for for converting byte to multiple bits.
        
    Args:
        (1) in_byte [USINT {Byte}]: Input number (BYTE -> possible values range from 0 to 255). 
        
    Returns:
        (1) out [BOOL {Bit} Array (0 .. 7)]: Output multiple bits (1 BYTE).
    """
        
    try: 
        assert in_byte >= DATA_TYPE_LOWER_LIMIT and in_byte <= USINT_UPPER_LIMIT

        # Create aux. variable
        aux_byte = in_byte
        
        # Convert decimal number (BYTE) to multiple Booleans (BITs)
        # Note: 1 BYTE [0 - 255] = 8 BITs [0 - 1]
        out = np.zeros(NUM_OF_BIT_IN_BYTE)

        for i in range(NUM_OF_BIT_IN_BYTE):
            if aux_byte > 0:
                out[i]   = aux_byte % 2
                aux_byte = int(aux_byte / 2)
            else:
                out[i] = 0

        return out

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')

def convert_multiple_bits_to_byte(in_bit):
    """
    Description:
        Function for converting multiple bits to byte.
        
    Args:
        (1) in_bit [BOOL {Bit} Array (0 .. 7)]: Input multiple bits (1 BYTE).
        
    Returns:
        (1) out [USINT {Byte}]: Output number (BYTE -> possible values range from 0 to 255). 
    """
    try: 
        assert len(in_bit) == NUM_OF_BIT_IN_BYTE

        for _, value in enumerate(in_bit):
            if value > BOOL_UPPER_LIMIT or value < DATA_TYPE_LOWER_LIMIT:
                assert False

        # Convert multiple Booleans (BITs) to decimal number (BYTE)
        # Note: 8 BITs [0 - 1] = 1 BYTE [0 - 255]
        out = 0

        for i, value in enumerate(in_bit):
            if value == BOOL_UPPER_LIMIT:
                out += 2**i

        return out

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')

def main():
    """
    Description:
        Simple tests of designed functions for data conversions.
    """

    # 1\ Test No. 1: UINT <-> BYTE[]
    # Converting uint (16-bit -> 2-byte) to multiple bytes.
    input_var = 12345
    input_tId = 2
    res_tId_2 = convert_num_to_multiple_bytes(input_var, input_tId)

    # Check result: Converting multiple bytes to an uint (16-bit -> 2-byte).
    check_res_tId_2 = convert_multiple_bytes_to_num(res_tId_2)

    # Compare results
    print('[INFO] Test No. 1: UINT <-> BYTE[]')
    if input_var == check_res_tId_2:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 2\ Test No. 2: UDINT <-> BYTE[]
    # Converting udint (32-bit -> 4-byte) to multiple bytes.
    input_var = 12345678
    input_tId = 4
    res_tId_4 = convert_num_to_multiple_bytes(input_var, input_tId)

    # Check result: Converting multiple bytes to an udint (32-bit -> 4-byte).
    check_res_tId_4 = convert_multiple_bytes_to_num(res_tId_4)

    # Compare results
    print('[INFO] Test No. 2: UDINT <-> BYTE[]')
    if input_var == check_res_tId_4:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 3\ Test No. 3:  BYTE <-> BIT[]
    # Converting byte to multiple bits.
    input_byte = 123
    res_bit_arr = convert_byte_to_multiple_bits(input_byte)

    # Check result: Converting multiple bits to byte.
    check_res = convert_multiple_bits_to_byte(res_bit_arr)

    # Compare results
    print('[INFO] Test No. 3: BYTE <-> BIT[]')
    if input_byte == check_res:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

if __name__ == '__main__':
    sys.exit(main())


