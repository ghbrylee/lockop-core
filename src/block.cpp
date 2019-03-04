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
        : mLatestBlockAge(0)
    {
    }

    CBlockHeader::CBlockHeader()
        : mVersion(1)
        , mHeight(0)
        , mHashPrevBlock(0)
        , mHashMerkleRoot(0)
        , mTime(0)
        , mData("0")
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
    
    uint64_t CBlockManager::buildMerkleTree() const{
        //build merkle tree
    }
    
    uint64_t CBlockManager::checkMerkleBranch() const{
        //check mekrle branch
    }


    void CBlockHeader::setHeight(){
        mHeight = mHeight + 1 ;
    }

    uint8_t CBlockHeader::getVersion(){
        return mVersion;
    }

    uint64_t CBlockHeader::getHeight(){
        return mHeight;
    }

    uint64_t CBlockHeader::getHashPrevBlock(){
        return mHashPrevBlock;
    }

    uint64_t CBlockHeader::getHashMerkleRoot(){
        return mHashMerkleRoot;
    }

    uint32_t CBlockHeader::getTime(){
        return mTime;
    }

    void CBlockManager::addingVecBlock(){
        this->blockchain.push_back("abc001"); 
        this->blockchain.push_back("abc002");
        this->blockchain.push_back("abc003"); 
        this->blockchain.push_back("abc004"); 
        this->blockchain.push_back("abc005"); 
        this->blockchain.push_back("abc006"); 
        this->blockchain.push_back("abc007"); 
        this->blockchain.push_back("abc008"); 
        this->blockchain.push_back("abc009"); 
    }

    void CBlockManager::getVecBlock(int i){
        std::cout << "[DEBUG] " << blockchain[i] << std::endl;
    }

    void CBlockManager::clearVecBlock(){
        this->blockchain.clear();
    }

    void checkerBlock(){
        
    }

    void addBlock(){
        CUtilManager util;
        CLogManager log;
        CTimeManager time;
        CBlockManager mn;
        CBlockHeader block;

        log.printText("DEBUG", "Block Info : ");
        log.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                                  block.getHashPrevBlock(), block.getHashMerkleRoot(),
                                  block.getTime()
                       );

        if(block.getHeight() == 0){
            log.printText("DEBUG", "Could not found any block. Initializing the blockhain..");
            //while(false){
                log.printText("DEBUG", "Block Generating..");
                usleep(BLCOK_CREATION_TIMESPAN);

                mn.addingVecBlock();
                for (int i=0; i<15; i++){
                    mn.getVecBlock(i);
                }
                mn.clearVecBlock();
                cout << "tt " << endl;
                for (int i=0; i<15; i++){
                    mn.getVecBlock(i);
                }
                
                // vector
                /*
                std::vector<std::string> blockVersion;
                std::vector<std::string> blockHeight;
                std::vector<std::string> blockPrevBlock;
                std::vector<std::string> blockMerkleRoot;
                std::vector<std::string> blockTime;
                std::vector<std::string> blockData;
                */
                block.setHeight();
                log.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                            block.getHashPrevBlock(), block.getHashMerkleRoot(),
                            block.getTime()
                              );
                //vec.clear();
            //}
        }
    }



}
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


