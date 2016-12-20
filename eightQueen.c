/*
 * =====================================================================================
 *
 *       Filename:  eightQueen.c
 *
 *    Description:  
 *
 *        Version:  1.0 
 *        Created:  12/19/2016 09:40:53 AM
 *       Revision:  digui hui lai de zhi budui ,i he over bianhua bu yi zhi 
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"
int over=0;
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
 *         Name:  columnCompare
 *  Description:  
 * =====================================================================================
 */
	void
columnCompare (int(*Queen)[2],int i)
{
	int j;
}		/* -----  end of function columnCompare  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  eightQueen
 *  Description:  
 * =====================================================================================
 */
	int
eightQueen (int (*Queen)[2],int i)
{
   int j=0,k=0;
   int sum,diff;
   int columnNum=0;
   int flag=0;
   while(i<8)
   {
//	printf("i=%d\n",i);
   	for(j=0;j<8;j++)
	{
            Queen[i][0]=i;
	    Queen[i][1]=j;
	    if(valueCompare(Queen,i)!=0)
		    columnNum++;
	    else
	    {
		columnNum=0;
	    	over=1;
	    	eightQueen(Queen,i+over);
	    }
	}
	if(columnNum==8||j==8)
	{
	    columnNum=0;
	    Queen[i][0]=10;
	    Queen[i][1]=100;
	    over=-1;
	    if(over<0) flag=1;
	    return -1;
	}
//	if(flag==1)
//	   return -5;
   }
   return 0;
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
	for(k=0;k<8;k++)
		for(j=0;j<2;j++)
			printf("%d",Queen[k][j]);
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
//	for(k=0;k<8;k++)
//	{
//		Queen[0][0]=0;
//		Queen[0][1]=k;
//		if(eightQueen(Queen,i)==0)
//			showArray(Queen);
//	}
	if(eightQueen(Queen,i)==0)
		showArray(Queen);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
