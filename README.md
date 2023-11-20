# Project1MMD

Smart Home Project

The Environment Monitoring System is a simple C++ program that simulates the monitoring and control of environmental conditions in a controlled space. This README provides an overview of the program's functionality and key features.

Features
User Authentication: Users are required to log in with a username and password. The default login credentials are "admin" for the username and "123" for the password.

Real-time Data Display: The program displays real-time data on various environmental parameters, including temperature, humidity, security status, and sensor readings. Data is updated every 2 seconds.

Environmental Sensors: The program simulates two environmental sensors: a humidity sensor and a temperature sensor. These sensors provide data that is used for monitoring and control.

Alarm System: An alarm system is in place to detect unusual conditions. When triggered, the alarm value is displayed in red to draw attention to critical situations.

Mock Data Simulation: Users can enable or disable mock data updates. When mock data updates are enabled, the program simulates random sensor readings, including temperature, humidity, and sensor statuses. This feature is useful for testing and demonstration purposes.

Multi-threading: The program utilizes multi-threading to perform concurrent tasks. Specifically, it uses separate threads for updating mock data and displaying real-time data. This approach ensures that data is continuously monitored and updated without blocking the main program.

Menu-driven Interface: Users interact with the program through a menu-driven interface. They can perform actions such as setting temperature thresholds, changing security status, and enabling/disabling energy-saving mode.

Clear Console Display: The program clears the console screen before displaying data, providing a clean and organized interface for users.

How to Use
Login: When you run the program, you will be prompted to log in. Use the following default login credentials:

Username: "admin"
Password: "123"
If you enter the correct credentials, you will be logged in, and the main menu will be displayed.

Main Menu: The main menu is the central hub for interacting with the program. You can use the following options:

1. Set Temperature Threshold: Allows you to set the minimum and maximum temperature thresholds for your controlled environment. Enter the new values when prompted.

2. Set Security Status: Lets you change the security status. You can set it to "On" or "Off" based on your needs.

3. Set Energy Saving: Allows you to enable or disable energy-saving mode. Choose "On" or "Off" as desired.

4. Start Program (Display Data Every 2 Seconds): Initiates the real-time data display. This option continuously shows system time, temperature, humidity, sensor statuses, and alarm status. The alarm value is highlighted in red if activated.

5. Mock Data Update (On/Off): Enables or disables mock data updates. When enabled, the program simulates random sensor readings for testing purposes.

M. Return to Main Menu: Use this option to return to the main menu if you are in another menu or display mode.

Real-time Data Display: After selecting "4. Start Program," you will see real-time data displayed on the screen. This includes system time, temperature, humidity, sensor statuses, and alarm status. The data is updated every 2 seconds.

Mock Data Simulation: If you enable "5. Mock Data Update," the program will simulate random sensor readings for temperature, humidity, and sensor statuses. This feature is useful for testing and demonstration purposes.

Why Multi-threading?
Multi-threading is used to achieve concurrent execution of tasks in the program. Specifically, it is employed for two key purposes:

Mock Data Simulation: The mock data update function runs in a separate thread, allowing it to generate random sensor readings independently while the main program is running. This ensures that mock data updates do not block the main program's execution.

Real-time Data Display: The data display function also runs in its own thread, updating the console display with real-time data every 2 seconds. By using multi-threading, the program can continuously monitor and display data without interruption.

Dependencies
This program relies on the C++ Standard Library and does not require external dependencies.
Contributors
Murathan Demirci
Deniz Ağar
Mustafa Çetinkaya
Feel free to reach out to the contributors for any questions or inquiries related to the program.

murathan.demirci@stu.khas.edu.tr
deniz.agar@stu.khas.edu.tr
mustafacetinkaya@stu.khas.edu.tr
