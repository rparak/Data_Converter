#include <iostream>
#include <chrono>
#include <vector>
#include <Converter.hpp>

int main()
{
    // g++ -std=c++17 main.cpp -o main
    // ./main

    ushort input_var_1 = 12345;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(auto i = 0; i < 1000; ++i){
        std::vector<uint8_t> out_num_arr = Converter::Number_To_Byte_Array<ushort>(input_var_1, 2);
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