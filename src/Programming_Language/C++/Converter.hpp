#include <iostream>
#include <vector>
// sudo apt-get install libboost-all-dev
#include <boost/range/adaptor/indexed.hpp>
#include <chrono>

template <typename T> std::vector<uint8_t> Number_To_Byte_Array(T in_num, uint8_t out_size)
{
    std::vector<uint8_t> out_num_arr;
    out_num_arr.push_back((in_num >> 0x00) & 0xff);
    out_num_arr.push_back((in_num >> 0x08) & 0xff);
    /*
    for(uint8_t i = 0; i < out_size; ++i){
        out_num_arr.push_back((in_num >> i * 0x08) & 0xff);
    }
    */

    return out_num_arr;
}

template <typename T> T Byte_Array_To_Number(std::vector<uint8_t> in_byte_arr)
{
    T out_num = 0;
    for (auto const& in_byte_arr_i : in_byte_arr | boost::adaptors::indexed(0)){
        out_num |= in_byte_arr_i.value() << in_byte_arr_i.index() * 0x08;
    }

    return out_num;
}

std::vector<bool> Byte_To_Bit_Array(uint8_t in_byte){
    std::vector<bool> out_bit_arr;

    for(uint8_t i = 0; i < 8; ++i){
        out_bit_arr.push_back((in_byte >> i * 0x01) & 0x01);
    }
 
    return out_bit_arr;
}

uint8_t Bit_Array_To_Byte(std::vector<bool> in_bit_array){
    uint8_t out_byte = 0;
    for (auto const& in_bit_arr_i : in_bit_array | boost::adaptors::indexed(0)){
        out_byte |= in_bit_arr_i.value() << in_bit_arr_i.index() * 0x01;
    }

    return out_byte;
}