SETMS - Smart Ethiopian Transport Management System
A C++ console application that verifies drivers before payment, built as part of a self-guided C++ learning project.
What It Does
Passengers verify a driver's identity before paying — reducing the risk of paying the wrong person. Each driver registers with a name, plate number (targa), and a unique 4-digit code. To pay, a passenger enters the driver's code, confirms the driver's name and plate number match, then completes a simulated payment based on trip distance.
Features
Driver Registration — name, 5-digit targa (plate number), and a unique 4-digit code
Input Validation — targa and code are checked for correct length/format before being accepted
Duplicate Code Protection — the system rejects a code that's already assigned to another driver
Pay by Code — passenger enters a code, system displays the matching driver's name and targa for verification
Distance-Based Fare Calculation
1–3.5 km → 10 birr
4–5.5 km → 15 birr
6–7.5 km → 25 birr
Payment Confirmation — passenger confirms before the (simulated) payment is completed
Technologies Used
C++
Object-Oriented Programming (classes, constructors)
Arrays
Functions
Loops & Conditionals (for, do-while, if/else)
How to Run
Download setms.cpp
Compile:
g++ setms.cpp -o setms
Run:
./setms
Sample Flow
===ETHIOPIAN SMART TRANSPORT MANAGEMENT SYSTEM===
1. Register Driver
2. Pay by Code
3. Exit
Choice: 1

Enter driver name: Abebe
Enter targa (5-digit number): 12345
Enter 4-digit code for this driver: 4821

Driver registered successfully!
Choice: 2

Enter driver's 4-digit code: 4821

--- Driver Found ---
Name: Abebe
Targa: 12345
---------------------
Enter trip distance (km): 5
Fare = 15 birr
Confirm payment? (1 = Yes, 2 = No): 1

Payment of 15 birr sent to Abebe successfully!
Known Limitations
Data is stored only in memory — closing the program clears all registered drivers
Fare calculation has small unhandled gaps between defined distance tiers (e.g. 3.6–3.9 km)
Payment is simulated only — no real payment provider is connected
Planned Improvements
Save/load driver data to a file so it persists between runs
Close the small gaps in the fare distance ranges
Trip history and ratings per driver
Author
Built as part of a self-directed C++ study plan, combining classes, validation logic, and a real-world use case (transport safety verification) inspired by ride-hailing driver verification flows.