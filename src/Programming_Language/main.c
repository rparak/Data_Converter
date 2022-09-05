#include <stdio.h>
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

int main() {
   unsigned short input_var_1 = 12345;
   unsigned char* out_num_arr;
   // Calculate the time taken by fun()
   clock_t t;
   t = clock();
   for(int i = 0; i < 10000; ++i){
    out_num_arr = Number_To_Byte_Array(input_var_1, 2);
   }
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

   printf("fun() took %f seconds to execute \n", time_taken);

   printf("%d %d", out_num_arr[0], out_num_arr[1]);
   printf("\n");

   return 0;
}
