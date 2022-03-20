# Fuzzing-Module

TODO: reword all the poor word choices of alex maleno bc he cannot write

TODO: have classmates read through learning module to get an estimate of how long it would take to complete the module (time differences for different levels of complexity) and write that here

TODO: table of contents with links (maybe, idk if we can do this within markdown, figure it out later)

## Introduction

Within this repository is this ReadMe, which gives an overview about what fuzzing is, why one would want to fuzz, and a detailed guide to teach anyone familiar with Computer Science about how they can start up their own fuzzing project. 

## What Is Fuzzing?

From [Wikipedia](https://en.wikipedia.org/wiki/Fuzzing), fuzzing is automated input testing for a codebase or executable. While fuzzing, invalid or unexpected (sometimes random) data is provided to an executable in hopes of finding some undefined behavior, or vulnerability. For more information about what fuzzing is and how it can be beneficial, you can look at [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Why Fuzz?

Fuzzing is useful in order to find vulnerabilities within code. This can be your own code, and you can fuzz it to reinforce that you covered all the edge cases of bugs that could occur, or it can be code you are interested in studying. Again, a more detailed description of why one would choose to fuzz can be found in [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Terms Used Throughout the Module
TODO: keep adding to this as we write the module so people know what terms mean

- **Container**: An isolated environment on a computer that allows code to run freely without interacting with the rest of your computer. You can think of this like a Virtual Machine, but only having a command line interface.
- **Wrapper**: A program that allows a fuzzer to interact with the desired code being fuzzed.
- **Mutations**: New inputs from the fuzzer that are modified from previous inputs to try to get to different areas of the code


## Tools Used

We use a number of tools throughout this learning module (with download links as they come up), so we will define them here.

- **Docker**: We will create a container using Docker in order to create an isolated environment on your computer in order to fuzz the code we are looking at. 
- **AFL++**: AFL++ is a fuzzer that we will be using in order to look for vulnerabilities. AFL++ will be attached to our code using a wrapper, and AFL++ will handle all of the inputs and mutations. When running code with AFL++, there is a nice output that updates automatically to show how long the code as been running and some information about the number of crashes/hangs that have been detected.
- **Kali Linux**: A virtual machine that we used during this process for Windows users. Any other virtual machine will work for our purposes.
- **Sourcetrail**: A tool that can be used to get familiar with a codebase. There are two main windows within Sourcetrail - the code being looked at and a graphical interpretation of that code. By clicking on functions within the code, you can see where those functions are called in other spots throughout the codebase. 

## How to Dowload Docker
 - To download Docker, go to this link on the [Docker wesbite](https://www.docker.com/products/docker-desktop/) and make sure 
 you choose the correct operating system and chip. If you have a Windows, machine, those download links can be found directly
 below the download links for Mac. 
 - After the download is complete, run through the steps in the setup and open the desktop app on your computer. 

## How to Clone AFLplusplus
 - The next step is to go to the AFLplusplus [Github Repo](https://github.com/AFLplusplus/AFLplusplus) and hit the green
 "Code" button, and copy the HTTPS link to clone the repository. 
- In your terminal - Terminal for Mac and PowerShell for Windows - write 
`git clone https://github.com/AFLplusplus/AFLplusplus` in order to clone AFLpluslplus onto you computer. 

### How to create an AFL++ Docker container
 - First, open the Docker desktop app on your computer, otherwise the next step will throw an error. 
 - In your terminal, run the following command `docker pull aflplusplus/aflplusplus`
 - After this command has run, you should be able to open the Docker app and see the AFL++ container under the 
 Container/Apps tab. Next to the container, it should say `aflplusplus/aflplusplus` in blue. 
 --if you do not see a new Container, go to the Images tab (also on the left) and find the most recent 
 aflplusplus/aflplusplus image.  Hover over it, click run on the far right, and then create a new container.  
 Once you have created the container, return to the Container / Apps tab.
 - Hover over that container, and click the play button to start the container (if there is a stop button 
 instead of a play button, then the container is already running).
 - Click on the CLI button, which has ">_" in a circle. This will open a new command line window that is already within y
 our AFL++ docker container.

## Kali Linux (for Windows) - or any other virtual machine
 - For our purposes, we chose Kali Linux as our virtual macine, but any virtual machine should work here. We used 
 t VM in order to run Sourcetrail. When running Sourcetrail on Windows, Sourcetrail was unable to locate the correct path
 for the code, so an alternate solution had to be employed. 
 - In order to do this properly on a Windows machine, simply download your VM of choice - we used VirtualBox or VMWare 
 with a Kali Linux image, all which can be found on the [Kali website](https://www.kali.org/get-kali/#kali-bare-metal) with the
 VM download on the page just below. 
 - After this is done - run through the setup of the VM and open it up, and run the image. Then, follow the next set of
 steps in order to download Sourcetrail in your VM. 
 
## Sourcetrail
 - In order to download Sourcetrail, which we can use to walk through and analyze code, go to the
 [Sourcetrail github](https://github.com/CoatiSoftware/Sourcetrail/releases) and download the release that is compatible
 with your operating system. Then run through the setup on your computer and open up the app. 

## Running AFL++

1. Within the /AFLplusplus directory (you should start here in the container when you start it), `make` the executables (this may take a few minutes, be patient)
2. Once done building the AFLplusplus executables, navigate to the folder of the code you want to fuzz. You will need to go up a directory from /AFLplusplus (cd ..), and then cd into [name of the directory you are adding to the container] from step 4 of "Creating a Container to Fuzz Code".
3. Create a build directory (standard practice to name it build)
4. cd into build
5. Add AFL++ tooling to the compiler for your executable: CC=/AFLplusplus/afl-clang-lto CXX=/AFLplusplus/afl-clang-lto++ cmake ..
    - afl-clang-lto/++ are just one example of compilers you can use with AFL++ - different compilers have different examples. You can use any of the compilers within the /AFLplusplus directory, and the CXX variable name is always the same as the CC variable, with ++ appended to the end
6. make (make) the files in build
7. /AFLplusplus/afl-fuzz -i [full path to your seeds directory] -o out -m none -d -- [full path to the executable, i.e. /code/build/testapp]
    - If you don't have a seed directory to begin with, you can populate files using the dd command, i.e. dd if=/dev/urandom of=seed_i bs=64 count=10
    - You can read more about the dd command at this [link](https://unix.stackexchange.com/questions/33629/how-can-i-populate-a-file-with-random-data)