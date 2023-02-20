/***********************************************************************
Arxeio ylopoihshs	: tameio.h
Skopos				: Header file gia thn diepafh typou stoixeioy twn tameiwn
Revision 			:  <Kolokythas Christos - 25/3/2018>
*********************************************************************/

typedef struct{
	int timebusy;
	int timeinactive;
	int arithmospelaton;
	int enapominonxronos;
}TTameio; //neos typos struct gia ta tameia

void TameioDimiourgia(TTameio *tameio); 
void TameioNewCustomer(TTameio *tameio, int Duration);
void TameioInService(TTameio *tameio);
void TameioNoWork(TTameio *tameio); 
void TameioBusy(TTameio *tameio); 
int TameioFree(TTameio tameio); 
int TameioGetArithmosPelatwn(TTameio tameio); 

int TameioGetInactiveXronos(TTameio tameio); 
int TameioGetBusyXronos(TTameio tameio); 
