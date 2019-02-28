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
    {
    }

    CLogManager::CLogManager()
    {
    }

    CTimeManager::CTimeManager()
    {
    }

    uint64_t CUtilManager::generateUniqueNum(){
            std::random_device rd;
            std::mt19937 mersenne(rd()); 
            std::uniform_int_distribution<> die(1, 6);
            for (int count = 1; count <= 30; ++count)
            {
                this->mUniqueNum = die(mersenne);
                //if (count % 6 == 0);
            }
            std::cout << this->mUniqueNum << std::endl;
            return this->mUniqueNum;
            

            std::random_device rd;
            std::mt19937 mersenne(rd()); 
            std::uniform_int_distribution<> die(1, 6);
            for (int count = 1; count <= 48; ++count)
            {
                std::cout << die(mersenne); // << "\t"; 
                if (count % 6 == 0);
                    //std::cout << "\n";
            }
            std::cout << "\n";

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


    void CLogManager::printBlock(const std::string& type, uint8_t version,
                                uint64_t height, uint64_t hashPrevBlock,
                                uint64_t hashMerkleRoot, uint32_t time){ 
        this->mType = type;
        this->mMessage = "(" + std::to_string(version) + ","
                             + std::to_string(height) + ","
                             + std::to_string(hashPrevBlock) + ","
                             + std::to_string(hashMerkleRoot) + ","
                             + std::to_string(time)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

    void CLogManager::printBlockAge(const std::string& type, uint8_t latestBlockAge){
        this->mType = type;
        this->mMessage = "Latest block age : ("
                             + std::to_string(latestBlockAge)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

}