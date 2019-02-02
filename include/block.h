//
//  block.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//

#pragma once
#include <string>
class CBlockHeader{
    public:
        CBlockHeader();
        ~CBlockHeader();
    private:
        std::string hash;
        std::string previousHash;
        int timestamp;
        
        
};

CBlockHeader::CBlockHeader(){
    hash = "";
    previousHash = "";
    
}

CBlockHeader::~CBlockHeader(){

}
