Behavioral patterons from GoF book
==================================


## TODO 

- [x] Chain of responsibility
- [x] Command
- [x] Interpreter 
- [ ] Iterator 
- [x] Mediator 
- [x] Memento 
- [x] Observer
- [x] State 
- [x] Strategy
- [x] Template method 
- [x] Visitor 


## Diagrams and comments 

1. Mediator:
![Mediator UML diagram](https://upload.wikimedia.org/wikipedia/commons/e/e4/Mediator_design_pattern.png)
Here `FlightCotroer` plays role of mediator and concrete mediator classes. `Aircraft` corresponds to colleague/abstract colleague classes. Method `FlightController::ReceiveAltitude` provides communication between colleagues (aircrafts). One can use inheritance to achieve higher flexibility.


2. Memento:
![Memento UML diagram](https://upload.wikimedia.org/wikipedia/commons/1/18/Memento_design_pattern.png)
In this realisation `state` corresponds to `originator`. 



3. Visitor:
![Visitor UML diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/VisitorDiagram.svg/515px-VisitorDiagram.svg.png)



4. Chain of responsibility:
![Chain of responsibility UML diagram](https://upload.wikimedia.org/wikipedia/ru/a/ae/Chain.png)



5. Command:
![Command UML diagram](https://upload.wikimedia.org/wikipedia/ru/0/0c/Command.gif)
Here we don't have `Invoker` class but instead we have ```int i```  that plays role of the invoker.


6. Observer:
![Observer UML diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/Observer.svg/854px-Observer.svg.png)

7. Strategy:
![Strategy UML diagram](https://upload.wikimedia.org/wikipedia/commons/3/39/Strategy_Pattern_in_UML.png)

8. State 

9. Template method

10. Interpreter