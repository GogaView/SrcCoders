//
//  GolombDecoder.hpp
//  GolombCoder
//
//  Created by MacBook on 15.09.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef GolombDecoder_hpp
#define GolombDecoder_hpp

#include <stdio.h>
#include <vector>
#include <cmath>

class GolombDecoder
{
    int                                         m_iM;
    
    std::vector<char>                           m_vBitStream;
    std::vector<char>                           m_vStreamData;
    std::vector<int>                            m_vDstData;
    
public:
    GolombDecoder(const std::vector<char>, int M);
    
private:
    
    void                                        _convertToByteStream();
    void                                        _golombDecoder();
    
    void                                        _golombDecoderEven();
    void                                        _golombDecoderUneven();
    
    
};



#endif /* GolombDecoder_hpp */
