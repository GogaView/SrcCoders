//
//  HaffmanDecoderPair.cpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "HaffmanDecoderPair.hpp"


CHaffmanDecoderPair::CHaffmanDecoderPair()
{
    
}

void CHaffmanDecoderPair::decoding(std::vector<int> vData)
{
    auto it = vData.begin();
    int iPrev = 0;
    
    std::vector<int> vCurrData;
    while(it != vData.end())
    {
        vCurrData.push_back(*it);
        
        auto mapIt =_find(iPrev, vCurrData);
        if(mapIt != m_haffmanData[iPrev].end())
        {
            m_vCodeData.push_back(mapIt->first);
            iPrev = mapIt->first;
            vCurrData.clear();
        }
        
        it++;
    }
    
}

void CHaffmanDecoderPair::setHaffmanMap(std::map<int, std::map<int, std::vector<int> > >  HaffmanMap)
{
    m_haffmanData = HaffmanMap;
}

std::vector<int> CHaffmanDecoderPair::getDecodingData()
{
    return m_vCodeData;
}

std::map<int, std::vector<int> >::iterator CHaffmanDecoderPair::_find(int iPrev, std::vector<int> second)
{
    for(auto it = m_haffmanData[iPrev].begin(); it != m_haffmanData[iPrev].end(); ++it)
    {
        if( (*it).second == second)
            return it;
    }
    
    return m_haffmanData[iPrev].end();
}