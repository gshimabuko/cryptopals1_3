/*********************************************************************************
 * @copyright Copyright (c) 2021 by Guilherme Shimabuko - Shima's Digital Hardware
 *
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions
 *     are met:
 *     
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of Shima's DIgital Hardware  nor the names of its
 *       contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *     IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTI-
 *     CULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SHIMA'S DIGITAL HARDWARE
 *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 *     THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************
 *
 * @file hex2base64.cpp
 * @brief Implementation of a hex to base 64 conversion
 *
 * @details This file implements functions to perform the conversion of a string
 *          in hexadecimal base to a 64 base by first converting the string to its
 *          binary representation as a string of Nibbles. These Nibbles are then 
 *          concatenated, and split again into groups of 6 bits.
 *          These new 6-bit words are then converted to base64.
 *          The implemented functions are as followed:
 *              1. bin2hex() - Translates a string of Nibbles into hex base;
 *              2. hex2bin() - Translates a hex string into string of nibbles;
 *              3. bin2base64() - Translates string of nibbles into base 64;
 *
 * @author Guilherme Shimabuko
 * 
 * date of last update in yy-mm-dd format
 *
 * @date 2021-09-08
 *
 * @version 1.01
 * 
 *      Version History
 *
 *      Version     Date            Author          Changes
 * 
 *      1.01        2021-09-08      GSHIMABUKO      Added Copyright and Header
 *                                                  Comments
 *
 *      1.00        2021-09-03      GSHIMABUKO      Implmented hex2base64 conversion
 *
 *********************************************************************************
 */


#include <iostream>
#include <vector>
std::vector<unsigned char> bin2hex(std::vector<unsigned char> binString)
{
    int decNumber;
    std::vector<unsigned char> hexString;
    std::string hexRef = "0123456789abcdef";
    for(long unsigned int i = 0; i < binString.size(); i = i+4)
    {
        decNumber = (binString[i+3] - '0') + (binString[i+2] - '0') * 2 + (binString[i+1] - '0') * 4 + (binString[i] - '0') * 8;
        hexString.push_back(hexRef[decNumber]);
    }
    return(hexString);
}
std::vector<unsigned char> hex2bin(std::vector<unsigned char> hexString)
{
    std::string binNumber;
    std::vector<unsigned char> binString;
    for(long unsigned int i = 0; i < hexString.size(); i++)
    {
        switch(hexString[i])
        {
            case '0':
                binNumber = "0000";
                break;
            case '1':
                binNumber = "0001";
                break;
            case '2':
                binNumber = "0010";
                break;
            case '3':
                binNumber = "0011";
                break;
            case '4':
                binNumber = "0100";
                break;
            case '5':
                binNumber = "0101";
                break;
            case '6':
                binNumber = "0110";
                break;
            case '7':
                binNumber = "0111";
                break;
            case '8':
                binNumber = "1000";
                break;
            case '9':
                binNumber = "1001";
                break;
            case 'a':
                binNumber = "1010";
                break;
            case 'b':
                binNumber = "1011";
                break;
            case 'c':
                binNumber = "1100";
                break;
            case 'd':
                binNumber = "1101";
                break;
            case 'e':
                binNumber = "1110";
                break;
            case 'f':
                binNumber = "1111";
                break;

        }
        for (int j = 0; j < 4 ; j++)
        {
            binString.push_back(binNumber[j]);
            //std::cout << binNumber[j];
        }
        //std::cout << " ";
    }
    //std::cout << "\n\n";
    return(binString);
}
std::vector<unsigned char> bin2base64(std::vector<unsigned char> binString)
{
    int decNumber;
    std::string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::vector<unsigned char> base64String;
    for (long unsigned int i = 0; i < binString.size(); i = i + 6)
    {
        decNumber = (binString[i+5] - '0') + (binString[i+4] - '0') * 2 + (binString[i+3] - '0') * 4 + (binString[i+2] - '0') * 8 + (binString[i+1] - '0') * 16 + (binString[i] - '0') * 32;
        //std::cout << binString[i] << binString[i+1] << binString[i+2] << binString[i+3] << binString[i+4] << binString[i+5] << "(" << decNumber << ")"<< " ";
        base64String.push_back(base64[decNumber]);
    }
    //std::cout << "\n\n";
    //std::cout << "\n\n";
    
    return base64String;
    
}

