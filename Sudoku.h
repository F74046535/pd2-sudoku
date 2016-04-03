class Sudoku
{
	public:
		
		bool FindUnassignedLocation( int &row, int &col);
		//bool isSafe( int row, int col, int num);
		int checkre();
		bool SolveSudokut();
		bool SolveSudokutt();
		bool SolveSudoku();
		bool FindUnassignedLocation( int array[9][9],int &row, int &col);
		bool UsedInRow(int array[9][9],int row, int num);
		bool UsedInCol(int array[9][9],int col, int num);
		bool UsedInBox(int array[9][9], int boxStartRow, int boxStartCol, int num);
		bool isSafe(int array[9][9], int row, int col, int num);
		bool check();
		void printGrid();
		void solve();
		void readIn();
		void giveQuestion();
		void printout();
		void changeRow(int a,int b);
		void changeCol(int c,int d);
		void changeNum(int a,int b);
		void rotate(int n);
		void flip(int n);
		void change();
		void transform();
		int checkret();
		bool checkunity();
	private:
		
		int grid[9][9];
    	int arrayt[9][9];
    	int total;
    	int no;
     	int b[9][9];
	 	int total1;
	 	int noo;
		
};
