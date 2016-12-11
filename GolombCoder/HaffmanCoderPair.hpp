//
//  HaffmanCoderPair.hpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanCoderPair_hpp
#define HaffmanCoderPair_hpp

#include <stdio.h>
#include <vector>
#include <map>

class CHaffmanCoderPair
{
    std::map<int, std::map<int, std::vector<int> > > m_haffmanData;
    
    
    std::vector<int>            m_vCodeData;
    
public:
    CHaffmanCoderPair();
    void                        coding(std::vector<int>);
    std::vector<int>            getCodingData();
    void                        setHaffmanMap(std::map<int, std::map<int, std::vector<int> > >);
    
};

#endif /* HaffmanCoderPair_hpp */
