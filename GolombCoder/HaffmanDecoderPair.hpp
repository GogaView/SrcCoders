//
//  HaffmanDecoderPair.hpp
//  GolombCoder
//
//  Created by MacBook on 29.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanDecoderPair_hpp
#define HaffmanDecoderPair_hpp

#include <stdio.h>
#include <vector>
#include <map>

class CHaffmanDecoderPair
{
    std::map<int, std::map<int, std::vector<int> > > m_haffmanData;
    
    
    std::vector<int>            m_vCodeData;
    
public:
    CHaffmanDecoderPair();
    void                        decoding(std::vector<int>);
    std::vector<int>            getDecodingData();
    void                        setHaffmanMap(std::map<int, std::map<int, std::vector<int> > > );
    
private:
    std::map<int, std::vector<int> >::iterator _find(int iPrev, std::vector<int>);
    
};

#endif /* HaffmanDecoderPair_hpp */
