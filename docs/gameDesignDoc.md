# Game Design Doc

# Rapid Recharge

*Author : Jody Lloyd Stocks*

<br>

# Summary

2d game where the player needs to collect dying pulses of energy in order to gain a score, increase their boost and stay alive as long as possible.

<br>

# Detailed Summary

### Overview

The player will have to collect `**Unstable pockets of energy**` in order gain `***boost***` and fill their bar. If this bar reaches `0`, the player will begin to loose `***health***` and will die if their `***health***` reaches `0`.
When the player collects enough energy after their `***health***` is depleted, they will slowly start to generate new `***health`*** from their gained ***`boost`***.
There will be obstacles to avoid as the game progressed and potentially a way to discharge extra `***boost***`.
They player can also upgrade their `***boost***` as they collect the `**Rick Energy Sources**`.

### Obstacles

As the game goes on, new Obstacles will begin to spawn and cause the player to try to dodge `killer walls` and `non killer walls`. The `Non Killer Walls` will just cause the player to stop and not be able to move so they will have to go around the obstacle but the `Killer Walls` will damage the players `***Boost***` first and then the remaining damage will go into their `***health***` if they choose to go through the `killer walls` based on a `50-25 %` based on the size of the wall.

If Obstacles show cracks, the player can break through it with a boost.
`Killer walls` will only damage the player by `15-8 %` based on the size of the wall.

### Boost

With the `energy` gathered, they player will be able to fill their ***`boost`*** bar and when pressing a key, the player can increase their speed for a short burst to move faster In a certain direction.

The players boost will also deplete at a rate of 2.5% every second.

### Energy Discharge

If you have some energy in your `boost` bar, you will be able to hold a button to charge up a discharge if you want to smash through a `Non killer wall` or a `killer wall`. Based on how much discharge you used, will determine if the wall can break or not. 

### Energy sources

- **`Rich Energy Source`** - This will be a bigger energy source that will fade into an unstable energy source after a short period of time. Collecting 3 of these in a row will allow you to grow your `***Boost***` bar by `10%`.
- `**Unstable Energy Source**` - This energy source will fill your `boost` bar by `25 - 0 %` Based on how much has faded away before they player collected it.

### Score

The score will increment based on the amount of `***boost***` collected.

<br>

# Pillars of Design

`Elements of the game that stand out to you`

`Eg: Fast, Acton Packed, Time travel`

- Fast passed
- Time trill
- Energy collection
- Obstacle basher

<br>

# Story

- `NA`
    
<br>

## Game Play Loop

`Why Dose the Player Care`

The player needs to survive as long as possible and to collect as much boost as possible to increase their score.

<br>

## Controls

- Keyboard
    - `w, a, s, d` - Movement
    - `Shift` - Boost
    - `Space` - Discharge
- Controller
    - `Left Joystick` - Movement
    - `Button 3 (X / A)` - Boost
    - `Button 4 (O / B)` - Discharge

<br>

## Enemies/Monsters

- `NA`

<br>

## Game Play Mechanics

`How your game works in more details, show your state machines.`

Check the state machines in the UML section for more details.


<br>

# Art and sounds

## Graphics requirements

`Put some art work here to show the mood and asthetic you are trying to achive.`

<br>

## Sound

`What type of sounds are we expecting, Tones, Heavy metal, chille ?`

<br>

# Level Overview

Level Maps


# UI

`Link to GDrive`

<br>


# Development Tools

## Game Engine / Framework

- SFML

## Programming Language

- C++

## 2D Tools

- Photoshop
- Krita
- Gimp

## 3D Tools

`NA`

# Team
Programmer	: Jody L. Stocks<br>
Art	        : Jody L. Stocks<br>
Design      : Jody L. Stocks<br>
Code Review : ...<br>