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
File Name: main.py
## =========================================================================== ## 
"""

# System (Default Lib.)
import sys
# Custom Script:
#   Converter (Data Conversion)
import Converter

def main():
    """
    Description:
        Simple tests to verify the functionality of individual functions to convert 
        data from the custom library.
    """

    # 1\ Test No. 1: UINT <-> BYTE[]
    #   Converting uint (16-bit -> 2-byte) to multiple bytes.
    input_var = 12345
    input_tId = 2
    res_tId_2 = Converter.Convert_Number_To_Byte_Array(input_var, input_tId)

    # Big-endian ->reverse array
    # Check result: 
    #   Converting multiple bytes to an uint (16-bit -> 2-byte).
    check_res_tId_2 = Converter.Convert_Byte_Array_To_Number(res_tId_2)

    # Compare results.
    print('[INFO] Test No. 1: UINT <-> BYTE[]')
    if input_var == check_res_tId_2:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 2\ Test No. 2: UDINT <-> BYTE[]
    #   Converting udint (32-bit -> 4-byte) to multiple bytes.
    input_var = 12345678
    input_tId = 4
    res_tId_4 = Converter.Convert_Number_To_Byte_Array(input_var, input_tId)

    # Check result: 
    #   Converting multiple bytes to an udint (32-bit -> 4-byte).
    check_res_tId_4 = Converter.Convert_Byte_Array_To_Number(res_tId_4)

    # Compare results.
    print('[INFO] Test No. 2: UDINT <-> BYTE[]')
    if input_var == check_res_tId_4:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

    # 3\ Test No. 3:  BYTE <-> BIT[]
    #   Converting byte to multiple bits.
    input_byte  = 123
    res_bit_arr = Converter.Convert_Byte_To_Bit_Array(input_byte)

    # Check result: 
    #   Converting multiple bits to byte.
    check_res = Converter.Convert_Bit_Array_To_BYTE(res_bit_arr)

    # Compare results.
    print('[INFO] Test No. 3: BYTE <-> BIT[]')
    if input_byte == check_res:
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')

if __name__ == '__main__':
    sys.exit(main())
