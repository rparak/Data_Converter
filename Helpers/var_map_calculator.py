"""
## =========================================================================== ## 
MIT License
Copyright (c) 2022 Roman Parak
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

# Default Bit Size (1 Byte = 8 bits)
CONST_NUM_OF_BIT_IN_BYTE = 8
# Initialization variables for output information about the results
CONST_DATA_TYPE = [['USINT', 'UINT', 'None', 'UDINT'], 
                   ['USINT', 'INT', 'None', 'REAL']]
CONST_RANGE     = [['[0, +255]', '[0, +65535]', 'None', '[0, +4294967295]'],
                   ['[0, +255]', '[-32768, +32767]', 'None', '[-3.4E+38, +3.4E+38]']]
CONST_SIZE      = ['8', '16' , 'None', '32']

def VM_Write(limit):
    """
    Description:
        Simple function to calculate mapping variables (addresses) for Ethernet protocols 
        such as PROFINET, EtherNet/IP.

        Note:
            PLC -> Robot, Controller, etc. 
            
    Args:
        (1) limit [INT Array]: Limit (upper / lower) mapping variables in bytes.

    Examples:
        # Lower Limit: Byte 0
        # Upper Limit: Byte 3
        # Type of the robot (controller): 0 (ABB), 1 (Universal Robots) 
        VM_Write([0, 3], 0)
    """

    try:
        assert limit.size == 2
        assert limit[0] == limit[1] or (limit[0] < limit[1] and (limit[0] and limit[1]) >= 0)

        if limit[0] != limit[1]:
            assert ((limit[1] - limit[0]) + 1) % 2 == 0

        # Number of variables used to transfer information between the Robot and the PLC.
        num_ofVar = ((limit[1] - limit[0]) + 1)

        # The resulting calculation of the equation.
        result_adr = np.array([limit[0] * CONST_NUM_OF_BIT_IN_BYTE, (limit[1] + 1) * (CONST_NUM_OF_BIT_IN_BYTE) - 1])

        return (num_ofVar, result_adr)

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def VM_Read(limit):
    """
    Description:
        Simple function to calculate mapping variables (addresses) for Ethernet protocols 
        such as PROFINET, EtherNet/IP. 
            
        Robot, Controller, etc. -> PLC

    Args:
        (1) limit [INT Array]: Limit (upper / lower) mapping variables in bits.

    Examples:
        # Lower Limit: Bit 0
        # Upper Limit: Bit 31
        VM_Read([0, 31], 0)
    """

    try:
        assert limit.size == 2
        assert limit[0] == limit[1] or (limit[0] < limit[1] and (limit[0] and limit[1]) >= 0)

        if limit[0] != limit[1]:
            assert ((limit[1] - limit[0]) + 1) % 2 == 0

        # Number of variables used to transfer information between the Robot and the PLC.
        num_ofVar = int(((limit[1] - limit[0]) + 1) / CONST_NUM_OF_BIT_IN_BYTE)

        # The resulting calculation of the equation.
        result_adr = np.array([limit[0] / CONST_NUM_OF_BIT_IN_BYTE, (limit[1] + 1) / (CONST_NUM_OF_BIT_IN_BYTE) - 1])

        return (num_ofVar, result_adr)

    except AssertionError as error:
        print('[ERROR] Invalid input. Please try again ...')
        print(f'[ERROR] Information: {error}')

def main():
    """
    Description:
        Test the functions for calculating mapping variables (addresses) for industrial ethernet protocols 
        such as PROFINET, EtherNet/IP. 
    """

    # Declaration of input variables.
    #   Limit (upper / lower) mapping variables in bytes.
    in_limit    = np.array([0, 3])
    #   Type of the robot (controller): 
    #       0 (ABB), 1 (Universal Robots) 
    in_rob_type = 0

    # Information about input variables
    print('[INFO] Limit (upper / lower) in bits: [%d, %d]' % (in_limit[0], in_limit[1]))
    print('[INFO] Type of the robot (controller): %d' % in_rob_type)

    # PLC -> Robot (Variable Mapping)
    print('[INFO] Calculation Type (Variable Mapping - PROFINET): PLC -> Robot:')
    # 1\ Test.
    vm_w_res = VM_Write(in_limit)

    # Display Additional informations (Output function 1\).
    print('[INFO]   Number of Variables: %d' % vm_w_res[0])
    print('[INFO]   Data Type: %s' % CONST_DATA_TYPE[in_rob_type][vm_w_res[0] - 1])
    print('[INFO]   Range: %s' % CONST_RANGE[in_rob_type][vm_w_res[0] - 1])
    print('[INFO]   Size (bits): %s' % CONST_SIZE[vm_w_res[0] - 1])
    print('[INFO]   Variable Mapping (Bytes):')
    print('[INFO]   Address (Lower): %d' % vm_w_res[1][0])
    print('[INFO]   Address (Upper): %d' % vm_w_res[1][1])

    # Robot -> PLC (Variable Mapping)
    print('[INFO] Calculation Type (Variable Mapping - PROFINET): Robot -> PLC:')
    # 2\ Test.
    vm_r_res = VM_Read(vm_w_res[1])

    # Display Additional informations (Output function 1\).
    print('[INFO]   Number of Variables: %d' % vm_r_res[0])
    print('[INFO]   Data Type: %s' % CONST_DATA_TYPE[in_rob_type][vm_r_res[0] - 1])
    print('[INFO]   Range: %s' % CONST_RANGE[in_rob_type][vm_r_res[0] - 1])
    print('[INFO]   Size (bits): %s' % CONST_SIZE[vm_r_res[0] - 1])
    print('[INFO]   Variable Mapping (Bytes):')
    print('[INFO]   Address (Lower): %d' % vm_r_res[1][0])
    print('[INFO]   Address (Upper): %d' % vm_r_res[1][1])

    # Compare results
    print('[INFO] Test No. 1 / 2:')
    if vm_r_res[1].all() == in_limit.all():
        print('[INFO] The calculation was completed successfully.')
    else:
        print('[INFO] Something is wrong.')
        
if __name__ == '__main__':
    sys.exit(main())
