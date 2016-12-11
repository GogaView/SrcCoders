//
//  GolombCoder.hpp
//  GolombCoder
//
//  Created by MacBook on 14.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef GolombCoder_hpp
#define GolombCoder_hpp

#include <stdio.h>
#include <list>
#include <vector>

class GolombCoder
{
    std::vector<int>                    m_lSrcData;
    std::vector<char>                   m_lStream;
    std::vector<char>                   m_lBitstream;
    int                                 m_iM;
    double                              m_dP;
    
public:
                                        GolombCoder(int, double);
    
public:
    void                                coding(std::vector<int>);
    std::vector<char>                   getBitstream();
    
private:
    void                                _processing();
    std::vector<char>                   _createGolombCode(int);
    std::vector<char>                   _createEvenGolombCode(int);
    std::vector<char>                   _createUnevenGolombCode(int);
    
    
    std::vector<char>                   _toBitstream();
    char                                _getBitCode(int);
    
    void                                _writeToFile();
    
};

#endif /* GolombCoder_hpp */
