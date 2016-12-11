//
//  HaffmanDecoder.cpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "HaffmanDecoder.hpp"


CHaffmanDecoder::CHaffmanDecoder()
{
    
}

void CHaffmanDecoder::decoding(std::vector<int> vData)
{
    auto it = vData.begin();
    
    
    std::vector<int> vCurrData;
    while(it != vData.end())
    {
        vCurrData.push_back(*it);
        
        auto mapIt =_find(vCurrData);
        if(mapIt != m_haffmanData.end())
        {
            m_vCodeData.push_back(mapIt->first);
            vCurrData.clear();
        }
        
        it++;
    }

}

void CHaffmanDecoder::setHaffmanMap(std::map<int,std::vector<int>> HaffmanMap)
{
    m_haffmanData = HaffmanMap;
}

std::vector<int> CHaffmanDecoder::getDecodingData()
{
    return m_vCodeData;
}

std::map<int,std::vector<int>>::iterator CHaffmanDecoder::_find(std::vector<int> second)
{
    for(auto it = m_haffmanData.begin(); it != m_haffmanData.end(); ++it)
    {
        if( (*it).second == second)
            return it;
    }
    
    return m_haffmanData.end();
}