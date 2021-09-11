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
 * @file encryptedMessage.h
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
#ifndef __ENCRYPTEDMESSAGE__
#define __ENCRYPTEDMESSAGE__

#include <vector>

class encryptedMessage
{
    private:
        std::vector <unsigned char> encodedMessage;
        std::vector <unsigned char> decodedMessage;
//        float charScore;
//        float statScore;

    public:
        void setEncodedMessage(std::string message);
        void decodeMessage(std::vector<unsigned char> keyVector);
//        void computeCharScore();
//        void computeStatScore();
//        std::string getEncodedMessage();
        std::string getDecodedMessage();
//        float getCharScore();
//        float getStatScore();
//        float getTotalScore();
};
#endif /* __ENCRYPTEDMESSAGE__ */
