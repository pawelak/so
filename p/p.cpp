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
queue <int> kolejka2;
bool matrix[m][n];
std::mutex mx;

void clearMatrix()
{
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			matrix[i][j] = false;
		}
	}
}

void printMatrix()
{	
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
	
}

void producent()
{
	srand( time( NULL ) );
	while(true)
	{
		mx.lock();
		kolejka1.push(rand() % m );
		kolejka2.push(rand() % n );
		mx.unlock();	
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

void przetwarzacz()
{	
	while(true)
	{
		int x,y;
		mx.lock();
		if(int a = kolejka1.back())x = kolejka1.back();
		if(int a = kolejka2.back())y = kolejka2.back();
		mx.unlock();
	}	
}


int main()
{

	//clearMatrix();
	//printMatrix();
	auto t1 = thread(producent);
	auto t2 = thread(print);

	t1.join();
	t2.join();



	return 0;
}
//initscr();
//endwin();


