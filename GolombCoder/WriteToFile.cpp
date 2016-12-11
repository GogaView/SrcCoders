//
//  WriteToFile.cpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "WriteToFile.hpp"





std::vector<char> CWriteToFile::_toBitstream()
{
    int iVectorSize = ceil( static_cast<double>(m_lStream.size()) / (sizeof(char) * 8) );
    
    std::vector<char> outpudData;
    for(int i = 0; i != iVectorSize; i++)
    {
        outpudData.push_back(_getBitCode(i * sizeof(char) * 8));
    }
    
    return outpudData;
    
}

char CWriteToFile::_getBitCode(int iFirstBit)
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
