//
//  MarcovGenerator.cpp
//  GolombCoder
//
//  Created by MacBook on 20.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "MarcovGenerator.hpp"

#include <assert.h>
#include <numeric>
#include <time.h>

CMarcovGenerator::CMarcovGenerator(int iSize)
    :m_iSize(iSize)
{
    srand(time(NULL));
    _createMatrix();
}

CMarcovGenerator::CMarcovGenerator(vect_prob vProbeMat)
    :m_vProbMatrix(vProbeMat)
{
    assert(!m_vProbMatrix.empty());
    assert(m_vProbMatrix.size() == m_vProbMatrix[0].size());
    m_iSize = m_vProbMatrix.size();
}

void CMarcovGenerator::_createMatrix()
{
    for(int i = 0; i != m_iSize; i++)
    {
        std::vector<int> vCount;
        for(int j = 0; j != m_iSize; j++)
        {
            vCount.push_back(rand()%en_max_count);
        }
        
        std::vector<double> vProb;
        for(int j = 0; j != m_iSize; j++)
        {
            vProb.push_back(static_cast<double>(vCount[j])/std::accumulate(vCount.begin(), vCount.end(), 0));
        }
        
        m_vProbMatrix.push_back(vProb);
    }
}

std::vector<int> CMarcovGenerator::getStreamData(int iCount)
{
    std::vector<int> vValues;
    int iCurrValue = 0;
    vValues.push_back(iCurrValue);
    
    while(vValues.size() <= iCount)
    {
        int iRand = rand()%en_max_prob;
        
        int iBuffer = 0;
        for(int i = 0; i != m_iSize; i++)
        {
            int iValue = m_vProbMatrix[iCurrValue][i] * en_max_prob;
            if( iRand < iValue + iBuffer)
            {
                iCurrValue = i;
                vValues.push_back(iCurrValue);
                break;
            }
            else
            {
                iBuffer += iValue;
            }
        }
    }
    m_vData = vValues;
    return vValues;
}

std::vector<int> CMarcovGenerator::getStreamData()
{
    return m_vData;
}

std::map<int, std::map<int, int> > CMarcovGenerator::getMapForHaffman()
{
    std::map<int, std::map<int, int> > mapForHaffman;
    
    for(int i = 0; i != m_iSize; i++)
        for(int j = 0; j != m_iSize; j++)
        {
            if(mapForHaffman.find(i) == mapForHaffman.end())
            {
                mapForHaffman[i] = std::map<int, int>();
            }
            
            mapForHaffman[i][j] = en_max_prob * m_vProbMatrix[i][j];
        }
    
    return mapForHaffman;
    
}