/*********************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Kolokythas Christos - 25/3/2018>
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "tameio.h"

int main(void)
{	TOuras      	oura;				 /*oura pelatwn-aytokinhtvn */
	TTameio			*p;				   	//gia na desmeusoyme dynamika pinaka gia ta tameia

	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*megistos xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos poy paramenei anoikth h trapeza */
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	enapomenon_xronos;	 /*xronos gia to telos e3yphrethshs enos pelath*/
	unsigned int	xronos_anamonis;
	unsigned int	extra_xronos;		//extra xronos pou menei anoikth h trapeza mexri na ejipiretithoun oloi oi pelates
	unsigned int	arithmos_pelaton;
	
	TSOuras			Pelatis;		 	/* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int             tamiasInactive=0;
	unsigned int	arithmostameion;
	time_t			t;
	
	int temp,i;

	printf("Dwste units of time poy paramenei anoikth h trapeza (0 <=), pi8anothta afikshs in unit of time (0,1) kai megisto xrono e3yphrethshs (>=1) in units of time kai ton arithmo twn tameion(>=0)\n");
	scanf("%u %f %u %u",&xronos_prosomoiosis,&pithanotita_afiksis,&xronos_eksipiretisis,&arithmostameion);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai sta9erh %d units of time .\n",xronos_eksipiretisis);
	printf("");
	
	OuraDimiourgia(&oura);
	
	p=malloc(arithmostameion*sizeof(TTameio));	 //desmebei enan pinaka gia ta tameia
	if(p==NULL){
		printf("Cannot allocate memory \n");
		return 1;
	}
	
	for(i=0;i<arithmostameion;i++)
		TameioDimiourgia(&p[i]);
	
	xronos = 0;
	enapomenon_xronos = 0;
	xronos_anamonis =0;
	srand(time(&t));
			
	while( xronos < xronos_prosomoiosis || !OuraKeni(oura))
	{	/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		
		if(xronos<xronos_prosomoiosis){
	
		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
			temp=rand()%xronos_eksipiretisis+1; 			//dimioyrgei tyxaio xrono eksipiretisis
			PelatisSetXronoEksipiretisis(&Pelatis,temp);
			temp=PelatisGetXronoEksipiretisis(&Pelatis);
			if (!OuraProsthesi(&oura, Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	};
    	};
    }
    
    	/* Tamias-Elegxos */
    	for(i=0;i<arithmostameion;i++)
		{	
		if ( TameioFree(p[i]) == 0)												/*eley8eros tamias*/
			if (!OuraKeni(oura))												/*yparxei pelaths*/
			{	OuraApomakrynsh(&oura,&Pelatis);								/*phgainei sto tamio*/
				xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
				TameioNewCustomer(&p[i],PelatisGetXronoEksipiretisis(&Pelatis));
				enapomenon_xronos =xronos_eksipiretisis-1; 						/* kallyptei to trexon unit time */
			}else TameioNoWork(&p[i]);
		else {
			TameioInService(&p[i]);												/*o tamias apasxolhmenos me pelath */
			TameioBusy(&p[i]);
		}
	}
		if(xronos>xronos_prosomoiosis)
			extra_xronos=extra_xronos+1;
		xronos++; 						/*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} 									/*while( xronos < xronos_prosomoiosis )*/

	for(i=0;i<arithmostameion;i++){
				
	printf("\nGia to tameio %d einai \n",i+1);
	printf("\nEksyphreth8hkan %d pelates\n",TameioGetArithmosPelatwn(p[i]));
	printf("O tamias htan adranhs gia %d units of time\n", TameioGetInactiveXronos(p[i]));
	printf("Den eksyphreththikan %d pelates \n",OuraGetSize(oura));
	printf("O xronos poy htan apasxolhmeno htan %d \n",TameioGetBusyXronos(p[i]));
}

for(i=0;i<arithmostameion;i++)
	arithmos_pelaton=arithmos_pelaton+TameioGetArithmosPelatwn(p[i]); 		//briskei ton arithmo twn pelatwn
	
	if (arithmos_pelaton == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)arithmos_pelaton);
		
	printf("\nO mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);
	printf("O xronos einai %d kai o extra xronos einai %d \n",xronos_prosomoiosis+extra_xronos,extra_xronos);

	return 0;
 
}

