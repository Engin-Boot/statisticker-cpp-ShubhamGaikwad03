#include "stats.h"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

Stats Statistics::ComputeStatistics(const std::vector<float>& value) {
    //Implement statistics here
    Stats st;
    if (value.empty())   // Error condition
    {
        st.average = NAN;
        st.min = NAN;
        st.max = NAN; 
        return st;
    }
    float sum=0;
    st.min = *min_element(value.begin(),value.end());
    st.max = *max_element(value.begin(), value.end());
    int count=0;
    for (int i = 0; i < value.size(); i++)
    {
        if(!insan(value[i]))
        {
        sum = sum + value[i];
        count=count+1;
        }
    }
    st.average = sum/count;
    return st;
}
