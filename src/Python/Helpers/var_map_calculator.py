"""
## =========================================================================== ## 
MIT License
Copyright (c) 2021 Roman Parak
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
## =========================================================================== ## 
Author   : Roman Parak
Email    : Roman.Parak@outlook.com
Github   : https://github.com/rparak
File Name: var_map_calculator.py
## =========================================================================== ## 
"""

# System (Default Lib.)
import sys

# Numpy (Array computing Lib.) [pip3 install numpy]
import numpy as np

def VM_Write(limit, rob_type):
    """
    Description:
        Simple function to calculate mapping variables (addresses) for Ethernet protocols 
        such as PROFINET, EtherNet/IP.

        PLC -> Robot, Controller, etc. 
            
    Args:
        (1) limit [INT Array]: Limit (upper / lower) mapping variables in bytes.
        (2) rob_type [INT]: Type of the robot (controller). 

    Examples:
        # Lower Limit: Byte 0
        # Upper Limit: Byte 3
         # Type of the robot (controller): 0 (ABB), 1 (Universal Robots) 
        VM_Write([0, 3], 0)
    """

    try:
        # Tests of input variables
        assert len(limit) == 2
        assert limit[0] == limit[1] or (limit[0] < limit[1] and (limit[0] and limit[1]) >= 0)

        if limit[0] != limit[1]:
            assert ((limit[1] - limit[0]) + 1) % 2 == 0

        # Information about input variables
        print('[INFO] Limit (upper / lower) in bytes: [%d, %d]' % (limit[0], limit[1]))
        print('[INFO] Type of the robot (controller): %d' % rob_type)

        # Initialization variables for output information about the results
        DATA_TYPE = [['USINT', 'UINT', 'None', 'UDINT'], ['USINT', 'INT', 'None', 'REAL']]
        RANGE     = [['[0, +255]', '[0, +65535]', 'None', '[0, +4294967295]'], ['[0, +255]', '[-32768, +32767]', 'None', '[-3.4E+38, +3.4E+38]']]
        SIZE      = [['8', '16' , 'None', '32'], ['8', '16' , 'None', '32']]

        # Default Bit Size (1 Byte = 8 bits)
        default_bitSize = 8

        # Number of variables used to transfer information between the Robot and the PLC
        num_ofVar = ((limit[1] - limit[0]) + 1)

        # The resulting calculation of the equation
        result = [limit[0] * default_bitSize, (limit[1] + 1) * (default_bitSize) - 1]

        # Display Results (Output)
        print('[INFO] Number of Variables: %d' % num_ofVar)
        print('[INFO] Data Type: %s' % DATA_TYPE[rob_type][num_ofVar - 1])
        print('[INFO] Range: %s' % RANGE[rob_type][num_ofVar - 1])
        print('[INFO] Size (bits): %s' % SIZE[rob_type][num_ofVar - 1])
        print('[INFO] Variable Mapping (Bits):')
        print('[INFO] Address (Lower): %d' % result[0])
        print('[INFO] Address (Upper): %d' % result[1])

    except AssertionError as error:
        print('[ERROR] Invalid operation (problem with input variables).')  

def VM_Read(limit, rob_type):
    """
    Description:
        Simple function to calculate mapping variables (addresses) for Ethernet protocols 
        such as PROFINET, EtherNet/IP. 
            
        Robot, Controller, etc. -> PLC

    Args:
        (1) limit [INT Array]: Limit (upper / lower) mapping variables in bits.
        (2) rob_type [INT]: Type of the robot (controller). 

    Examples:
        # Lower Limit: Bit 0
        # Upper Limit: Bit 31
        # Type of the robot (controller): 0 (ABB), 1 (Universal Robots) 
         VM_Read([0, 31], 0)
    """

    try:
        # Tests of input variables
        assert len(limit) == 2
        assert limit[0] == limit[1] or (limit[0] < limit[1] and (limit[0] and limit[1]) >= 0)

        if limit[0] != limit[1]:
            assert ((limit[1] - limit[0]) + 1) % 2 == 0

        # Information about input variables
        print('[INFO] Limit (upper / lower) in bits: [%d, %d]' % (limit[0], limit[1]))
        print('[INFO] Type of the robot (controller): %d' % rob_type)

        # Initialization variables for output information about the results
        DATA_TYPE = [['USINT', 'UINT', 'None', 'UDINT'], ['USINT', 'INT', 'None', 'REAL']]
        RANGE     = [['[0, +255]', '[0, +65535]', 'None', '[0, +4294967295]'], ['[0, +255]', '[-32768, +32767]', 'None', '[-3.4E+38, +3.4E+38]']]
        SIZE      = [['8', '16' , 'None', '32'], ['8', '16' , 'None', '32']]

        # Default Bit Size (1 Byte = 8 bits)
        default_bitSize = 8

        # Number of variables used to transfer information between the Robot and the PLC
        num_ofVar = int(((limit[1] - limit[0]) + 1) / default_bitSize)

        # The resulting calculation of the equation
        result = [limit[0] / default_bitSize, (limit[1] + 1) / (default_bitSize) - 1]

        # Display Results (Output)
        print('[INFO] Number of Variables: %d' % num_ofVar)
        print('[INFO] Data Type: %s' % DATA_TYPE[rob_type][num_ofVar - 1])
        print('[INFO] Range: %s' % RANGE[rob_type][num_ofVar - 1])
        print('[INFO] Size (bits): %s' % SIZE[rob_type][num_ofVar - 1])
        print('[INFO] Variable Mapping (Bytes):')
        print('[INFO] Address (Lower): %d' % result[0])
        print('[INFO] Address (Upper): %d' % result[1])

    except AssertionError as error:
        print('[ERROR] Invalid operation (problem with input variables).')

def main():
    """
    Description:
        Test the functions for calculating mapping variables (addresses) for Ethernet protocols 
        such as PROFINET, EtherNet/IP. 
    """

    # PLC -> Robot (Variable Mapping)
    #print('[INFO] Calculation Type (Variable Mapping - PROFINET): PLC -> Robot:')
    
    VM_Write([7, 7], 0)
    print('\n')

    # Robot -> PLC (Variable Mapping)
    #print('[INFO] Calculation Type (Variable Mapping - PROFINET): Robot -> PLC:')
    #VM_Read([656,663], 0)
    #print('\n')

if __name__ == '__main__':
    sys.exit(main())
