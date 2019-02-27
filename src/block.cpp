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
        CLogManager util;

        if (mLatestBlockAge > 5){
            mLatestBlockAge = 0;
        } else{
            mLatestBlockAge = mLatestBlockAge + 1;
            util.printBlockAge("DEBUG", mLatestBlockAge);
        }
    }
    
    uint64_t CBlockManager::buildMerkleTree() const{
        //build merkle tree
    }
    
    uint64_t checkMerkleBranch() const{
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
        while(true){
            usleep(100000);
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

        // 5614143346 5333461435 3221424411 6523112663 36222531
        // 
    }

    void generateBlock(){
        CLogManager util;
        CBlockManager mn;
        CBlockHeader block;

        util.printLog("DEBUG", "Start to generate block ...");
        util.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                                  block.getHashPrevBlock(), block.getHashMerkleRoot(),
                                  block.getTime()
                        );

        if(block.getHeight() == 0){
            util.printLog("DEBUG", "Could not found genesis block.");
            util.printLog("DEBUG", "Block Generating..");
            while(true){
                usleep(BLCOK_CREATION_TIMESPAN);
                
                block.setHeight();
                util.printBlock("DEBUG", block.getVersion(), block.getHeight(),
                            block.getHashPrevBlock(), block.getHashMerkleRoot(),
                            block.getTime()
                
                );
            }
        }


    }

}