# **FDF 42**  

## **Introduction**  
**FdF** is a **graphics programming project** that introduces 3D rendering concepts by displaying **"iron wire" mesh models** using **isometric projection**. This project helps you understand coordinate transformations, projections, and basic rendering techniques.  

## **Project Goal**  
The goal of **FdF** is to create a program that:  
- ✔ **Reads a heightmap file** containing (x, y, z) coordinates.  
- ✔ **Converts 3D coordinates into a 2D isometric projection**.  
- ✔ **Renders the map as a wireframe**, connecting points with lines.  
- ✔ **Allows user interactions** such as rotation, zooming, and movement.  
- ✔ **Handles elevation levels** to create realistic height variations.  
- ✔ **Supports optional color gradients** for better visualization.  

This is achieved using **MiniLibX**, a lightweight graphics library for macOS/Linux.  

## **Controls**  

| Action            | Key |
|------------------|----|
| **Increase Height** | `E` |
| **Reduce Height**  | `Q` |
| **Zoom In**        | `W` |
| **Zoom Out**       | `S` |
| **Rotate -Y Axis** | `A` |
| **Rotate +Y Axis** | `D` |
| **Move Map**       | `Arrow Keys` |

## **Example Output**  

![FDF Animation](https://github.com/erwkuvi/fdf_42wolfsburg/blob/main/assets/fdf_anim.gif)  
