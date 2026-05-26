// Copyright 2026 ALGORITHMTASKS
#include "train.h"

Train::Train() : countOp(0), head(nullptr), countCar(0) {}

Train::~Train() {
  if (!head) return;
  Car* current = head;
  do {
    Car* next = current->next;
    delete current;
    current = next;
  } while (current != head);
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!head) {
    newCar->next = newCar;
    newCar->prev = newCar;
    head = newCar;
  } else {
    Car* last = head->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = head;
    head->prev = newCar;
  }
  countCar++;
}

int Train::getLenght() {
  if (!head) throw "TRAIN IS EMPTY";
  if (countCar < 2) throw "TRAIN IS TOO SHORT";
  countOp = 0;
  Car* car = head;
  do {
    car->light = false;
    car = car->next;
  } while (car != head);
  head->light = true;
  Car* current = head->next;
  int lenght = 1;
  while (true) {
    ++countOp;
    if (current->light) {
      break;
    }
    current->light = true;
    ++lenght;
    current = current->next;
  }
  return lenght;
}

int Train::getOpCount() const {
  return countOp;
}
