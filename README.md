# PierresPoutine
Pierre's Poutine Delivery System

List of Files:
	- Location.h/.cc : Contains map coordinates as well as the street names
	- Order.h/.cc : Contains information about a customer’s Order from Pierres
	- Entity : Contains Pierres user information - base class for Franchises and Drivers
	- Franchise.h/.cc : An Entity representing a Pierres franchise location
	- Driver.h/.cc : An Entity who pickups and delivers Orders
	- Queue.h/.cc : A ’first-in first-out’ data structure made from a linked list to store Orders
	- Pierres.h/.cc : Manages the Drivers and Franchises of Pierres and Coordinates taking, picking up, and delivering Orders
	- Controller.h/.cc : Controls the interaction of Pierres with the View
	- View.h/.cc : Provides a user menu, takes input, and gives output
	- refs.h :  contains a single preprocessor constant, MENU_ITEMS

Compilation and Execution Instructions:
	1. compile with 'make pierre'
	2. Execute with './pierre'
	3. Check memory leaks with 'valgrind ./pierre' 
