// VehicleModel.cpp - Implementation file for the VehicleModel class
#include <iostream>
#include <cstring>
#include "VehicleModel.h"

// Constructor
VehicleModel::VehicleModel(int year, const std::string& make, const std::string& model, const std::string& fuel)
{
    this->year = year;
    this->make = make;
    this->model = model;
    this->fuel = fuel;
}

int VehicleModel::nextId = 0;

// Destructor
VehicleModel::~VehicleModel() 
{
    // Destructor implementation goes here if needed
}

// Getter methods
int VehicleModel::getYear() const
{
    return year;
}

std::string VehicleModel::getMake() const 
{
    return make;
}

std::string VehicleModel::getModel() const 
{
    return model;
}

std::string VehicleModel::getFuel() const
{
    return fuel;
}

// Setter methods
void VehicleModel::setYear(int year) 
{
    this->year = year;
}

void VehicleModel::setMake(const std::string& make) 
{
    this->make = make;
}

void VehicleModel::setModel(const std::string& model) 
{
    this->model = model;
}

void VehicleModel::setFuel(const std::string& fuel)
{
    this->fuel = fuel;
}

// Other methods
void VehicleModel::displayInfo() const 
{
    std::cout << "Year: " << year << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Fuel: " << fuel << std::endl;
}
