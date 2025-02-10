# Cub3d

## Introduction
**Cub3d** is a 3D raycasting engine project at 42, inspired by the classic **Wolfenstein 3D** game. The goal of this project is to develop a basic 3D game engine that renders a 3D world using raycasting, which is a technique for simulating 3D environments on a 2D screen. By building this engine from scratch, students learn about graphics programming, math (geometry and trigonometry), and game development concepts like camera movement and collision detection.

The engine features a first-person perspective, and the player can navigate the world using **WASD** keys and **mouse input**.

## Objectives
- Implement a raycasting algorithm to render 3D walls and floors.
- Use textures to improve the appearance of walls and floors.
- Implement a 2D map of the world, with walls, floors, and other elements.
- Handle user input for movement and mouse look.
- Implement basic game features such as camera movement and collisions.
- Render 3D graphics from a 2D map, simulating a first-person perspective.
- Improve performance by implementing optimizations like limiting the number of rays cast per frame.

## Features
- **Raycasting Engine**: The core of the project is the raycasting engine, which calculates intersections between rays and walls to render a 3D view.
- **Textured Walls and Floors**: The walls and floors are rendered using textures, which are mapped onto the 3D world.
- **Map Parsing**: The game world is defined by a **.cub** file, which contains the map and configurations like textures, colors, and resolution.
- **Player Movement**: The player can move around the world using the **WASD** keys and adjust the camera view with the **mouse**.
- **Collision Detection**: The player cannot walk through walls, and the system detects collisions when moving or rotating the camera.
- **Mouse Input**: The mouse is used to look around the world and control the player's direction.
- **Performance Optimization**: Raycasting is optimized to reduce the number of rays per frame to improve rendering performance.

## Requirements
- **C Programming**: The project is written in C, with an emphasis on system-level programming concepts such as memory management, graphics handling, and input/output.
- **Graphics Library**: The project uses **MiniLibX** for graphics rendering (an X11-based library).
- **Unix/Linux Environment**: The project should be developed in a Unix-like environment (Linux, macOS, etc.) with access to graphics libraries.
- **Math**: Strong understanding of geometry and trigonometry is required for implementing raycasting and camera movement.

## Implementation Details
- **Raycasting Algorithm**: The raycasting algorithm is the backbone of the engine. It traces rays from the player's position to determine the closest wall, and then the wall's texture is drawn on the screen.
- **Map Representation**: The map is a 2D grid, represented as an array in the program. Each element corresponds to a position in the world, and the map is read from a `.cub` file.
- **Texture Mapping**: Textures are applied to walls and floors using basic texture mapping techniques. Each pixel on a wall is rendered with the corresponding part of a texture.
- **Camera and Movement**: The camera is controlled using keyboard inputs for movement (W, A, S, D) and mouse input for rotation. The player can move forward, backward, or strafe left and right.
- **Event Handling**: The program uses **hooks** to handle user inputs, and the rendering loop is continuously updated with new camera angles and movement.
- **Optimization**: Optimizations include casting fewer rays to increase performance while maintaining visual fidelity.
