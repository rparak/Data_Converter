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
File Name: Converter.cs
****************************************************************************/

// System Lib.
using System;
using System.Linq;
using System.Collections.Generic;

namespace DataConverter
{
    /*
        Description:
            Library to converts base data types to an array of bytes, and an array of bytes to base data types as well as 
            byte to an array of bits, and an array of bits to byte.

        Note 1: 
            A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 

        Note 2:
            BOOL (Bit)  : Boolean               [0, 1]          | 1-bit
            USINT (Byte): Unsigned char         [0, 255]        | 8-bit 
            UINT        : Unsigned INT          [0, 65535]      | 16-bit
            UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit

        Note 3:
            Bitwise Operators:
                &	Bitwise AND
                |	Bitwise OR
                <<	Shift left
                >>	Shift right
     */

    public static class Core
    {
        public static byte[] NumberToByteArray<T>(T in_num, byte out_size)
        {
            /*
                Description:
                    Conversion of input value (T <data_type>) into a vector of values (BYTES).

                Args:
                    (1) in_num [T <data_type>]: Input number.
                    (2) out_size [USINT {Byte}]: The size of the output byte array.

                                                 Identification number: 
                                                    out_size = 2 (BYTEs OUT)
                                                    out_size = 4 (BYTEs OUT)

                Returns:
                    (1) parameter [USINT {Byte} Array]: Vector of values (BYTES). Possible values range from 0 to 255 in each array index.
                                                
                                                        Note:
                                                            parameter.Length = 2 -> UINT (possible values range from 0 to 65535)
                                                            parameter.Length = 4 -> UDINT (possible values range from 0 to 4294967295)
             */

            dynamic in_num_dynamic = in_num;

            byte[] out_num_arr = new byte[out_size];
            for (byte i = 0; i < out_size; ++i)
            {
                out_num_arr[i] = (byte)((in_num_dynamic >> i * 0x08) & 0xff);
            }

            return out_num_arr;
        }

        public static T ByteArrayToNumber<T>(byte[] in_byte_arr)
        {
            /*
                Description:
                    Conversion of a vector of values (BYTES) to a value (T <data_type>).

                Args:
                    (1) in_byte_arr [USINT {Byte} Array]: Input multiple numbers. Possible values range from 0 to 255 in each array index.
                                                    
                                                    Note:
                                                        in_byte_arr.Length = 2 -> UINT (possible values range from 0 to 65535)
                                                        in_byte_arr.Length = 4 -> UDINT (possible values range from 0 to 4294967295)

                Returns:
                    (1) parameter [T <data_type>]: Output number.
             */

            dynamic out_num_dynamic = (T)Convert.ChangeType(0 | in_byte_arr[0] << 0 * 0x08, typeof(T));

            // Start from index 1, as the first index is already calculated.
            //  Note: arr.Skip(1)
            foreach (var (in_byte_arr_i, i) in in_byte_arr.Skip(1).Select((in_byte_arr_i, i) => (in_byte_arr_i, i)))
            {
                out_num_dynamic |= (T)Convert.ChangeType(in_byte_arr_i << (i + 0x01) * 0x08, typeof(T));
            }

            return (T)out_num_dynamic;
        }

        public static bool[] ByteToBitArray(byte in_byte)
        {
            /*
                Description:
                    Conversion of input value (BYTE) into a vector of logical values (BITs = Booleans).
                    
                    Note:
                        1 BYTE [0 - 255] = 8 BITs [0 - 1]

                Args:
                    (1) in_byte [USINT {Byte}]: Input number (BYTE -> possible values range from 0 to 255). 

                Returns:
                    (1) parameter [BOOL {Bit} Array (0 .. 7)]: Output multiple bits (1 BYTE).
             */

            bool[] out_bit_arr = new bool[CONST_NUM_OF_BIT_IN_BYTE];
            for (byte i = 0; i < out_bit_arr.Length; ++i)
            {
                out_bit_arr[i] = (1 == ((in_byte >> i * 0x01) & 0x01));
            }

            return out_bit_arr;
        }

        public static byte BitArrayToByte(bool[] in_bit_arr)
        {
            /*
                Description:
                    Conversion of a vector of logical values (BITS = Booleans) to a value (BYTE).

                    Note:
                        8 BITs [0 - 1] = 1 BYTE [0 - 255]

                Args:
                    (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Input multiple bits (1 BYTE). 

                Returns:
                    (1) parameter [USINT {Byte}]: Output number (BYTE -> possible values range from 0 to 255)..
             */

            byte out_byte = 0;
            foreach (var (in_bit_arr_i, i) in in_bit_arr.Select((in_bit_arr_i, i) => (in_bit_arr_i, i)))
            {
                out_byte |= (in_bit_arr_i == true ? (byte)(1 << i * 0x01) : out_byte);
            }

            return out_byte;
        }
    }
}