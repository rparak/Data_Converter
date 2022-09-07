#include <iostream>
#include <vector>
// sudo apt-get install libboost-all-dev
#include <boost/range/adaptor/indexed.hpp>
#include <chrono>

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

template <typename T> std::vector<uint8_t> Number_To_Byte_Array(T in_num, uint8_t out_size)
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
    
    Fastest Way:
            out_num_arr.push_back((in_num >> 0x00) & 0xff);
            out_num_arr.push_back((in_num >> 0x08) & 0xff);

    Returns:
        (1) parameter [USINT {Byte} Array]: Vector of values (BYTES). Possible values range from 0 to 255 in each array index.
                                    
                                            Note:
                                                parameter.Length = 2 -> UINT (possible values range from 0 to 65535)
                                                parameter.Length = 4 -> UDINT (possible values range from 0 to 4294967295)
    */

    std::vector<uint8_t> out_num_arr;
    for(uint8_t i = 0; i < out_size; ++i){
        out_num_arr.push_back((in_num >> i * 0x08) & 0xff);
    }

    return out_num_arr;
}

template <typename T> T Byte_Array_To_Number(std::vector<uint8_t> in_byte_arr)
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

    T out_num = 0;
    for (auto const& in_byte_arr_i : in_byte_arr | boost::adaptors::indexed(0)){
        out_num |= in_byte_arr_i.value() << in_byte_arr_i.index() * 0x08;
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
        (1) in_byte [USINT {Byte}]: Input number (BYTE -> possible values range from 0 to 255). 

    Returns:
        (1) parameter [BOOL {Bit} Array (0 .. 7)]: Output multiple bits (1 BYTE).
    */

    std::vector<bool> out_bit_arr;
    for(uint8_t i = 0; i < 8; ++i){
        out_bit_arr.push_back((in_byte >> i * 0x01) & 0x01);
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
        (1) in_bit_arr [BOOL {Bit} Array (0 .. 7)]: Input multiple bits (1 BYTE). 

    Returns:
        (1) parameter [USINT {Byte}]: Output number (BYTE -> possible values range from 0 to 255).
    */

    uint8_t out_byte = 0;
    for (auto const& in_bit_arr_i : in_bit_array | boost::adaptors::indexed(0)){
        out_byte |= in_bit_arr_i.value() << in_bit_arr_i.index() * 0x01;
    }

    return out_byte;
}