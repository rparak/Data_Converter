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
CONST_NUM_OF_VALUES_IN_BYTE = 256
CONST_NUM_OF_BIT_IN_BYTE    = 8
CONST_DATA_TYPE_LOWER_LIMIT = 0

"""
Notes:
    USINT: Unsigned (short) INT  [0, 255]
    UINT : Unsigned INT          [0, 65535]
    UDINT: Unsigned (double) INT [0, 4294967295]
"""
CONST_BOOL_UPPER_LIMIT      = 1
CONST_USINT_UPPER_LIMIT     = np.iinfo(np.uint8).max 
CONST_UINT_UPPER_LIMIT      = np.iinfo(np.uint16).max 
CONST_UDINT_UPPER_LIMIT     = np.iinfo(np.uint32).max 

def Convert_NUM_To_Multiple_BYTES(in_num, type_id):
    """
    Description:
        Conversion of input value (UINT/UDINT) into a vector of values (BYTES).

        Note:
            UINT: 16-bit -> 2-byte
            UDINT: 32-bit -> 4-byte
        
    Args:
        (1) in_num [UINT / UDINT]: Input number (2 -> possible values range from 0 to 65535 / 4 BYTEs -> possible values range from 0 to 4294967295).
        (2) type_id [USINT {Byte}]: Type of calculation. 
                                    Identification number: 2 -> 2 BYTEs OUT, 4 -> BYTEs OUT
        
    Returns:
        (1) parameter [USINT {Byte} Array (2, 4)]: Vector of values (BYTES). Possible values range from 0 to 255 in each array index.
    """
 
    try:
        assert type_id == 2 or type_id == 4
        assert ((type_id == 2 and (CONST_DATA_TYPE_LOWER_LIMIT <= in_num <= CONST_UINT_UPPER_LIMIT)) or \
                (type_id == 4 and (CONST_DATA_TYPE_LOWER_LIMIT <= in_num <= CONST_UDINT_UPPER_LIMIT)))

        # Create aux. variable.
        aux_var = int(in_num/CONST_NUM_OF_VALUES_IN_BYTE)

        out_num_arr = np.zeros(type_id, dtype = np.uint8)
        # Calculate the first index of the output array.
        out_num_arr[0] = int(in_num) % CONST_NUM_OF_VALUES_IN_BYTE
        
        for i in range(1, type_id):
            out_num_arr[i] = int(aux_var) % CONST_NUM_OF_VALUES_IN_BYTE
            aux_var /= CONST_NUM_OF_VALUES_IN_BYTE
        
        return out_num_arr

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
            if CONST_DATA_TYPE_LOWER_LIMIT > in_byte_arr_i > CONST_USINT_UPPER_LIMIT:
                assert False

            out_num += in_byte_arr_i * (CONST_NUM_OF_VALUES_IN_BYTE**i)
            
        return out_num

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_BYTE_To_Multiple_BITS(in_byte):
    """
    Description:
        Conversion of input value (BYTE) into a vector of logical values (BITS).
        
    Args:
        (1) in_byte [USINT {Byte}]: Input number (BYTE -> possible values range from 0 to 255). 
        
    Returns:
        (1) parameter [BOOL {Bit} Array (0 .. 7)]: Output multiple bits (1 BYTE).
    """
        
    try: 
        assert CONST_DATA_TYPE_LOWER_LIMIT <= in_byte <= CONST_USINT_UPPER_LIMIT

        # Create aux. variable
        aux_byte = in_byte
        
        # Convert decimal number (BYTE) to multiple Booleans (BITs).
        # Note: 1 BYTE [0 - 255] = 8 BITs [0 - 1]
        out_bit_arr = np.zeros(CONST_NUM_OF_BIT_IN_BYTE, dtype=np.bool_)
        
        for i in range(CONST_NUM_OF_BIT_IN_BYTE):
            out_bit_arr[i] = aux_byte % 2
            aux_byte = int(aux_byte / 2)

        return out_bit_arr

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def Convert_Multiple_BITS_To_BYTE(in_bit_arr):
    """
    Description:
        Conversion of a vector of logical values (BITS) to a value (BYTE).
        
    Args:
        (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Input multiple bits (1 BYTE).
        
    Returns:
        (1) parameter [USINT {Byte}]: Output number (BYTE -> possible values range from 0 to 255). 
    """

    try: 
        assert in_bit_arr.size == CONST_NUM_OF_BIT_IN_BYTE

        # Convert multiple Booleans (BITs) to decimal number (BYTE)
        # Note: 8 BITs [0 - 1] = 1 BYTE [0 - 255]
        out_byte = 0

        for i, in_bit_arr_i in enumerate(in_bit_arr):
            if CONST_DATA_TYPE_LOWER_LIMIT < in_bit_arr_i < CONST_BOOL_UPPER_LIMIT:
                assert False

            out_byte += 2**i if in_bit_arr_i == CONST_BOOL_UPPER_LIMIT else CONST_DATA_TYPE_LOWER_LIMIT

        return out_byte

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def main():
    """
    Description:
        Simple tests of designed functions for data conversions.
    """

    # 1\ Test No. 1: UINT <-> BYTE[]
    #   Converting uint (16-bit -> 2-byte) to multiple bytes.
    input_var = 12345
    input_tId = 2
    res_tId_2 = Convert_NUM_To_Multiple_BYTES(input_var, input_tId)

    # Check result: 
    #   Converting multiple bytes to an uint (16-bit -> 2-byte).
    check_res_tId_2 = Convert_Multiple_BYTES_To_NUM(res_tId_2)

    # Compare results
    print('[INFO] Test No. 1: UINT <-> BYTE[]')
    if input_var == check_res_tId_2:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 2\ Test No. 2: UDINT <-> BYTE[]
    #   Converting udint (32-bit -> 4-byte) to multiple bytes.
    input_var = 12345678
    input_tId = 4
    res_tId_4 = Convert_NUM_To_Multiple_BYTES(input_var, input_tId)

    # Check result: 
    #   Converting multiple bytes to an udint (32-bit -> 4-byte).
    check_res_tId_4 = Convert_Multiple_BYTES_To_NUM(res_tId_4)

    # Compare results
    print('[INFO] Test No. 2: UDINT <-> BYTE[]')
    if input_var == check_res_tId_4:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 3\ Test No. 3:  BYTE <-> BIT[]
    #   Converting byte to multiple bits.
    input_byte  = 123
    res_bit_arr = Convert_BYTE_To_Multiple_BITS(input_byte)

    # Check result: 
    #   Converting multiple bits to byte.
    check_res = Convert_Multiple_BITS_To_BYTE(res_bit_arr)

    # Compare results
    print('[INFO] Test No. 3: BYTE <-> BIT[]')
    if input_byte == check_res:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

if __name__ == '__main__':
    sys.exit(main())
