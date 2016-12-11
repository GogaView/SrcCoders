//
//  GolombGenerator.cpp
//  GolombCoder
//
//  Created by MacBook on 14.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "GolombGenerator.hpp"

#include <fstream>
#include <map>
#include <sstream>

CGolombGenerator::CGolombGenerator(int iCount, double dP)
    :m_iNumbersCount(iCount),
    m_dP(dP)
{
    _initSourceData();
    _createGisto();
}

void CGolombGenerator::_initSourceData()
{
    std::geometric_distribution<int> distribution(m_dP);
    std::default_random_engine generator;
    
    for(int i = 0; i < m_iNumbersCount; i++)
    {
        m_lSourceData.push_back(distribution(generator));
    }
}

std::vector<int> CGolombGenerator::getSourceData()
{
    return m_lSourceData;
}

void CGolombGenerator::_createGisto()
{
    std::map<int,int> mOutput;
    
    for(int i = 0; i != m_lSourceData.size(); i++)
    {
        if( mOutput.find(m_lSourceData[i]) == mOutput.end())
        {
            mOutput[m_lSourceData[i]] = 0;
        }
        else
        {
            mOutput[m_lSourceData[i]] = mOutput[m_lSourceData[i]] + 1;
        }
    }
    
    std::stringstream ss;
    ss << "/Users/macbook/Documents/tmp/" << "Gisto_" << m_dP << ".txt";
    
    std::string str = ss.str();
    std::ofstream outFile;
    outFile.open(ss.str());
    
    
    
    std::map<int,int>::iterator it;
    for(it = mOutput.begin(); it != mOutput.end(); ++it)
    {
        outFile << (*it).first << "\t" << (*it).second << std::endl;
    }
    
}