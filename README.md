# KVE
KVE is a simple 3D voxel engine written in C++ that allows for pathfinding from point A to point B in a 3D array of any size in O(n³) time

<img width="1400" height="1178" alt="изображение" src="https://github.com/user-attachments/assets/b3216850-d34d-429e-b5df-7a2f846d9097" />


## This project is a simple C++ voxel engine featuring a pathfinding algorithm designed to navigate from a starting point within a 3D space. The algorithm operates with $O(n^3)$ complexity.

# The SIZE Parameter

<img width="1057" height="457" alt="изображение" src="https://github.com/user-attachments/assets/2bd532ff-06f6-41c2-80ea-d8917253b97c" />

The main file, KVE.cpp, contains three constants; one of them is SIZE. As the name suggests, this constant determines the dimensions of the array. The larger the array, the longer the search takes. By default, the algorithm searches for an exit within a 10x10x10 matrix. You can modify this parameter. Note that the main matrix uses the `int` data type; if you wish to specify a significantly larger matrix size, you will need to modify the code.

# The PROCENT Parameter

<img width="1060" height="457" alt="изображение" src="https://github.com/user-attachments/assets/e8e25284-ad2c-4653-9f7c-220a402f0b76" />

This is the second constant. It controls the percentage of blocks within the matrix. By default, the algorithm generates a block with a 25% probability. You are free to adjust this parameter as you see fit. In my opinion, this percentage is optimal, and I do not recommend using a higher value.

# The LIMIT Parameter

<img width="949" height="236" alt="изображение" src="https://github.com/user-attachments/assets/3dbb31d0-67ab-4e75-97e0-28b435371df6" />


This is the final constant. It defines the maximum number of moves allowed. The move count increments after each loop iteration; the algorithm halts once this count exceeds the specified limit. The default value is 1000. If you are using a massive array requiring a higher number of attempts, it is advisable to change the data type from `int` to `long int`. This will also require some code modifications.

# Matrix Generation

<img width="1454" height="451" alt="изображение" src="https://github.com/user-attachments/assets/2a567cbf-46ef-4e83-b734-92a2ca682eda" />

While the generation parameters are described in the code comments, I will mention them here as well. By default, the algorithm utilizes four parameters: 0 for air, 1 for a block, 2 for the exit, and 3 for the agent's position. Matrix generation is handled by the `initMatrix` function.

# Additional Checks

<img width="1861" height="1153" alt="изображение" src="https://github.com/user-attachments/assets/08a2790d-5af8-4c4c-8709-2851184eaf06" />

The code also includes checks to determine whether the finish point or the agent itself is blocked. This is handled by the `ifExitIsLocked` and `ifExecutorIsLocked` functions, respectively. There are also functions for setting random starting and exit positions. And, of course, the main loop checks whether the executor has found the exit.

# Comments

<img width="1897" height="605" alt="изображение" src="https://github.com/user-attachments/assets/c1c1095c-efc4-4cfe-b372-b67d19c2f2ae" />

All functions, key variables, and parameters in the code are documented with comments. It is important to consult them when making changes. The algorithm itself is quite compact, so please be careful not to break anything when modifying the code; I would be very upset if your code failed to work or—heaven forbid—failed to compile.

# The algorithm's mathematical clumsiness

<img width="507" height="408" alt="изображение" src="https://github.com/user-attachments/assets/727292ca-118d-423b-900b-586f0eb121da" />

Right now, the algorithm is like moving a pawn in 3D chess. If the agent hits a wall—as shown in the image—the algorithm outputs a message stating that the agent is stuck. Of course, this will be fixed soon, though there is something oddly cool about the algorithm feeling like a game of Russian roulette: will the agent crash into a wall or not? In terms of timing, the algorithm is similar to Floyd's algorithm. I plan to rewrite the algorithm in pure C just for the fun of it, though that isn't set in stone. Naturally, the code will be optimized and improved. I hope you’ll at least give this algorithm a try. Please.

<img width="512" height="404" alt="изображение" src="https://github.com/user-attachments/assets/261252f5-eba7-4387-9035-f8cf1f85edd2" />

To me, my algorithm looks a lot like Floyd's algorithm—even though I actually recalled the latter completely by chance. The only difference is that mine operates in three-dimensional space. I’ve attached a screenshot below of the specific 3D chess game with pawns that I’m referring to. I hope my analogy makes sense to you.

<img width="1395" height="1052" alt="изображение" src="https://github.com/user-attachments/assets/6f6cf098-201e-43f8-85a4-9cece6e6a8ef" />


License

To save you from having to look at the LICENSE file, I’ll just paste its contents here:




