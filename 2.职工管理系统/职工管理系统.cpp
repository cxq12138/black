#include<iostream>
using namespace std;
#include"workerManager.h"
#include"workers.h"

int main()
{
	WorkerManager w;
	int opt;
	while (true)
	{
		w.showMenu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		cin >> opt;
		if (opt == 0)
			return 0;
		if (opt == 1)
			w.add_per();
		if (opt == 2)
			w.showWorkers();
		if (opt == 3)
			w.delworker();
		if (opt == 4)
			w.modifyWorker();
		if (opt == 5)
			w.selectWorker();
		if (opt == 6)
			w.sortArray();
		if (opt == 7)
			w.clearWorker();

	}
	system("pause");
}