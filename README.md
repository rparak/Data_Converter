# Data Conversion in Multiple Programming Languages

## Requirements:

**Programming Language:**

```bash
C, ANSI C, C++, C# ABB RAPID, Python
```

**Import Libraries:**
```bash
More information can be found in the individual scripts (.h, .hpp, .py, etc.)
```

**Supported on the following operating systems:**
```bash
Windows, Linux
```

## Project Description:
Library to converts base data types to an array of bytes, and an array of bytes to base data types as well as byte to an array of bits, and an array of bits to byte.

This library can be useful for understanding data conversion using multiple programming languages (C, ANSI C, C++, C#, ABB RAPID, Python). It can also be used for industrial communication via PROFINET, EtherNet/IP, etc. industrial ethernet protocols.

The application (libraries) was primarily tested on company hardware (B&R Automation, SMC Industrial Automation, ABB and Universal robots). Industrial communication between B&R Automation PLCs and robots (Universal Robots, ABB) was tested via PROFINET and between B&R Automation devices and SMCs via Ethernet/IP.

**Data Types:**
```bash 
    BOOL (Bit)  : Boolean               [0, 1]          | 1-bit  | 0-Byte |
    USINT (Byte): Unsigned char         [0, 255]        | 8-bit  | 1-Byte |
    UINT        : Unsigned INT          [0, 65535]      | 16-bit | 2-Byte |
    UDINT       : Unsigned (double) INT [0, 4294967295] | 32-bit | 4-Byte |
```

**Bitwise Operators:**
```bash 
    &	Bitwise AND
    |	Bitwise OR
    <<	Shift left
    >>	Shift right
```
## Project Hierarchy:

**Repositary [/Data_Converter/]:**
```bash

[/Helpers/var_map_calculator.py]
Description:
    Test the functions for calculating mapping variables (addresses) for industrial ethernet 
    protocols such as PROFINET, EtherNet/IP.

Language = C, ANSI C, C++, C# ABB RAPID, Python;

[/src/Programming_Language/{Language}/Converter.*]
* = .sys, .h, .hpp, .cs, .py
Description:
    Main lib. for data conversion.
    
[/src/Programming_Language/{Language}/main.*] 
* = .mod, .h, .hpp, .cs, .py
Description:
    Simple tests to verify the functionality of individual functions.
```

## Test:

**Description:**
Conversion of input value (UINT/UDINT) into a vector of values (BYTES).

**ABB_Robotics_RAPID:**
```bash 
    VAR dnum IN_UINT_t1 := 12345;
    VAR dnum OUT_BYTE_t1{2};
    
    Convert_UINT_To_USINT_Array IN_UINT_t1, OUT_BYTE_t1;
```

**BaR_Automation_ANSI_C:**
```bash 
    _LOCAL struct Convert_UINT_To_USINT_Array C_UINT_To_USINT_Arr_1;
    
    C_UINT_To_USINT_Arr_1.INPUT = 12345;
    Convert_UINT_To_USINT_Array(&C_UINT_To_USINT_Arr_1);
```

**C++:**
```bash 
   ushort input_var_1 = 12345;
   std::vector<uint8_t> res_tId_1 = Converter::Number_To_Byte_Array<ushort>(input_var_1, 2);
```

**C:**
```bash 
   unsigned int input_var_1 = 12345;
   unsigned char* res_tId_1 = Convert_Number_To_Byte_Array(input_var_1, 2);
```

**C#:**
```bash 
    ushort input_var_1 = 12345;
    byte[] res_tId_1 = Convert.NumberToByteArray<ushort>(input_var_1);
```

**Python:**
```bash 
    input_var = 12345
    res_tId_2 = Converter.Convert_Number_To_Byte_Array(input_var, 2)
```

## Contact Info:
Roman.Parak@outlook.com

## Citation (BibTex)
```bash
@misc{RomanParak_DataConverter,
  author = {Roman Parak},
  title = {An open-source library for base data type conversions},
  year = {2022},
  publisher = {GitHub},
  journal = {GitHub repository},
  howpublished = {\url{https://https://github.com/rparak/Data_Converter}}
}
```
