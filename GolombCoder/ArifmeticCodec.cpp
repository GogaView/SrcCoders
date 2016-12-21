//
//  ArifmeticCodec.cpp
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "ArifmeticCodec.hpp"

#include <math.h>

CArifmeticCoder::CArifmeticCoder(std::map<int, pair_borders> mBorders)
    :m_mBorders(mBorders),
    m_pairOldBorder(std::make_pair(0.0, 0.0))
{
    
}

void CArifmeticCoder::code(std::vector<int> vData)
{
    std::vector<int> bits;
    
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        pair_borders newBorder;
        
        if(it == vData.begin())
        {
            newBorder = m_mBorders[*it];
        }
        else
        {
            newBorder.second = m_pairOldBorder.first + (m_pairOldBorder.second - m_pairOldBorder.first) * m_mBorders[*it].second;
        
            newBorder.first = m_pairOldBorder.first + (m_pairOldBorder.second - m_pairOldBorder.first) * m_mBorders[*it].first;
        }
        
//        int resSize = ceil( (-1) * log2( newBorder.second) + 1) ;
        int resSize = 50;
        double value = newBorder.first + (newBorder.second - newBorder.first) / 2 ;
        bits = _getBits( value, resSize);
        
//        m_vOutput.insert(m_vOutput.end(), bits.begin(), bits.end());
        
        m_pairOldBorder = newBorder;
    }
    
    m_vOutput = bits;
}

std::vector<int> CArifmeticCoder::_getBits(double dValue, int iSize)
{
    std::vector<int> vectBits;
    for(int i = 0; i != iSize; i++)
    {
        dValue = dValue * 2;
        if(dValue >= 1)
        {
            vectBits.push_back(1);
            dValue -= 1;
        }
        else
        {
            vectBits.push_back(0);
        }
    }
    
    return vectBits;
}

std::vector<int> CArifmeticCoder::decode(int iSize)
{
    std::vector<int> vOutput_Dec;
    double dData = _fromBits(m_vOutput);
    auto mLocalBorders = m_mBorders;
    
    for(int i = 0 ; i != iSize; i++)
    {
        int iValue = _decodeSign(mLocalBorders, dData);
        _correctBorders(mLocalBorders, iValue);
        vOutput_Dec.push_back(iValue);
    }
    
    return vOutput_Dec;
}

double CArifmeticCoder::_fromBits(std::vector<int> vData)
{
    double d = 0;
    
    for(int i = 0; i != vData.size(); i++)
    {
        d += vData[i] * pow(2,(-(i+1)));
    }
    
    return d;
}

int CArifmeticCoder::_decodeSign(std::map<int, pair_borders> mBorders, double dValue)
{
    double dProb = 0;
    for(auto it = mBorders.begin(); it != mBorders.end(); ++it)
    {
        dProb = it->second.second;
        if(dProb >= dValue)
            return it->first;
    }
    return  -1;
}

void CArifmeticCoder::_correctBorders(std::map<int, pair_borders>& mBorders, int iValue)
{
    std::map<int, pair_borders> mNewBorders;
    
    if( iValue == 2)
        int i = 0;
    
    
    auto currBorder = mBorders[iValue];
    
    for(auto it = mBorders.begin(); it != mBorders.end(); ++it)
    {
        auto currPair = *it;
        
//        currPair.second.first = m_mBorders[iValue].first + it->second.first * ( m_mBorders[iValue].second - m_mBorders[iValue].first);
//        
//        currPair.second.second = m_mBorders[iValue].first + it->second.second * ( m_mBorders[iValue].second - m_mBorders[iValue].first);

    currPair.second.first = currBorder.first + m_mBorders[it->first].first * ( currBorder.second - currBorder.first);
        
    currPair.second.second = currBorder.first + m_mBorders[it->first].second * ( currBorder.second - currBorder.first);
        
        mNewBorders.insert(currPair);
    }
    
    mBorders = mNewBorders;
}

std::vector<int> CArifmeticCoder::getRes()
{
    return m_vOutput;
}