//
//  MatrixCulculate.cpp
//  Grancin Dopusk1
//
//  Created by MacBook on 26.04.16.
//  Copyright (c) 2016 kosa. All rights reserved.
//

#include "MatrixCulculate.h"

#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <iostream>


CMatrixCalculate::CMatrixCalculate(std::map<int, std::map<int, int> >& mapProb)
{
    
    a.resize(mapProb.size());
    for(int i = 0; i != mapProb.size(); i++)
    {
        a[i].resize(mapProb.size());
    }
    
    for(int i = 0; i != a.size(); i++)
    {
        for(int j = 0; j != a.size(); j++)
        {
            a[i][j] = mapProb[i][j];
        }
    }
    
    for(int i = 0; i != a.size(); i++)
    {
        int iVal = 0;
        for(int j = 0; j != a.size(); j++)
        {
            iVal += a[i][j];
        }
        
        for(int j = 0; j != a.size(); j++)
        {
            a[i][j] /= iVal;
        }
    }
    
    m_matOrigIn = a;
    
    for(int i = 0; i != a.size(); i++)
    {
        a[i][i] -= 1;
    }
    
    for(int i = 0; i != a.size(); i++)
    {
        a[a.size() - 1][i] = 1;
    }
    
    
    for(int i = 0; i != a.size() - 1; i++)
    {
        a[i].push_back(0);
    }
    
    a[a.size() - 1].push_back(1);
    
    
}

using namespace std;
#define INF INT_MAX
#define EPS 0.000000000001


int CMatrixCalculate::gauss ()
{
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
        
        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }
    
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}


