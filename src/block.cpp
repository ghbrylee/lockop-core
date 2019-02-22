#include <iostream>
#include "include/block.h"

using namespace std;
namespace lockop{
    CBlockHeader::CBlockHeader()
        : mBlockNum(0)
        , mHash(0)
        , mPreviousHash(0)
        , mTimestamp(0)
        , mBlockData("")
    {
    }
    
    int CBlockHeader::getBlockNum() const{
        return mBlockNum;
    }

    int64_t CBlockHeader::getPreviousHash() const{
        return mPreviousHash;
    }

    std::string& CBlockHeader::getBlockData(){
        return mBlockData;
    }

    void CBlockGenerate::genesisBlockCheck() const{
        if (genesisBlock == ""){
            std::cout << "GenesisBlock hash is empty. Please create it first" << '\n';
        }
    
    }

    void CBlockGenerate::blockGenerator() const{
        
    }
}