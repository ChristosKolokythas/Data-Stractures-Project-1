/***************************************************************
Arxeio ylopoihshs	: tameio.c
Skopos				: ulopoihsh typou stoixeioy twn tameiwn
Revision 			:  <Kolokythas Christos - 25/3/2018>
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tameio.h"

void TameioDimiourgia(TTameio *tameio) 
{
	tameio->timebusy=0;
	tameio->timeinactive=0;
	tameio->arithmospelaton=0;
	tameio->enapominonxronos=0;
}

void TameioNewCustomer(TTameio *tameio, int Duration){
	tameio->arithmospelaton++;
	tameio->enapominonxronos=Duration;
}

void TameioInService(TTameio *tameio){
	tameio->enapominonxronos--;
}

void TameioNoWork(TTameio *tameio)
{
	tameio->timeinactive++;
}

void TameioBusy(TTameio *tameio){
	tameio->timebusy++;
}

int TameioFree(TTameio tameio){
	return(tameio.enapominonxronos);
}

int TameioGetArithmosPelatwn(TTameio tameio){
	return(tameio.arithmospelaton);
}

int TameioGetInactiveXronos(TTameio tameio){
	return(tameio.timeinactive);
}

int TameioGetBusyXronos(TTameio tameio){
	return(tameio.timebusy);
}
