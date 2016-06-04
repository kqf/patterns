Behavioral patterons from GoF book
==================================


1. Mododerator:
---------------
![enter image description here](https://upload.wikimedia.org/wikipedia/commons/e/e4/Mediator_design_pattern.png)

Here `FlightCotroer` plays role of mediator and concrete mediator classes.
`Aircraft` corresponds to colleague/abstract colleague classes.
Method `FlightController::ReceiveAltitude` provides communication between colleagues (aircrafts).
One can use inheritance to achieve higher flexibility. 