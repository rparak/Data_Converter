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

namespace Converter
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] bytes = Convert.NumberToByteArray<uint>(12345);
            foreach (byte byte_i in bytes)
            {
                Console.WriteLine(byte_i.ToString());
            }

            uint value = Convert.ByteArrayToNumber<uint>(bytes);
            Console.WriteLine(value.ToString());


            byte[] out_b = BitConverter.GetBytes(12345);
            foreach (byte byte_i in out_b)
            {
                Console.WriteLine(byte_i.ToString());
            }

            Int16 values = BitConverter.ToInt16(out_b, 0);
            Console.WriteLine(values);

            bool[] b_arr = Convert.ByteToBitArray(84);

            foreach (bool b_i in b_arr)
            {
                Console.WriteLine(b_i.ToString());
            }

            Console.WriteLine(Convert.BitArrayToByte(b_arr));

        }
    }
}
