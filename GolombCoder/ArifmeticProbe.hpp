//
//  ArifmeticProbe.hpp
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef ArifmeticProbe_hpp
#define ArifmeticProbe_hpp

#include <stdio.h>
#include <map>
#include <vector>

class СArifmeticProbe
{
    typedef std::pair<double, double>       pair_borders;
    
    std::map<int, pair_borders>             m_mBorders;
    
    
public:
    
    
    СArifmeticProbe(int iSize);
    СArifmeticProbe(std::map<int, std::map<int, int> >);
    СArifmeticProbe(std::vector<int>, int iSize);
    
public:
    std::map<int, pair_borders>             getProbe();
};

#endif /* ArifmeticProbe_hpp */
