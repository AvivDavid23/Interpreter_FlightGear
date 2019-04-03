# Second_Year_Project-BIU-First_Semester
Our project for the second year
Creaters : Aviv David and Dvir Segev
# Interpreter:
An interpreter for FlightGear simulator. the program gets a script as an argument which contains different commands.

The program first lexes the script, then parses it and execute each command. Meanwhile, the programs opens a server in another thread which stores data from the simulator(the simulator connects to this server as a client).
With the script, the programs sends commands to the simulator and autopilot and airplane
# Server Side:
A multy-threaded server that can accept multy clients at the same time.

The client sends a path-finding problem(low cost to destination path) to the server(in a form of a matrix). The server solves the problem with a chosen algorithm(which is one of many algorithmes we implemented), stores the solution and send it to the client. When another client asks for soulutin, the server first checks if we already have a soulution, and if so, it sends it witout solving again.
