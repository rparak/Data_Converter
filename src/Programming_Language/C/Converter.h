/****************************************************************************
MIT License
Copyright(c) 2022 Roman Parak
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************
Author   : Roman Parak
Email    : Roman.Parak @outlook.com
Github   : https://github.com/rparak
File Name: Converter.h
****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>

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