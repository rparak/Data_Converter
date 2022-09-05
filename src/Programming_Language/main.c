#include <stdio.h>
#include <cstdlib>

// g++ main.c -o main
// ./main

unsigned char* Number_To_Byte_Array(unsigned short in_num, unsigned char out_size)
{
    static unsigned char* out_num_arr;
    out_num_arr = (unsigned char*)malloc(out_size * sizeof(unsigned char));

    for(unsigned char i = 0; i < out_size; ++i){
        out_num_arr[i] = (in_num >> i * 0x08) & 0xff;
    }
    return out_num_arr;
}

int main() {
   unsigned short input_var_1 = 12345;
   unsigned char* out_num_arr = Number_To_Byte_Array(input_var_1, 2);

   printf("%d %d", out_num_arr[0], out_num_arr[1]);
   printf("\n");

   return 0;
}
