#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {
  // Чекор 1: читање на содржина од фајл
  const std::string filename = "pesna.txt";
  std::ifstream file(filename);

  if (!file) {
    std::cerr << "Greska pri citanje na fajlot " << filename << std::endl;
    return 1;
  }

  int broj_na_indeks;
  std::string ime, izveduvac;
  std::getline(file, ime);
  file >> broj_na_indeks >> izveduvac;
  file.ignore();

  std::string pesna_text((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
  file.close();

  // Чекор 2: издвојување на најголемата цифра
  int max_cifra = 0;
  int tmp = broj_na_indeks;
  while (tmp > 0) {
    int cifra = tmp % 10;
    if (cifra > max_cifra) {
      max_cifra = cifra;
    }
    tmp /= 10;
  }

  // Чекор 3: наголемување на ascii вредностите и сместување во вектор
  std::vector<int> ascii_vrednosti;
  for (char c : pesna_text) {
    ascii_vrednosti.push_back(static_cast<int>(c));
  }

  // Чекор 4: сортирање на векторот
  std::sort(ascii_vrednosti.begin(), ascii_vrednosti.end());

  // Чекор 5: запишување на содржината во излезен фајл
  const std::string output_filename = std::to_string(broj_na_indeks) + ".Proekt1";
  std::ofstream output_file(output_filename);

  if (!output_file) {
    std::cerr << "Greska pri otvaranje na fajlot " << output_filename << std::endl;
    return 1;
  }

  output_file << "Broj na indeks: " << broj_na_indeks << std::endl;
  output_file << "Ime: " << ime << std::endl;
  output_file << "Izveduvac: " << izveduvac << std::endl;
  output_file << "Tekst na pesna: " << pesna_text << std::endl;
  output_file << "Najgolema cifra e: " << max_cifra << std::endl;
  output_file << "Sortirani ascci vrednosti: ";
  for (int vrednost : ascii_vrednosti) {
    output_file << vrednost << " ";
  }
  output_file.close();

  std::cout << "Sodrzinata e zapisana vo fajlot " << output_filename << std::endl;

  return 0;
}
