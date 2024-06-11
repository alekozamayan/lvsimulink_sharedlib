/*
 * File: ClusterAlg.h
 *
 * Code generated for Simulink model 'ClusterAlg'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ClusterAlg_h_
#define RTW_HEADER_ClusterAlg_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ClusterAlg_COMMON_INCLUDES_
# define ClusterAlg_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* ClusterAlg_COMMON_INCLUDES_ */

#include "ClusterAlg_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define PARAMETER_COUNT 3
#define TESTPARAM_COUNT 5

typedef struct {
    real32_T numerator[PARAMETER_COUNT];
    int16_T denominator[PARAMETER_COUNT];
    real_T testval[TESTPARAM_COUNT];
} ExtU_ClusterAlg_T;

typedef struct {
    int32_T division[PARAMETER_COUNT];
    real32_T absval[PARAMETER_COUNT];
    real32_T sqroot[PARAMETER_COUNT];
    real_T testval[TESTPARAM_COUNT];
} ExtY_ClusterAlg_T;

extern ExtU_ClusterAlg_T ClusterAlg_U;
extern ExtY_ClusterAlg_T ClusterAlg_Y;

void ClusterAlg_step();

void ClusterAlg_initialize();


#endif                                 /* RTW_HEADER_ClusterAlg_h_ */
