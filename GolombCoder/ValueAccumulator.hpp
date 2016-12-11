//
//  ValueAccumulator.hpp
//  GolombCoder
//
//  Created by MacBook on 20.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef ValueAccumulator_hpp
#define ValueAccumulator_hpp

#include <stdio.h>
#include <vector>
#include <map>

class CValueAccumulator
{
    typedef std::vector< std::vector<double> > vect_prob;
    
    vect_prob                               m_vProbe;
    std::vector<int>                        m_vValues;
    
    
    
public:
                                            CValueAccumulator(std::vector<int>);
                                            CValueAccumulator(vect_prob);
    
    
    std::map<int, int>                      getAccumNormal();
    std::map<int, std::map<int, int> >      getAccumNormalByPairs();
    
private:
    void                                    _makeProbMap();
};

#endif /* ValueAccumulator_hpp */
