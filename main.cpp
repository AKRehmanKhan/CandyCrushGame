// nlkklm.cpp : This file contains the 'main'////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//															    													   ///
//												PROJECT : CANDY CRUSH												   ///
//																													   ///
// GROUP MEMBERS																									   ///
//							ZAIN AHMED																				   ///
//							MUSAB AHMED																				   ///
//							HAFIZ HAMZA SHAHID																		   ///
//							ABDUL RAHMAN KHAN	    																   ///
//																													   ///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <time.h>
#include "myconsole.h";
#include "mygraphics.h";
#include <conio.h>


using namespace std;

const int row = 9, col = 9;
int score = 0, target_score = 5000;

void SaveGameMenu();
void NewGameMenu();
void LosingMessage();
void WinningMessage();
void NewGame(int matrix[row][col], int row_h, int col_h, int swaps);
void LoadGame(int matrix[row][col], int row_h, int col_h, int swaps);
void Initialize(int matrix[row][col]);
void Regenrate(int matrix[row][col]);
void Print(int matrix[row][col], int row_h, int col_h);
void Points(int candy_type, int  number_of_candies, int& sum);
void CrushColStripe(int matrix[row][col], int column);
void CrushRowStripe(int matrix[row][col], int row);
void create_wrapped(int array[row][col]);
void Wrapped_simple(int matrix[row][col], int rowno, int colno);
void bomb_wrapped(int matrix[row][col], int wrapped_type);
void wrapped_striped(int array[row][col], int i, int j);
void ZEROS_SORTING(int matrix[row][col]);
void Searching_Row(int matrix[row][col]);
void Searching_Col(int matrix[row][col]);
void RedCandy(int x1, int y1, int x2, int y2);
void YellowCandy(int x1, int y1, int x2, int y2);
void GreenCandy(int x1, int y1, int x2, int y2);
void BlueCandy(int x1, int y1, int x2, int y2);
void OrangeCandy(int x1, int y1, int x2, int y2);
void RedColStripeCandy(int x1, int y1, int x2, int y2);
void RedRowStripeCandy(int x1, int y1, int x2, int y2);
void YellowColStripeCandy(int x1, int y1, int x2, int y2);
void YellowRowStripeCandy(int x1, int y1, int x2, int y2);
void BlueColStripeCandy(int x1, int y1, int x2, int y2);
void BlueRowStripeCandy(int x1, int y1, int x2, int y2);
void GreenColStripeCandy(int x1, int y1, int x2, int y2);
void GreenRowStripeCandy(int x1, int y1, int x2, int y2);
void OrangeColStripeCandy(int x1, int y1, int x2, int y2);
void OrangeRowStripeCandy(int x1, int y1, int x2, int y2);
void RedWrappedCandy(int x1, int y1, int x2, int y2);
void YellowWrappedCandy(int x1, int y1, int x2, int y2);
void GreenWrappedCandy(int x1, int y1, int x2, int y2);
void BlueWrappedCandy(int x1, int y1, int x2, int y2);
void OrangeWrappedCandy(int x1, int y1, int x2, int y2);
void BombCandy(int x1, int y1, int x2, int y2);
void CandyPrinting(int matrix[row][col], int rowno, int colno);
void ScreenLayout(int mat[row][col], int highlightedrow, int highlightedcol);
void Swap(int matrix[row][col], int highlighted_row, int highlighted_col);
void Wrapped_Wrapped(int matrix[row][col], int rowno, int colno);
void Stripe_Stripe(int matrix[row][col], int rowno, int colno);
void bomb_simple(int matrix[row][col], int candy_type);
void Bomb_Striped(int array[row][col], int row_h, int col_h);
void bomb_bomb(int matrix[row][col]);

int main()
{
	ifstream load;
	int array[row][col], highlighted_row = 0, highlighted_col = 0;
	char menu_choice = '\0';
	int turns = 30;

	while (menu_choice != '0')
	{
		system("CLS");
		
		//cout << " *****	   *     **       * ******  *       *        ***** ****   *     *  **** *    *" << endl;
		//cout << "*	  * *    *  *     * *     *   *   *         *      *   *  *     * *	*    *" << endl;
		//cout << "*	 *****   *    *   * *     *     *           *      ****   *     *  ***  ******" << endl;
		//cout << "*	*     *  *      * * *     *     *           *      * *    *     *     * *    *" << endl;
		char str[100] = "CANDY CRUSH";
		//cout << " ***** *       * *       ** ******      *            ***** *   *   *****  ****	*    *	" << endl;
		//FullScreen();
		Maximized();
		
		//cout << endl << endl << endl << endl << endl << endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		myDrawTextWithFont(450 , 200, 200 ,str , RGB(255,255,255), RGB(255,0,0));
		
		load.open("savefile.txt");
		if (!load)
		{
			NewGameMenu();
		}
		else
		{
			SaveGameMenu();
		}
		menu_choice = getch();
		switch (menu_choice)
		{
		case '1':
		{
			system("CLS");
			if (!load)
				cout << "Incorrect Option." << endl;
			else
			{
				LoadGame(array, highlighted_row, highlighted_col, turns);
			}
			break;
		}
		case '2':
		{
			system("CLS");
			score = 0;
			NewGame(array, highlighted_row, highlighted_col, turns);
			break;
		}
		case '3':
		{
			char option_choice = '\0';
			system("CLS");
			while (option_choice != '0')
			{
				cout << "Press 1 To Change The Number Of Turns Allowed." << endl;
				cout << "Press 2 To Change The Target Score." << endl;
				cout << "Press 0 To Go Back." << endl;
				option_choice = getch();
				system("CLS");
				switch (option_choice)
				{
				case '1':
				{
					cout << "Enter The Number Of Turns : ";
					cin >> turns;
					break;
				}
				case '2':
				{
					cout << "Current target is : " << target_score << endl;
					cout << "Enter New Target : ";
					cin >> target_score;
					break;
				}
				case '0':
				{
					break;
				}
				default:
					cout << "Incorrect Option." << endl;
				}
			}
			break;
		}
		case '4':
		{
			system("CLS");
			char control_choice;
			cout << "-You can use W A S D keys to move up, left, down, and right respectively." << endl;
			cout << "-Press F to swap the highlighted key." << endl;
			cout << "-After pressing F, again use W A S D to swap." << endl << endl;
			cout << "Press any key to go back : ";
			control_choice = getch();
			switch (control_choice)
			{
			default:
				break;
			}
			break;
		}
		case '0':
		{
			break;
		}

		default:
			cout << "Incorrect Choice." << endl;
		}
	}
}


void Initialize(int matrix[row][col])
{
	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = (rand() % 5) + 1;
		}
	}
}

void Regenrate(int matrix[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
				matrix[i][j] = (rand() % 5) + 1;
		}
	}
}

void Print(int matrix[row][col], int row_h, int col_h)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == row_h && j == col_h)
				cout << "  <" << matrix[i][j] << ">  ";
			else
				cout << "   " << matrix[i][j] << "   ";
		}
		cout << endl << endl << endl;
	}
}

void Points(int candy_type, int  number_of_candies, int& sum)
{

	if (candy_type == 1)
	{
		sum = sum + 30 * number_of_candies;
	}
	if (candy_type == 2)
	{
		sum = sum + 30 * number_of_candies;
	}
	if (candy_type == 3)
	{
		sum = sum + 40 * number_of_candies;
	}
	if (candy_type == 4)
	{
		sum = sum + 50 * number_of_candies;
	}
	if (candy_type == 5)
	{
		sum = sum + 60 * number_of_candies;
	}
}

void CrushColStripe(int matrix[row][col], int column)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][column] == 1)
			count1++;
		if (matrix[i][column] == 2)
			count2++;
		if (matrix[i][column] == 3)
			count3++;
		if (matrix[i][column] == 4)
			count4++;
		if (matrix[i][column] == 5)
			count5++;
	}

	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = 0; i < row; i++)
	{
		matrix[i][column] = 0;
	}
}

void CrushRowStripe(int matrix[row][col], int row)
{
	int row_h = 9;
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = 0; i < col; i++)
	{
		if (matrix[row][i] == 1)
			count1++;
		if (matrix[row][i] == 2)
			count2++;
		if (matrix[row][i] == 3)
			count3++;
		if (matrix[row][i] == 4)
			count4++;
		if (matrix[row][i] == 5)
			count5++;
	}

	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = 0; i < col; i++)
	{
		matrix[row][i] = 0;
	}
}

void create_wrapped(int array[row][col])
{
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int k = 1, l = 6; k < 6; k++, l++)// searching l 
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i + 2][j] == k && array[i + 2][j + 1] == k && array[i + 2][j + 2] == k)
				{
					array[i + 2][j] = l;
					array[i][j] = 0;
					array[i + 1][j] = 0;
					array[i + 2][j + 1] = 0;
					array[i + 2][j + 2] = 0;
				}
			}


			for (int k = 1, l = 6; k < 6; k++, l++)   //searching l 
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i + 2][j] == k && array[i + 2][j - 1] == k && array[i + 2][j - 2] == k)
				{
					array[i + 2][j] = l;
					array[i][j] = 0;
					array[i + 1][j] = 0;
					array[i + 2][j - 1] = 0;
					array[i + 2][j - 2] = 0;
				}
			}

			for (int k = 1, l = 6; k < 6; k++, l++)// searching l 
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i - 1][j + 1] == k && array[i - 1][j + 2] == k)
				{
					array[i - 1][j] = l;
					array[i][j] = 0;
					array[i + 1][j] = 0;
					array[i - 1][j + 1] = 0;
					array[i - 1][j + 2] = 0;
				}
			}

			for (int k = 1, l = 6; k < 6; k++, l++)// searching l  
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i - 1][j - 1] == k && array[i - 1][j - 2] == k)
				{
					array[i - 1][j] = l;
					array[i][j] = 0;
					array[i + 1][j] = 0;
					array[i - 1][j - 1] = 0;
					array[i - 1][j - 2] = 0;
				}
			}

			for (int k = 1, l = 6; k < 6; k++, l++)  // searching T
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i - 1][j - 1] == k && array[i - 1][j + 1] == k)
				{
					array[i - 1][j] = l;
					array[i][j] = 0;
					array[i + 1][j] = 0;
					array[i - 1][j - 1] = 0;
					array[i - 1][j + 1] = 0;
				}
			}

			for (int k = 1, l = 6; k < 6; k++, l++)   // searching T
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i + 1][j + 1] == k && array[i + 1][j - 1] == k)
				{
					array[i + 1][j] = l;
					array[i][j] = 0;
					array[i - 1][j] = 0;
					array[i + 1][j - 1] = 0;
					array[i + 1][j + 1] = 0;

				}
			}

			for (int k = 1, l = 6; k < 6; k++, l++)   // searching T
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i][j + 1] == k && array[i][j + 2] == k)
				{
					array[i][j] = l;
					array[i + 1][j] = 0;
					array[i - 1][j] = 0;
					array[i][j + 1] = 0;
					array[i][j + 2] = 0;

				}
			}


			for (int k = 1, l = 6; k < 6; k++, l++)   // searching T
			{
				if (array[i][j] == k && array[i + 1][j] == k && array[i - 1][j] == k && array[i][j - 1] == k && array[i][j - 2] == k)
				{
					array[i][j] = l;
					array[i + 1][j] = 0;
					array[i - 1][j] = 0;
					array[i][j - 1] = 0;
					array[i][j - 2] = 0;

				}
			}

		}
	}
}

void Wrapped_simple(int matrix[row][col], int rowno, int colno)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = rowno - 1; i <= rowno + 1; i++)
	{
		for (int j = colno - 1; j <= colno + 1; j++)
		{
			if (matrix[i][j] == 1)
				count1++;
			if (matrix[i][j] == 2)
				count2++;
			if (matrix[i][j] == 3)
				count3++;
			if (matrix[i][j] == 4)
				count4++;
			if (matrix[i][j] == 5)
				count5++;
		}
	}
	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = rowno - 1; i < rowno + 1; i++)
	{
		for (int j = colno - 1; j < colno + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Wrapped_Wrapped(int matrix[row][col], int rowno, int colno)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = rowno - 2; i < rowno + 2; i++)
	{
		for (int j = colno - 2; j < colno + 2; j++)
		{
			if (matrix[i][j] == 1)
				count1++;
			if (matrix[i][j] == 2)
				count2++;
			if (matrix[i][j] == 3)
				count3++;
			if (matrix[i][j] == 4)
				count4++;
			if (matrix[i][j] == 5)
				count5++;
		}
	}
	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = rowno - 2; i < rowno + 2; i++)
	{
		for (int j = colno - 2; j < colno + 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}


void bomb_wrapped(int matrix[row][col], int wrapped_type)
{
	if (wrapped_type == 6)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 1)
				{
					matrix[i][j] = 6;
				}
			}
		}
	}
	if (wrapped_type == 7)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 2)
				{
					matrix[i][j] = 7;
				}
			}
		}
	}
	if (wrapped_type == 8)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 3)
				{
					matrix[i][j] = 8;
				}
			}
		}
	}
	if (wrapped_type == 9)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 4)
				{
					matrix[i][j] = 9;
				}
			}
		}
	}
	if (wrapped_type == 10)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (matrix[i][j] == 5)
				{
					matrix[i][j] = 10;
				}
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] = 6 || matrix[i][j] == 7 || matrix[i][j] == 8 || matrix[i][j] == 9 || matrix[i][j] == 10)
			{
				Wrapped_simple(matrix, i, j);
			}
		}
	}
}

void ZEROS_SORTING(int matrix[row][col])
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				for (int k1 = i, k2 = i - 1; k2 >= 0; k1--, k2--)
				{
					int arr = matrix[k1][j];
					matrix[k1][j] = matrix[k2][j];
					matrix[k2][j] = arr;
				}
			}
		}
	}
}
void Searching_Row(int matrix[row][col])
{
	int count_1 = 0, count1 = 0, count_2 = 0, count2 = 0, count_3 = 0, count3 = 0,
		count_4 = 0, count4 = 0, count_5 = 0, count5 = 0;
	int i, j, k, l = 0;
	for (i = 0; i < row; i++)
	{
		count_1 = 0, count_2 = 0, count_3 = 0,
			count_4 = 0, count_5 = 0;

		for (j = 0; j < col; j++)
		{

			if (matrix[i][j] % 5 == 1 && matrix[i][j] != 16)
				count_1++;
			else
				count_1 = 0;
			if (count_1 == 3 || count_1 == 4 || count_1 == 5)
			{
				count1 = count_1;
				l = j;
			}

			if (matrix[i][j] % 5 == 2 && matrix[i][j] != 16)
				count_2++;
			else
				count_2 = 0;
			if (count_2 == 3 || count_2 == 4 || count_2 == 5)
			{
				count2 = count_2;
				l = j;
			}

			if (matrix[i][j] % 5 == 3 && matrix[i][j] != 16)
				count_3++;
			else
				count_3 = 0;
			if (count_3 == 3 || count_3 == 4 || count_3 == 5)
			{
				count3 = count_3;
				l = j;
			}

			if (matrix[i][j] % 5 == 4 && matrix[i][j] != 16)
				count_4++;
			else
				count_4 = 0;
			if (count_4 == 3 || count_4 == 4 || count_4 == 5)
			{
				count4 = count_4;
				l = j;
			}

			if (matrix[i][j] % 5 == 0 && matrix[i][j] != 0)
				count_5++;
			else
				count_5 = 0;
			if (count_5 == 3 || count_5 == 4 || count_5 == 5)
			{
				count5 = count_5;
				l = j;
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		if (count1 == 5)
		{
			Points(1, 5, score);
			for (k = l; k > l - 5; k--)
			{
				if (matrix[i][k] == 6)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 11)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count1 = 0;
			matrix[i][l] = 16;
		}
		else if (count1 == 4)
		{
			Points(1, 4, score);
			for (k = l; k > l - 4; k--)
			{
				if (matrix[i][k] == 6)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 11)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count1 = 0;
			matrix[i][l] = 11;
		}
		else if (count1 == 3)
		{
			Points(1, 3, score);
			for (k = l - 3; k < l; k++)
			{
				if (matrix[i][k] == 6)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 11)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count1 = 0;
		}

		if (count2 == 5)
		{
			Points(2, 5, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[i][k] == 7)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 12)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count2 = 0;
			matrix[i][l] = 16;
		}
		else if (count2 == 4)
		{
			Points(1, 4, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[i][k] == 7)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 12)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count2 = 0;
			matrix[i][l] = 12;
		}
		else if (count2 == 3)
		{
			Points(2, 3, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[i][k] == 7)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 12)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count2 = 0;
		}

		if (count3 == 5)
		{
			Points(3, 5, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[i][k] == 8)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 13)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count3 = 0;
			matrix[i][l] = 16;
		}
		else if (count3 == 4)
		{
			Points(3, 4, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[i][k] == 8)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 13)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count3 = 0;
			matrix[i][l] = 13;
		}
		else if (count3 == 3)
		{
			Points(3, 3, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[i][k] == 8)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 13)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count3 = 0;
		}

		if (count4 == 5)
		{
			Points(4, 5, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[i][k] == 9)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 14)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count4 = 0;
			matrix[i][l] = 16;
		}
		else if (count4 == 4)
		{
			Points(4, 4, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[i][k] == 9)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 14)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count4 = 0;
			matrix[i][l] = 14;
		}
		else if (count4 == 3)
		{
			Points(1, 3, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[i][k] == 9)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 14)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count4 = 0;
		}

		if (count5 == 5)
		{
			Points(5, 5, score);
			for (k = l; k > l - count_5; k--)
			{
				if (matrix[i][k] == 10)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 15)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count5 = 0;
			matrix[i][l] = 16;
		}
		else if (count5 == 4)
		{
			Points(5, 4, score);
			for (k = l; k > l - count5; k--)
			{
				if (matrix[i][k] == 10)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 15)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count5 = 0;
			matrix[i][l] = 15;
		}
		else if (count5 == 3)
		{
			Points(5, 3, score);
			for (int k = l; k > l - count5; k--)
			{
				if (matrix[i][k] == 10)
					Wrapped_simple(matrix, i, k);
				else if (matrix[i][k] == 15)
					CrushRowStripe(matrix, i);
				else
					matrix[i][k] = 0;
			}
			count5 = 0;
		}
	}
}

void Searching_Col(int matrix[row][col])
{
	int count_1 = 0, count1 = 0, count_2 = 0, count2 = 0, count_3 = 0, count3 = 0,
		count_4 = 0, count4 = 0, count_5 = 0, count5 = 0;
	int i, j, k, l = 0;
	for (j = 0; j < col; j++)
	{
		count_1 = 0, count_2 = 0, count_3 = 0,
			count_4 = 0, count_5 = 0;

		for (i = 0; i < row; i++)
		{

			if (matrix[i][j] % 5 == 1 && matrix[i][j] != 16)
				count_1++;
			else
				count_1 = 0;
			if (count_1 == 3 || count_1 == 4 || count_1 == 5)
			{
				count1 = count_1;
				l = i;
			}

			if (matrix[i][j] % 5 == 2 && matrix[i][j] != 16)
				count_2++;
			else
				count_2 = 0;
			if (count_2 == 3 || count_2 == 4 || count_2 == 5)
			{
				count2 = count_2;
				l = i;
			}

			if (matrix[i][j] % 5 == 3 && matrix[i][j] != 16)
				count_3++;
			else
				count_3 = 0;
			if (count_3 == 3 || count_3 == 4 || count_3 == 5)
			{
				count3 = count_3;
				l = i;
			}

			if (matrix[i][j] % 5 == 4 && matrix[i][j] != 16)
				count_4++;
			else
				count_4 = 0;
			if (count_4 == 3 || count_4 == 4 || count_4 == 5)
			{
				count4 = count_4;
				l = i;
			}

			if (matrix[i][j] % 5 == 0 && matrix[i][j] != 0)
				count_5++;
			else
				count_5 = 0;
			if (count_5 == 3 || count_5 == 4 || count_5 == 5)
			{
				count5 = count_5;
				l = i;
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		if (count1 == 5)
		{
			Points(1, 5, score);
			for (k = l; k > l - count1; k--)
			{
				if (matrix[k][j] == 6)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 21)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count1 = 0;
			matrix[l][j] = 16;
		}
		else if (count1 == 4)
		{
			Points(1, 4, score);
			for (k = l; k > l - count1; k--)
			{
				if (matrix[k][j] == 6)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 21)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count1 = 0;
			matrix[l][j] = 21;
		}
		else if (count1 == 3)
		{
			Points(1, 3, score);
			for (k = l; k > l - count1; k--)
			{
				if (matrix[k][j] == 6)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 21)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count1 = 0;
		}

		if (count2 == 5)
		{
			Points(2, 5, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[k][j] == 7)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 22)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count2 = 0;
			matrix[l][j] = 16;
		}
		else if (count2 == 4)
		{
			Points(2, 4, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[k][j] == 7)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 22)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count2 = 0;
			matrix[l][j] = 22;
		}
		else if (count2 == 3)
		{
			Points(2, 3, score);
			for (k = l; k > l - count2; k--)
			{
				if (matrix[k][j] == 7)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 22)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count2 = 0;
		}

		if (count3 == 5)
		{
			Points(3, 5, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[k][j] == 8)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 23)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count3 = 0;
			matrix[l][j] = 16;
		}
		else if (count3 == 4)
		{
			Points(3, 4, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[k][j] == 8)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 23)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count3 = 0;
			matrix[l][j] = 23;
		}
		else if (count3 == 3)
		{
			Points(3, 3, score);
			for (k = l; k > l - count3; k--)
			{
				if (matrix[k][j] == 8)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 23)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count3 = 0;
		}

		if (count4 == 5)
		{
			Points(4, 5, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[k][j] == 9)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 24)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count4 = 0;
			matrix[l][j] = 16;
		}
		else if (count4 == 4)
		{
			Points(4, 4, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[k][j] == 9)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 24)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count4 = 0;
			matrix[l][j] = 24;
		}
		else if (count4 == 3)
		{
			Points(4, 3, score);
			for (k = l; k > l - count4; k--)
			{
				if (matrix[k][j] == 9)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 24)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count4 = 0;
		}

		if (count5 == 5)
		{
			Points(5, 5, score);
			for (k = l; k > l - count_5; k--)
			{
				if (matrix[k][j] == 10)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 25)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count5 = 0;
			matrix[l][j] = 16;
		}
		else if (count5 == 4)
		{
			Points(5, 4, score);
			for (k = l; k > l - count5; k--)
			{
				if (matrix[k][j] == 10)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 25)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count5 = 0;
			matrix[l][j] = 25;
		}
		else if (count5 == 3)
		{
			Points(5, 3, score);
			for (int k = l; k > l - count5; k--)
			{
				if (matrix[k][j] == 10)
					Wrapped_simple(matrix, k, j);
				else if (matrix[k][j] == 25)
					CrushColStripe(matrix, j);
				else
					matrix[k][j] = 0;
			}
			count5 = 0;
		}
	}
}

void RedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 0, 0), RGB(255, 0, 0));
}

void YellowCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 255, 0), RGB(255, 255, 0));
}

void GreenCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(0, 255, 0), RGB(0, 255, 0));
}

void BlueCandy(int x1, int y1, int x2, int y2)
{
	myEllipse(x1, y1, x2, y2, RGB(0, 0, 255), RGB(0, 0, 255));
}

void OrangeCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 165, 0), RGB(255, 165, 0));
}

void RedColStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = x1; k + 8 < x2; k += 8)
	{
		myRect(k, y1, k + 4, y2, RGB(255, 0, 0), RGB(255, 0, 0));
		myRect(k + 4, y1, k + 8, y2, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void RedRowStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = y1; k + 8 < y2; k += 8)
	{
		myRect(x1, k, x2, k + 4, RGB(255, 0, 0), RGB(255, 0, 0));
		myRect(x1, k + 4, x2, k + 8, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void YellowColStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = x1; k + 8 < x2; k += 8)
	{
		myRect(k, y1, k + 4, y2, RGB(255, 255, 0), RGB(255, 0, 0));
		myRect(k + 4, y1, k + 8, y2, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void YellowRowStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = y1; k + 8 < y2; k += 8)
	{
		myRect(x1, k, x2, k + 4, RGB(255, 255, 0), RGB(255, 255, 0));
		myRect(x1, k + 4, x2, k + 8, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void BlueColStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = x1; k + 8 < x2; k += 8)
	{
		myRect(k, y1, k + 4, y2, RGB(0, 0, 255), RGB(0, 0, 255));
		myRect(k + 4, y1, k + 8, y2, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void BlueRowStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = y1; k + 8 < y2; k += 8)
	{
		myRect(x1, k, x2, k + 4, RGB(0, 0, 255), RGB(0, 0, 255));
		myRect(x1, k + 4, x2, k + 8, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void GreenColStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = x1; k + 8 < x2; k += 8)
	{
		myRect(k, y1, k + 4, y2, RGB(0, 255, 0), RGB(0, 255, 0));
		myRect(k + 4, y1, k + 8, y2, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void GreenRowStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = y1; k + 8 < y2; k += 8)
	{
		myRect(x1, k, x2, k + 4, RGB(0, 255, 0), RGB(0, 255, 0));
		myRect(x1, k + 4, x2, k + 8, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void OrangeColStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = x1; k + 8 < x2; k += 8)
	{
		myRect(k, y1, k + 4, y2, RGB(255, 165, 0), RGB(255, 165, 0));
		myRect(k + 4, y1, k + 8, y2, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void OrangeRowStripeCandy(int x1, int y1, int x2, int y2)
{
	for (int k = y1; k + 8 < y2; k += 8)
	{
		myRect(x1, k, x2, k + 4, RGB(255, 165, 0), RGB(255, 165, 0));
		myRect(x1, k + 4, x2, k + 8, RGB(255, 255, 255), RGB(255, 255, 255));
	}
}
void RedWrappedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 0, 0), RGB(0, 0, 0));
	myEllipse(x1 + 4, y1 + 4, x2 - 4, y2 - 4, RGB(255, 0, 0), RGB(255, 0, 0));
}
void YellowWrappedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 255, 0), RGB(0, 0, 0));
	myEllipse(x1 + 4, y1 + 4, x2 - 4, y2 - 4, RGB(255, 255, 0), RGB(255, 255, 0));
}
void GreenWrappedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(0, 255, 0), RGB(0, 0, 0));
	myEllipse(x1 + 4, y1 + 4, x2 - 4, y2 - 4, RGB(0, 255, 0), RGB(0, 255, 0));
}
void BlueWrappedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(0, 0, 255), RGB(0, 0, 0));
	myEllipse(x1 + 4, y1 + 4, x2 - 4, y2 - 4, RGB(0, 0, 255), RGB(0, 0, 255));
}
void OrangeWrappedCandy(int x1, int y1, int x2, int y2)
{
	myRect(x1, y1, x2, y2, RGB(255, 165, 0), RGB(0, 0, 0));
	myEllipse(x1 + 4, y1 + 4, x2 - 4, y2 - 4, RGB(255, 165, 0), RGB(255, 165, 0));
}
void BombCandy(int x1, int y1, int x2, int y2)
{
	myEllipse(x1 - 3, y1 - 3, x2 + 2, y2 + 2, RGB(139, 69, 19), RGB(139, 69, 19));
}
void CandyPrinting(int matrix[row][col], int rowno, int colno)
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	x1 = colno * 50 + 50;
	x2 = x1 + 25;
	y1 = rowno * 50 + 100;
	y2 = y1 + 25;
	if (matrix[rowno][colno] == 1)
		RedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 2)
		YellowCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 3)
		GreenCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 4)
		BlueCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 5)
		OrangeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 6)
		RedWrappedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 7)
		YellowWrappedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 8)
		GreenWrappedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 9)
		BlueWrappedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 10)
		OrangeWrappedCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 11)
		RedRowStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 12)
		YellowRowStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 13)
		GreenRowStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 14)
		BlueRowStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 15)
		OrangeRowStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 16)
		BombCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 21)
		RedColStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 22)
		YellowColStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 23)
		GreenColStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 24)
		BlueColStripeCandy(x1, y1, x2, y2);
	if (matrix[rowno][colno] == 25)
		OrangeColStripeCandy(x1, y1, x2, y2);
}

void ScreenLayout(int mat[row][col], int highlightedrow, int highlightedcol)
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			x1 = j * 50 + 50;
			x2 = x1 + 25;
			y1 = i * 50 + 100;
			y2 = y1 + 25;
			if (i == highlightedrow && j == highlightedcol)
			{
				myRect(x1 - 10, y1 - 10, x2 + 10, y2 + 10, RGB(255, 255, 255), RGB(0, 0, 0));
				CandyPrinting(mat, i, j);
			}
			else
			{
				CandyPrinting(mat, i, j);
			}
		}
	}
}

void Swap(int matrix[row][col], int highlighted_row, int highlighted_col)
{
	char move;
	int temp = 0, replace_row = 0, replace_col = 0;
	cout << "Play your move: ";
	move = getch();
	if (move == 'a' || move == 'A')
	{
		replace_row = highlighted_row;
		replace_col = highlighted_col - 1;
	}
	else if (move == 'd' || move == 'D')
	{
		replace_row = highlighted_row;
		replace_col = highlighted_col + 1;
	}
	else if (move == 's' || move == 'S')
	{
		replace_row = highlighted_row + 1;
		replace_col = highlighted_col;
	}
	else if (move == 'w' || move == 'W')
	{
		replace_row = highlighted_row - 1;
		replace_col = highlighted_col;
	}
	else
		cout << "Incorrect Move!" << endl;

	if (matrix[highlighted_row][highlighted_col] >= 1 && matrix[highlighted_row][highlighted_col] <= 5)
	{
		if (matrix[replace_row][replace_col] == 16)
			bomb_simple(matrix, matrix[highlighted_row][highlighted_col]);
		else
		{
			temp = matrix[highlighted_row][highlighted_col];
			matrix[highlighted_row][highlighted_col] = matrix[replace_row][replace_col];
			matrix[replace_row][replace_col] = temp;
		}

	}
	else if (matrix[highlighted_row][highlighted_col] >= 6 && matrix[highlighted_row][highlighted_col] <= 10)
	{
		if (matrix[replace_row][replace_col] >= 6 && matrix[replace_row][replace_col] <= 10)
			Wrapped_Wrapped(matrix, replace_row, replace_col);
		else if (matrix[replace_row][replace_col] >= 1 && matrix[replace_row][replace_col] <= 5)
		{
			temp = matrix[highlighted_row][highlighted_col];
			matrix[highlighted_row][highlighted_col] = matrix[replace_row][replace_col];
			matrix[replace_row][replace_col] = temp;
		}
		else if (matrix[replace_row][replace_col] >= 11 && matrix[replace_row][replace_col] <= 15)
		{
			wrapped_striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 21 && matrix[replace_row][replace_col] <= 25)
		{
			wrapped_striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] == 16)
		{
			bomb_wrapped(matrix, matrix[highlighted_row][highlighted_col]);
			system("CLS");
			ScreenLayout(matrix, replace_row, replace_col);
			Sleep(1000);
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (matrix[i][j] = 6 || matrix[i][j] == 7 || matrix[i][j] == 8 || matrix[i][j] == 9 || matrix[i][j] == 10)
					{
						Wrapped_simple(matrix, i, j);
					}
				}
			}
		}
	}
	else if (matrix[highlighted_row][highlighted_col] >= 11 && matrix[highlighted_row][highlighted_col] <= 15)
	{
		if (matrix[replace_row][replace_col] >= 6 && matrix[replace_row][replace_col] <= 10)
		{
			wrapped_striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 1 && matrix[replace_row][replace_col] <= 5)
		{
			temp = matrix[highlighted_row][highlighted_col];
			matrix[highlighted_row][highlighted_col] = matrix[replace_row][replace_col];
			matrix[replace_row][replace_col] = temp;
		}
		else if (matrix[replace_row][replace_col] >= 11 && matrix[replace_row][replace_col] <= 15)
		{
			Stripe_Stripe(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 21 && matrix[replace_row][replace_col] <= 25)
		{
			Stripe_Stripe(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] == 16)
		{
			Bomb_Striped(matrix, highlighted_row, highlighted_col);
		}
	}
	else if (matrix[highlighted_row][highlighted_col] >= 21 && matrix[highlighted_row][highlighted_col] <= 25)
	{
		if (matrix[replace_row][replace_col] >= 6 && matrix[replace_row][replace_col] <= 10)
		{
			wrapped_striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 1 && matrix[replace_row][replace_col] <= 5)
		{
			temp = matrix[highlighted_row][highlighted_col];
			matrix[highlighted_row][highlighted_col] = matrix[replace_row][replace_col];
			matrix[replace_row][replace_col] = temp;
		}
		else if (matrix[replace_row][replace_col] >= 11 && matrix[replace_row][replace_col] <= 15)
		{
			Stripe_Stripe(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 21 && matrix[replace_row][replace_col] <= 25)
		{
			Stripe_Stripe(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] == 16)
		{
			Bomb_Striped(matrix, highlighted_row, highlighted_col);
		}
	}
	else if (matrix[highlighted_row][highlighted_col] >= 16)
	{
		if (matrix[replace_row][replace_col] >= 6 && matrix[replace_row][replace_col] <= 10)
		{
			bomb_wrapped(matrix, matrix[highlighted_row][highlighted_col]);
			system("CLS");
			ScreenLayout(matrix, replace_row, replace_col);
			Sleep(1000);
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (matrix[i][j] = 6 || matrix[i][j] == 7 || matrix[i][j] == 8 || matrix[i][j] == 9 || matrix[i][j] == 10)
					{
						Wrapped_simple(matrix, i, j);
					}
				}
			}
		}
		else if (matrix[replace_row][replace_col] >= 1 && matrix[replace_row][replace_col] <= 5)
		{
			bomb_simple(matrix, matrix[replace_row][replace_col]);
		}
		else if (matrix[replace_row][replace_col] >= 11 && matrix[replace_row][replace_col] <= 15)
		{
			Bomb_Striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] >= 21 && matrix[replace_row][replace_col] <= 25)
		{
			Bomb_Striped(matrix, replace_row, replace_col);
		}
		else if (matrix[replace_row][replace_col] == 16)
		{
			bomb_bomb(matrix);
		}
	}
}

void wrapped_striped(int array[row][col], int i, int j)
{
	if (array[i][j] == 6 || array[i][j] == 7 || array[i][j] == 8 || array[i][j] == 9 || array[i][j] == 10)
	{
		if (i != 0 && i != 8)
		{
			for (int l = i - 1; l < i + 2; l++)
			{
				for (int m = 0; m < col; m++)
					array[l][m] = 0;
			}
		}

		else if (i == 0)
		{
			for (int l = i; l < i + 3; l++)
			{
				for (int m = 0; m < col; m++)
					array[l][m] = 0;
			}
		}

		else if (i == 8)
		{
			for (int l = i; l > i - 3; l--)
			{
				for (int m = 0; m < col; m++)
					array[l][m] = 0;
			}
		}

		if (j != 0 && j != 8)
		{
			for (int l = 0; l < row; l++)
			{
				for (int m = j - 1; m < j + 2; m++)
					array[l][m] = 0;
			}
		}

		else if (j == 0)
		{
			for (int l = 0; l < row; l++)
			{
				for (int m = j; m < j + 3; m++)
					array[l][m] = 0;
			}
		}

		else if (j == 8)
		{
			for (int l = 0; l < row; l++)
			{
				for (int m = j; m > 5; m--)
					array[l][m] = 0;
			}
		}

	}
}

void Stripe_Stripe(int matrix[row][col], int rowno, int colno)
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int j = 0; j < col; j++)
	{
		if (matrix[rowno][j] == 1)
			count1++;
		if (matrix[rowno][j] == 2)
			count2++;
		if (matrix[rowno][j] == 3)
			count3++;
		if (matrix[rowno][j] == 4)
			count4++;
		if (matrix[rowno][j] == 5)
			count5++;
	}
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][colno] == 1)
			count1++;
		if (matrix[i][colno] == 2)
			count2++;
		if (matrix[i][colno] == 3)
			count3++;
		if (matrix[i][colno] == 4)
			count4++;
		if (matrix[i][colno] == 5)
			count5++;
	}
	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = 0; i < row; i++)
	{
		matrix[i][colno] = 0;
	}
	for (int j = 0; j < col; j++)
	{
		matrix[rowno][j] = 0;
	}
}

void bomb_simple(int matrix[row][col], int candy_type)
{
	int count = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == candy_type)
				count++;
		}
	}

	Points(candy_type, count, score);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == candy_type)
				matrix[i][j] = 0;
		}
	}
}

void Bomb_Striped(int array[row][col], int row_h, int col_h)  // here  k and l is position of stripe candy
{
	for (int q = 11, w = 1; q < 16; q++, w++)
	{
		if (array[row_h][col_h] == q)
		{
			for (int z = 0; z < 9; z++)      // making all candies of that colour, stripe 
			{
				for (int x = 0; x < 9; x++)
				{
					if (array[z][x] == w)
						array[z][x] = q;
				}
			}

			for (int z = 0; z < 9; z++)   // making rows including perticular stripe, zero
			{
				for (int x = 0; x < 9; x++)
				{
					if (array[z][x] == q)
					{
						for (int v = 0; v < 9; v++)
							array[z][v] = 0;
					}
				}
			}
		}
	}

	for (int q = 21, w = 1; q < 26; q++, w++)
	{
		if (array[row_h][col_h] == q)
		{
			for (int z = 0; z < 9; z++)     // making all candies of that colour, stripe 
			{
				for (int x = 0; x < 9; x++)
				{
					if (array[z][x] == w)
						array[z][x] = q;
				}
			}

			for (int z = 0; z < 9; z++)     // making columns including perticular stripe, zero
			{
				for (int x = 0; x < 9; x++)
				{
					if (array[x][z] == q)
					{
						for (int v = 0; v < 9; v++)
							array[v][z] = 0;
					}
				}
			}
		}
	}
}

void bomb_bomb(int matrix[row][col])
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 1)
				count1++;
			if (matrix[i][j] == 2)
				count2++;
			if (matrix[i][j] == 3)
				count3++;
			if (matrix[i][j] == 4)
				count4++;
			if (matrix[i][j] == 5)
				count5++;
			if (matrix[i][j] == 6 || matrix[i][j] == 7 || matrix[i][j] == 8 || matrix[i][j] == 9 || matrix[i][j] == 10)
			{
				Wrapped_simple(matrix, i, j);
			}
			if (matrix[i][j] == 11 || matrix[i][j] == 12 || matrix[i][j] == 13 || matrix[i][j] == 14 || matrix[i][j] == 15)
			{
				CrushRowStripe(matrix, i);
			}
			if (matrix[i][j] == 20 || matrix[i][j] == 21 || matrix[i][j] == 22 || matrix[i][j] == 23 || matrix[i][j] == 24)
			{
				CrushColStripe(matrix, j);
			}
		}
	}
	Points(1, count1, score);
	Points(2, count2, score);
	Points(3, count3, score);
	Points(4, count4, score);
	Points(5, count5, score);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void NewGame(int matrix[row][col], int row_h, int col_h, int swaps)
{
	char input, closing = '\0';
	ofstream save;
	Initialize(matrix);
	while (closing != 'y' && swaps != 0)
	{
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		create_wrapped(matrix);
		Searching_Row(matrix);
		Searching_Col(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		ZEROS_SORTING(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		Regenrate(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		input = getch();
		if (input == 'd' || input == 'D')
			col_h++;
		else if (input == 'a' || input == 'A')
			col_h--;
		else if (input == 'w' || input == 'W')
			row_h--;
		else if (input == 's' || input == 'S')
			row_h++;
		else if (input == 'f' || input == 'F')
		{
			Swap(matrix, row_h, col_h);
			swaps--;
		}
		else if (input == 'q' || input == 'Q')
		{
			save.open("savefile.txt");
			save << row_h << endl;
			save << col_h << endl;
			save << swaps << endl;
			save << score << endl;
			save << target_score << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					save << matrix[i][j] << " ";
				}
				save << endl;
			}
			closing = 'y';
		}
		if (row_h == 9)
		{
			row_h = 0;
		}
		if (col_h == 9)
		{
			col_h = 0;
		}
		if (row_h == -1)
		{
			row_h = 8;
		}
		if (col_h == -1)
		{
			col_h = 8;
		}
		system("CLS");
	}
	if (swaps == 0)
	{
		if (score >= target_score)
		{
			WinningMessage();
			system("pause");
		}
		else
		{
			LosingMessage();
			system("pause");
		}
	}
}

void LoadGame(int matrix[row][col], int row_h, int col_h, int swaps)
{
	char input, closing = '\0';
	ifstream load;
	ofstream save;
	load.open("savefile.txt");
	while (!load.eof())
	{
		load >> row_h;
		load >> col_h;
		load >> swaps;
		load >> score;
		load >> target_score;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				load >> matrix[i][j];
			}
		}
	}
	while (closing != 'y' && swaps != 0)
	{
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		create_wrapped(matrix);
		Searching_Row(matrix);
		Searching_Col(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		ZEROS_SORTING(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		Regenrate(matrix);
		system("CLS");
		cout << "SCORE : " << score << "               REMAINING MOVES : " << swaps << "               TARGET : " << target_score << endl;
		ScreenLayout(matrix, row_h, col_h);
		input = getch();
		if (input == 'd' || input == 'D')
			col_h++;
		else if (input == 'a' || input == 'A')
			col_h--;
		else if (input == 'w' || input == 'W')
			row_h--;
		else if (input == 's' || input == 'S')
			row_h++;
		else if (input == 'f' || input == 'F')
		{
			Swap(matrix, row_h, col_h);
			swaps--;
		}
		else if (input == 'q' || input == 'Q')
		{
			save.open("savefile.txt");
			save << row_h << endl;
			save << col_h << endl;
			save << swaps << endl;
			save << score << endl;
			save << target_score << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					save << matrix[i][j] << " ";
				}
				save << endl;
			}
			closing = 'y';
		}
		if (row_h == 9)
		{
			row_h = 0;
		}
		if (col_h == 9)
		{
			col_h = 0;
		}
		if (row_h == -1)
		{
			row_h = 8;
		}
		if (col_h == -1)
		{
			col_h = 8;
		}
		system("CLS");
	}
	if (swaps == 0)
	{
		if (score >= target_score)
		{
			WinningMessage();
			system("pause");
		}
		else
		{
			LosingMessage();
			system("pause");
		}
	}
}

void WinningMessage()
{
	cout << "*       *  *****  *     *          *      *  *****  **       *  " << endl;
	cout << "  *   *   *     * *     *          *      * *     * *  *     *  " << endl;
	cout << "    *     *     * *     *          *  **  * *     * *    *   *  " << endl;
	cout << "    *     *     * *     *          * *  * * *     * *      * *" << endl;
	cout << "    *      *****   *****            *    *   *****  *       **   " << endl;
}

void LosingMessage()
{
	cout << "*       *  *****  *     *          *	     *****   ****  ******" << endl;
	cout << "  *   *   *     * *     *  	   *	    *     * *	   *     " << endl;
	cout << "    *     *     * *     * 	   *        *     *  ****  *****  " << endl;
	cout << "    *     *     * *     *  	   *        *     *      * *    " << endl;
	cout << "    *      *****   *****  	   *******   *****   ****  ******  " << endl;
}

void NewGameMenu()
{
	char str1[23]="Press 2 For New Game.";
	myDrawTextWithFont(530, 500, 60, str1, RGB(255, 255, 255), RGB(255, 0, 0));
	char str2[] = "Press 3 For Options.";
	myDrawTextWithFont(545, 600, 60, str2, RGB(255, 255, 255), RGB(255, 0, 0));
	char str3[]="Press 4 For Controls.";
	myDrawTextWithFont(542, 700, 60, str3, RGB(255, 255, 255), RGB(255, 0, 0));
	char str4[]= "Press 0 To Exit The Game." ;
	myDrawTextWithFont(550, 800, 60, str4, RGB(255, 255, 255), RGB(255, 0, 0));
}

void SaveGameMenu()
{
	cout << "Press 1 To Load Game." << endl;
	cout << "Press 2 For New Game." << endl;
	cout << "Press 3 For Options." << endl;
	cout << "Press 4 For Controls." << endl;
	cout << "Press 0 To Exit The Game." << endl;
}
