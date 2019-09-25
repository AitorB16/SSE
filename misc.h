#ifndef _misc
#define _misc

typedef enum planifikazio_politika_t{
    FIFO,
    RR,
    LEHENTASUNA,
} planifikazio_politika_t;

typedef enum kanporaketa_politika_t{
    EZ_KANPORATZAILEA,
    KANPORATZAILEA,
} kanporaketa_politika_t;

/**  * Definition of boolean values.  */ 
typedef enum bool_t {     
    FALSE = 0, 
    TRUE = 1 
} bool_t;

#endif
