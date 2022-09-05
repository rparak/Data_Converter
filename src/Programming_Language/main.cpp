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

int main()
{
    // g++ -std=c++17 main.cpp -o main
    // ./main

    ushort input_var_1 = 12345;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(auto i = 0; i < 1000; ++i){
        std::vector<uint8_t> out_num_arr = Number_To_Byte_Array<ushort>(input_var_1, 2);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

    /*
    std::cout << out_num_arr.size() << std::endl;
    for(auto x: out_num_arr){
        std::cout << "Result: " << static_cast<ushort>(x) << std::endl;
    }

    ushort out_var = Byte_Array_To_Number<ushort>(out_num_arr);

    std::cout << out_var << std::endl;

    uint8_t in_byte = 123;
    std::vector<bool> out_bool_arr = Byte_To_Bit_Array(in_byte);

    for(auto y: out_bool_arr){
        std::cout << "Result: " << y << std::endl;
    }

    uint8_t out_byte = Bit_Array_To_Byte(out_bool_arr);

    std::cout << static_cast<ushort>(out_byte) << std::endl;
    */
    return 0;
}