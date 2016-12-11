//
//  HaffmanContainer.hpp
//  GolombCoder
//
//  Created by MacBook on 02.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanContainer_hpp
#define HaffmanContainer_hpp

#include <stdio.h>
#include <map>
#include <vector>

#include "HaffmanElement.hpp"

class CHaffmanContainer
{
    std::multimap<int, CHaffmanElement>         m_mmData;
    
    CHaffmanElement                             m_resElement;
    std::map<int,std::vector<int>>              m_rResMap;
    
    
public:
    void                setValues(std::map<int, int>);
    void                addValue(std::pair<int, int>);
    void                processTree();
    void                resMap();
    std::map<int,std::vector<int>> getResMap();
    
    std::map<int,std::vector<int>> getRes();
    
private:
    void                _parsChild(std::shared_ptr<CHaffmanElement>, std::vector<int>, int);
};

#endif /* HaffmanContainer_hpp */
