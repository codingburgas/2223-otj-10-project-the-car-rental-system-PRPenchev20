#include "VehicleModel.h"
#include "VehicleService.h"

// Constructor
VehicleService::VehicleService(const std::string& filename) :repository(filename)
{
}

// Create a new vehicle record
void VehicleService::createVehicle(int year, const std::string& make, const std::string& model, const std::string& fuel)
{
    VehicleModel vehicle(year, make, model, fuel);

    repository.addVehicle(vehicle);
}

// Read all vehicle records
std::vector<VehicleModel> VehicleService::getAllVehicles()
{
    return repository.getVehicles();
}

// Update an existing vehicle record
void VehicleService::updateVehicle(int oldYear, const std::string& oldMake, const std::string& oldModel, const std::string& oldFuel,int newYear, const std::string& newMake, const std::string& newModel, const std::string& newFuel)
{
    VehicleModel oldVehicle(oldYear, oldMake, oldModel, oldFuel);
    VehicleModel newVehicle(newYear, newMake, newModel, newFuel);
    repository.updateVehicle(oldVehicle, newVehicle);
}

// Delete a vehicle record
void VehicleService::deleteVehicle(int year, const std::string& make, const std::string& model, const std::string& fuel)
{
    VehicleModel vehicle(year, make, model, fuel);
    repository.removeVehicle(vehicle);
}

void VehicleService::deleteAllVehicles()
{
    repository.removeAllVehicles();
}