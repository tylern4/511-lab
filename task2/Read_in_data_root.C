#include "Riostream.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TStyle.h"
#include <fstream>
#include <iostream>

std::vector<float> read_in_data(std::string file_name = "distribution.dat") {
  // Make a input stream object and open the file
  ifstream data_file;
  data_file.open(file_name);

  // Make a string varialbe to store each line of the file temperarolly
  std::string line;

  // Make a vector that will be filled and returned
  std::vector<float> histogram_data;
  // Make sure the file is open
  if (data_file.is_open())
    // For each of the lines push the line to the back of the vector as a float
    while (getline(data_file, line)) {
      histogram_data.push_back(stof(line));
    }

  // If the file is still open close it
  if (data_file.is_open())
    data_file.close();

  // return the data
  return histogram_data;
}

void plot_data(std::vector<float> input_data) {
  // TODO:
  // 1) Take in the vector of data and fill a histogram
  // 2) Draw it
  // 3) Fit it with a gaussian

  // Prints the length of the data
  std::cout << input_data.size() << std::endl;

  // Change the i<10 to i<input_data.size() to go over all the data
  for (int i = 0; i < 100; i++) {
    // This is the way to print in c++
    std::cout << input_data[i] << std::endl;
  }
}

void Read_in_data_root() {

  // Auto will use the type information from the function to declare the type
  // for the variable
  std::vector<float> input_data = read_in_data("distribution.dat");
  std::cout << "Here" << std::endl;
  // same as:
  // std::vector<float> data = read_in_data();

  plot_data(input_data);
}
