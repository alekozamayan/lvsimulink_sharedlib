
#include "deflist.h"

/* Call Library source file */ 
#define STRINGIFY(X) #X
#define MODEL_HEADER(X) STRINGIFY(X.h)
#include MODEL_HEADER(MODEL_NAME)

#include "extcode.h"

/* lv_prolog.h and lv_epilog.h set up the correct alignment for LabVIEW data. */
#include "lv_prolog.h"

/* Typedefs */
#define NI_STRUCT_DEF(TYPE)\
    typedef struct {\
        int32_t dimSize;\
        TYPE elt[1];\
    }

#define NI_NUM(TYPE,NAME) 

#define NI_ARR(TYPE,NAME)\
    NI_STRUCT_DEF(TYPE) NAME##InStruct;\
    typedef NAME##InStruct **NAME##InStructHdl;

NI_INPUT_LIST

#undef NI_ARR

#define NI_ARR(TYPE,NAME)\
    NI_STRUCT_DEF(TYPE) NAME##OutStruct;\
    typedef NAME##OutStruct **NAME##OutStructHdl;

NI_OUTPUT_LIST

#undef NI_ARR

#undef NI_NUM
/* -------- */

/* Argument defs */

#define NI_NUM(TYPE,NAME) TYPE NAME;

#define NI_ARR(TYPE,NAME) NAME##InStructHdl NAME;
typedef struct {
    NI_INPUT_LIST
} InputType;
#undef NI_ARR

#define NI_ARR(TYPE,NAME) NAME##OutStructHdl NAME;
typedef struct {
    NI_OUTPUT_LIST
} OutputType;
#undef NI_ARR

#undef NI_NUM

/* -------------- */

#include "lv_epilog.h"


#define MIN(A,B) ((A) > (B) ? (B) : (A))
#define ARRAY_SIZE(A) (sizeof(A)/sizeof((A)[0]))

#define PASTER(X,Y) X ## _ ## Y
#define EVALUATOR(X,Y) PASTER(X,Y)

#define ALGO_SYMBOL(label) EVALUATOR(MODEL_NAME,label)
#define ALGO_STEP ALGO_SYMBOL(step)
#define ALGO_INIT ALGO_SYMBOL(initialize)
#define ALGO_INPUT ALGO_SYMBOL(U)
#define ALGO_OUTPUT ALGO_SYMBOL(Y)


void alg_step(const InputType *input, OutputType *output)
{	
	/*
     * Feed input data
     */
#define NI_ARR(TYPE,NAME)\
    for(int32_t i = 0; i < MIN((int32_t)(ARRAY_SIZE(ALGO_INPUT.NAME)),(*input->NAME)->dimSize); ++i)\
        ALGO_INPUT.NAME[i] = (*input->NAME)->elt[i];

#define NI_NUM(TYPE,NAME)\
    ALGO_INPUT.NAME = input->NAME;
  
    NI_INPUT_LIST
    
#undef NI_ARR
#undef NI_NUM
     
     /*
     * Step algorithm
     */
     ALGO_STEP();
     
     /*
     * Get output data
     */

#define NI_ARR(TYPE,NAME)\
    for(int32_t i = 0; i < MIN((int32_t)(ARRAY_SIZE(ALGO_OUTPUT.NAME)),(*output->NAME)->dimSize); ++i)\
        (*output->NAME)->elt[i] = ALGO_OUTPUT.NAME[i];

#define NI_NUM(TYPE,NAME)\
    output->NAME = ALGO_OUTPUT.NAME;
  
    NI_OUTPUT_LIST
    
#undef NI_ARR
#undef NI_NUM
     
}


void alg_initialize()
{
	ALGO_INIT();
}


