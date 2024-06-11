#include "ClusterAlg.h"
#include "ClusterAlg_private.h"
#include <string.h>


ExtU_ClusterAlg_T ClusterAlg_U;
ExtY_ClusterAlg_T ClusterAlg_Y;

void ClusterAlg_step()
{
    int i = 0;
    for(; i < PARAMETER_COUNT; ++i)
    {
        // Make division
        ClusterAlg_Y.division[i] = (int32_T)(ClusterAlg_U.numerator[i] / ClusterAlg_U.denominator[i]);
        
        // Absolute value
        ClusterAlg_Y.absval[i] = fabsf(ClusterAlg_U.numerator[i]);
        
        // Square root
        ClusterAlg_Y.sqroot[i] = sqrtf(ClusterAlg_U.numerator[i]);
    }
    
    // Sum test val
    for(i = 0; i < TESTPARAM_COUNT; ++i)
    {
        ClusterAlg_Y.testval[i] = testval_memorized[i] + ClusterAlg_U.testval[i];
        testval_memorized[i] = ClusterAlg_Y.testval[i];
    }
}

void ClusterAlg_initialize()
{
    memset(testval_memorized, 0, sizeof(testval_memorized));
    
    memset(&ClusterAlg_U, 0, sizeof(ClusterAlg_U));
    memset(&ClusterAlg_Y, 0, sizeof(ClusterAlg_Y));
}