/*
    configurator.cpp
    created on :30/8/2023
    author     :shrief mahmoud

*/
#include "config_lib.hpp"

// This function takes a file name and returns an array of pointers to the strings in the file.
vector<string> getStringsFromFile(const string &filename)
{
  // Open the file.
  ifstream file(filename);

  // Create a vector to store the strings.
  vector<string> strings;
  if (!file.is_open())
  {
    cout << "ERROR:file_is_not_opened";
  }

  // Read each line in the file.
  string line;
  while (getline(file, line))
  {
    strings.push_back(line);
  }

  // Close the file.
  file.close();

  // Return the vector of strings.
  return strings;
}
