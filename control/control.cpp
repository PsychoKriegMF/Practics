#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

void clear_arr(int arr[], const int length, int x) {
	for(int i = 0; i < length; i++){
		if (arr[i] == x)
			arr[i] = 0;		
	}
}
int index_sum(int arr[], int arr2[], const int length, const int length2, int n) {
	if (n >= length || n >= length2 || n < 0) {
		std::cout << "ERROR\n";
		return 0;
	}
	return arr[n] + arr2[n];
}
int compare_pare(int arr[], const int length, int a, int b) {
	for (int i = 0; i < length - 1; i++)
		if (arr[i] == a && arr[i + 1] == b)
			return i;
	return -1;
}

void prime_range(int a, int b) {
	for (int j = a; j <= b; j++) {
		int counter = 1;
		for (int i = 1; i <= j / 2; i++)
			if (j % i == 0)
				counter++;
		if (counter == 2)
			std::cout << j << ' ';
	}
	std::cout << std::endl;
}
void prime_range(int a) {
	prime_range(1, a);
}


template <typename T>
void permute_arr(T arr[], const int length) {
	if (length % 2 != 0)
		for (int i = 0; i < length / 2; i++) 
			std::swap(arr[i], arr[i + length / 2 + 1]);
	else
		for (int i = 0; i < length / 2; i++)
			std::swap(arr[i], arr[i + length / 2]);
}




int main() {
	setlocale(LC_ALL, "ru");
	int n;
	const int size = 10;
	int arr[size]{1,2,3,6,5,2,7,6,9,10};
	
	std::cout << "Задача 1.";
	std::cout << "Изначальный массив: \n";
	print_arr(arr, size);
	clear_arr(arr, size, 9);
	std::cout << "Обнуленные значения массива: \n";
	print_arr(arr, size);
	
	
	std::cout << "\nЗадача 2.\n";

	const int size2 = 10;
	int arr2[size2]{ 10,9,8,7,6,10,4,3,2,1};
	
	std::cout << "Два массива : \n";
	print_arr(arr, size);
	print_arr(arr2, size2);	
	std::cout << "Введите индекс -> ";
	std::cin >> n;
	std::cout << "Сумма элементов: " << index_sum(arr, arr2, size, size2, n) << "\n";
	

	std::cout << "\nЗадача 3.\n";
	print_arr(arr, size);
	std::cout << compare_pare(arr, size, 2, 3);
	
	
	std::cout << "\nЗадача 4.\n";
	prime_range(2, 35);
	prime_range(35);

	

	std::cout << "\nЗадача 5.\n";
	const int size3 = 7;
	int arr3[size3]{ 1,2,3,4,5,6,7};
	print_arr(arr3, size3);
	permute_arr(arr3, size3);
	print_arr(arr3, size3);


	return 0;
}