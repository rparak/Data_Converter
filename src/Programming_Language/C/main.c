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

   unsigned short input_var_1 = 12345;
   unsigned char* out_num_arr;
   /*
   // Calculate the time taken by fun()
   clock_t t;
   t = clock();
   for(int i = 0; i < 1000; ++i){
    out_num_arr = Number_To_Byte_Array(input_var_1, 2);
   }
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
   printf("fun() took %f seconds to execute \n", time_taken);
   */

   out_num_arr = Convert_Number_To_Byte_Array(input_var_1, 2);

   printf("%d %d", out_num_arr[0], out_num_arr[1]);
   printf("\n");

   unsigned short out_num = Convert_Byte_Array_To_Number(out_num_arr);
   printf("%d", out_num);
   printf("\n");

   unsigned char in_byte = 123;
   bool* out_bool_arr = Convert_Byte_To_Bit_Array(in_byte);

   unsigned char out_byte = Convert_Bit_Array_To_Byte(out_bool_arr);

   printf("%d", out_byte);
   printf("\n");
   return 0;
}
