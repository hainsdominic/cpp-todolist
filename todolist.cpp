#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int menu();
void action(int choice);
void display();
vector<string> read_todo_file();
void save_todo_file(vector<string> todos);

int main()
{
  while (true)
  {

    display();
    int choice = menu();
    action(choice);
  }
}

// Display the menu and collect the menu input
int menu()
{
  int choice;
  cout << "MENU:\n1 - Add a todo \n2 - Delete a todo \n3 - Quit \nChoose the option number: ";
  cin >> choice;
  return choice;
}

// Execute the action corresponding to the menu input
void action(int choice)
{
  vector<string> todos = read_todo_file();
  switch (choice)
  {
  case 1:
  {
    string new_todo;
    cout << "Enter your new todo: ";
    getline(cin >> ws, new_todo);
    todos.push_back(new_todo);
  }
  break;
  case 2:
  {
    vector<string>::iterator index = todos.begin();
    int id;
    cout << "Enter the id of the todo to delete: ";
    cin >> id;
    todos.erase(index + id);
  }
  break;
  case 3:
    exit(0);
    break;
  }
  save_todo_file(todos);
}

// Display the todos
void display()
{
  vector<string> todos = read_todo_file();

  cout << "\033[H\033[2J\033[3J"; // Clears the terminal

  cout << "-------------YOUR TODOS------------- \n";
  for (size_t i = 0; i != todos.size(); i++)
  {

    cout << i << " - " << todos[i] << "\n";
  }
  cout << "------------------------------------\n";
}

vector<string> read_todo_file()
{
  vector<string> todos;
  string todo;

  ifstream todo_file;
  todo_file.open("todos.txt");

  if (todo_file)
  {
    while (getline(todo_file, todo))
    {
      todos.push_back(todo);
    }
  }

  todo_file.close();

  return todos;
}

void save_todo_file(vector<string> todos)
{
  ofstream todo_file("todos.txt");

  for (auto &todo : todos)
  {
    todo_file << todo << endl;
  }
}