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

   // 1\ Test No. 1: UINT <-> BYTE[]
   ushort input_var_1 = 12345;

   // Converting uint (16-bit -> 2-byte) to multiple bytes.
   std::vector<uint8_t> res_tId_1 = Converter::Number_To_Byte_Array<ushort>(input_var_1, 2);

   // Check result:
   // Converting multiple bytes to an uint (16-bit -> 2-byte).
   ushort check_res_tId_1 = Converter::Byte_Array_To_Number<ushort>(res_tId_1);

   // Compare results.
   std::cout << "[INFO] Test No. 1: UINT <-> BYTE[]" << std::endl;
   if(input_var_1 == check_res_tId_1)
   {
      std::cout << "[INFO] The calculation was completed successfully." << std::endl;
   }
   else
   {
      std::cout << "[INFO] Something is wrong." << std::endl;
   }

   // 2\ Test No. 2: UDINT <-> BYTE[]
   uint input_var_2 = 12345678;

   // Converting udint (32-bit -> 4-byte) to multiple bytes.
   std::vector<uint8_t> res_tId_2 = Converter::Number_To_Byte_Array<uint>(input_var_2, 4);

   // Check result:
   // Converting multiple bytes to an udint (32-bit -> 4-byte).
   uint check_res_tId_2 = Converter::Byte_Array_To_Number<uint>(res_tId_2);

   // Compare results.
   std::cout << "[INFO] Test No. 2: UDINT <-> BYTE[]" << std::endl;
   if (input_var_2 == check_res_tId_2)
   {
      std::cout << "[INFO] The calculation was completed successfully." << std::endl;
   }
   else
   {
      std::cout << "[INFO] Something is wrong." << std::endl;
   }

   // 3\ Test No. 3:  BYTE <-> BIT[]
   // Converting uint (16-bit -> 2-byte) to multiple bytes.
   uint8_t input_var_3 = 123;

   // Converting byte (0 - 255) to multiple bits.
   std::vector<bool> res_tId_3 = Converter::Byte_To_Bit_Array(input_var_3);

   // Check result:
   // Converting multiple bits to byte (0 - 255).
   uint8_t check_res_tId_3 = Converter::Bit_Array_To_Byte(res_tId_3);

   // Compare results.
   std::cout << "[INFO] Test No. 3: BYTE <-> BIT[]" << std::endl;
   if (input_var_3 == check_res_tId_3)
   {
      std::cout << "[INFO] The calculation was completed successfully." << std::endl;
   }
   else
   {
      std::cout << "[INFO] Something is wrong." << std::endl;
   }

    return 0;
}