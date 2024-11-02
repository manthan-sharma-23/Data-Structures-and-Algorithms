#include <fstream>
#include <iostream>

int main() {
  char arr[100];
  std::cout << "Enter your name and age: ";
  std::cin.getline(arr, 100);

  std::ofstream myfile("file.txt", std::ios::app);

  myfile << arr;
  myfile.close();

  std::cout << "Data written to file.txt" << std::endl;

  std::ifstream obj("file.txt");

  obj.get(arr, 100);

  std::cout << "array content :" << arr << std::endl;

  return 0;
}
