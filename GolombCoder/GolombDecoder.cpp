//
//  GolombDecoder.cpp
//  GolombCoder
//
//  Created by MacBook on 15.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "GolombDecoder.hpp"
#include <iostream>

GolombDecoder::GolombDecoder(const std::vector<char> Bitstream, int M)
    :m_vBitStream(Bitstream),
    m_iM(M)
{
    _convertToByteStream();
    _golombDecoder();
    
//    std::cout << "OUTPUT:" << std::endl;
//    
//    for(int i = 0; i != m_vDstData.size(); i++)
//        std::cout << m_vDstData[i] << std::endl;
}

void GolombDecoder::_convertToByteStream()
{
    std::vector<char>::iterator it;
    for(it = m_vBitStream.begin(); it != m_vBitStream.end(); ++it)
    {
        char cCurrData = *it;
        
        for(int i = 0; i != sizeof(char)*8; i++)
        {
            char tmp = cCurrData << i;
            tmp = tmp >> (sizeof(char)*8 - 1);
            tmp = tmp & 1;
            m_vStreamData.push_back(tmp);
        }
    }
}

void GolombDecoder::_golombDecoder()
{
    double dValue = log2(m_iM);
    int iValue = dValue;
    
    if( dValue - iValue == 0)
    {
        _golombDecoderEven();
    }
    else
    {
        _golombDecoderUneven();
    }
}

void GolombDecoder::_golombDecoderEven()
{
    int i = 0;
    while(i < m_vStreamData.size())
    {
        int q = 0;
        while(true)
        {
            if(m_vStreamData[i] == 1)
            {
                q++;
                i++;
                if(i >= m_vStreamData.size())
                    return;
            }
            else
                break;
        }
        
        if(m_vStreamData[i] == 0)
        {
            i++;
            if(i >= m_vStreamData.size())
                return;
        }
        
        int b = log2(m_iM);
        
        int r = 0;
        for(int j = 0; j < b; j++, i++)
        {
            r = r * 2 + m_vStreamData[i];
            
            if(i >= m_vStreamData.size())
                return;
        }
        
        m_vDstData.push_back(m_iM * q + r);
    }
}

void GolombDecoder::_golombDecoderUneven()
{
    int i = 0;
    while(i < m_vStreamData.size())
    {
        int q = 0;
        while(true)
        {
            if(m_vStreamData[i] == 1)
            {
                q++;
                i++;
                if(i >= m_vStreamData.size())
                    return;
            }
            else
                break;
        }
        
        if(m_vStreamData[i] == 0)
        {
            i++;
            if(i >= m_vStreamData.size())
                return;
        }
        
        int b = ceil(log2(m_iM));
        
        int r = 0;

        for(int j = 0; j < b; j++, i++)
        {
            r = r * 2 + m_vStreamData[i];
            
            if(j == b - 2)
            {
                
                if(r < pow(2,b) - m_iM)
                {
                    
                    i++;
                    break;
                }
            }
            
            if(j == b - 1)
            {
                r = r - (pow(2,b) - m_iM);
                i++;
                break;
            }
            

            
            if(i >= m_vStreamData.size())
                return;
        }
        
        m_vDstData.push_back(m_iM * q + r);
    }
}