//
//  ArifmeticCodec.hpp
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef ArifmeticCodec_hpp
#define ArifmeticCodec_hpp

#include <stdio.h>
#include <map>
#include <vector>


class CArifmeticCoder
{
    typedef std::pair<double, double>       pair_borders;
    
    
    std::map<int, pair_borders>             m_mBorders;
    pair_borders                            m_pairOldBorder;
    
    std::vector<int>                        m_vOutput;
    
public:
                                            CArifmeticCoder(std::map<int, pair_borders> );
    
public:
    void                                    code(std::vector<int>);
    std::vector<int>                        decode(int);
    
    std::vector<int>                        getRes();
    
private:
    std::vector<int>                        _getBits(double dValue, int iSize);
    double                                  _fromBits(std::vector<int>);
    
    int                                     _decodeSign(std::map<int, pair_borders>, double);
    
    void                                    _correctBorders(std::map<int, pair_borders>&, int);
};

#endif /* ArifmeticCodec_hpp */
