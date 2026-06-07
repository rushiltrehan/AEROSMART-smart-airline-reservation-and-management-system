#include <iostream>
#include <string>
using namespace std;

class Flight
{
private:
    string flightNumber;
    int totalRows;
    int seatsPerRow;
    int** seatMatrix;
    int availableSeats;
    double basePrice;
    double revenue;
    static double totalSystemRevenue;

public:
    Flight()
    {
    flightNumber = "";
    totalRows = 0;
    seatsPerRow = 0;
    seatMatrix = nullptr;
    availableSeats = 0;
    basePrice = 0;
    revenue = 0;
    }
    
    Flight(string fNo, int rows, int seats, double price)
    {
        flightNumber = fNo;
        totalRows = rows;
        seatsPerRow = seats;
        basePrice = price;
        revenue = 0;
        availableSeats = rows * seats;

        
        seatMatrix = new int*[totalRows];

        for(int i = 0; i < totalRows; i++)
        {
            seatMatrix[i] = new int[seatsPerRow];

            for(int j = 0; j < seatsPerRow; j++)
            {
                seatMatrix[i][j] = 0; 
            }
        }

        cout << "Flight " << flightNumber << " initialized successfully.\n";
    }

    
    ~Flight()
    {
        for(int i = 0; i < totalRows; i++)
        {
            delete[] seatMatrix[i];
        }

        delete[] seatMatrix;

        cout << "Memory released for Flight " << flightNumber << endl;
    }

    void displaySeats()
    {
        cout << "\nSeating Layout for Flight " << flightNumber << "\n";
        cout << "----------------------------------------\n";

        char seatLabel;

        for(int i = 0; i < totalRows; i++)
        {
            cout << "Row " << i+1 << ": ";

            for(int j = 0; j < seatsPerRow; j++)
            {
                seatLabel = 'A' + j;

                if(seatMatrix[i][j] == 0)
                    cout << "[" << seatLabel << "] ";
                else
                    cout << "[X] ";
            }

            cout << endl;
        }

        cout << "\nAvailable Seats: " << availableSeats << endl;
    }

    string getFlightNumber()
    {
        return flightNumber;
    }
       
    int getAvailableSeats()
    {
        return availableSeats;
    }

    bool bookSeat(int row, char seatLetter)
{
    int seatIndex = seatLetter - 'A';

    if(row < 1 || row > totalRows || seatIndex < 0 || seatIndex >= seatsPerRow)
    {
        cout << "Invalid seat selection.\n";
        return false;
    }

    if(seatMatrix[row-1][seatIndex] != 0)
    {
        cout << "Seat already booked.\n";
        return false;
    }
    double price = calculatePrice();

    seatMatrix[row-1][seatIndex] = price;

    availableSeats--;

    revenue += price;
    totalSystemRevenue += price;

    cout << "Seat " << row << seatLetter << " booked successfully.\n";
    cout << "Ticket Price: " << price << endl;


    return true;
}

   bool cancelSeat(int row, char seatLetter)
{
    int seatIndex = seatLetter - 'A';

    if(seatMatrix[row-1][seatIndex] == 0)
    {
        cout << "Seat is already empty.\n";
        return false;
    }

    double price = seatMatrix[row-1][seatIndex];

    seatMatrix[row-1][seatIndex] = 0;

    availableSeats++;

    revenue -= price;

    totalSystemRevenue -= price;

    cout << "Seat " << row << seatLetter << " cancelled successfully.\n";

    return true;
}

double getOccupancy()
{
    int totalSeats = totalRows * seatsPerRow;
    int bookedSeats = totalSeats - availableSeats;

    return ((double)bookedSeats / totalSeats) * 100;
}

double getRevenue()
{
    return revenue;
}

static double getTotalRevenue()
{
    return totalSystemRevenue;
}

bool operator>(Flight &other)
{
    return this->revenue > other.revenue;
}

double calculatePrice()
{
    if(availableSeats > 40)
        return basePrice;

    else if(availableSeats > 20)
        return basePrice * 1.2;

    else
        return basePrice * 1.4;
}

void simulateBookings(int count)
{
    int booked = 0;

    for(int i = 0; i < totalRows && booked < count; i++)
    {
        for(int j = 0; j < seatsPerRow && booked < count; j++)
        {
            if(seatMatrix[i][j] == 0)
            {
                double price = calculatePrice();

                seatMatrix[i][j] = price;

                availableSeats--;

                revenue += price;
                totalSystemRevenue += price;

                booked++;
            }
        }
    }

    cout << booked << " seats auto-booked for demo.\n";
}

};

double Flight::totalSystemRevenue = 0;

class FlightManager
{
private:
    Flight** flights;
    int totalFlights;

public:
    FlightManager(int n)
    {
        totalFlights = n;
        flights = new Flight*[totalFlights];

     flights[0] = new Flight("DEL-MUM101",10,6,5000);
     flights[1] = new Flight("DEL-BLR202",10,6,5500);
     flights[2] = new Flight("DEL-HYD303",10,6,6000);
     flights[3] = new Flight("DEL-KOL404",10,6,6500);
    }

    ~FlightManager()
{
    for(int i = 0; i < totalFlights; i++)
    {
        delete flights[i];
    }

    delete[] flights;
}

    void displayFlights()
{
    cout << "\nAvailable Flights:\n";

    for(int i = 0; i < totalFlights; i++)
    {
        cout << i+1 << ". "
             << flights[i]->getFlightNumber()
             << " | Available Seats: "
             << flights[i]->getAvailableSeats()
             << endl;
    }
}

    Flight* getFlight(int index)
    {
        if(index < 0 || index >= totalFlights)
            return nullptr;

        return flights[index];
    }
};


int main()
{

FlightManager manager(4);
string adminUser = "admin";
string adminPass = "1234";
 while(true)
{
    int choice;

    cout << "\n===== AeroSmart Airline System =====\n";
    cout << "1. Admin Login\n";
    cout << "2. Passenger Access\n";
    cout << "3. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;
     if(choice == 1)
{
    string u,p;

    cout << "Username: ";
    cin >> u;

    cout << "Password: ";
    cin >> p;

    if(u == adminUser && p == adminPass)
    {
        cout << "Login successful\n";
        int adminChoice;

while(true)
{
    cout << "\n===== ADMIN DASHBOARD =====\n";
    cout << "1. View Flights\n";
    cout << "2. View Seats of a Flight\n";
    cout << "3. View Flight Occupancy\n";
    cout << "4. View System Revenue\n";
    cout << "5. Simulate Booking\n";
    cout << "6. Logout\n";

    cout << "Enter choice: ";
    cin >> adminChoice;
    if(adminChoice == 1)
{
    manager.displayFlights();
}
   else if(adminChoice == 2)
{
    int flightChoice;

    manager.displayFlights();

    cout << "Select flight: ";
    cin >> flightChoice;

    Flight* f = manager.getFlight(flightChoice-1);

    if(f != nullptr)
        f->displaySeats();
}
    else if(adminChoice == 3)
{
    int flightChoice;

    manager.displayFlights();

    cout << "Select flight: ";
    cin >> flightChoice;

    Flight* f = manager.getFlight(flightChoice-1);

    if(f != nullptr)
    {
        cout << "Occupancy: " << f->getOccupancy() << "%\n";
    }
}
    else if(adminChoice == 4)
{
    cout << "Total System Revenue: "
         << Flight::getTotalRevenue() << endl;
}
   else if(adminChoice == 5)
{
    int flightChoice, seats;

    manager.displayFlights();

    cout << "Select flight: ";
    cin >> flightChoice;

    cout << "How many seats to simulate booking: ";
    cin >> seats;

    Flight* f = manager.getFlight(flightChoice-1);

    if(f != nullptr)
    {
        f->simulateBookings(seats);
        f->displaySeats();
    }

    
    
}
  else if(adminChoice == 6)
{
    break;
}
  }
}
}
  else if(choice == 2)
{
    int passengerChoice;

    while(true)
    {
        cout << "\n===== PASSENGER MENU =====\n";
        cout << "1. View Flights\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Seat\n";
        cout << "4. Back\n";

        cout << "Enter choice: ";
        cin >> passengerChoice;
        if(passengerChoice == 1)
{
    manager.displayFlights();
}
   else if(passengerChoice == 2)
{
    int flightChoice,row;
    char seat;

    manager.displayFlights();

    cout << "Select flight: ";
    cin >> flightChoice;

    Flight* f = manager.getFlight(flightChoice-1);

    if(f != nullptr)
    {
        f->displaySeats();

        cout << "Enter row: ";
        cin >> row;

        cout << "Enter seat letter: ";
        cin >> seat;

        f->bookSeat(row,seat);
        f->displaySeats();
    }
}
  else if(passengerChoice == 3)
{
    int flightChoice,row;
    char seat;

    manager.displayFlights();

    cout << "Select flight: ";
    cin >> flightChoice;

    Flight* f = manager.getFlight(flightChoice-1);

    if(f != nullptr)
    {
        f->displaySeats();

        cout << "Enter row: ";
        cin >> row;

        cout << "Enter seat letter: ";
        cin >> seat;

        f->cancelSeat(row,seat);
        f->displaySeats();
    }
}
   else if(passengerChoice == 4)
{
    break;
}
    }
}
else if(choice == 3)
    {
        cout << "Exiting system...\n";
        break;
    }

    else
    {
        cout << "Invalid choice\n";
    }
}
}






