//
//  address.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <sstream> // stringstream
#include <string>

namespace lockop{
    class CAddressManager{
        public:
            CAddressManager();
            std::stringstream& getAddress();
            std::string generateAddress();
        private:
            std::stringstream mRsultPrivateKey;
            std::stringstream mResultPublicKey;
    };
}

