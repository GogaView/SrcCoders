//
//  GolombCoder.cpp
//  GolombCoder
//
//  Created by MacBook on 14.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "GolombCoder.hpp"

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

GolombCoder::GolombCoder(int iM, double dP)
    :m_iM(iM),
    m_dP(dP)
{
    
}

void GolombCoder::coding(std::vector<int> lSrcData)
{
    m_lSrcData = lSrcData;
    _processing();
    m_lBitstream = _toBitstream();
    
    _writeToFile();
}

void GolombCoder::_processing()
{
    std::vector<char> vBitStream;
    
    std::vector<int>::iterator it;
    for(it = m_lSrcData.begin(); it != m_lSrcData.end(); ++it)
    {
        std::vector<char> vDataBits;
        vDataBits = _createGolombCode(*it);
        vBitStream.insert(vBitStream.end(), vDataBits.begin(), vDataBits.end());
    }
    
    m_lStream = vBitStream;
}

std::vector<char> GolombCoder::_createGolombCode(int iNumber)
{
    double dValue = log2(m_iM);
    int iValue = dValue;
    
    if( dValue - iValue == 0)
    {
        return _createEvenGolombCode(iNumber);
    }
    else
    {
        return _createUnevenGolombCode(iNumber);
    }
}

std::vector<char> GolombCoder::_createEvenGolombCode(int iNumber)
{
    int q = iNumber / m_iM;
    
    int b = ( log2(m_iM));
    
    int iOutputSize = (q + 1) + b;
    
    std::vector<char> vBits(iOutputSize, 1);
    for(int i = 0; i < q; i++)
    {
        vBits[i] = 1;
    }
    
    vBits[q] = 0;
    
    int r = iNumber % m_iM;
    
    int iLastNumber = iOutputSize - 1;
    while(r > 1)
    {
        vBits[iLastNumber] = r % 2;
        r = r / 2;
        iLastNumber--;
    }
    
    vBits[iLastNumber] = r;
    
    return vBits;
}

std::vector<char> GolombCoder::_createUnevenGolombCode(int iNumber)
{
    int q = iNumber / m_iM;
    
    int b = ceil( log2(m_iM));
    
    int iOutputSize;
    
    int r = iNumber % m_iM;
    if(r < pow(2,b) - m_iM)
    {
        iOutputSize = (q + 1) + b - 1;
    }
    else
    {
        iOutputSize = (q + 1) + b;
    }
    
    std::vector<char> vBits(iOutputSize, 1);
    for(int i = 0; i < q; i++)
    {
        vBits[i] = 1;
    }
    
    vBits[q] = 0;
    
    if(r >= pow(2,b) - m_iM)
    {
        r = r + pow(2,b) - m_iM;
    }
    
    int iLastNumber = iOutputSize - 1;
    while(r > 1)
    {
        vBits[iLastNumber] = r % 2;
        r = r / 2;
        iLastNumber--;
    }
    
    vBits[iLastNumber] = r;
    
    return vBits;
}

std::vector<char> GolombCoder::_toBitstream()
{
    int iVectorSize = ceil( static_cast<double>(m_lStream.size()) / (sizeof(char) * 8) );
    
    std::vector<char> outpudData;
    for(int i = 0; i != iVectorSize; i++)
    {
        outpudData.push_back(_getBitCode(i * sizeof(char) * 8));
    }
                             
    return outpudData;

}

char GolombCoder::_getBitCode(int iFirstBit)
{
    char cOutput = 0;
    
    for(int i = 0; i != sizeof(char) * 8; i++)
    {
        if(m_lStream.size() > iFirstBit + i)
        {
            cOutput = cOutput << 1;
            cOutput += m_lStream[iFirstBit + i];
        }
        else
        {
            cOutput = cOutput << 1;
        }
    }
    
    return cOutput;
}

std::vector<char> GolombCoder::getBitstream()
{
    return m_lBitstream;
}

void GolombCoder::_writeToFile()
{
    std::stringstream ss;
    ss << "/Users/macbook/Documents/tmp/" << "Code_" << m_dP << ".txt";
    
    std::ofstream outFile;
    outFile.open(ss.str());
    
    std::vector<char>::iterator it;
    for(it = m_lBitstream.begin(); it != m_lBitstream.end(); ++it)
    {
        outFile << *it;
    }
}
    
