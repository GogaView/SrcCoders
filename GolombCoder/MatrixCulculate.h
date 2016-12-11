//
//  MatrixCulculate.h
//  Grancin Dopusk1
//
//  Created by MacBook on 26.04.16.
//  Copyright (c) 2016 kosa. All rights reserved.
//

#ifndef __Grancin_Dopusk1__MatrixCulculate__
#define __Grancin_Dopusk1__MatrixCulculate__

#include <stdio.h>
#include <vector>
#include <map>

class CMatrixCalculate
{
    typedef std::vector<std::vector<double>> t_matrix;
    
public:
    t_matrix                        m_matIn;
    t_matrix                        m_matOrigIn;
    t_matrix                        m_matOut;
    t_matrix                        inv;
    
    
    std::vector < std::vector<double> >     a;
    
public:
    std::vector<double>                     ans;
    
    
public:
                                    CMatrixCalculate(std::map<int, std::map<int, int> >&);
    
    
    int                             gauss();
};

#endif /* defined(__Grancin_Dopusk1__MatrixCulculate__) */
