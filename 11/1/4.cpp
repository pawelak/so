#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

long long sum = 0;
std::mutex mx;

void foo()
{
  long long sumL = 0;
  for (int i = 0; i < 1000000; i++)
    {
      //mx.lock();
      //sum += 7;
      //mx.unlock();
	 sumL+=7;
    }
  mx.lock();
  sum +=sumL;
  mx.unlock();
}

int main()
{
  std::vector<std::thread> threads;

  for (int i = 0; i < 10; i++)
    threads.push_back(std::thread(foo)); // startuje nowy watek i wrzca do wektora

  for (auto& thread : threads) // for (int i = 0; i < 10; i++)
    thread.join();	       // threads[i].join();
  
  std::cout << sum << std::endl;

  return 0;
}
