//
//  HafmanCoder.cpp
//  GolombCoder
//
//  Created by MacBook on 02.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "HafmanCoder.hpp"


CHaffmanCoder::CHaffmanCoder()
{
    
}

void CHaffmanCoder::coding(std::vector<int> vData)
{
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        m_vCodeData.insert(m_vCodeData.end(), m_haffmanData[*it].begin(), m_haffmanData[*it].end());
    }
}

void CHaffmanCoder::setHaffmanMap(std::map<int,std::vector<int>> HaffmanMap)
{
    m_haffmanData = HaffmanMap;
}

std::vector<int> CHaffmanCoder::getCodingData()
{
    return m_vCodeData;
}