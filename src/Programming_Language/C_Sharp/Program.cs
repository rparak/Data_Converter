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
File Name: Program.cs
****************************************************************************/

// System Lib.
using System;
// Custom Script:
//  Base conversion between data. 
using Convert = DataConverter.Core;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Description:
                Simple tests to verify the functionality of individual functions to convert 
                data from the custom library.
            */

            // 1\ Test No. 1: UINT <-> BYTE[]
            ushort input_var_1 = 12345;

            // Converting uint (16-bit -> 2-byte) to multiple bytes.
            byte[] res_tId_1 = Convert.NumberToByteArray<ushort>(input_var_1);

            // Display the results.
            //string[] result_t1 = Array.ConvertAll(res_tId_1, x => x.ToString());
            //Console.WriteLine("[ " + String.Join(", ", result_t1) + " ]");

            // Check result:
            // Converting multiple bytes to an uint (16-bit -> 2-byte).
            ushort check_res_tId_1 = Convert.ByteArrayToNumber<ushort>(res_tId_1);

            // Compare results.
            Console.WriteLine("[INFO] Test No. 1: UINT <-> BYTE[]");
            if(input_var_1 == check_res_tId_1)
            {
                Console.WriteLine("[INFO] The calculation was completed successfully.");
            }
            else
            {
                Console.WriteLine("[INFO] Something is wrong.");
            }

            // 2\ Test No. 2: UDINT <-> BYTE[]
            uint input_var_2 = 12345678;

            // Converting udint (32-bit -> 4-byte) to multiple bytes.
            byte[] res_tId_2 = Convert.NumberToByteArray<uint>(input_var_2);

            // Check result:
            // Converting multiple bytes to an udint (32-bit -> 4-byte).
            uint check_res_tId_2 = Convert.ByteArrayToNumber<uint>(res_tId_2);

            // Compare results.
            Console.WriteLine("[INFO] Test No. 2: UDINT <-> BYTE[]");
            if (input_var_2 == check_res_tId_2)
            {
                Console.WriteLine("[INFO] The calculation was completed successfully.");
            }
            else
            {
                Console.WriteLine("[INFO] Something is wrong.");
            }

            // 3\ Test No. 3:  BYTE <-> BIT[]
            // Converting uint (16-bit -> 2-byte) to multiple bytes.
            byte input_var_3 = 123;

            // Converting byte (0 - 255) to multiple bits.
            bool[] res_tId_3 = Convert.ByteToBitArray(input_var_3);

            // Check result:
            // Converting multiple bits to byte (0 - 255).
            byte check_res_tId_3 = Convert.BitArrayToByte(res_tId_3);

            // Compare results.
            Console.WriteLine("[INFO] Test No. 3: BYTE <-> BIT[]");
            if (input_var_3 == check_res_tId_3)
            {
                Console.WriteLine("[INFO] The calculation was completed successfully.");
            }
            else
            {
                Console.WriteLine("[INFO] Something is wrong.");
            }
        }
    }
}
