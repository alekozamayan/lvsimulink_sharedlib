#ifndef DEFLIST_H
#define DEFLIST_H

/*
* This header holds the input/output cluster interface
* define list.
* NI_INPUT_LIST stands for the input interface from LabView
* NI_OUTPUT_LIST stands for the output interface from LabView
*
* In both lists, user should define the Call Library Function
* Node interfaces in the correct order. To lookup the order:
* After creating the input/output clusters and wiring them
* to the Call Library Function Node,
* - right click to the node, click "Configure"
* - set the function name as "alg_step"
* - on the Parameters tab, add 2 arguments as "input", "output"
* - set both argument types as "Adapt to Type", "Handle by Value"
* - exit and right click to node again, click "Create C File"
* - in the created C file, check input and output structure order and element types
*
*
* After being sure about the input/output structure,
* populate the NI_INPUT_LIST and NI_OUTPUT_LIST with the
* entries below:
*
* NI_NUM(TYPE, NAME) : Stands for numeric types.
* NI_ARR(TYPE, NAME) : Stands for array types.
*    \ TYPE : Correspondent type of the parameter in the Simulink algorithm 
*             (See the explanation of TYPE below for full list)
*    \ NAME : Correspondent name of the parameter in the Simulink algorithm
*
*
* The parameter TYPE explained in the list below (it is valid for x86 Linux targets)
* 
*
* 
*  |  LabView(VI)  |    Simulink(C)   |
*  |---------------|------------------|
*  |      I8       |       int8_T     |
*  |      I16      |       int16_T    |
*  |      I32      |       int32_T    |
*  |      I64      |       int64_T    |
*  |      U8       |       uint8_T    |
*  |      U16      |       uint16_T   |
*  |      U32      |       uint32_T   |
*  |      U64      |       uint64_T   |
*  |      SGL      |       real32_T   |
*  |      DBL      | real_T, real64_T |
*
*
* The produced shared library (.so) will export two methods below: 
*
* void alg_step(const void* input, void* output) :
*     \ This is the step function of algorithm. 
*     \ input: The input cluster. Should be provided in every loop
*     \ output: The output cluster. Should be provided in every loop.
*               The function will fill this cluster with the resulted
*               data
*
* void alg_initialize() :
*     \ This is the initialization method of algorithm.
*     \ It has no arguments or return data.
*     \ It must be called once at the start of the application,
*     \ otherwise, the call to alg_step may produce unexpected results.
*
*/


#define NI_INPUT_LIST \
    NI_ARR(real32_T, numerator)\
	NI_ARR(int16_T,  denominator)\
	NI_ARR(real_T,   testval)
    

#define NI_OUTPUT_LIST \
    NI_ARR(int32_T,  division)\
    NI_ARR(real32_T, absval)\
    NI_ARR(real32_T, sqroot)\
    NI_ARR(real_T,   testval)


#endif