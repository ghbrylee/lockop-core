//
//  address.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <sstream> // stringstream

namespace lockop{
    class CAddressManager{
        public:
            CAddressManager();
            std::string& getAddress();
            std::string generateAddress();
        private:
            std::stringstream mRsultAddress;
    };
}

