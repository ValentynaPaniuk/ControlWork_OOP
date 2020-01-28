#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Option 2
/*
2. Написати програму «Автоматизована інформаційна система на залізничному вокзалі». 
Інформаційна система містить дані про відправлення поїздів дальнього сполучення. 

Для кожного потяга вказується: 
номер потяга, 
станція призначення, 
час відправлення.

Програма повинна забезпечувати вибір за допомогою меню і виконання однієї наступних функцій:
 первісне введення даних в інформаційну систему (із клавіатури чи з файлу);
//                        виведення даних про всі потяги;
 виведення даних пpо потяг з запитаним номером;
 виведення даних про ті потяги, що слідують до запитаної станції
призначення.
Збереження даних організувати з застосуванням контейнерного класу vector.
*/

template<typename T1, typename T2, typename T3>
class Station
{
private:
	template <typename T1, typename T2, typename T3>
	class Train
	{
	public:
		Train *nextTrain;
		T1 numberTrain;
		T2 destinationStation;
		T3 departureTime;

		Train() { cout << "Default constructor Bus " << this << endl; };
		Train(T1 numberTrain, T2 destinationStation, T3 departureTime)
		{
			this->numberTrain = numberTrain;
			this->destinationStation = destinationStation;
			this->departureTime = departureTime;
			cout << "Overload constructor Train " << this << endl;
		}



	};
	Train <T1, T2, T3> *head;
	int size;

public:
	//Constructor Station
	Station()
	{
		this->size = 0;
		this->head = nullptr;
		cout << "Default constructor Station " << this << endl;
	}
	
	//Metor povernennia Size
	int GetSize()
	{
		return this->size;
	}

	//Metod stvorennia poizda na pochatok spyska
	void Push(T1 numberTrain, T2 destinationStation, T3 departureTime)
	{
		if (head == nullptr)
		{
			this->head = new Train<T1, T2, T3>(numberTrain, destinationStation, departureTime);
		}
		else
		{
			Train<T1, T2, T3> *tmp = this->head;
			while (tmp->nextTrain != nullptr)
			{
				tmp = tmp->nextTrain;
			}
			tmp->nextTrain = new Train <T1, T2, T3>(numberTrain, destinationStation, departureTime);
		}
		this->size++;
	}

	//Metod dodavannia pershogo elementy
	void Pop(T1 numberTrain, T2 destinationStation, T3 departureTime)
	{
		head = new Train<T1, T2, T3>(numberTrain, destinationStation, departureTime);
		this->size++;
	}


	//Metod vydalennia pershogo elementa
	void DeleteFirst()
	{
		Train<T1, T2, T3> *tmp = this->head;
		this->head = head->nextTrain;
		delete tmp;
		size--;
	}



	//Metod vydalyty za indeksom
	void RemoveByIndex(const int index)
	{
		if (index == 0)
		{
			DeleteFirst();
		}
		else
		{
			Train<T1, T2, T3> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextTrain;
			}
			Train<T1, T2, T3> *toDel = prev->nextTrain;
			prev->nextTrain = toDel->nextTrain;
			delete toDel;
			size--;
		}
	}

	//Metod vyvodu na ekran
	void ShowInfo()
	{
		Train<T1, T2, T3> *tmp = head;
		int counter = 0;

		while (tmp != nullptr)
		{
			cout << "Train N " << counter + 1 << ": " << endl;
			cout << "Train's number: " << tmp->numberTrain << "\tDestination station\t: " << tmp->destinationStation << "\tTime: " << tmp->departureTime<< endl;
			tmp = tmp->nextTrain;
			counter++;
		}
		//cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	}

	//Metod peregruzky operatora []
	T1 &operator[](const int index)
	{
		int counter = 0;
		Train<T1, T2, T3> *train = this->head;

		while (train != nullptr)
		{
			if (train == index)
			{
				return train->numberTrain;

			}
			train = train->nextBus;
			counter++;
		}
	}


	//Metod vyvodu na ekran 
	void ShowInfoByIndex()
	{
		int index;
		Train<T1, T2, T3> *tmp = head;
		int counter = 0;
		

		cout << "Enter the train number "; cin >> index;
		
			while (train != nullptr)
			{
				if (index == tmp->numberTrain)
				{

					cout << "Train's number: " << tmp->numberTrain << "\tDestination station\t: " << tmp->destinationStation << "\tTime: " << tmp->departureTime << endl;
					tmp = tmp->nextTrain;
					counter++;
				}
				else
				{
					cout << "Please check that you are correct" << endl;
				}
			}
		
		
				

	}




	
		



};



void Menu()
{
	Station<int, string, int> station;
	bool exit = false;
	int menu = 0;
	int numberOfTrain = 0;
	int numberTrain;
	string description;
	int time;
	
	

	while (!exit)
	{
		system("cls");
		cout << " =================     MENU   ==============================:\n";
		cout << "  1.Create Station:\n"; // Ввід бази даних
		cout << "        11.From File\n";
		cout << "        12.From keyboard\n";
		cout << "  2.Browsing the database:\n"; //Перегляд бази даних
		cout << "        21.All database\n"; //+
		cout << "        22.By number of Train: \n"; //+
		cout << "  3.Editing the database:\n"; //Редагування бази даних
		cout << "  4.Database output:\n"; //Вивід бази даних
		cout << "  5.Data search:\n";//Пошук
		cout << "        51.By Trains number\n"; 
		cout << "        52.By destination Station\n";
		cout << "  6.Database output:\n"; // Запис бази даних в файл
		cout << "  7.Exit\n\n";

		cout << "Select menu item: ";
		cin >> menu;
		switch (menu)
		{
		case 11: // Створити базу даних з файлу
		{
			system("cls");

			system("pause");
			break;
		}
		case 12: // Ввести потяг з клавіатури
		{
			system("cls");
			cout << "Enter the number of trains: ";	 cin >> numberOfTrain;
			cout << "======================================" << endl;
			for (int i = 0; i < numberOfTrain; i++)
			{
				cout << "====================================================" << endl;
				cout << "Add information about Train N [" << i + 1 << "]" << endl;
				cout << "Enter number of Train for number: ";					cin >> numberTrain;
				cout << "Enter destination Station of Train: ";					cin >> description;
				cout << "Enter the departure time of Train: ";					cin >> time;

				station.Push(numberTrain, description, time);
			}
			system("pause");
			break;
		}
		case 21: //Перегляд бази даних
		{
			system("cls");
			station.ShowInfo();
			system("pause");
			break;
		}
		case 22: //Перегляд бази даних
		{
			system("cls");
			station.ShowInfoByIndex();
			
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");

			system("pause");
			break;
		}
		case 5:
		{
			system("cls");

			system("pause");
			break;
		}
		case 51:
		{
			system("cls");

			system("pause");
			break;
		}
		case 52:
		{
			system("cls");

			system("pause");
			break;
		}
		case 6:
		{
			system("cls");

			system("pause");
			break;
		}
		case 7:
		{
			exit = true;
			break;
			
		}
		default:
		{
			cout << "ERROR! \n\n";
			menu = 8;
		}
		}


	}
}






int main()
{
	cout << " **** Option 2 ****" << endl;
	Menu();


	



	system("pause");
	return 0;
}