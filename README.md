# AEROSMART-smart-airline-reservation-and-management-system
# AeroSmart Airline Reservation System

A console-based Airline Reservation System developed in C++ using Object-Oriented Programming concepts. The system allows passengers to book and cancel seats while providing administrators with tools to monitor flights, occupancy, and revenue.

## Features

### Passenger Features
- View available flights
- View seating layout of a selected flight
- Book seats using row number and seat letter
- Cancel booked seats
- Real-time seat availability updates

### Admin Features
- Secure admin login
- View all flights
- View seating layout of any flight
- Check flight occupancy percentage
- View total system revenue
- Simulate bulk bookings for testing and demonstrations

### Flight Management
- Multiple predefined flights
- Dynamic seat allocation using 2D arrays
- Seat status tracking
- Automatic memory management using constructors and destructors

### Dynamic Pricing System
Ticket prices increase as seats become occupied:

- Base Price → More than 40 seats available
- 20% Increase → Between 21 and 40 seats available
- 40% Increase → 20 or fewer seats available

### Revenue Tracking
- Individual flight revenue tracking
- Total airline revenue tracking across all flights

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Dynamic Memory Allocation
- Classes and Objects
- Constructors and Destructors
- Operator Overloading
- Static Data Members
- 2D Dynamic Arrays

## Predefined Flights

| Flight Number | Route | Base Price |
|--------------|--------|------------|
| DEL-MUM101 | Delhi → Mumbai | ₹5000 |
| DEL-BLR202 | Delhi → Bangalore | ₹5500 |
| DEL-HYD303 | Delhi → Hyderabad | ₹6000 |
| DEL-KOL404 | Delhi → Kolkata | ₹6500 |

## Admin Credentials

Username:
admin

Password:
1234

## Project Structure

### Flight Class
Handles:
- Seat allocation
- Seat booking
- Seat cancellation
- Revenue calculation
- Occupancy calculation
- Dynamic pricing

### FlightManager Class
Handles:
- Flight creation
- Flight storage
- Flight selection
- Flight display

## Sample Menu

```text
===== AeroSmart Airline System =====

1. Admin Login
2. Passenger Access
3. Exit
```

## Learning Outcomes

This project demonstrates:
- Object-Oriented Design
- Dynamic Memory Management
- Real-world System Modeling
- Menu Driven Applications
- Revenue and Occupancy Analytics
- Airline Reservation Logic

## Future Improvements

- Passenger records
- Ticket generation
- File handling for data persistence
- Flight search by destination
- User account system
- Graphical User Interface (GUI)
- Database integration

## Author

Rushil Trehan

First Year Engineering Student
