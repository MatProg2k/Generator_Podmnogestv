#include "stdafx.h"                       
#include <iostream>
#include <ctime>
#include <locale>
#include <fstream>
#include <vector>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	
	int sizeSet;
	int sizeSubset;

	const int maskaForBit = 0x1;

	std::vector<int> set;
	std::vector<std::vector<int>> subset;

	//Данные
	sizeSet = 4;
	sizeSubset = (int)pow(2, sizeSet);
	for (int i = 0; i < sizeSet; i++)
	{
		set.push_back(i);
	}

	// Генерация
	for (int i = 0; i < sizeSubset; i++)
	{
		int tempMask = i;
		std::vector<int> temp;
		for (int j = 0; j < sizeSet; j++)
		{
			if ((tempMask & maskaForBit) == 1)
			{
				temp.push_back(j);
			}
			tempMask >>= 1;
		}
		subset.push_back(temp);
	}

	//Вывод
	std::cout << "Подмножества множества:" << std::endl;
	for (int i = 0; i < sizeSubset; i++)
	{
		std::cout << "{ ";
		for (int j = 0; j < subset[i].size(); j++)
		{
			std::cout << char(97 + subset[i][j]) << " ";
		}
		std::cout << "}" << std::endl;
	}
	
	system("pause");
	return 0;
}

