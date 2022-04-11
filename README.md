TODO: organize the table of contents into sections and subsections by phase (0,I,II, etc)
TODO: make the links open in a separate window?? ... not possible https://stackoverflow.com/questions/41915571/open-link-in-new-tab-with-github-markdown-using-target-blank

TODO: reword all the poor word choices of alex maleno bc he cannot write

TODO: have classmates read through learning module to get an estimate of how long it would take to complete the module (time differences for different levels of complexity) and write that here

TODO: add a bit after/at the end of "Running AFL++" about how to see the input that caused crashes

# Table of Contents

1. [Introduction](https://github.com/alex-maleno/Fuzzing-Module#introduction)
2. [What Is Fuzzing?](https://github.com/alex-maleno/Fuzzing-Module#what-is-fuzzing)
3. [Why Fuzz?](https://github.com/alex-maleno/Fuzzing-Module#why-fuzz)
4. [Terms Used Throughout the Module](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module)
5. [Tools Used](https://github.com/alex-maleno/Fuzzing-Module#tools-used)
6. [How to Dowload Docker](https://github.com/alex-maleno/Fuzzing-Module#how-to-dowload-docker)
7. [How to Clone AFLplusplus](https://github.com/alex-maleno/Fuzzing-Module#how-to-clone-aflplusplus)
8. [Kali Linux (for Windows) - or any other virtual machine](https://github.com/alex-maleno/Fuzzing-Module#kali-linux-for-windows---or-any-other-virtual-machine)
9. [Sourcetrail Download](https://github.com/alex-maleno/Fuzzing-Module#sourcetrail)
10. [Creating a Container to Fuzz Code](https://github.com/alex-maleno/Fuzzing-Module#creating-a-container-to-fuzz-code)
11. [Running AFL++](https://github.com/alex-maleno/Fuzzing-Module#running-afl)
12. [Building Targets: on Mac](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#on-mac)
13. [Building Targets: on Windows](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#on-windows)
14. [Indexing and Analysis in Sourcetrail](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#indexing-and-analysis-in-sourcetrail)
15. [Creating a Slice](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#creating-a-slice)

# Fuzzing-Module

## Introduction

This repository contains a README which explains the concept of fuzzing and why one would want to fuzz.  The README goes on to teach anyone familiar with Computer Science how they can start fuzzing their own projects using the three examples ("problem1", etc.) in the repository. 

## What Is Fuzzing?

From [Wikipedia](https://en.wikipedia.org/wiki/Fuzzing), fuzzing is automated input testing for a codebase or executable. While fuzzing, invalid or unexpected (sometimes random) data is provided to an executable in hopes of finding some undefined behavior, or vulnerability. For more information about what fuzzing is and how it can be beneficial, you can look at [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Why Fuzz?

Fuzzing is used to find vulnerabilities in software. You can fuzz your own code or open source projects to find and patch edge cases of bugs or for other academic purposes. Again, a more detailed description of why one would choose to fuzz can be found in [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Terms Used Throughout the Module
TODO: keep adding to this as we write the module so people know what terms mean

- **Container**: An isolated environment on a computer that allows code to run freely without interacting with the rest of your computer or other hardware. You can think of this like a Virtual Machine which only uses a command line interface.
- **Wrapper**: A program that allows a fuzzer to interact with the slice being fuzzed.  It is the code which glues together the fuzzer and the target code.
- **Mutations**: New inputs which the fuzzer generates by modifying previous inputs with the goal of reaching more areas of the target code.
- **Slice**: A section of a codebase that is isolated from the rest of it.  Isolation of slices makes finding vulnerabilites and bugs easier and more efficient.

# Phase 0: Setup and Software

## Key Terms

We use a number of tools throughout this learning module (with download links as they come up), so we will outline them here.

- **Docker**: We will create a container using Docker to create an isolated environment for fuzzing the target code.
- **AFL++**: AFL++ is the fuzzer we will use in this learning module. AFL++ will attache to the target code using a wrapper, and it will handle all of the inputs and mutations. When running code with AFL++, there is a nice output that updates automatically to show how long the code as been running and some information about the number of crashes/hangs that have been detected.
- **Kali Linux**: A virtual machine that we used during our testing process for Windows users. Any other virtual machine will work for our purposes.
- **Sourcetrail**: A tool that can be used to get familiar with a codebase. There are two main windows within Sourcetrail - the code being looked at and a graphical interpretation of it. By clicking on functions within the code, you can see where those functions are called in other spots throughout the codebase. We found Sourcetrail to be quite useful for exploring large projects because we could more easily determine how various parts of the codebases were connected.

## How to Dowload Docker
 - To download Docker, go to this link on the [Docker wesbite](https://www.docker.com/products/docker-desktop/) and choose the correct operating system and chip. The website should automatically propose the correct software for your system, but download links for other versions will also be availabile on the page.
 - After the download is complete, run through the steps in the setup and open the desktop app on your computer. 

## How to Clone AFLplusplus
 - Go to the AFLplusplus [Github Repo](https://github.com/AFLplusplus/AFLplusplus) and click the green "Code" button.  Copy the HTTPS link to clone the repository. 
- In your terminal - Terminal for Mac and PowerShell for Windows - execute this command to colone the repository: `git clone https://github.com/AFLplusplus/AFLplusplus` .

## How to Create an AFL++ Docker Container
 - Open the Docker app on your computer, otherwise the next step will throw an error. 
 - In your terminal, run the following command: `docker pull aflplusplus/aflplusplus`
    - After this command has run, open the Docker app and see the AFL++ container under the Container/Apps tab. Next to the container, it should say `aflplusplus/aflplusplus` in blue.
    - If you do not see a new container, go to the Images tab (also on the left) and find the most recent aflplusplus/aflplusplus image.  Hover over it, click run on the far right, and then create a new container.  
 - Once you have created the container, return to the Container / Apps tab.
 - Hover over the new container and click the play button to start the container.
    - If there is a stop button instead of a play button, then the container is already running.
 - Click on the CLI button, which has " >_ " in a circle. This will open a new command line window that is already within your AFL++ docker container.

## Kali Linux (for Windows) - or any other virtual machine
 - For our purposes, we chose Kali Linux as our virtual macine, but any other virtual machine should suffice. We used a VM to run Sourcetrail because, while running Sourcetrail on Windows, Sourcetrail was routinely unable to locate the correct path for the code. 
 - To do this properly on a Windows machine, simply download your VM of choice - we used VirtualBox or VMWare with a Kali Linux image, all which can be found on the [Kali website](https://www.kali.org/get-kali/#kali-bare-metal) with the VM download on the page just below. 
	- To download the correct Kali image, make sure you are matching your computer architecture with the image you download. 
	Under the Bare Metal header, you can choose 64 or 32-bit images. The recommended image to download is the "Installer"
	image, which is the first one you see and is 2.8GB in size. You can read more about which image to download [here](https://www.kali.org/docs/introduction/what-image-to-download/).
	- After downloading the correct image, scroll down on the page under the "Virtual Machines" header, and choose either the VMWare or the VirtualBox download (make sure to choose either 64 or 32 bit here as well). 
 - After this is done - run through the setup of the VM and open it up, and run the image. After you run, you should
 get a login screen - the default credentials to enter are a username and password of `kali`. Then, follow the next set of
 steps in order to download Sourcetrail in your VM. 
 
## Sourcetrail Download
 - To download Sourcetrail go to the [Sourcetrail github](https://github.com/CoatiSoftware/Sourcetrail/releases) and select the release that is compatible with your operating system. Run through the setup on your computer and open the app. 

## Creating a Container to Fuzz Code

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

## Running AFL++

1. Within the /AFLplusplus directory (you should start here in the container when you start it), `make` the executables (this may take a few minutes, be patient)
2. Once done building the AFLplusplus executables, navigate to the folder of the code you want to fuzz. You will need to go up a directory from /AFLplusplus (cd ..), and then cd into [name of the directory you are adding to the container] from step 4 of "Creating a Container to Fuzz Code".
3. Create a build directory (standard practice to name it build)
    - `mkdir build`
4. Change directory into build
    - `cd build`
5. Add AFL++ tooling to the compiler for your executable:
    - `CC=/AFLplusplus/afl-clang-lto CXX=/AFLplusplus/afl-clang-lto++ cmake ..`
    - afl-clang-lto/++ are just one example of compilers you can use with AFL++ - different compilers have different examples. You can use any of the compilers within the /AFLplusplus directory, and the CXX variable name is always the same as the CC variable, with ++ appended to the end
6. Make the files in build
    - `make`
7. If you do not already have a seed directory, follow this process to create and populate one using the dd command.  If you do have such a directory, skip to step 8.
        - `cd ..`
        - `mkdir seeds`
        - `dd if=/dev/urandom of=seed_i bs=64 count=10`
        - repeat the above step 5 times, each time changing the value seed_i to seed_ii, etc.
        - `cd ..`
        - `cd build`
    - You can read more about the dd command at this [Stack Exchange post](https://unix.stackexchange.com/questions/33629/how-can-i-populate-a-file-with-random-data)
8. Once you have a seed directory, enter the following command:
    - `/AFLplusplus/afl-fuzz -i [full path to your seeds directory] -o out -m none -d -- [full path to the executable, i.e. /code/build/testapp]`

Congratulations, you are now running AFL++ on your target code! There should be a UI in terminal which shows you various statistics about the fuzzing proccess - look for the number of crashes detected.

# Phase I: Building Targets

## On Mac

TODO: building on mac and bugs to look for

The example programs which we provide for you in this repository can be "made" using cmake.  Ensure that the directory has a file called "CMakeLists.txt" which contains a version of the following:
    project([executable name])
    add_executable([executable name] cpp1.cpp main.cpp [etc.])


Additionally, much of our testing was performed on the open source drone control package ArduPilot.  To build ArduPilot on a Mac, follow these steps (much of this content copied from and/or originally found [here](https://ardupilot.org/dev/docs/building-setup-linux.html) under "Setup using Docker"):
1. Clone the ArduPilot repository
    - `git clone https://github.com/ArduPilot/ardupilot.git`
2. Build the Docker image and "tag" it with the name ardupilot.
    - docker build . -t ardupilot
3. Run the ArduPilot docker container.
    - `docker run --rm -it -v `pwd`:/ardupilot ardupilot:latest bash`

<a href="https://ardupilot.org/dev/docs/building-setup-linux.html">here</a>


## On Windows

When going through the process of building our targets on Windows, we had compatibility issues with Sourcetrail that prevented 
the files in our targets from being indexed properly by Sourcetrail. This issue was remedied through the use of a virtual machine. 
As mentioned previously, we used Kali Linux with VMWare/VirtualBox, however any VM should work as a solution. If you are not
familiar with VMs, we will walk through using Kali Linux with VMWare and VirtualBox in this guide. 

### VirtualBox

In order to open your image of Kali Linux on VirtualBox, all you have to do is follow the steps on [this website](https://itsfoss.com/install-kali-linux-virtualbox/).
The image of Kali Linux described earlier in the module is one of the "ready-to-use" virtual images, which means all of the correct
settings should import as well when you import the image to VirtualBox. Make sure you are using the file with the `.ova` extension.
After you import the image, you can hit "Import" and then after a few minutes you should see the image in the sidebar of the
VirtualBox application. Select it, and then press the green "Start" arrow to start up the VM. 

Once you are logged in, you should see a Desktop with the Kali logo in the background. In the top left corner, there is an 
icon resembling a terminal. Open this, and follow the download steps for Sourcetrail as well as doing `git clone` for the chosen
target(s). After the target(s) are cloned in the VM, you can build them and move forward with the steps outlined in the [Indexing 
in Sourcetrail](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#indexing-and-analysis-in-sourcetrail) section

### VMWare 

VMware is a free-to-use, at the personal level, virtual machine software for many potential operating systems. The VMware code can be downloaded for free [here](https://www.vmware.com/products/workstation-player/workstation-player-evaluation.html). Once VMWare is installed, it may be used with any potential linux OS which provides a VMWare configuration. In the context of this project, we decided to use Kali, however, any linux version would work insofar as there exists a VMware file for it. Once the virtual machine software has finished installing, one can simply open the Kali, or any other, VM file within the program to run it.

## Indexing and Analysis in Sourcetrail

- After the project is built, open up Sourcetrail and hit New Project. Name the project something relevant and in the "Sourcetrail
Project Location" text box, click the three dots on the right and navigate to the directory where your project is. After the path 
is listed in the text box, click "Add Source Group" at the bottom of the window. 
- In the new pop up, select the "CDB" option if it is a C or C++ project. A new window will pop up. Click the three dots in
the "Compilation Database" textbox, and navigate to the "compile_commands.json" file within the build folder you created in the 
target. This will allow the files to be indexed in Sourcetrail. 
- On a Windows machine, this process is the same, but must be done within the virtual machine. 
- Once everything is indexed in Sourcetrail, open the project in another program for viewing code (like VS code) so you can 
see the files listed out and can navigate them more easily. This will allow you to glance over code and find things that would
be interesting to investigate further using Sourcetrail (Sourcetrail has a searchbar, so you can find any function or chunk of code 
very quickly). 
- The best way to find potential entry points in your targets is too look for files dealing with inputs from an outside source	
	- This could look like sensors, GPS systems, user inputs, communication modules, etc. 
- After finding a file that could be of interest, navigate to it in Sourcetrail by looking it up. After doing this, we can see the 
different functions inside of the file, and the inputs to those functions. We can click through those things to learn more 
about them 
- In general, its good practice to bookmark things in Soucetrail that look interesting so you can come back to them later

## Creating a Slice
TODO: figure out an appropriate spot to have this section. Tossed it at the end just to get ideas down. Also write more

When creating a [slice](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module), you want to narrow down the code that will be running as much as possible. For example, if you were looking to fuzz a drone system, you may just want to fuzz the communication module or the gps module to see if there are flaws in the logic that the fuzzer you are using can detect. Each fuzzing project is different, based on the layout of the codebase and the build system thats used to compile the executable. Looking at the documentation for the codebase can be very helpful to learn how all the different modules interact with each other, which can then help you figure out where to start looking at the code in Sourcetrail.

For the slice, you can comment out some of the code in the target to ignore features that you are not interested in fuzzing. The essential pieces in order to run the code should be the only code left uncommented. For example, if there is a section that `sleeps` a certain period of time to wait for another module to be up and running, but you are not interested in that module of the target, then comment it out.

When using AFL++, something that needs to be included in the [wrapper](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module) are the following lines:

`#ifdef __AFL_HAVE_MANUAL_CONTROL`

   `__AFL_INIT();`

`#endif`

These lines need to be included in your `main` before you read inputs from `STDIN`. They allow AFL++ to have control over the inputs by feeding it's inputs through `STDIN`.

### How to Create a Slice for Problem 3
In the wrapper, you should include all files that are necessary for the module you are fuzzing to run. Excess files are unnecessary. For example, let's fuzz the `hard` target that we have created for this module... 

