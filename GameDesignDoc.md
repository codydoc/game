# Game Design Document
## Chris Hadfield Defends Earth

In a Jetman/Copter style game, an avatar of Chris Hadfield (the Canadian ISS astronaut) will move up and down to avoid the targets. 


![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/ChrisTitle.png?raw=true "Chris Hadfield Game")



----

## Things

# Alien 1
The Alien can materialize anywhere. It only stays on for a few second, and if Chris can hit/kill it, he is rewarded with another life. All items
in the scene move to the left, towards Chris, so the location of the Alien will be random, and whether or not it reaches Chris is dependent 
on where it materializes. It does not move vertically, only horizonally once it materializes.
# UFO
The UFO moves from the top of the scene to the bottom of the scene on one axis, and toward Chris horizontally on the other vertical axis.
If the UFO hits Chris, he loses a life.
# Asteroid
The asteroid moves in a diagonal pattern, either with a positive or negative slope, towards Chris. If it hits Chris, he loses a life.
# Comet
The comet moves in a straight horizontal line. It is the fastest object, and if it hits Chris, he loses a life.
# Space Shuttle
The space shuttle is the non-moving object in the game. If the user clicks on the space shuttle, then the astronaut can "redeem" a life.
This is essentially the dynamic reward storage mechanism. Every time Chris hits five aliens, he is rewarded one extra life. The catch is 
that he has to return to the shuttle in order to add the extra life to the life count.

----

## Gameplay
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/gameplay.png?raw=true "Gameplay")

The gameplay is as follows. The user clicks on Chris to start the game. Then, by default, Chris moves downward. When the player clicks and holds the mouse,
Chris moves upwards. When the mouse is released, he moves downwards at a constant rate. He does not move horizontally. The goal of the game is to
avoid the UFO, asteroid, and comet, and hit/kill as many aliens as possible. For every alien that Chris hits, he gains a life. For every comet,
asteroid, or UFO that hits Chris, he loses a life.

The loss and gain of life happens dynamically during gameplay. When the lifecount reaches zero, it is Game Over and the game ends.

Users can click on the Space Shuttle in the bottom left hand of the screen to redeem the lives they win by hitting aliens (+1 life for every five
aliens hit).



# Score Changes
# Number of Lives

----

## User Interface

