# 🏦 Bank Management System

A fully object-oriented C++ banking simulation with modular architecture, security features, and real-world functionality.

![C++](https://img.shields.io/badge/C%2B%2B-OOP-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-informational)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple)

---

## About

A comprehensive bank management system built entirely in C++ using Object-Oriented Programming principles. The system is designed with a modular, screen-based architecture where every screen is handled by its own dedicated class and header file — making the codebase clean, maintainable, and scalable.

The system simulates core real-world banking operations including account management, secure authentication, money transfers, currency exchange, and role-based access control — all backed by persistent file storage.

---

## Features

- 🔐 **Login security** — Account lock after 3 failed attempts. Encrypted passwords stored in user files.
- 📜 **Login history** — Full login register screen showing authentication history with timestamps.
- 💸 **Money transfers** — Transfer funds between accounts with a full transfers log screen.
- 🌍 **Currency exchange** — List currencies, update rates, find currency, and calculate conversions.
- 🕓 **Live date & user display** — Current date and logged-in user shown across all screens.
- 🔑 **Role-based permissions** — Bitwise permissions system controlling access per user role.

---

## Tech Stack

- C++ with full OOP design — classes, encapsulation, and header-based modularity
- File I/O for persistent storage of users, clients, transfers, and currency data
- STL vectors for dynamic data handling
- Bitwise operations for user permission management
- Built with Visual Studio Community 2022

---

## Project Structure

```
📁 Bank-System-Management/
├── 📄 Project 3 Bank System v2.sln
├── 📁 Project 3 Bank System v2/
│   ├── 📁 Header Files/
│   │   ├── 📁 Core/
│   │   │   ├── clsClient.h
│   │   │   ├── clsCurrency.h
│   │   │   ├── clsPerson.h
│   │   │   └── clsUser.h
│   │   ├── 📁 Lib/
│   │   │   ├── clsChar.h
│   │   │   ├── clsDate.h
│   │   │   ├── clsInputValidation.h
│   │   │   ├── clsString.h
│   │   │   └── clsUtility.h
│   │   ├── 📁 Screens/
│   │   │   ├── Main Menu/
│   │   │   ├── clsLoginScreen.h
│   │   │   ├── clsMainScreen.h
│   │   │   └── clsScreen.h
│   │   └── GlobalUser.h
│   └── 📁 Source Files/
```

---

## Getting Started

1. Clone the repository
2. Open `Project 3 Bank System v2.sln` in Visual Studio 2022
3. Build the solution (Ctrl + Shift + B)
4. Run the project (F5)
