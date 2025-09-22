# 3d-viewer
Test assignment for C++/Qt Developer – 3D primitives editor with Qt Quick 3D

## Description
Test assignment for the **C++/Qt Developer** position.  
The application implements adding and managing 3D primitives (cube, pyramid) using **Qt 6 + Qt Quick 3D**.  

Main features:
- Add a group of primitives with parameters (dimensions, count).
- Place them at random coordinates with random colors.
- Display the list of primitives in a sidebar.
- Select an object (highlighted in the 3D scene).
- Delete individual objects or clear the entire scene.
- Interactive 3D scene with a camera (pan, zoom, rotate).

---

## 🛠️ Requirements
- **Qt 6.8+** (modules: Core, Gui, Quick, Quick3D)
- **CMake 3.16+**
- C++17

---

##  Build & Run

# Build
cmake -B build
cmake --build build

# Run
./build/appuntitled       
build\Debug\appuntitled.exe 
