//
//  ArifmeticProbe.cpp
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "ArifmeticProbe.hpp"
#include "MatrixCulculate.h"

СArifmeticProbe::СArifmeticProbe(int iSize)
{
    for(int i = 0 ; i != iSize; i++)
    {
        pair_borders border;
        border.first = static_cast<double>(i) / iSize;
        border.second = static_cast<double>(i + 1) / iSize;
        
        m_mBorders[i] = border;
    }
}

СArifmeticProbe::СArifmeticProbe(std::map<int, std::map<int, int> > mProbe)
{
    
    CMatrixCalculate matrixCalcul(mProbe);
    matrixCalcul.gauss();
    
    auto dVect = matrixCalcul.ans;
    
    double dMem = 0.0;
    for(int i = 0 ; i != dVect.size(); i++)
    {
        pair_borders border;
        border.first = dMem;
        border.second = dMem + dVect[i];
        
        m_mBorders[i] = border;
        dMem = border.second;
    }
}

СArifmeticProbe::СArifmeticProbe(std::vector<int> vData, int iSize)
{
    std::map<int, int> mProb;
    
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        if(mProb.find(*it) == mProb.end())
        {
            mProb[*it] = 1;
        }
        else
        {
            mProb[*it] = mProb[*it] + 1;
        }
    }
    
    
    double dMem = 0.0;
    for(int i = 0 ; i != mProb.size(); i++)
    {
        pair_borders border;
        border.first = dMem;
        border.second = dMem + static_cast<double>(mProb[i]) / vData.size();
        
        m_mBorders[i] = border;
        dMem = border.second;
    }
    
}

std::map<int, СArifmeticProbe::pair_borders> СArifmeticProbe::getProbe()
{
    return m_mBorders;
}