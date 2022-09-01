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
File Name: Converter.cs
****************************************************************************/

// System Lib.
using System;
using System.Linq;
using System.Collections.Generic;

namespace DataConverter
{
    // Converts base data types to an array of bytes, and an array of bytes to base data types.

    public static class Core
    {
        /* 
            Description:
                A byte is a unit of storage in a computer which contains 8-bits and can store 256 different values: 0 to 255. 
        */
        const byte CONST_BYTE_MAX_VALUE = byte.MaxValue;
        // 1 BYTE = 8 BIT
        const byte CONST_NUM_OF_BIT_IN_BYTE = 8;

        public static byte[] NumberToByteArray<T>(T x)
        {
            /*
                Description:
                    ....

                Args:
                    (1) x [...]: ...

                Returns:
                    (1) parameter [...]: ...

                */

            List<byte> y = new List<byte>() { };

            dynamic x_dynamic = x;
            dynamic y_i = (x_dynamic >> (0 * CONST_NUM_OF_BIT_IN_BYTE));

            y.Add((byte)y_i);

            byte i = 1;
            while (true)
            {
                y_i = (x_dynamic >> (i * CONST_NUM_OF_BIT_IN_BYTE));
                if (y_i == 0)
                {
                    break;
                }
                else
                {
                    y.Add((byte)y_i);
                    ++i;
                }
            }

            return y.ToArray();
        }

        public static T ByteArrayToNumber<T>(byte[] x)
        {
            dynamic y = (T)Convert.ChangeType(x[0] * Math.Pow(CONST_BYTE_MAX_VALUE + 1, 0), typeof(T));
            foreach (var (x_i, i) in x.Skip(1).Select((x_i, i) => (x_i, i)))
            {
                y += (T)Convert.ChangeType(x_i * Math.Pow(CONST_BYTE_MAX_VALUE + 1, i + 1), typeof(T));
            }

            return y;
        }

        public static bool[] ByteToBitArray(byte x)
        {
            bool[] y = new bool[CONST_NUM_OF_BIT_IN_BYTE];

            for (byte i = 0; i < y.Length; ++i)
            {
                y[i] = (1 == ((x >> i) & 1));
            }

            return y;
        }

        public static byte BitArrayToByte(bool[] x)
        {
            byte y = 0;

            foreach (var (x_i, i) in x.Select((x_i, i) => (x_i, i)))
            {
                y = (x_i == true ? (byte)(y + Math.Pow(2, i)) : y);
            }

            return y;
        }
    }
}