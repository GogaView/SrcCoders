//
//  GolombGenerator.hpp
//  GolombCoder
//
//  Created by MacBook on 14.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef GolombGenerator_hpp
#define GolombGenerator_hpp

#include <stdio.h>
#include <random>
#include <vector>

class CGolombGenerator
{
    int                 m_iNumbersCount;
    double              m_dP;
    
    std::vector<int>      m_lSourceData;
    
public:
                        CGolombGenerator(int, double);
    
private:
    void                _initSourceData();
    void                _createGisto();
    
public:
    std::vector<int>      getSourceData();
    
    
};

#endif /* GolombGenerator_hpp */
