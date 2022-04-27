Exercise 3 - Working with multiple files

Many projects that exist are horrible in their own unique way - whether it is how the build system is organized, how the files are organized in subdirectories and modules, or even the style of the code written (if there even is a consistent style). This is an example of a simple "drone" project (it doesn't actually do anything), and the way the files are built is simple and easy to understand. Looking at the `CMakeLists.txt` should be self explanatory, even if you have no experience reading or
writing CMake code yourself.

One thing to note when looking at the `CMakeLists.txt` file is that we have two `add_executable` lines - one of them is for the project as a whole, but we also added a line for a new executable, which was `add_executable(specs-slice specs-slice.cpp specs.cpp)`. This was a line specific to the example slice that we wrote, and it includes the executable name, then the file containing the slice code, then the dependant file from the simple "drone" project. When trying to create your own slice from this example project, follow this guide in order to add an executable for your slice to the `CMakeLists.txt` file. 

If you want to learn more about how CMake works, you can read about it at [this link](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html).
