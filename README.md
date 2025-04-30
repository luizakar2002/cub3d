# cub3D - First-Person Raycaster (C + MiniLibX)

## Overview

**cub3D** is a first-person 3D raycasting engine developed in pure **C**, using the **MiniLibX** graphics library.  
It parses `.cub` scene files to render textured 3D environments with **real-time movement, collision detection, and view rotation**.  
Inspired by the mechanics of early 3D games like *Wolfenstein 3D*, `cub3D` features a full **2.5D engine**, complete with a customizable map system, player control, and game loop architecture.

---

## Core Features

- 🧱 **Raycasting Engine**
  - Renders 3D scenes from 2D maps using raycasting logic
  - Texture mapping based on wall orientation (N/S/E/W)
  - Supports floor and ceiling coloring
  - Parses `.cub` scene files for complete environment specification

- 🎮 **Player Movement & Interaction**
  - W/A/S/D movement with collision detection
  - Arrow keys or mouse for view rotation
  - ESC or window close for clean exit

- 🗺️ **Map & Scene System**
  - `.cub` files describe full scenes: textures, map layout, colors
  - Map must be enclosed with walls; invalid configurations trigger error messages
  - Configurable player spawn point and orientation

- 🧠 **Advanced Add-ons**
  - Minimap display
  - Animated sprites and openable doors (bonus)
  - Mouse-based camera rotation (bonus)

---

## Tech Stack

- **Language**: C  
- **Graphics**: MiniLibX  
- **Math**: 2D vector math + raycasting principles  
- **Input**: Keyboard & Mouse event hooks  
- **Engine Design**: Custom game loop, modular parsing, and rendering pipeline

---

## Build & Run

```bash
git clone https://github.com/luizakar2002/cub3d.git
cd cub3d
make
./cub3D <your_map>.cub
