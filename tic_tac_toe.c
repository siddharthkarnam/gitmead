#include<stdio.h>

static int count=0;
char puzzle[3][3]= {
			0,0,0,
			0,0,0,
			0,0,0
		   };

int check()
{
	int row,col;
	for(row=0;row<3;row++)
	{
		if((puzzle[row][0]==puzzle[row][1]) && (puzzle[row][0]==puzzle[row][2]))
		{
			return(row);
		}
	}

	for(col=0;col<3;col++)
	{
		if((puzzle[0][col]==puzzle[1][col]) && (puzzle[0][col] ==puzzle[2][col]))
		{
			return(col+3);
		}
	}

	if((puzzle[0][0]==puzzle[1][1]) && (puzzle[0][0]==puzzle[2][2]))
	return(6);

	if((puzzle[0][2]==puzzle[1][1]) && (puzzle[0][2]==puzzle[2][0]))
	return(7);

	return(8);
}
	
int user_input(int row,int col,char c)
{
	int p=8;
	if((puzzle[row-1][col-1]=='X')||(puzzle[row-1][col-1]=='O'))
	{
		printf("\nLocation already has a character, please enter another location\n");
		return(-1);
	}
	
	if(row>3 || row<1  || col>3 || col<1)
	{
		printf("\nOut of bounds, please enter co-ordinates from 1-3\n");
		return(-1);
	}
	
	puzzle[row-1][col-1]=c;
	count++;

	if(count>=5)
	{
		p=check();
		if((count%2==1)&&(p!=8))
		{
			return(1);
		}
		if((count%2==0)&&(p!=8))
		{
			return(2);
		}
		if(p==8&&count==9)
		{
			return(3);
		}
	}	
	return(0);
}

void main()
{
	int row,col,l=0;
	while (l==0)
	{
		do
		{
			printf("\nPlayer 1, enter co-ordinates:\n");
			scanf("%d%d",&row,&col);
			l=user_input(row,col,'X');
		}
		while(l==-1);
		
		if(l!=0)
		break;

		do
		{
			printf("\nPlayer 2,enter co-ordinates:\n");
			scanf("%d%d",&row,&col);
			l=user_input(row,col,'O');
		}
		while(l==-1);
	}

	if(l==3)
	printf("\nTie\n");
	if(l==1)
	printf("\nPlayer 1 wins !!\n");
	if(l==2)
	printf("\nPlayer 2 wins !!\n");
}
