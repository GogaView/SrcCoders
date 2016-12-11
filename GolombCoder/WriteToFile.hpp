//
//  WriteToFile.hpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef WriteToFile_hpp
#define WriteToFile_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

class CWriteToFile
{
    std::vector<int>                m_lStream;
    
    
public:
                                    CWriteToFile(std::string strFile, std::vector<int> vData)
    :m_lStream(vData)
    {
        _writeToFile(strFile, _toBitstream());
    }
    
    CWriteToFile(std::string strFile, std::vector<int> vData, int)
    :m_lStream(vData)
    {
        _writeToFile(strFile, m_lStream);
    }
    
private:
    template<typename T>
    void                            _writeToFile(std::string, std::vector<T> );
    std::vector<char>               _toBitstream();
    char                            _getBitCode(int iFirstBit);
    
};

template<typename T>
void CWriteToFile::_writeToFile(std::string strFile, std::vector<T> vData)
{
    
    std::ofstream outFile;
    outFile.open(strFile);
    
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        outFile << *it;
    }
}

#endif /* WriteToFile_hpp */
