//
//  HaffmanDecoder.hpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanDecoder_hpp
#define HaffmanDecoder_hpp

#include <stdio.h>
#include <vector>
#include <map>

class CHaffmanDecoder
{
    std::map<int,std::vector<int>> m_haffmanData;
    
    
    std::vector<int>            m_vCodeData;
    
public:
                                CHaffmanDecoder();
    void                        decoding(std::vector<int>);
    std::vector<int>            getDecodingData();
    void                        setHaffmanMap(std::map<int,std::vector<int>>);
    
private:
    std::map<int,std::vector<int>>::iterator _find(std::vector<int>);
    
};


#endif /* HaffmanDecoder_hpp */
