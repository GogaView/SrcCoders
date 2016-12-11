//
//  HafmanCoder.hpp
//  GolombCoder
//
//  Created by MacBook on 02.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HafmanCoder_hpp
#define HafmanCoder_hpp

#include <stdio.h>
#include <vector>
#include <map>


class CHaffmanCoder
{
    std::map<int,std::vector<int>> m_haffmanData;
    
    
    std::vector<int>            m_vCodeData;
    
public:
                                CHaffmanCoder();
    void                        coding(std::vector<int>);
    std::vector<int>            getCodingData();
    void                        setHaffmanMap(std::map<int,std::vector<int>>);
    
};



#endif /* HafmanCoder_hpp */
