//
//  ValueAccumulator.cpp
//  GolombCoder
//
//  Created by MacBook on 20.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "ValueAccumulator.hpp"

CValueAccumulator::CValueAccumulator(std::vector<int> vValues)
    :m_vValues(vValues)
{
    _makeProbMap();
}

CValueAccumulator::CValueAccumulator(vect_prob vProbe)
    :m_vProbe(vProbe)
{
    
}

void CValueAccumulator::_makeProbMap()
{
    std::map<int, int> mValuesSpecial;
    for(std::vector<int>::iterator it = m_vValues.begin(); it !=  m_vValues.end();++it)
    {
        mValuesSpecial[*it] = 1;
    }
    
    
    std::vector< std::vector<int> > vValues;
    vValues.resize(mValuesSpecial.size());
    for(int i = 0; i != vValues.size(); i++)
    {
        vValues[i].resize(vValues.size());
    }
    
    for(std::vector<int>::iterator it = m_vValues.begin(); ;++it)
    {
        int iCurr = *it;
        int iNext;
        if(it + 1 == m_vValues.end())
            break;
        else
            iNext = *(it + 1);
        
        vValues[iCurr][iNext]++;
    }
    
    m_vProbe.resize(vValues.size());
    for(int i = 0; i != vValues.size() ;i++)
    {
        m_vProbe[i].resize(vValues[i].size());
        
        for(int j = 0; j != vValues[i].size() ; ++j)
        {
            m_vProbe[i][j] = static_cast<double>(vValues[i][j] / m_vValues.size() );
        }
    }
    
}

std::map<int, int> CValueAccumulator::getAccumNormal()
{
    std::map<int, int> mValueCount;
    for(std::vector<int>::iterator it = m_vValues.begin(); it != m_vValues.end(); ++it)
    {
        if(mValueCount.find(*it) == mValueCount.end())
        {
            mValueCount[*it] = 1;
        }
        else
        {
            mValueCount[*it] = mValueCount[*it] + 1;
        }
    }
    
    return mValueCount;
}

std::map<int, std::map<int, int> > CValueAccumulator::getAccumNormalByPairs()
{
    std::map<int, std::map<int, int> > mValues;
    
    for(int i = 0; i != m_vProbe.size(); i++)
        for(int j = 0; j != m_vProbe.size(); j++)
        {
            if(mValues.find(i) == mValues.end())
            {
                mValues.insert(std::make_pair(i, std::map<int, int>()));
            }
            
            if(mValues[i].find(j) == mValues[i].end())
            {
                mValues[i][j] = 1;
            }
            else
            {
                mValues[i][j] = mValues[i][j] + 1;
            }
        }
    
    return mValues;
}
