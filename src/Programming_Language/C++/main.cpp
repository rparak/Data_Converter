// Custom Lib.:
//   Base conversion between data.
#include "Converter.hpp"

/*
 Note:
   $ g++ -std=c++17 main.cpp -o main
   $ ./main
 */

int main()
{
    /*
	 Description:
	    Simple tests to verify the functionality of individual functions to convert 
        data from the custom library.
	*/

    ushort input_var_1 = 12345;

    std::vector<uint8_t> out_num_arr = Converter::Number_To_Byte_Array<ushort>(input_var_1, 2);


    std::cout << out_num_arr.size() << std::endl;
    for(auto x: out_num_arr){
        std::cout << "Result: " << static_cast<ushort>(x) << std::endl;
    }

    ushort out_var = Converter::Byte_Array_To_Number<ushort>(out_num_arr);

    std::cout << out_var << std::endl;

    uint8_t in_byte = 123;
    std::vector<bool> out_bool_arr = Converter::Byte_To_Bit_Array(in_byte);

    for(auto y: out_bool_arr){
        std::cout << "Result: " << y << std::endl;
    }

    uint8_t out_byte = Converter::Bit_Array_To_Byte(out_bool_arr);

    std::cout << static_cast<ushort>(out_byte) << std::endl;

    return 0;
}