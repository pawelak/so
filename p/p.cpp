#include <queue>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <mutex>
#include <thread>

#include <iostream>

using namespace std;


const int m=10,n=10;
queue <int> kolejka1;
std::mutex k1;

queue <int> kolejka2;
std::mutex k2;

bool matrix[m][n];
std::mutex mx;



void clearMatrix()
{
	while(true)
	{	mx.lock();
		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=n; j++)
			{
				matrix[i][j] = false;
			}
		}
		mx.unlock();
		this_thread::sleep_for(std::chrono::seconds(10));
	}
}

void printMatrix()
{	
	initscr();
	while(true)
	{
		clear();
		mx.lock();
	    	for (int i=0; i<=m; i++)
		{
			printw(" ");
			for (int j=1; j<=n*4+3; j++)
			{
				if(j%4 == 0)printw("+");
				else printw("-");	
			}
			printw("\n|");
			for (int j=0; j<=n; j++)
			{
				if(matrix[i][j] == false) printw("   |");
				if(matrix[i][j] == true) printw(" o |");
			}
			printw("\n");
		
		}
		printw(" ");
		for (int j=1; j<=n*4+3; j++)
		{
			if(j%4 == 0)printw("+");
			else printw("-");	
		}
		mx.unlock();
		this_thread::sleep_for(std::chrono::seconds(1));	
		
	}
	endwin();	
	
}

void producent()
{
	srand( time( NULL ) );
	while(true)
	{
		k1.lock();
		kolejka1.push(rand() % m );
		k1.unlock();
		k2.lock();
		kolejka2.push(rand() % n );
		k2.unlock();	
	}
}

void print()
{	
	while(true)
	{
		if(int a = kolejka1.back()) cout << a;
		if(int a = kolejka2.back()) cout << a;
	}	
}

bool przestaw (int x, int y)
{
	int r = rand() % 3;
	if(r==0 && x > 0 && matrix[x-1][y] == false)
	{
		matrix[x][y] = false;
		matrix[x-1][y] = true;
		return true;
	}
	if(r==1 && y < n-1 && matrix[x][y+1] == false)
	{
		matrix[x][y] = false;
		matrix[x][y+1] = true;
		return true;
	}
	if(r==2 && x < m-1 && matrix[x+1][y] == false)
	{
		matrix[x][y] = false;
		matrix[x+1][y] = true;
		return true;
	}
	if(r==3 && x > 0 && matrix[x][y-1] == false)
	{
		matrix[x][y] = false;
		matrix[x][y-1] = true;
		return true;
	}

	return false;
}

void przetwarzacz()
{	
	while(true)
	{
		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=n; j++)
			{
				
				if(matrix[i][j] == true)
				{
					mx.lock();
					przestaw(i,j);
					mx.unlock();
				}
			}
		}

		int x,y;
		k1.lock();
		if(int a = kolejka1.back())x = kolejka1.back();
		k1.unlock();
		k2.lock();
		if(int a = kolejka2.back())y = kolejka2.back();
		k2.unlock();
		mx.lock();
		if(matrix[x][y] == true)przestaw(x,y);
		matrix[x][y] = true;
		mx.unlock();
	}	
}


int main()
{
	auto tClear = thread(clearMatrix);
	auto tPrint = thread(printMatrix);
	auto tProducent = thread(producent);
	auto tPrzetwarzacz = thread(przetwarzacz);
	

	tClear.join();
	tPrint.join();
	tProducent.join();
	tPrzetwarzacz.join();



	return 0;
}
//initscr();
//endwin();


