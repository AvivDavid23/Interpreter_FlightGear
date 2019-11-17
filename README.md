# Interpreter:
An interpreter that allows autopilot FlightGear simulator. the program gets a script as an argument which contains different commands.

The program first lexes the script, then parses it and execute each command. Meanwhile, the programs opens a server in another thread which stores data from the simulator(the simulator connects to this server as a client).
With the script, the programs sends commands to the simulator and autopilot and airplane
