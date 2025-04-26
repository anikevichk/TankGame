# Toon Tanks – 3D Tank Shooter
[Gameplay Video](https://www.youtube.com/watch?v=kIzC08xY0xk)

**Toon Tanks** is a 3D arcade-style shooter where the player controls a tank and battles enemy towers. All core gameplay mechanics are implemented in C++ using Unreal Engine's systems.

## Core Gameplay
- Precise tank movement, aiming, and shooting.
- Automated enemy towers that track and attack the player.
- Health system for player and enemies.
- Game flow management: start screen, win/lose conditions.

## Implemented Features
- **C++-Driven Gameplay**  
  Entire game logic (movement, shooting, health, death) is fully written in C++.

- **Auto-Targeting Towers**  
  Enemy towers automatically find and fire at the player.

- **Projectiles and Particle Effects**  
  Projectiles with collision detection, damage application, and visual effects for impacts.

- **Gameplay Management**  
  Custom `GameMode` controls the start, victory, and defeat conditions, as well as screen widgets.

## Code Structure
| File | Purpose |
|:---|:---|
| `PlayerTank.cpp/.h` | Handles tank movement, aiming, and shooting |
| `EnemyTower.cpp/.h` | Manages enemy tower behavior and attacks |
| `Projectile.cpp/.h` | Controls projectile logic and collisions |
| `HealthComponent.cpp/.h` | Manages health and damage |
| `TanksGameMode.cpp/.h` | Oversees gameplay rules and game flow |
| `TanksPlayerController.cpp/.h` | Handles input and camera control |

## Controls
- **WASD** — Move the tank
- **Left Mouse Button** — Fire a projectile
- **Spacebar** — Restart the level
