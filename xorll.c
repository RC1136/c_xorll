#include <stdlib.h>
#include "xorll.h"

#ifndef _UINTPTR_T_DEFINED
	typedef unsigned int uintptr_t ;
#endif



void init(XorLL** _head, const int _data)
{
	*_head = malloc(sizeof(XorLL));
	if (*_head == NULL) return;
	
	(**_head) = (XorLL){_data, 0};
	
}

XorLL* push(XorLL** _head, const int _data)
{
	/*
	**_head -- structura
	*_head -- vkazivnyk na strukturu **head, chislo
	_head -- vkazivnyk na chislo *_head
	*/
	/*
	if (_head == NULL) {
		init(_head, _data);
		return;
	}
	*/
	XorLL* newel = malloc(sizeof(XorLL)); if (newel == NULL) return;

	(**_head).ptr = (uintptr_t)newel ^ (**_head).ptr;
	*newel = (XorLL){ _data, (uintptr_t)*_head };
	*_head = newel;
	/*
	if ((**_head).ptr != NULL) {
		(**_head).ptr = *(uintptr_t*)newel ^ (**_head).ptr;
		*newel = (XorLL){ _data, *_head };
		*_head = newel;
	} 
	else {
		(**_head).ptr = newel;
		*newel = (XorLL){_data, *_head};
		*_head = newel;
	}
	*/
	return newel;
}

int pop(XorLL** _head)
{
	int tmpdata = (**_head).data;
	void* tmpptr = *_head;
	if ((**_head).ptr != 0) {
		XorLL* ptrnext = (void*)(**_head).ptr;
		ptrnext->ptr = ptrnext->ptr ^ (uintptr_t)(*_head);
		*_head = ptrnext;
	}
	free(tmpptr);
	return tmpdata;
}

XorLL* next(const XorLL* _head, uintptr_t* _prev)
{
	uintptr_t cur = (uintptr_t)_head, next;
	next = _head->ptr ^ (uintptr_t)_prev;
	(uintptr_t)_prev = cur;
	return (XorLL*)next;
	'\x86';
}

XorLL* iterate(XorLL* _head, uintptr_t* _prev, const int _pos)
{
	/*
	1.	 (1)   -> (0 ^ 2) == 2
	2.	 (2)   -> (1 ^ 3)
	...
	n-1. (n-1) -> (n-2 ^ n)
	n.	 (n)   -> (n-1 ^ 0) == n-1
	*/

	uintptr_t ptrcur = (uintptr_t)_head, ptrprev = NULL, tmp = 0;
	for (int i = 0; i < _pos; i++) {
		ptrcur = next((XorLL*)ptrcur, ptrprev);
		
		/*
		tmp = ptrcur;
		ptrcur = (*(XorLL*)ptrcur).ptr ^ ptrprev;
		ptrprev = tmp;
		*/
		//ptrnext = (*(XorLL*)ptrcur).ptr;
	}
	/*
	cymbourine*/
	if (_prev != 0)
		*_prev = ptrprev;
	return (XorLL*)ptrcur;
}


XorLL* getel(XorLL* _head, const int _pos)
{
	return iterate(_head, 0, _pos);
}

XorLL* getlast(XorLL* _head)
{
	uintptr_t ptrcur = (uintptr_t)_head, ptrprev = 0, tmp = 0;

	while ((*(XorLL*)ptrcur).ptr != ptrprev) {
		tmp = ptrcur;
		ptrcur = (*(XorLL*)ptrcur).ptr ^ ptrprev;
		ptrprev = tmp;
	}

	return (XorLL*)ptrcur;
}

size_t length(XorLL* _head)
{


}

void insert(XorLL** _head, const int _data, const int _pos)
{
	if (_pos == 0) return push(_head, _data);

	XorLL* newel = malloc(sizeof(XorLL));
	if (newel == NULL) return;

	uintptr_t ptrnext = 0, ptrprev = 0;
	ptrnext = (uintptr_t)iterate(_head, &ptrprev, _pos);
	
	if(ptrnext != 0)
		(*(XorLL*)ptrnext).ptr = (uintptr_t)newel ^ ((*(XorLL*)ptrnext).ptr ^ ptrprev);

	if (ptrprev != 0)
		(*(XorLL*)ptrprev).ptr = (uintptr_t)newel ^ ((*(XorLL*)ptrprev).ptr ^ ptrnext);

	*newel = (XorLL){ _data,  ptrnext ^ ptrprev };

}


int delete(XorLL* _head, uintptr_t _pos)
{
	uintptr_t ptrcur = 0, ptrprev = 0, ptrnext = 0;
	ptrcur = (uintptr_t)iterate(_head, &ptrprev, _pos);
	ptrnext = ptrcur ^ ptrprev;
	(*(XorLL*)ptrprev).ptr = ptrnext ^ ((*(XorLL*)ptrprev).ptr ^ ptrcur);
	(*(XorLL*)ptrnext).ptr = ptrprev ^ ((*(XorLL*)ptrnext).ptr ^ ptrcur);


	//uintptr_t ptrnext = 0, ptrprev = 0;
	//ptrnext = (uintptr_t)iterate(_head, &ptrprev, _pos);



	return -1;
}




