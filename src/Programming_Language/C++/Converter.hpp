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
File Name: Converter.hpp
****************************************************************************/

#include <iostream>
#include <vector>
// sudo apt-get install libboost-all-dev
#include <boost/range/adaptor/indexed.hpp>

namespace Converter{
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
    const uint8_t CONST_HEX_ONE = 0x01;
    // Number of bits in byte: 1 BYTE = 8 BIT
    const uint8_t CONST_HEX_EIGHT = 0x08;
    const uint8_t CONST_BYTE_MAX_VALUE = 0xff;

    template <typename T> std::vector<uint8_t> Number_To_Byte_Array(T in_num, uint8_t out_size)
    {
        /*
        Description:
            Conversion of input value (T <data_type>) into a vector of values (BYTES).

        Args:
            (1) in_num [T <data_type>]: A real number greater than or equal to zero.
            (2) out_size [USINT {Byte}]: The size of the output byte array.
                                          Identification number: 
                                            out_size = 2 (BYTEs OUT)
                                            out_size = 4 (BYTEs OUT)

        Returns:
            (1) parameter [USINT {Byte} Array]: Vector of values (BYTES).                             
                                                Note:
                                                    parameter.size() = 2 (UINT) 
                                                    parameter.size() = 4 (UDINT)
        */

        std::vector<uint8_t> out_num_arr;
        for(uint8_t i = 0; i < out_size; ++i){
            out_num_arr.push_back((in_num >> i * CONST_HEX_EIGHT) & CONST_BYTE_MAX_VALUE);
        }

        return out_num_arr;
    }

    template <typename T> T Byte_Array_To_Number(std::vector<uint8_t> in_byte_arr)
    {
        /*
        Description:
            Conversion of a vector of values (BYTES) to a value (T <data_type>).

        Args:
            (1) in_byte_arr [USINT {Byte} Array]: Vector of values (BYTES). 
                                                  Note:
                                                    parameter.size() = 2 (UINT) 
                                                    parameter.size() = 4 (UDINT)ble values range from 0 to 4294967295)

        Returns:
            (1) parameter [T <data_type>]: A real number greater than or equal to zero.
        */

        T out_num = 0;
        for (auto const& in_byte_arr_i : in_byte_arr | boost::adaptors::indexed(0)){
            out_num |= in_byte_arr_i.value() << in_byte_arr_i.index() * CONST_HEX_EIGHT;
        }

        return out_num;
    }

    std::vector<bool> Byte_To_Bit_Array(uint8_t in_byte)
    {
        /*
        Description:
            Conversion of input value (BYTE) into a vector of logical values (BITs = Booleans).
            
            Note:
                1 BYTE [0 - 255] = 8 BITs [0 - 1]

        Args:
            (1) in_byte [USINT {Byte}]: A real number greater than or equal to zero. 

        Returns:
            (1) parameter [BOOL {Bit} Array (0 .. 7)]: Vector of bits (1 BYTE).
        */

        std::vector<bool> out_bit_arr;
        for(uint8_t i = 0; i < 8; ++i){
            out_bit_arr.push_back((in_byte >> i * CONST_HEX_ONE) & CONST_HEX_ONE);
        }
    
        return out_bit_arr;
    }

    uint8_t Bit_Array_To_Byte(std::vector<bool> in_bit_array){
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

        uint8_t out_byte = 0;
        for (auto const& in_bit_arr_i : in_bit_array | boost::adaptors::indexed(0)){
            out_byte |= in_bit_arr_i.value() << in_bit_arr_i.index() * CONST_HEX_ONE;
        }

        return out_byte;
    }
}
