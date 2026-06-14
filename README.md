## Reaction Timer
This is a simple program to measure reaction times. You are presented with a visual stimulus and press Enter as quickly as you can. The program will measure your reaction time and present it to you.<br>
The program has the functionality of saving your best reaction time across executions. After the first execution, a binary file `best.bin` will be created, storing your best time.

# Example
```
./main
Press 'Enter' once the box appears.
##########
##########
##########
##########

Reaction time: 0.569465 seconds.
Your best reaction time is: 0.327105 seconds.
```
# Installation
First, clone the repo into your desired directory:<br>
`git clone https://github.com/venvio/reaction_timer`

Navigate into the directory:<br>
`cd reaction_timer`

Build the project using make:<br>
`make`

Then run with the following:<br>
`./main`
