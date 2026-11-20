#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vehicle {
private:
 string vehicleID;
 string vehicleType;
 double rentalRate;
 bool available;
public:
 Vehicle(string id, string type, double rate) {
 vehicleID = id;
 vehicleType = type;
 rentalRate = rate;
 available = true;
 }
 void displayInfo() {
 cout << "ID: " << vehicleID << " | Type: " << vehicleType
 << " | Rate: Rs." << rentalRate << "/day | Status: "
 << (available ? "Available" : "Rented") << endl;
 }
 bool bookVehicle() {
 if(available) {
 available = false;
 return true;
 }
 return false;
 }
 void returnVehicle() {
 available = true;
 }
 bool isAvailable() { return available; }
 string getVehicleID() { return vehicleID; }
 double getRentalRate() { return rentalRate; }
};
class RentalSystem {
private:
 vector<Vehicle> vehicles;
public:
 void addVehicle(string id, string type, double rate) {
 vehicles.push_back(Vehicle(id, type, rate));
 }
 void viewAvailableVehicles() {
 cout << "\nAvailable Vehicles:\n";
 for(auto &v : vehicles)
 if(v.isAvailable()) v.displayInfo();
 }
 void bookVehicle(string id) {
 for(auto &v : vehicles) {
 if(v.getVehicleID() == id) {
 if(v.bookVehicle())
 cout << "Vehicle booked successfully!" << endl;
 else
 cout << "Vehicle not available!" << endl;
 return;
 }
 }
 cout << "Vehicle not found!" << endl;
 }
 void returnVehicle(string id) {
 for(auto &v : vehicles) {
 if(v.getVehicleID() == id) {
 v.returnVehicle();
 cout << "Vehicle returned successfully!" << endl;
 return;
 }
 }
 }
};
int main() {
 RentalSystem system;
 system.addVehicle("V001", "Car", 500);
 system.addVehicle("V002", "Bike", 200);
 system.addVehicle("V003", "Bus", 1000);
 int choice;
 string id;
 do {
 cout << "\n=== Vehicle Rental System ===";
 cout << "\n1. View Available Vehicles\n2. Book Vehicle\n3. ReturnVehicle\n4. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch(choice) {
 case 1:
 system.viewAvailableVehicles();
 break;
 case 2:
 cout << "Enter vehicle ID to book: ";
 cin >> id;
 system.bookVehicle(id);
 break;
 case 3:
 cout << "Enter vehicle ID to return: ";
 cin >> id;
 system.returnVehicle(id);
 break;
 case 4:
 cout << "Exiting..." << endl;
 break;
 default:
 cout << "Invalid choice!" << endl;
 }
 } while(choice != 4);
 return 0;
}
