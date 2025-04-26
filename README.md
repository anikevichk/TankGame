# Toon Tanks – 3D Tank Shooter
[Gameplay Video](https://www.youtube.com/watch?v=kIzC08xY0xk)

**Toon Tanks** is a 3D arcade-style shooter where the player controls a tank and battles enemy towers. All core gameplay mechanics are implemented in C++ using Unreal Engine's systems.

## Core Gameplay
- Precise tank movement, aiming, and shooting.
- Automated enemy towers that track and attack the player.
- Health system for player and enemies.
- Game flow management: start screen, win/lose conditions.

## Implemented Features

### C++-Driven Interaction System
- All core mechanics (grabbing, pedestal logic, movable structures, traps) are fully implemented in C++ without relying on Blueprints.

### Physics-Based Grabbing System
- Realistic object pickup, movement, and placement using `UPhysicsHandleComponent`.

### Dynamic Pedestal Logic
- Pedestals automatically detect statues nearby and trigger events such as opening doors or activating traps.

### Movable Structures and Trap Activation
- Walls, doors, and trap mechanisms dynamically react based on pedestal states or trap triggers.

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
