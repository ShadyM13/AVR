/****************************/
/*  Author:  Omar Morsy     */
/*  Date:    August 4, 2020 */
/*  Version: 1.0            */
/****************************/

#ifndef LBIT_MATH_H
#define LBIT_MATH_H

#define SET_BIT(Reg, Bit)      Reg |=  (1<<Bit)
#define CLEAR_BIT(Reg, Bit)    Reg &= ~(1<<Bit)
#define TOGGLE_BIT(Reg, Bit)   Reg ^=  (1<<Bit)
#define GET_BIT(Reg, Bit)      ((Reg >> Bit)&1)



#endif