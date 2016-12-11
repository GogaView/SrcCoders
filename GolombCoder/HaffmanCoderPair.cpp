//
//  HaffmanCoderPair.cpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "HaffmanCoderPair.hpp"

CHaffmanCoderPair::CHaffmanCoderPair()
{
    
}

void CHaffmanCoderPair::coding(std::vector<int> vData)
{
    int iCurrent = 0;
    
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        m_vCodeData.insert(m_vCodeData.end(), m_haffmanData[iCurrent][*it].begin(), m_haffmanData[iCurrent][*it].end());
        
        iCurrent = *it;
    }
}

void CHaffmanCoderPair::setHaffmanMap(std::map<int, std::map<int, std::vector<int> > > HaffmanMap)
{
    m_haffmanData = HaffmanMap;
}

std::vector<int> CHaffmanCoderPair::getCodingData()
{
    return m_vCodeData;
}