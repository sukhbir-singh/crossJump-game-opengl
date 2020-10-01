## OpenGL-Game--CrossJump

### Introduction: 
CrossJump is a two player game. It consists of 5 Levels of difficulty (which can be selected by 
pressing any of the keys between 1 to 5 during pause screen in game), Player to cross the finishing line 'FIRST' 
will be declared as winner.

### How to Play: 
Both players complete against each other to reach the finishing line as fast as possible.
Controls(Player1: i j k l)(Player2: w a s d) of both players is given below. 

### How to install:
Game is developed in C++ using OpenGL, so only game requirement is OpenGL and C++ compiler installed on system,
If OpenGL is installed on the system (If not please Google it), just compile and run the game.

To install freeGlut (inplace for OpenGL) in linux, run following command:
```
sudo apt-get install freeglut3-dev
```
And for compiling and executing the Game .cpp file, run following commands:
```
g++ crossJumpGame.cpp -lglut -lGL
```
this will make a.out file, use following command to run it:
```
./a.out
```
### Game info
After Starting the Game (any level), 
Players have to move from Starting platform to Middle platform (known as SAFE ZONE) to Destination Platform.
During your Travel, he have to pass over only White platforms, if you fall in black area then your player restarts 
from initial position. 

### Players:
Player1 is of 'RED' color and Player2 is of 'BLUE' color.

### Controls: 
Player1 can move around the area using keys i(UP), j(LEFT), l(RIGHT), k(DOWN)
Player2 can move around the area using keys w(UP), a(LEFT), d(RIGHT), s(DOWN)

### Pause Button: 
'p' key is used to Pause, Resume, or For selecting different levels during the gamePlay.

##### Important:- After reaching the finishing line of game, pressing 'p' will restart the game.

### Levels: 
Game consists of 5 Levels of varying difficulty. Levels can be selected by pressing any of the keys
1,2,3,4,5 during Pause screen (Pause screen appears when 'p' is pressed during gameplay.)

### Screenshots:
![Screenshot 1](screenshot1.png?raw=true "Instruction Screen")
![Screenshot 2](screenshot2.png?raw=true "Stage 3 Screen")
![Screenshot 3](screenshot3.png?raw=true "Winner Screen")
![Screenshot 4](screenshot4.png?raw=true "Stage 5 Screen")

