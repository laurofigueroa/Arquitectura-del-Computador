#ifndef __GUINDOWS_H__
#define __GUINDOWS_H__

#include <setjmp.h>

#define	TRANSFER(o, d)	(setjmp(o) == 0 ? (longjmp(d,1), 0) : 0)
typedef	jmp_buf	task;

extern void stack(task t, void (*pf)());

#endif
