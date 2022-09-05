#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#include <time.h>

// g++ main.c -o main
// ./main

unsigned char* Number_To_Byte_Array(unsigned short in_num, unsigned char out_size)
{
    static unsigned char* out_num_arr;
    out_num_arr = (unsigned char*)malloc(out_size * sizeof(unsigned char));

    for(unsigned char i = 0; i < out_size; ++i){
        out_num_arr[i] = (in_num >> i * 0x08) & 0xff;
    }

    /*
    static unsigned char out_num_arr[2];
    out_num_arr[0] = (in_num >> 0x00) & 0xff;
    out_num_arr[1] = (in_num >> 0x08) & 0xff;
    */
    return out_num_arr;

}

unsigned short Byte_Array_To_Number(unsigned char* in_byte_arr)
{
    unsigned short out_num = 0; size_t n = sizeof(in_byte_arr)/sizeof(in_byte_arr[0]);
    for (unsigned char i = 0; i < n; ++i){
        out_num |= in_byte_arr[i] << i * 0x08;
    }

    return out_num;
}

bool* Byte_To_Bit_Array(unsigned short in_byte){
    static bool out_bit_arr[8];

    for(unsigned char i = 0; i < 8; ++i){
        out_bit_arr[i] = (in_byte >> i * 0x01) & 0x01;
    }
 
    return out_bit_arr;
}

unsigned short Bit_Array_To_Byte(bool* in_bit_array){
    unsigned short out_byte = 0; size_t n = sizeof(in_bit_array)/sizeof(in_bit_array[0]);
    for (unsigned char i = 0; i < n; ++i){
        out_byte |= in_bit_array[i] << i * 0x01;
    }

    return out_byte;
}

int main() {
   unsigned short input_var_1 = 12345;
   unsigned char* out_num_arr;
   // Calculate the time taken by fun()
   clock_t t;
   t = clock();
   for(int i = 0; i < 1000; ++i){
    out_num_arr = Number_To_Byte_Array(input_var_1, 2);
   }
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

   printf("fun() took %f seconds to execute \n", time_taken);

   printf("%d %d", out_num_arr[0], out_num_arr[1]);
   printf("\n");

   unsigned short out_num = Byte_Array_To_Number(out_num_arr);
   printf("%d", out_num);
   printf("\n");

   unsigned char in_byte = 123;
   bool* out_bool_arr = Byte_To_Bit_Array(in_byte);

   unsigned char out_byte = Bit_Array_To_Byte(out_bool_arr);

   printf("%d", out_byte);
   printf("\n");
   return 0;
}
