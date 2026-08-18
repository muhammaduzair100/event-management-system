# 🎟️ Event Management System (C Project)

A console-based **Event Management System** built in C as a first semester project. It allows users to manage events, customers, ticket bookings, and organizers through a simple menu-driven interface, with data persisted to local text files.

## 📌 Features

- **Event Management**
  - Create, list, search, update, and delete events
  - Store event details: name, venue, date, time, and total tickets

- **Customer Management**
  - Add, list, search, update, and delete customer records
  - Store customer name, phone number, and email

- **Ticket Management**
  - Book tickets by linking a customer to an event
  - Auto-assigns seat number and ticket ID
  - List, search, and cancel booked tickets

- **Organizer Management**
  - Add, list, search, update, and delete event organizers
  - Required to create an event

- **Data Persistence**
  - All records are saved to `.txt` files (`event.txt`, `customer.txt`, `ticket.txt`, `organizer.txt`)
  - Data automatically loads back in when the program restarts

- **User-Friendly CLI**
  - Color-coded terminal menus (ANSI escape codes)
  - Input validation to prevent crashes on invalid input

## 🛠️ Tech Stack

- **Language:** C
- **Concepts used:** Structs, Arrays, File I/O, Functions, Loops, Switch-case, String handling

## 📂 Project Structure

```
├── main.c          # Complete source code (menus + logic)
```

## 🚀 How to Run

1. Compile the program:
   ```bash
   gcc main.c -o event_management
   ```
2. Run the executable:
   ```bash
   ./event_management
   ```
3. Follow the on-screen menu to manage events, customers, tickets, and organizers.

## 📝 How It Works

- Each entity (Event, Customer, Ticket, Organizer) has a unique auto-incrementing ID.
- To create an event, a valid **Organizer ID** is required.
- To book a ticket, a valid **Customer ID** and **Event ID** are required.
- Deleting a record automatically shifts remaining records and re-indexes their IDs to keep the list consistent.

## 🎯 Purpose

This project was built as a **first semester project** to practice core C programming concepts including data structures, file handling, and building an interactive command-line application.

## 👤 Author

- *Muhammad Uzair*

## 📄 License

This project is open for educational use. Feel free to fork and build upon it.
