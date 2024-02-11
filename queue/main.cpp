#include <iostream>

struct Node
{
  int value;
  Node *next;

  Node(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  void insert(int value)
  {
    Node *newNode = new Node(value);
    if (!head)
    {
      head = newNode;
    }
    else
    {
      Node *nodeTmp = head;
      Node *nodePrev = nullptr;
      while (nodeTmp)
      {
        nodePrev = nodeTmp;
        nodeTmp = nodeTmp->next;
      }
      nodePrev->next = newNode;
    }
  }

  void remove(int value)
  {
    Node *nodeTmp = head;
    Node *nodePrev = nullptr;

    while (nodeTmp)
    {
      if (head->value == value)
      {
        head = head->next;
        break;
      }
      nodePrev = nodeTmp;
      nodeTmp = nodeTmp->next;
      if (nodeTmp->value == value)
      {
        nodePrev->next = nodeTmp->next;
        break;
      }
    }
  }

  void update(int value, int newValue)
  {
    Node *nodeTmp = head;

    while (nodeTmp)
    {
      if (nodeTmp->value == value)
      {
        nodeTmp->value = newValue;
        break;
      }
      nodeTmp = nodeTmp->next;
    }
  }

  void display()
  {
    Node *current = head;
    while (current)
    {
      std::cout << current->value << " ";
      current = current->next;
    }

    std::cout << " " << std::endl;
  }
};

int main()
{
  LinkedList list;
  list.insert(3);
  list.insert(6);
  list.insert(2);
  list.insert(5);
  list.insert(1);
  list.remove(3);
  list.update(1, 99);

  std::cout << "Lista Encadeada: ";
  list.display();
  return 0;
}
