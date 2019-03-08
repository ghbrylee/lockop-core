//
//  util.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-27.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "util.h"

using namespace std;
namespace lockop{
    CUtilManager::CUtilManager()
        :mUniqueNumStr("")
    {
    }

    CLogManager::CLogManager()
    {
    }

    CTimeManager::CTimeManager()
    {
    }

    std::string& CUtilManager::getUniqueNum(int dice_digestSize){
            std::string bindedResult;
            std::random_device rd;
            std::mt19937 mersenne(rd());
            std::uniform_int_distribution<> die(0, 9);

            this->mUniqueNumStr = ""; // Initialization
            for (int count = 1; count <= dice_digestSize; ++count)
            {
                bindedResult = std::to_string(die(mersenne));
                this->mUniqueNumStr.append(bindedResult);
                //if (count % 6 == 0);
            }

            return this->mUniqueNumStr;
    }

    uint32_t CTimeManager::getCurrentTimestamp(){
        std::time_t result = std::time(nullptr);
        mCurrentTimestamp = result;

        return this->mCurrentTimestamp;
    }

    std::string& CTimeManager::getCurrentDate(){
        std::time_t result = std::time(nullptr);
        mCurrentDate = std::asctime(std::localtime(&result));

        return this->mCurrentDate;
    }

    

    void CLogManager::printText(const std::string& type, const std::string& message){
//        std::cout << Type << '\n' << std::endl;
//        std::cout << Message << '\n' << std::endl;
        this->mType = type;
        this->mMessage = message;
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

/*
    void CLogManager::printBlock(const std::string& type, uint8_t version,
                                uint64_t height, std::string& hashPrevBlock,
                                std::string& hashMerkleRoot, uint32_t time){ 
        this->mType = type;
        this->mMessage = "(" + std::to_string(version) + ","
                             + std::to_string(height) + ","
                             + hashPrevBlock + ","
                             + hashMerkleRoot + ","
                             + std::to_string(time)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }
*/

    void CLogManager::printBlockAge(const std::string& type, uint8_t latestBlockAge){
        this->mType = type;
        this->mMessage = "Latest block age : ("
                             + std::to_string(latestBlockAge)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

/*
    std::string generateSha256Hash()
    {
        CUtilManager util;
        CTimeManager time;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        uint32_t uniqueTime = time.getCurrentTimestamp();
        std::string uniqueTimeStr = std::to_string(uniqueTime);
        std::string uniqueSeed = uniqueTimeStr.append(util.generateUniqueNum(10));

        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, uniqueSeed.c_str(), uniqueSeed.size());
        SHA256_Final(hash, &sha256);

        stringstream ss;
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            ss << hex << setw(2) << setfill('0') << (int)hash[i];
        }
        
        return ss.str();
    }
    */


}

