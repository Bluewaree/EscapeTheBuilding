# Escape The Building
> A simple Unreal Engine 4 3D puzzle game.
## Introduction 
> The game is played by controlling a robot whose main goal is to escape the whole building. The character spawns in one of the building's rooms while locked inside it and can never get out of it unless he types the right code which opens its door. Each room has basically the same system. However, in order to complete the game, the player should find every room's code and get through it. 
## Constructions
- Download and install Unreal Engine 4.
- Unzipp the game folder inside UE4's projects folder.
- Open UE4 and launch the unzipped folder.
- At first, a message appears saying asking for permission to rebuilt the project. Press "Yes" and wait a few minutes for it to be completed.
- Enjoy.
## Solutions
- Room 1 : 102 
  - The only number wrriten backwards amongst the list of numbers shown on one of the toilet's doors
- Room 2 : 0 
  - There are 4 figures with with 5m length in total, and 5 figures with 7m length in total, so each figure's sides have both 5m/4l = 1.25 and 7m/5l = 1.4 lengths. However in order for a figure to be defined as a square it should have in both sides the same length which none of this figures has.
- Room 3 : 382 
  - Interacting with both buttons will give away a hint about a column and a line in which the desired number might be found. The table of numbers can be found on one of the toilet's doors (Room 1).
- Room 4 : 160
  - The "57[5] + 21[6] = 791" is just a misleading equation which is confirmed as wrong when paying close attention to a "wrong" sign printed on the left-bottom side of the equation. By then the meaning of "X[y]" should be comprehended as "Code[room]" and by filling up the other equation correctly [((57 + 1 + 102[Room 1])/2)+((57 + 1 + 102[Room 1])/2)] it gives a total of "160"
- Room 5 : 57 
  - In both 2nd and 4th rooms a "57[5]" hint is already mentionned and used, so the code for this room (room 5) is "57".
- Room 6 : 21
  - In the misleading equation of the 4th room a "21[6]" is mentionned as well. 21 is the code for this room.
- Room 7 : 71
  - Pushing the button should help uncover a number on one of the 6th room's wall which is "71".
- Room 8 : 314
  - Pushing the same button used in the previous romm would uncover yet another code in the 6th room. The final code is "314".
