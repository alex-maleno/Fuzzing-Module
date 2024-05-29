## How to create Target Docker Container

1. Start the docker container for AFL++ using the Docker app on your desktop
2. Within the command line, type: `docker ps`
    - This will output the running docker containers on your machine at the moment. Copy the `CONTAINER ID` for the running AFL++ container
3. Next, with your copied container ID, type: `docker commit [container id]`
    - This will output a SHA256 hash of the committed container. Copy the first 7-10 characters of the commit hash.
4. To start the AFL++ container with the target code, first navigate to the top directory of the code you want to fuzz. Then type: `docker run --rm -it -v $(pwd):/[name of the directory you are adding to the container] [the commit hash that you copied in the previous step]`
    - If you don't want to navigate to the directory of the code you want to fuzz, you can replace $(pwd) with the *full path to the directory you want to fuzz, starting at your home directory*
    - If the terminal prints the following error: _docker: `invalid reference format: repository name must be lowercase`, add "quotation marks" around the `$(pwd):/\[directory\]`
        - This error arises when directory names contain space characters
    - For example, the complete command looks something like the following for one of the authors of this repository: `docker run --rm -it -v "/Users/george/Desktop/CS Capstone/capstone/medium":"/Users/george/Desktop/CS Capstone/capstone/medium" f9a71912b4`


## How to Run AFL++ on Problem 2

1. After starting the docker container, you should be within the `/AFLplusplus` directory. Navigate to the folder of the code you want to fuzz. You will need to go up a directory from `/AFLplusplus` (`cd ..`), and then `cd` into [name of the directory you are adding to the container] from step 4 of "Creating a Container to Fuzz Code".
2. Create a build directory (standard practice to name it build)
    - `mkdir build`
3. Change directory into build
    - `cd build`
4. Add AFL++ tooling to the compiler for your executable:
    - `CC=/AFLplusplus/afl-clang-lto CXX=/AFLplusplus/afl-clang-lto++ cmake ..`
    - `afl-clang-lto/++` is just one example of compilers you can use with AFL++ - different compilers have different advantages. You can use any of the compilers within the `/AFLplusplus` directory, and the `CXX` variable name is always the same as the `CC` variable, with `++` appended to the end
5. Make the files in build
    - `make`
6. If you do not already have a seed directory, follow this process to create and populate one using the `dd` command.  If you do have such a directory, skip to step 7.

    - `cd ..`
    - `mkdir seeds`
    - `for i in {0..4}; do dd if=/dev/urandom of=seed_$i bs=64 count=10; done`
    - `cd ..`
    - `cd build`

    - You can read more about the `dd` command at this [Stack Exchange post](https://unix.stackexchange.com/questions/33629/how-can-i-populate-a-file-with-random-data)
7. Once you have a seed directory, enter the following command:
    - `/AFLplusplus/afl-fuzz -i [full path to your seeds directory] -o out -m none -d -- [full path to the executable]`

Look familiar? That's because the process to run AFL++ on Problem 2 is identical to the process of running it on Problem 1. These two problems are not something you would come across in the real world, but were written to get you familiar with how AFL++ functions and what it looks like to actually run AFL++. In Problem 3, we will walk you through a simplified version of what you may actually encounter in a real fuzzing project.
