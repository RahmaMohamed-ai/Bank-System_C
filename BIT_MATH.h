//BIT_MATH.h
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(r,b)	(r) |=(1<<(b))
#define CLR_BIT(r,b)	(r)&= ~(1<<(b))
#define TOG_BIT(r,b)	(r) ^= (1<<(b))
#define GET_BIT(r,b)	(1 & ((r)>>(b)))

#endif
