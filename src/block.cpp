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

    void CBlockManager::blockAgeCalculator(){
        CLogManager log;

        if (mLatestBlockAge > 5){
            mLatestBlockAge = 0;
        } else{
            mLatestBlockAge = mLatestBlockAge + 1;
            log.printBlockAge("DEBUG", mLatestBlockAge);
        }
    }
    
    void CBlockManager::buildNewBlock(){
        CUtilManager util;
        CLogManager log;
        CBlockStorage block;

        uint32_t height = block.getLatestHeight();
        cout << "[DEBUG] Build new block : " << height << endl;
        log.printText("DEBUG", "Check Point build new block");
        
        if (block.getLatestHeight() == 1){
            log.printText("DEBUG", "Could not found Genesis Block.");
            //block.setLatestHeight();

            // new hash
            std::string newHash;
            newHash = util.getSha256Hash();
            cout << "[DEUBG] new hash : " << newHash << endl;

        } else{
            log.printText("DEBUG", "Found a Genesis Block.");
        }
        

    }

    uint64_t CBlockManager::buildMerkleTree() const{
        //build merkle tree 

    }
    
    uint64_t CBlockManager::checkMerkleBranch() const{
        //check mekrle branch
    }

    uint32_t CBlockStorage::getLatestHeight(){
        this->mLatestHeight.push_back(0);
        this->mLatestHeight.push_back(1);
        uint32_t height = mLatestHeight.back();
        cout << "[block] Latest Block Height : " << height << endl;
        return height;
    }

    uint8_t CBlockStorage::getVersion(int index){
        return this->mVersion[index];
    }

    std::string& CBlockStorage::getHashPrevBlock(int index){
        return this->mHashPrevBlock[index];
    }

    std::string& CBlockStorage::getHashMerkleRoot(int index){
        return this->mHashMerkleRoot[index];
    }

    uint32_t CBlockStorage::getTime(int index){
        return this->mTime[index];
    }

    std::string& CBlockStorage::getData(int index){
        return this->mData[index];
    }

    void CBlockStorage::setLatestHeight(){
        uint32_t latestHeight;
        latestHeight = mLatestHeight.back();
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

    void CBlockStorage::initest(){
        this->mLatestHeight.push_back(0);
        this->mLatestHeight.push_back(1);
    }

    void addBlock(){
        CUtilManager util;
        CLogManager log;
        CTimeManager time;
        CBlockManager mn;
        CBlockStorage block;
        
        log.printText("DEBUG", "Block Info : ");
        block.initest(); // initialized
        
        if(block.getLatestHeight() == 1){
            log.printText("DEBUG", "Could not found any block. Initializing the blockhain..");
            while(true){
                log.printText("DEBUG", "Block Generating..");
                //usleep(BLCOK_CREATION_TIMESPAN);
                mn.buildNewBlock();
                log.printText("DEBUG", "-----");
                
                //vec.clear();
            }
        }
        
    

    
    }
}




/*
                log.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                            block.getHashPrevBlock(), block.getHashMerkleRoot(),
                            block.getTime()
                              );
*/

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


