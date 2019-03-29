//
//  address.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "address.h"
#include "util.h"

using namespace std;
namespace lockop{
    CAddressManager::CAddressManager()
    {
    }

    std::stringstream& CAddressManager::getAddress(){
        // get address
        std::cout << "TEST " << this->mRsultPrivateKey.str() << std::endl;
    }

    std::string CAddressManager::generateAddress(){
        CTimeManager time;
        CUtilManager util;

// AA3DC07413 4DF11D31E2 A421BAFF37 01 -> 32 bytes
// AA3DC074134DF11D31E2A421BAFF3701
// AA3DC074134DF11D31E2A421BAFF3701

        unsigned char hash[SHA256_DIGEST_LENGTH];
        uint32_t uniqueTime = time.getCurrentTimestamp();
        //std::string uniqueSeed = "00f24a5851e9372b87810a8e60cdd2e7cfd8026e31";
        std::string uniqueTimeStr = std::to_string(uniqueTime);
        std::string uniqueSeed = uniqueTimeStr.append(util.getUniqueNum(10));
        //7694 3b6ab625b4 bf97c99dcd 865cadd716 5b680ce66e 6482a0e8bf ee783198e0
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, uniqueSeed.c_str(), uniqueSeed.size());
        SHA256_Final(hash, &sha256);

        this->mRsultPrivateKey.str(""); // Initialization
        for(int i=0; i<16; i++){
            this->mRsultPrivateKey << hex << setw(2) << setfill('0') << (int)hash[i];
        }

        std::string PrivKeyRaw = this->mRsultPrivateKey.str();
        std::transform(PrivKeyRaw.begin(), PrivKeyRaw.end(), PrivKeyRaw.begin(), ::toupper);
        
        return PrivKeyRaw;
        
    }

}

// ** Below public and private key is example for test. Empty addresses.

//1MGMN7tqRCZRiEX9kZ7nu6e1hMXbmVyqdD
//5K2FwRUtaSRqyG8FC7qSyi85vLW6Myk2i57Y18FfEd3a1eJACy5

//1CWmbssvHekt8ANuLdnr9ZdBHe3NMv5vXD
//5KKNGgCtjeg5kTrnMEUwNKPNfwDYzg39VXMJQY5RLi3VjMXYWsG

//1ECzy64N8UkucxQUGDbt2kczrunDSvJKRc
//5KRWVRXiUNgPr4DBRqiQ7iyjS2XGVDzUm6Mad8rrR6SjKgfEjXU

//GDKNTTVKGEE3P4FRLW6OKQRF5KTCC3AQR6DDHKZE4W5ZJRJTD6B7HW2H
//SDWCGLXG5INK6CCS4BN24NWLVK37ANJBM6IUN6JQPOXQOUYJNTAQB3DN

//GCVFWJZZMPCHTSEVUNEROS5TD6H2473IVIX32G2ARZQ4XGCNHB6JKZBA
//SD2HTGC7PWMICJT2TZ5U2IOBTVXZ2EEFRJC3UBGSJVBQ26AESKXQCKNY

//GCD7XL DEIYZZ3LUI JMOAYMRN3C JZLW2MGLQR PMFNE35DBO NBBYKJAED5
//SBIXDTWMLISDA6Z6DX4CJQ2FWLKTWD4A4NATQTDEQ3QWIQXQCEH2BWNQ