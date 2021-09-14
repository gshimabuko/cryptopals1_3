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
 * @file encryptedMessage.cpp
 * @brief Implementation of class abstraction for encrypted messages.
 *
 * @details This file implements a Encrypted message class that holds the original
 * encrypted message, a decrypted message, and two scores that define the likelyhood
 * of a decoded string being a real message in the English language.
 * This class will also include functions to decode the message and to calculate
 * said scores, to set the encoded message and to get the scores.
 * 
 *      The implemented functions are as followed:
 *
 * @author Guilherme Shimabuko
 * 
 * date of last update in yy-mm-dd format
 *
 * @date 2021-09-10
 *
 * @version 1.00
 * 
 *      Version History
 *
 *      Version     Date            Author          Changes
 *
 *      1.00        2021-09-10      GSHIMABUKO      Class implementation
 *
 *********************************************************************************
 */


#include <iostream>
#include <vector>
#include "hex2base64.h"
#include "XOR.h"
#include "encryptedMessage.h"

void encryptedMessage::setEncodedMessage(std::string message)
{
    std::vector<unsigned char> temp (message.begin(), message.end());
    encodedMessage = temp;
}
void encryptedMessage::decodeMessage(std::vector<unsigned char> keyVector)
{
    std::vector<unsigned char> binVector;
    std::vector<unsigned char> binDecode;

    binVector = hex2bin(encodedMessage);
    std::cout << std::endl;
    for (long unsigned int i = 0; i < binVector.size(); i=i+8)
    {
        for(long unsigned int j = 0; j < 8; j++)
        {
            if(7 - j < keyVector.size())
            {
                binDecode.push_back(bitwiseXOR(binVector[i+j], keyVector[7 - j]));
            }
            else
            {
                binDecode.push_back(bitwiseXOR(binVector[i+j], '0'));
            }
        }   
    }
    decodedMessage = bin2dec(binDecode);
}
std::string encryptedMessage::getDecodedMessage()
{
    std::string message(decodedMessage.begin(),decodedMessage.end());
    return(message);
}

int main()
{
    std::string hexString = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    encryptedMessage message;
    std::vector<unsigned char> binKey;

    message.setEncodedMessage(hexString);
    for (int i = 0 ; i < 256; i++)
    {
        binKey = dec2bin(i);
        for (long unsigned int k = 0; k < 8; k++)
        {
            std::cout << binKey[k];
        }
        message.decodeMessage(binKey);
        std::cout << message.getDecodedMessage() << std::endl;
    }
        binKey = dec2bin(88);
        message.decodeMessage(binKey);
        std::cout << message.getDecodedMessage() << std::endl;
}
