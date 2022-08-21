#ifndef  GPIO_CONFIG_H
#define  GPIO_CONFIG_H


/*******************  MODE***************/
#define 	Input       0
#define     GPoutMode   1
#define      AF         2
#define     AnalogMode  3

/*******************  TYPE***************/
#define OUT_PUSHPULL    0
#define OUT_OPENDRAIN   1

/*******************  SPEED***************/
#define LOW_S           0
#define Medium_S        1
#define High_S          2
#define VeryHigh_S      3

/*******************  puLL UP-DOWN ***************/
#define NOPullup_down   0
#define Pull_up         1
#define Pull_down       2
#define Reserved        3

/**********************  PORT A *************************/
 /* PORT A Mode */
#define M_PORTA_0     GPoutMode
#define M_PORTA_1     GPoutMode
#define M_PORTA_2     Input
#define M_PORTA_3     GPoutMode
#define M_PORTA_4     GPoutMode
#define M_PORTA_5     Input
#define M_PORTA_6     GPoutMode
#define M_PORTA_7     GPoutMode
#define M_PORTA_8     GPoutMode
#define M_PORTA_9     GPoutMode
#define M_PORTA_10    GPoutMode
#define M_PORTA_11    GPoutMode
#define M_PORTA_12    GPoutMode
#define M_PORTA_15    GPoutMode
/*PORT A Mode */
#define T_PORTA_0     OUT_OPENDRAIN
#define T_PORTA_1     OUT_OPENDRAIN
#define T_PORTA_2     OUT_PUSHPULL
#define T_PORTA_3     OUT_PUSHPULL
#define T_PORTA_4     OUT_PUSHPULL
#define T_PORTA_5     OUT_PUSHPULL
#define T_PORTA_6     OUT_PUSHPULL
#define T_PORTA_7     OUT_PUSHPULL
#define T_PORTA_8     OUT_PUSHPULL
#define T_PORTA_9     OUT_PUSHPULL
#define T_PORTA_10    OUT_PUSHPULL
#define T_PORTA_11    OUT_PUSHPULL
#define T_PORTA_12    OUT_PUSHPULL
#define T_PORTA_15    OUT_PUSHPULL
/* PORT A Speed */

#define S_PORTA_0       Medium_S
#define S_PORTA_1       Medium_S
#define S_PORTA_2       Medium_S
#define S_PORTA_3       Medium_S
#define S_PORTA_4       Medium_S
#define S_PORTA_5       Medium_S
#define S_PORTA_6       Medium_S
#define S_PORTA_7       Medium_S
#define S_PORTA_8       Medium_S
#define S_PORTA_9       Medium_S
#define S_PORTA_10      Medium_S
#define S_PORTA_11      Medium_S
#define S_PORTA_12      Medium_S
#define S_PORTA_15      Medium_S
/* PORT A pullup-down */
#define P_PORTA_0       NOPullup_down
#define P_PORTA_1       NOPullup_down
#define P_PORTA_2       Pull_up
#define P_PORTA_3       NOPullup_down
#define P_PORTA_4       NOPullup_down
#define P_PORTA_5       Pull_up
#define P_PORTA_6       NOPullup_down
#define P_PORTA_7       NOPullup_down
#define P_PORTA_8       NOPullup_down
#define P_PORTA_9       NOPullup_down
#define P_PORTA_10      NOPullup_down
#define P_PORTA_11      NOPullup_down
#define P_PORTA_12      NOPullup_down
#define P_PORTA_15      NOPullup_down


/**********************  PORT B *********************/

#define M_PORTB_0     GPoutMode
#define M_PORTB_1     GPoutMode
#define M_PORTB_2     GPoutMode
#define M_PORTB_3     GPoutMode
#define M_PORTB_4     GPoutMode
#define M_PORTB_5     GPoutMode
#define M_PORTB_6     GPoutMode
#define M_PORTB_7     GPoutMode
#define M_PORTB_8     GPoutMode
#define M_PORTB_9     GPoutMode
#define M_PORTB_10    GPoutMode
#define M_PORTB_11    GPoutMode
#define M_PORTB_12    GPoutMode
#define M_PORTB_13    Input
#define M_PORTB_14    GPoutMode
#define M_PORTB_15    GPoutMode

#define T_PORTB_0     OUT_PUSHPULL
#define T_PORTB_1     OUT_PUSHPULL
#define T_PORTB_2     OUT_PUSHPULL
#define T_PORTB_3     OUT_PUSHPULL
#define T_PORTB_4     OUT_PUSHPULL
#define T_PORTB_5     OUT_PUSHPULL
#define T_PORTB_6     OUT_PUSHPULL
#define T_PORTB_7     OUT_PUSHPULL
#define T_PORTB_8     OUT_PUSHPULL
#define T_PORTB_9     OUT_PUSHPULL
#define T_PORTB_10    OUT_PUSHPULL
#define T_PORTB_12    OUT_PUSHPULL
#define T_PORTB_13    OUT_PUSHPULL
#define T_PORTB_14    OUT_PUSHPULL
#define T_PORTB_15    OUT_OPENDRAIN
/* Speed */
#define S_PORTB_0       Medium_S
#define S_PORTB_1       Medium_S
#define S_PORTB_2       Medium_S
#define S_PORTB_3       Medium_S
#define S_PORTB_4       Medium_S
#define S_PORTB_5       Medium_S
#define S_PORTB_6       Medium_S
#define S_PORTB_7       Medium_S
#define S_PORTB_8       Medium_S
#define S_PORTB_9       Medium_S
#define S_PORTB_10      Medium_S
#define S_PORTB_12      Medium_S
#define S_PORTB_13      Medium_S
#define S_PORTB_14      Medium_S
#define S_PORTB_15      Medium_S
/* pullup-down */
#define P_PORTB_0       NOPullup_down
#define P_PORTB_1       NOPullup_down
#define P_PORTB_2       NOPullup_down
#define P_PORTB_3       NOPullup_down
#define P_PORTB_4       NOPullup_down
#define P_PORTB_5       NOPullup_down
#define P_PORTB_6       NOPullup_down
#define P_PORTB_7       NOPullup_down
#define P_PORTB_8       NOPullup_down
#define P_PORTB_9       NOPullup_down
#define P_PORTB_10      NOPullup_down
#define P_PORTB_12      NOPullup_down
#define P_PORTB_13      Pull_up
#define P_PORTB_14      NOPullup_down
#define P_PORTB_15      NOPullup_down

/**********************  PORT C ********************/

#define M_PORTC_13    GPoutMode
#define M_PORTC_14    GPoutMode
#define M_PORTC_15    GPoutMode
/* */
#define T_PORTC_13    OUT_PUSHPULL
#define T_PORTC_14    OUT_PUSHPULL
#define T_PORTC_15    OUT_OPENDRAIN
/* */
#define S_PORTC_13      Medium_S
#define S_PORTC_14      Medium_S
#define S_PORTC_15      Medium_S
/* */
#define P_PORTC_13      NOPullup_down
#define P_PORTC_14      NOPullup_down
#define P_PORTC_15      OUT_OPENDRAIN



#endif
