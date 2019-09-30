#ifndef _misc
#define _misc

typedef enum scheduling_policy_t{
    FIFO,
    RR,
    PRIORITY,
} scheduling_policy_t;

typedef enum execution_policy_t{
    PREEMPTIVE,
    NONPREEMPTIVE,
} execution_policy_t;

/**  * Definition of boolean values.  */
typedef enum bool_t {
    FALSE = 0,
    TRUE = 1
} bool_t;

#endif
