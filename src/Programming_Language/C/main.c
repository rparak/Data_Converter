// Custom Lib.:
//   Base conversion between data.
#include "Converter.h"

/*
 Note:
   $ g++ main.c -o main
   $ ./main
 */

int main() {
   /*
	 Description:
	    Simple tests to verify the functionality of individual functions to convert 
        data from the custom library.
	*/

   // 1\ Test No. 1: UINT <-> BYTE[]
   unsigned int input_var_1 = 12345;

   // Converting uint (16-bit -> 2-byte) to multiple bytes.
   unsigned char* res_tId_1 = Convert_Number_To_Byte_Array(input_var_1, 2);

   // Check result:
   // Converting multiple bytes to an uint (16-bit -> 2-byte).
   unsigned int check_res_tId_1 = Convert_Byte_Array_To_Number(res_tId_1);

   // Compare results.
   printf("[INFO] Test No. 1: UINT <-> BYTE[]\n");
   if(input_var_1 == check_res_tId_1)
   {
      printf("[INFO] The calculation was completed successfully.\n");
   }
   else
   {
      printf("[INFO] Something is wrong.\n");
   }

   // 2\ Test No. 2: UDINT <-> BYTE[]
   unsigned int input_var_2 = 12345678;

   // Converting udint (32-bit -> 4-byte) to multiple bytes.
   unsigned char* res_tId_2 = Convert_Number_To_Byte_Array(input_var_2, 4);

   // Check result:
   // Converting multiple bytes to an udint (32-bit -> 4-byte).
   unsigned int check_res_tId_2 = Convert_Byte_Array_To_Number(res_tId_2);

   // Compare results.
   printf("[INFO] Test No. 2: UDINT <-> BYTE[]\n");
   if (input_var_2 == check_res_tId_2)
   {
      printf("[INFO] The calculation was completed successfully.\n");
   }
   else
   {
      printf("[INFO] Something is wrong.\n");
   }

   // 3\ Test No. 3:  BYTE <-> BIT[]
   // Converting uint (16-bit -> 2-byte) to multiple bytes.
   unsigned char input_var_3 = 123;

   // Converting byte (0 - 255) to multiple bits.
   bool* res_tId_3 = Convert_Byte_To_Bit_Array(input_var_3);

   // Check result:
   // Converting multiple bits to byte (0 - 255).
   unsigned char check_res_tId_3 = Convert_Bit_Array_To_Byte(res_tId_3);

   // Compare results.
   printf("[INFO] Test No. 3: BYTE <-> BIT[]\n");
   if (input_var_3 == check_res_tId_3)
   {
      printf("[INFO] The calculation was completed successfully.\n");
   }
   else
   {
      printf("[INFO] Something is wrong.\n");
   }

   return 0;
}
