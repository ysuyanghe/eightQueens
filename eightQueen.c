/*
 * =====================================================================================
 *
 *       Filename:  eightQueen.c
 *
 *    Description:  
 *
 *        Version:  1.0 
 *        Created:  12/19/2016 09:40:53 AM
 *       Revision:  
 *       Compiler:  gcc
 *
 *         Author:  yanghe 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int over=0;

void showArray (int(* Queen)[2]);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  valueCompare
 *  Description:  
 * =====================================================================================
 */
	int 
valueCompare (int (* Queen)[2],int i)
{
	int k;
	int sum=Queen[i][0]+Queen[i][1];
	int diff=Queen[i][0]-Queen[i][1];
	for(k=0;k<8;k++)
	{
		if(k!=i)
		{
			if((Queen[i][0]==Queen[k][0])||(Queen[i][1]==Queen[k][1])
			              ||(sum==(Queen[k][0]+Queen[k][1]))||(diff==(Queen[k][0]-Queen[k][1])))
				return -1;
		}
	}
	return 0;
}		/* -----  end of function valueCompare  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  eightQueen
 *  Description:  
 * =====================================================================================
 */
	void
eightQueen (int (*Queen)[2],int i)
{
   int j=0,k=0;
   int sum,diff;
   int columnNum=0;
   int valueRes=0;
   static int uQueen=0;
   while(i<8)
   {
   	for(j=0;j<8;j++)
	{
            Queen[i][0]=i;
	    Queen[i][1]=j;
	    valueRes=valueCompare(Queen,i);
	    if(valueRes==0&&i<7)
	    {
	    	over=1;
	    	eightQueen(Queen,i+over);
	    }
	    if(valueRes==0&&i==7)
	    {
		    uQueen++;
		    printf("%d  :",uQueen);
		    showArray(Queen);
		    Queen[7][0]=10;
		    Queen[7][1]=100;
		    return ;
	    }
	}
	Queen[i][0]=10;
	Queen[i][1]=100;
	over=-1;
	return ;
	
   }
   return ;
}		/* -----  end of function eightQueen  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  showArray
 *  Description:  
 * =====================================================================================
 */
	void
showArray (int(* Queen)[2])
{
	int k,j;
//	for(k=0;k<8;k++)
//		for(j=0;j<2;j++)
//			printf("%d ",Queen[k][j]);
	for(k=0;k<8;k++)
		printf("%d ",Queen[k][1]);
	printf("\n");
}		/* -----  end of function show  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int k,j,i=0;
	int Queen[8][2]={10,100,10,100,10,100,10,100,
			10,100,10,100,10,100,10,100};
	showArray(Queen);
	eightQueen(Queen,i);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
