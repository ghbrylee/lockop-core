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


                for (int i=0; i<20; i++){
                    std::cout << sha256(32) << std::endl;
                }

                std::cout << "DEBUG " << util.generateUniqueNum() << std::endl;
                std::cout << "DEBUG " << util.generateUniqueNum() << std::endl;
                std::cout << "DEBUG " << util.generateUniqueNum() << std::endl;
                std::cout << "DEBUG " << util.generateUniqueNum() << std::endl;

                // vector
                std::vector<int> vec;
                std::vector<std::string> mv;
                mv.push_back("abcd001");
                mv.push_back("abcd002");
                std::cout << "[DEBUG] vector back TT: " << mv[0] << std::endl;
                /*
                for (int i=0; i<20; i++){
                    std::cout << "[DEBUG] vector" << i << " : " << vec[i] << std::endl;
                }
                */
                //=========
                block.setHeight();
                log.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                            block.getHashPrevBlock(), block.getHashMerkleRoot(),
                            block.getTime()
                               );
                //vec.clear();
            //}
        }
    }

    std::string to_hex(unsigned char s){
        stringstream ss;
        ss << hex << (int) s;
        return ss.str();
    }

    std::string sha256(int SHA256_DIGEST_SIZE){
        CTimeManager time;
        unsigned char hash[SHA256_DIGEST_SIZE];
        uint32_t uniqueTime = time.getCurrentTimestamp();
        std::string uniqueTimeStr = std::to_string(uniqueTime);

        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, uniqueTimeStr.c_str(), uniqueTimeStr.length());
        SHA256_Final(hash, &sha256);

        string output = "";
        for(int i = 0; i < SHA256_DIGEST_SIZE; i++) {
            output += to_hex(hash[i]);
        }
        return output;
    }


}