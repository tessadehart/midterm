#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//student class
class Student
{
private:
  //variables
  std::string id;
  std::string first;
  std::string last;
  std::string email;

public:
  //functions
  //function to open the csv
  bool openFile(std::string fileName, std::ifstream &records);
  //function to create an object with data from the csv
  Student createStudent(std::ifstream &records);
  //inline mutator functions to assign values to private data members
  void setId(std::string id) { this->id = id; }
  void setFirst(std::string first) { this->first = first; }
  void setLast(std::string last) { this->last = last; }
  void setEmail(std::string email) { this->email = email; }
  //inline accessor functions to read private data members
  std::string getId() { return id; }
  std::string getFirst() { return first; }
  std::string getLast() { return last; }
  std::string getEmail() { return email; }
};

//function to open the csv
bool openFile(std::string fileName, std::ifstream &records)
{
  //open the file
  records.open(fileName);
  //return true if the file is open successfully
  if (records.is_open())
    return true;
  return false;
}

Student createStudent(std::ifstream &records)
{
  Student newStudent;
  //create variable to store data within the line while parsing
  std::string data;
  //collect the id, assign the value to the object variable
  std::getline(records, data, ',');
  newStudent.setId(data);
  //collect the first name, assign the value to the object variable
  std::getline(records, data, ',');
  newStudent.setFirst(data);
  //collect the last name, assign the value to the object variable
  std::getline(records, data, ',');
  newStudent.setLast(data);
  //collect the email, assign the value to the object variable
  std::getline(records, data);
  newStudent.setEmail(data);
  return newStudent;
}

void printRoster(std::vector<Student> roster)
{
  for (auto i = roster.begin(); i != roster.end(); ++i)
  {
    std::cout << "(" << i->getId() << ") " << i->getLast() << ", " << i->getFirst() << " - " << i->getEmail() << std::endl;
  }
}

int main()
{
  //create and open input file stream
  std::ifstream records;

  //check if file is open, if it is execute code
  if (openFile("sample.csv", records))
  {
    //create a vector of all records in the csv
    std::vector<Student> roster;

    //loop until the file is empty
    while (!records.eof())
    {
      //create a new student object from the csv values
      Student newStudent = createStudent(records);
      //adds the initialized object to the end of the vector
      roster.push_back(newStudent);
    }

    printRoster(roster);
  }
}