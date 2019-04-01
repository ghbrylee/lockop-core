//
//  block.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "block.h"
#include "util.h"

using namespace std;
namespace lockop{
    CBlockManager::CBlockManager()
    {
    }

    CBlockStorage::CBlockStorage()
    {
    }

    void addBlock(){
        CUtilManager util;
        CLogManager log;
        CTimeManager time;
        CBlockManager mn;
        CBlockStorage block;

        while(true){
            uint32_t height = block.getLatestHeight();
            std::string newHash;
            std::string hashPrevHash;
            std::string nullHashPrevHash = "0000000000000000000000000000000000000000000000000000000000000000";

            usleep(BLCOK_CREATION_TIMESPAN);
            //block.buildNewBlock(&block);
            log.printText("DEBUG", "-----");
            cout << "[DEBUG] Recently Block Index : " << height << endl;
            
            if (block.getLatestHeight() == 0){
                log.printText("DEBUG", "Could not found any block. Initializing the blockhain..");
                log.printText("DEBUG", "Building a new genesis block...");
                block.setHashPrevBlock(nullHashPrevHash);
            }

            block.setLatestHeight();

            newHash = mn.buildBlockHash();
            cout << "[DEUBG] Block Hash : " << newHash << endl;
            block.setVersion();
            block.setTime(time.getCurrentTimestamp());
            cout << "[DEBUG] Get current time of block : " << block.getTime(height) << endl;
            
            //vec.clear();
        }
    }

    void CBlockManager::blockAgeCalculator(){
        CLogManager log;

        if (mLatestBlockAge > 5){
            mLatestBlockAge = 0;
        } else{
            mLatestBlockAge = mLatestBlockAge + 1;
            log.printBlockAge("DEBUG", mLatestBlockAge);
        }
    }

    std::string CBlockManager::buildBlockHash(){
        CTimeManager time;
        CUtilManager util;

        unsigned char hash[SHA256_DIGEST_LENGTH];
        uint32_t uniqueTime = time.getCurrentTimestamp();
        std::string uniqueTimeStr = std::to_string(uniqueTime);
        std::string uniqueSeed = uniqueTimeStr.append(util.getUniqueNum(10));
        
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, uniqueSeed.c_str(), uniqueSeed.size());
        SHA256_Final(hash, &sha256);

        std::stringstream res;
        res.str(""); // Initialization
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            res << hex << setw(2) << setfill('0') << (int)hash[i];
        }
        
        return res.str();
    }

    uint32_t CBlockStorage::getLatestHeight(){
        bool IsHeightEmpty;
        IsHeightEmpty = this->mLatestHeight.empty();

        if (IsHeightEmpty == true){
            this->mLatestHeight.push_back(0);
            return this->mLatestHeight.back();
        }else{
            return this->mLatestHeight.back();
        }
    }

    uint8_t CBlockStorage::getVersion(int nIndex){
        return this->mVersion[nIndex];
    }

    std::string& CBlockStorage::getHashPrevBlock(int nIndex){
        return this->mHashPrevBlock[nIndex];
    }

    std::string& CBlockStorage::getHashMerkleRoot(int nIndex){
        return this->mHashMerkleRoot[nIndex];
    }

    uint32_t CBlockStorage::getTime(int nIndex){
        return this->mTime[nIndex];
    }

    std::string& CBlockStorage::getData(int nIndex){
        return this->mData[nIndex];
    }

    void CBlockStorage::setLatestHeight(){
        uint32_t latestHeight = getLatestHeight();
        latestHeight += 1;
        this->mLatestHeight.push_back(latestHeight);
    }

    void CBlockStorage::setVersion(){
        this->mVersion.push_back(BLOCK_VERSION);
    }

    void CBlockStorage::setHashPrevBlock(std::string& hashPrevBlock){
        this->mHashPrevBlock.push_back(hashPrevBlock);
    }

    void CBlockStorage::setHashMerkleRoot(std::string& hashMerkleRoot){
        this->mHashMerkleRoot.push_back(hashMerkleRoot);
    }

    void CBlockStorage::setTime(uint32_t time){
        this->mTime.push_back(time);
    }

    void CBlockStorage::setData(std::string& data){
        this->mData.push_back(data);
    }

}

/*
    log.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                block.getHashPrevBlock(), block.getHashMerkleRoot(),
                block.getTime()
                    );
//bitcoin
//00000000839a8e6886ab5951d76f411475428afc90947ee320161bbf18eb6048
//000000006a625f06636b8bb6ac7b960a8d03705d1ace08b1a19da3fdcc99ddbd
//0000000082b5015589a3fdf2d4baff403e6f0be035a5d9742c1cae6295464449
//000000004ebadb55ee9096c9a2f8880e09da59c0d68b1c228da88e48844a1485
//0000 00009b7262 315dbf0717 87ad365609 7b892abffd 1f95a1a022 f896f533fc

//stellar
//0509d8d23a07b5bcdb759bd8b553c4d20bd4c8aa976bc0dbf3c973033b587c58
//c2e76ad886078c0df6f208077abd9add39a8924f23472cf5d9b7594224d6d54f
//4910a3dc1d84624522f59923dc5b01560ad49f8e0d776b51edbaeebb6f7d6cc6
*/