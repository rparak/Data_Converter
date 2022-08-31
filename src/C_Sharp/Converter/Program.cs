/****************************************************************************
MIT License
Copyright(c) 2020 Roman Parak
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
using System.Linq;
using System.Collections.Generic;

namespace Converter
{
    class Program
    {
        /* 
            Description:
                A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 
         */
        public const byte CONST_BYTE_MAX_VALUE = byte.MaxValue;
        // 1 BYTE = 8 BIT
        public const byte CONST_NUM_OF_BIT_IN_BYTE = 8;

        public static byte[] Convert_Value_To_Byte_Array<T>(T x)
        {
            /*
                Description:
                    ....

                Args:
                    (1) x [...]: ...

                Returns:
                    (1) parameter [...]: ...

             */

            List<byte> y = new List<byte>() {};

            dynamic x_dynamic = x;
            dynamic y_i = (x_dynamic >> (0 * CONST_NUM_OF_BIT_IN_BYTE));

            y.Add((byte)y_i);

            byte i = 1;
            while (true) { 
                y_i = (x_dynamic >> (i * CONST_NUM_OF_BIT_IN_BYTE));
                if (y_i == 0) { 
                    break; 
                }else { 
                    y.Add((byte)y_i); 
                    ++i; 
                }
            }

            return y.ToArray();
        }

        public static T Convert_Byte_Array_To_Value<T>(byte[] x) 
        { 
            dynamic y = (T)Convert.ChangeType(x[0] * Math.Pow(CONST_BYTE_MAX_VALUE + 1, 0), typeof(T));
            foreach (var (x_i, i) in x.Skip(1).Select((x_i, i) => (x_i, i)))
            {
                y += (T)Convert.ChangeType(x_i * Math.Pow(CONST_BYTE_MAX_VALUE + 1, i + 1), typeof(T));
            }

            return y;
        }

        public static bool[] Convert_Byte_To_Bool_Array(byte x)
        {
            bool[] y = new bool[CONST_NUM_OF_BIT_IN_BYTE];

            for(byte i = 0; i < y.Length; ++i)
            {
                y[i] = (1 == ((x >> i) & 1));
            }

            return y;
        }

        public static byte Convert_Bool_Array_To_Byte(bool[] x)
        {
            byte y = 0;

            foreach (var (x_i, i) in x.Select((x_i, i) => (x_i, i)))
            {
                y = (x_i == true ? (byte)(y + Math.Pow(2, i)) : y);
            }

            return y;
        }


        static void Main(string[] args)
        {

            byte[] bytes = Convert_Value_To_Byte_Array<uint>(12345);
            foreach (byte byte_i in bytes)
            {
                Console.WriteLine(byte_i.ToString());
            }

            uint value = Convert_Byte_Array_To_Value<uint>(bytes);
            Console.WriteLine(value.ToString());


            byte[] out_b = BitConverter.GetBytes(12345);
            foreach (byte byte_i in out_b)
            {
                Console.WriteLine(byte_i.ToString());
            }

            Int16 values = BitConverter.ToInt16(out_b, 0);
            Console.WriteLine(values);

            bool[] b_arr = Convert_Byte_To_Bool_Array(84);

            foreach (bool b_i in b_arr)
            {
                Console.WriteLine(b_i.ToString());
            }

            Console.WriteLine(Convert_Bool_Array_To_Byte(b_arr));

        }
    }
}
