//
//  MarcovGenerator.hpp
//  GolombCoder
//
//  Created by MacBook on 20.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef MarcovGenerator_hpp
#define MarcovGenerator_hpp

#include <vector>
#include <map>

class CMarcovGenerator
{
    typedef std::vector< std::vector<double> > vect_prob;
    
    enum
    {
        en_max_count        = 10000,
        en_max_prob         = 100000
    };
    
    int                     m_iSize;
    vect_prob               m_vProbMatrix;
    std::vector<int>        m_vData;
    
public:
                            CMarcovGenerator(int iSize);
                            CMarcovGenerator(vect_prob);
    
public:
    std::vector<int>        getStreamData(int iCount);
    std::map<int, std::map<int, int> > getMapForHaffman();
    std::vector<int>        getStreamData();
    
private:
    void                    _createMatrix();
    
};

#endif /* MarcovGenerator_hpp */
