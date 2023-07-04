#include "VehicleModel.h"
#include "VehicleService.h"

// Constructor
VehicleService::VehicleService(const std::string& filename) :repository(filename)
{
}

// Create a new vehicle record
void VehicleService::createVehicle(int id, int year, const std::string& manufacturer, const std::string& model, const std::string& fuel)
{
    VehicleModel vehicle(id, year, manufacturer, model, fuel);

    repository.addVehicle(vehicle);
}

// Read all vehicle records
std::vector<VehicleModel> VehicleService::getAllVehicles()
{
    return repository.getVehicles();
}

// Update an existing vehicle record
void VehicleService::updateVehicle(int id, int newYear, const std::string& newManufacturer, const std::string& newModel, const std::string& newFuel)
{
    VehicleModel newVehicle(id, newYear, newManufacturer, newModel, newFuel);
    repository.updateVehicle(newVehicle);
}

// Delete a vehicle record
void VehicleService::deleteVehicle(int id, int year, const std::string& manufacturer, const std::string& model, const std::string& fuel)
{
    VehicleModel vehicle(id, year, manufacturer, model, fuel);
    repository.removeVehicle(vehicle);
}

void VehicleService::deleteAllVehicles()
{
    repository.removeAllVehicles();
}