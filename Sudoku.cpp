#include <iostream>
#include <cstdio>
#include <cstring>
#include<ctime>
#include <cstdlib>
#include"Sudoku.h" 
using namespace std;
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int row, int col, int num);
void Sudoku::printout(){
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			std::cout<<grid[i][j]<<" ";
        }
		std::cout<<std::endl;
	}
}
void Sudoku::changeRow(int a,int b){
	
	int temp,temp2,temp3; 
		for(int j=0;j<9;j++)
		{
			temp=grid[a*3][j];
			grid[a*3][j]=grid[3*b][j];
			grid[3*b][j]=temp;
			temp2=grid[a*3+1][j];
			grid[a*3+1][j]=grid[3*b+1][j];
			grid[3*b+1][j]=temp2;
			temp3=grid[a*3+2][j];
			grid[a*3+2][j]=grid[3*b+2][j];
			grid[3*b+2][j]=temp3;
		   
		}
	
};
void Sudoku::changeCol(int c,int d){
	int temp,temp2,temp3;
		for(int i=0;i<9;i++)
		{
			temp=grid[i][c*3];
			grid[i][c*3]=grid[i][3*d];
			grid[i][3*d]=temp;
			temp2=grid[i][3*c+1];
			grid[i][3*c+1]=grid[i][3*d+1];
			grid[i][3*d+1]=temp2;
			temp3=grid[i][3*c+2];
			grid[i][3*c+2]=grid[i][3*d+2];
			grid[i][3*d+2]=temp3;
        }
};
void Sudoku::changeNum(int a,int b){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(grid[i][j]==a)
				grid[i][j]=b;
			else if(grid[i][j]==b)
				 grid[i][j]=a;
		}
	}
}
void Sudoku::rotate(int n){
   n=n%4;
   int row,col;
   int rot[9][9];
   for(int count=0;count<n;count++)
   {
      	row = 0;col = 0;
		for (int i=0;i<9;i++)
			for (int j=8;j>=0;j--)
			{
				rot[row][col] = grid[j][i];
				col++;
				if (col == 9) { row++; col = 0;} 
			}
	
	for (int i=0;i<9;i++)
		for (int j=0;j<9;j++)
			grid[i][j] = rot[i][j];
	}
}


void Sudoku::flip(int n){
		int i=0;
		int j=0;
		int temp;
		if(n==0){
		  for(i=0;i<4;i++){
		  
			for(j=0;j<9;j++){
					temp=grid[i][j];
					grid[i][j]=grid[8-i][j];
					grid[8-i][j]=temp;
			}
	      } 
		}
		if(n==1){
		 for(j=0;j<4;j++){
		    for(i=0;i<9;i++){
				temp=grid[i][j];
				grid[i][j]=grid[i][8-j];
				grid[i][8-j]=temp;
			}
		}
    }
}
void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
}
void Sudoku::transform(){
	//readIn();
	change();
	//printout();
}


int Sudoku::checkre()
{    
	 //int 
	 total=0;
     //int 
	 no=0;
     //int b[N][N];
	 //int 
	 total1=0;
	 for(int row=0;row<9;row++)
	 {
	 	for(int col=0;col<9;col++)
	 	{
	 		total+=grid[row][col];
	 		total1+=grid[col][row];
	    }
	    if(total!=45||total1!=45)
	    {
	    	no++;
		}
		  total=0;
		  total1=0;
	  }
		 return no;
	 }
int Sudoku::checkret()
{    
	 //int 
	 total=0;
     //int 
	 noo=0;
     //int b[N][N];
	 //int 
	 total1=0;
	 for(int row=0;row<9;row++)
	 {
	 	for(int col=0;col<9;col++)
	 	{
	 		total+=arrayt[row][col];
	 		total1+=arrayt[col][row];
	    }
	    if(total!=45||total1!=45)
	    {
	    	noo++;
		}
		  total=0;
		  total1=0;
	  }
		 return noo;
	 }	 
bool Sudoku::SolveSudokut()
{
	int row, col;
	for(int row=0;row<9;row++){
		for(int col=0;col<9;col++){
			arrayt[row][col]=grid[row][col];
	    }
    } 
}

bool Sudoku::SolveSudokutt()
{
    int row,col;
    if (!FindUnassignedLocation(arrayt, row, col))
      return true;
    for (int num = 9; num >=1; num--)
    {
        if (isSafe(arrayt,row, col, num))
        {
            arrayt[row][col] = num;
            if (SolveSudokutt())
                return true;
            arrayt[row][col] = UNASSIGNED;
        }
    }
  return false;
}
/* assign values to all unassigned locations for Sudoku solution  
 */
bool Sudoku::SolveSudoku()
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
      return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku())
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
  return false;
}
/* Searches the grid to find an entry that is still unassigned. */
bool Sudoku::FindUnassignedLocation(int array[9][9], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (array[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Returns whether any assigned entry n the specified row matches 
   the given number. */
bool Sudoku::UsedInRow(int array[9][9],int row, int num)
{
    for (int col = 0; col < N; col++)
        if (array[row][col] == num)
            return true;
    return false;
}
 
/* Returns whether any assigned entry in the specified column matches 
   the given number. */
bool Sudoku::UsedInCol(int array[9][9], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (array[row][col] == num)
            return true;
    return false;
}
 
/* Returns whether any assigned entry within the specified 3x3 box matches 
   the given number. */
bool Sudoku::UsedInBox(int array[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (array[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
/* Returns whether it will be legal to assign num to the given row,col location. 
 */
bool Sudoku::isSafe(int array[9][9],int row, int col, int num)
{
    return !UsedInRow(array, row, num) && !UsedInCol(array, col, num) &&
           !UsedInBox(array,row - row % 3 , col - col % 3, num);
}
bool Sudoku::check()
{
	for(int row=0;row<9;row++)
	{
			for(int col=0;col<9;col++)
			{
				 if(grid[row][col]!=arrayt[row][col])
		  		 return true;
		  		
			}
		  
	}
	
	
	return false;
}
 
bool Sudoku::checkunity()
{
	for(int row=0;row<9;row++)
	{
		for(int y=0;y<9;y++)
		{
			for(int c=0;c<9;c++)
			{
				if(grid[row][y]!=0)
				if((grid[row][y]==grid[row][c])&&y!=c)
				{
					//cout<<"y="<<y<<' '<<"c="<<c<<endl;
					return false;
				}
			}	
		}	  
	}
	
	for(int col=0;col<9;col++)
	{
		for(int y=0;y<9;y++)
		{
			for(int c=0;c<9;c++)
			{
				if(grid[y][col]!=0)
				if((grid[y][col]==grid[c][col])&&y!=c)
				{
					
					return false;
				}
			}	
		}	  
	}
	
	
	return true;
} 
 
 
 
/* print grid  */
void Sudoku::printGrid()
{
	 int row,col;
	 int flag=1;
if(SolveSudoku()==false||checkre()!=0)
{
	       cout<<"0"<<endl;
	        flag=0;
	   
    
   }else
	{

             
		if(check()==false||checkret()!=0)
     	{
	
            cout<<1<<endl; 
           for (int row = 0; row < 9; row++)
         {
          for (int col = 0; col < 9; col++)
              cout<<grid[row][col]<<" ";
              cout<<endl;
           } 
        }else 
           {
         	  cout<<2;
		   }
		    
     }
   }
   
   
      
		     
  



 void Sudoku::readIn()
    {
    	for(int i=0;i<9;i++)
    	{
    		for(int j=0;j<9;j++)
    		{
    			cin>>grid[i][j];
				//scanf("%d",&grid[i][j]);
			}
		}
	}

void Sudoku::solve()
{   
	int a,b;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(grid[i][j]==0)
			a++;
			if(grid[i][j]!=0)
			b++;
			
		}
	}
	
	if(a==81) {
	cout<<"2";	return;
	}
	if(b==81){
		cout<<"1"<<endl;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{ 
		         cout<<grid[i][j]<<" ";
			}
		  cout<<endl;
		}	
	return;
	}
	
	
	if(checkunity()==false)
	{
		cout<<"0"<<endl;
		return;
	}
	
	SolveSudokut();
	SolveSudokutt();
	SolveSudoku();
	checkre();
	checkret();
    printGrid();
}



void Sudoku::giveQuestion(){
	int c[9][9]={{3,0,6,5,0,8,4,0,0},
		         {5,2,0,0,0,0,0,0,0},
				 {0,8,7,0,0,0,0,3,1},
				 {0,0,3,0,1,0,0,8,0},
				 {9,0,0,8,6,3,0,0,5},
				 {0,5,0,0,9,0,0,0,0},
				 {1,3,0,0,0,0,2,5,0},
				 {0,0,0,0,0,0,0,7,4},
				 {0,0,5,2,0,6,3,0,0}};
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			std::cout<<c[i][j]<<" ";
		}
	   std::cout<<std::endl;
	}
		
}
 
