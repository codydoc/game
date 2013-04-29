# Game Design Document
## Chris Hadfield Defends Earth

In a Jetman/Copter style game, an avatar of Chris Hadfield (the Canadian ISS astronaut) will move up and down to avoid the targets and 
hit/kill aliens. 


![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/ChrisTitle.png?raw=true "Chris Hadfield Game")


----

## Things

# Alien 
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/alien.png?raw=true "Alien")

The Alien can materialize anywhere. It only stays on for a few second before moving to a new random location, and if Chris can hit/kill it, he is rewarded with points. All items
in the scene move to the left, towards Chris, so the location of the Alien will be random, and whether or not it reaches Chris is dependent 
on where it materializes. When Chris kills three aliens, a heart appears on his shuttle. When he clicks the shuttle, he redeems the life.
# UFO
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/saucer.png?raw=true "UFO")

The UFO moves from the top of the scene to the bottom of the scene on one axis, and toward Chris horizontally on the other vertical axis.
Travels in diagonal lines. If the UFO hits Chris, he loses a life.
# Asteroid
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/asteroid.png?raw=true "Asteroid")

The asteroid moves in a crazy, random rotational pattern towards Chris. It rotates over its origin at different intervals and speeds.
It is the biggest, and most dangerous item. If it hits Chris, he loses a life.
# Comet
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/comet.png?raw=true "Comet")

The comet moves in a straight horizontal line. It is the fastest object, and if it hits Chris, he loses a life.
# Space Shuttle
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/spaceship.png?raw=true "Shuttle")

The space shuttle is the non-moving object in the game. If the user clicks on the space shuttle when a heart appears on it, then the astronaut can "redeem" a life.
This is essentially the dynamic reward storage mechanism. Every time Chris hits three aliens, he is rewarded one extra life. The catch is 
that he has to click the shuttle in order to add the extra life to the life count.
Chris can also hide behind the shuttle, but it does not offer him any protection from the objects.

----

## Gameplay
![alt text](https://github.com/usc-csci102-spring2013/game_codyrapp/blob/master/gameplay.png?raw=true "Gameplay")

The gameplay is as follows. The user clicks Start Game in the top left corner to start the game. Chris and his shuttle materialize. Then the objects begin to randomly appear. 
Chris moves up when the player hits the up arrow and down when the player hits the down arrow. He does not move horizontally. The goal of the game is to
avoid the UFO, asteroid, and comet, and hit/kill/clicl as many aliens as possible. For every alien that Chris hits, he wins points. For every comet,
asteroid, or UFO that hits Chris, he loses a life.

The loss and gain of life happens dynamically during gameplay. When the lifecount reaches zero, it is Game Over and the game ends.

Users can click on the Space Shuttle in the bottom left hand of the screen to redeem the lives they win when they hit 3 aliens. A
heart will appear on the shuttle indicating this.



### Score Changes

Score is based on the time Chris survives and the number of aliens he hits. He receives +100 points for each alien he hits. An automatic timer
will count up by a factor for each timer interval that Chris is alive. If Chris is hit by an asteroid, a comet, or a UFO, his score goes down and he loses a life.

### Number of Lives

Chris will start out with 3 lives. Each time he kills 3 aliens, he will be rewarded one more life, but the user has to redeem it by clicking on the
space shuttle on the bottom left hand of the screen.

----

## User Interface

When the game is executed, the user is prompted for his/her name, and a home screen image appears in the scene. When the user presses the start button,
disappears and the game scene appears. The user is instructed via a pop up box when he/she presses start how to play the game. 
When the user clicks the start game button, the text boxes will be populated with number of lives and the score count will begin. There is a pause and a quit
button at the bottom of the GUI to pause the game and to exit out of the GUI.




