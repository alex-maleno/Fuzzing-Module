# Table of Contents

## Phase 0: What is Fuzzing?

0.1 [Introduction](https://github.com/alex-maleno/Fuzzing-Module#introduction)  
0.2 [What Is Fuzzing?](https://github.com/alex-maleno/Fuzzing-Module#what-is-fuzzing)  
0.3 [Why Fuzz?](https://github.com/alex-maleno/Fuzzing-Module#why-fuzz)  
0.4 [Terms Used Throughout the Module](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module)  

## Phase 1: Setup and Software

1.1 [Required Software Tools](https://github.com/alex-maleno/Fuzzing-Module#Required-Software-Tools)  
1.2 [How to Clone Target Code](https://github.com/alex-maleno/Fuzzing-Module#How-to-Clone-Target-code)  
1.3 [How to Download Docker](https://github.com/alex-maleno/Fuzzing-Module#how-to-download-docker)  
1.4 [How to Clone AFLplusplus](https://github.com/alex-maleno/Fuzzing-Module#how-to-clone-aflplusplus)  
1.5 [How to Get Kali Linux](https://github.com/alex-maleno/Fuzzing-Module#How-to-Get-Kali-Linux-(Windows-Only))  
1.6 [How To Download VirtualBox](https://github.com/alex-maleno/Fuzzing-Module#how-to-download-virtualbox)  
1.7 [How To Download VMware](https://github.com/alex-maleno/Fuzzing-Module#how-to-download-vmware)  
1.8 [How To Download SourceTrail](https://github.com/alex-maleno/Fuzzing-Module#How-To-Download-Sourcetrail)  

## Phase 2: The first Fuzz

2.1 [How to Create an AFL++ Docker Container](https://github.com/alex-maleno/Fuzzing-Module#how-to-create-an-afl-docker-container)    
2.2 [How to Create Target Docker Container](https://github.com/alex-maleno/Fuzzing-Module#how-to-create-target-docker-container)  
2.3 [How to Run AFL++ on Exercise 1](https://github.com/alex-maleno/Fuzzing-Module#how-to-run-afl-on-exercise-1)  
2.4 [Analyzing the Crashes](https://github.com/alex-maleno/Fuzzing-Module#analyzing-the-crashes)  
2.5 [Challenge: Fuzz Exercise 2](https://github.com/alex-maleno/Fuzzing-Module#challenge-fuzz-exercise-2)  


## Phase 3: Finding Potential Vulnerabilities

3.1 [How To Use Sourcetrail](https://github.com/alex-maleno/Fuzzing-Module#how-To-Use-Sourcetrail)  


## Phase 4: Fuzzing a Target with a slice

4.1 [How To Create a Slice](https://github.com/alex-maleno/Fuzzing-Module#How-To-Create-a-Slice)  
4.2 [How To Create a Slice for Exercise 3](https://github.com/alex-maleno/Fuzzing-Module#how-to-create-a-slice-for-exercise-3)  
4.3 [Fuzzing Exercise 3](https://github.com/alex-maleno/Fuzzing-Module#fuzzing-exercise-3)  
4.4 [Solution: How To Fuzz Exercise 3](https://github.com/alex-maleno/Fuzzing-Module#solution-how-to-fuzz-exercise-3)   
4.5 [Conclusion](https://github.com/alex-maleno/Fuzzing-Module#conclusion)  
---
# Fuzzing-Module

# Phase 0: What is Fuzzing

Estimated Time: 2 minutes

## Introduction

This repository contains a README which explains the concept of fuzzing and why one would want to fuzz.  The README goes on to teach anyone familiar with Computer Science how they can start fuzzing their own projects using the three examples ("exercise1", etc.) in the repository. We have designed this module to be completed on a Mac - Windows users can still complete the module but will need to use the virtual machines. 

Quick note: Fuzzing is an intermediate level topic. Although we include basic instructions, like how to install the tools needed in order to fuzz a target (installing Docker, using Sourcetrail, etc.), to be successful while fuzzing requires some experience. **Knowing how to build different projects is essential in order to fuzz a target, and that is not something that is covered in this module.**

## What Is Fuzzing?

From [Wikipedia](https://en.wikipedia.org/wiki/Fuzzing), fuzzing is automated input testing for a codebase or executable. While fuzzing, invalid or unexpected (sometimes random) data is provided to an executable in hopes of finding some undefined behavior, or vulnerability. For more information about what fuzzing is and how it can be beneficial, you can look at [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Why Fuzz?

Fuzzing is used to find vulnerabilities in software. You can fuzz your own code or open source projects to find and patch edge cases of bugs or for other academic purposes. Again, a more detailed description of why one would choose to fuzz can be found in [Google's Fuzzing repo](https://github.com/google/fuzzing).

## Terms Used Throughout the Module

- **Container**: An isolated environment on a computer that allows code to run freely without interacting with the rest of your computer or other hardware. You can think of this like a Virtual Machine which only uses a command line interface.
- **Wrapper**: A program that allows a fuzzer to interact with the slice being fuzzed.  It is the code which glues together the fuzzer and the target code.
- **Mutations**: New inputs which the fuzzer generates by modifying previous inputs with the goal of reaching more areas of the target code.
- **Slice**: A section of a codebase that is isolated from the rest of it.  Isolation of slices makes finding vulnerabilities and bugs easier and more efficient.

# Phase 1: Setup and Software

Estimated Time: 15 minutes

## Required Software Tools

We use a number of tools throughout this learning module (with download links as they come up), so we will outline them here.

- **Docker**: We will create a container using Docker to create an isolated environment for fuzzing the target code.
- **AFL++**: AFL++ is the fuzzer we will use in this learning module. AFL++ will attach to the target code using a wrapper, and it will handle all of the inputs and mutations. When running code with AFL++, there is a nice output that updates automatically to show how long the code as been running and some information about the number of crashes/hangs that have been detected.
- **Kali Linux**: A virtual machine that we used during our testing process for Windows users. Any other virtual machine will work for our purposes. This is only necessary for windows users.
- **Sourcetrail**: A tool that can be used to get familiar with a codebase. There are two main windows within Sourcetrail - the code being looked at and a graphical interpretation of it. By clicking on functions within the code, you can see where those functions are called in other spots throughout the codebase. We found Sourcetrail to be quite useful for exploring large projects because we could more easily determine how various parts of the codebases were connected.

## How to Clone Target code
 -To clone the target code for this module, simply use either the https or ssh clone process for this repository.
 -Clone the target code into wherever you want on your os.

## How to Download Docker
 - To download Docker, go to this link on the [Docker website](https://www.docker.com/products/docker-desktop/) and choose the correct operating system and chip. The website should automatically propose the correct software for your system, but download links for other versions will also be available on the page.
 - After the download is complete, run through the steps in the setup and open the desktop app on your computer.
 - Disclaimer; this may take up a lot of space on your computer

## How to Clone AFLplusplus
 - The next step is to go to the AFLplusplus [Github Repo](https://github.com/AFLplusplus/AFLplusplus) and hit the green
 "Code" button, and copy the HTTPS link to clone the repository.
- In your terminal - Terminal for Mac and PowerShell for Windows - write
`git clone https://github.com/AFLplusplus/AFLplusplus` in order to clone AFLpluslplus onto you computer.

## How to Get Kali Linux (Windows Only)
 - For our purposes, we chose Kali Linux as our virtual machine, but any other virtual machine should suffice. We used a VM to run Sourcetrail because, while running Sourcetrail on Windows, Sourcetrail was routinely unable to locate the correct path for the code.
 - To do this properly on a Windows machine, simply download your VM of choice - we used VirtualBox or VMWare with a Kali Linux image, all which can be found on the [Kali website](https://www.kali.org/get-kali/#kali-bare-metal) with the VM download on the page just below.
	- To download the correct Kali image, make sure you are matching your computer architecture with the image you download.
	Under the Bare Metal header, you can choose 64 or 32-bit images. The recommended image to download is the "Installer"
	image, which is the first one you see and is 2.8GB in size. You can read more about which image to download [here](https://www.kali.org/docs/introduction/what-image-to-download/).
	- After downloading the correct image, scroll down on the page under the "Virtual Machines" header, and choose either the VMWare or the VirtualBox download (make sure to choose either 64 or 32 bit here as well).
 - After this is done - run through the setup of the VM and open it up, and run the image. After you run, you should
 get a login screen - the default credentials to enter are a username and password of `kali`. Then, follow the next set of
 steps in order to download Sourcetrail in your VM.

## Virtual Machines (Windows only)

Through our experience on this project we would recommend using VirtualBox rather than VMware.

#### How To Download VirtualBox

In order to open your image of Kali Linux on VirtualBox, all you have to do is follow the steps on [this website](https://itsfoss.com/install-kali-linux-virtualbox/).
The image of Kali Linux described earlier in the module is one of the "ready-to-use" virtual images, which means all of the correct
settings should import as well when you import the image to VirtualBox. Make sure you are using the file with the `.ova` extension.
After you import the image, you can hit "Import" and then after a few minutes you should see the image in the sidebar of the
VirtualBox application. Select it, and then press the green "Start" arrow to start up the VM.

Once you are logged in, you should see a Desktop with the Kali logo in the background. In the top left corner, there is an
icon resembling a terminal. Open this, and follow the download steps for Sourcetrail as well as doing `git clone` for the chosen
target(s). After the target(s) are cloned in the VM, you can build them and move forward with the steps outlined in the [Indexing
in Sourcetrail](https://github.com/alex-maleno/Fuzzing-Module/blob/main/README.md#indexing-and-analysis-in-sourcetrail) section

#### How To Download VMWare

VMware is a free-to-use, at the personal level, virtual machine software for many potential operating systems. The VMware code can be downloaded for free [here](https://www.vmware.com/products/workstation-player/workstation-player-evaluation.html). Once VMWare is installed, it may be used with any potential linux OS which provides a VMWare configuration. In the context of this project, we decided to use Kali, however, any linux version would work insofar as there exists a VMware file for it. Once the virtual machine software has finished installing, one can simply open the Kali, or any other, VM file within the program to run it.

## How To Download Sourcetrail
When going through the process of building our targets on Windows, we had compatibility issues with Sourcetrail that prevented
the files in our targets from being indexed properly by Sourcetrail. We remedied the issue by using a virtual machine.
As mentioned previously, we used Kali Linux with VMWare/VirtualBox, however any VM should work as a solution. If you are not
familiar with VMs, we will walk through using Kali Linux with VMWare and VirtualBox in this guide.

 - In order to download Sourcetrail, which we can use to walk through and analyze code, go to the
 [Sourcetrail github](https://github.com/CoatiSoftware/Sourcetrail/releases) and download the release that is compatible
 with your operating system. Then run through the setup on your computer and open up the app.

# Phase 2: The First Fuzz  

Estimated Time: 45 Minutes

## How to create an AFL++ Docker Container
This is completed in the main OS terminal
 - First, open the Docker desktop app on your computer, otherwise the next step will throw an error.
 - In your terminal, run the following command `docker pull aflplusplus/aflplusplus`
 - After this command has run, you should be able to open the Docker app and see the AFL++ container under the Container/Apps tab. Next to the container, it should say `aflplusplus/aflplusplus` in blue.
    - if you do not see a new Container, go to the Images tab (also on the left) and find the most recent aflplusplus/aflplusplus image.  Hover over it, click run on the far right, and then create a new container. Once you have created the container, return to the Container / Apps tab.
 - Hover over that container, and click the play button to start the container (if there is a stop button instead of a play button, then the container is already running).
 - Click on the CLI button, which has ">_" in a circle. This will open a new command line window that is already within your AFL++ docker container.  

The following step is completed in the Docker CLI terminal

 - You should be in the `AFLplusplus` directory (you can confirm this with `pwd`). Once there, **`make`** the AFL++ executables. This will take several minutes. Once it is done `make`ing, you can close the CLI.


## How to create Target Docker Container
This is completed in the main OS terminal
1. Start the docker container for AFL++ using the Docker app on your desktop
2. Within the command line, type: `docker ps`
    - This will output the running docker containers on your machine at the moment. Copy the `CONTAINER ID` for the running AFL++ container
3. Next, with your copied container ID, type: `docker commit [container id]`
    - This will output a SHA256 hash of the committed container. Copy the first 7-10 characters of the commit hash.
4. To start the AFL++ container with the target code, first navigate to the top directory of your clone of this github repository. Then type: `docker run --rm -it -v $(pwd):/[name of the directory you are adding to the container] [the commit hash that you copied in the previous step]`
    - For example, the complete command looks something like the following for one of the authors of this repository: `docker run --rm -it -v "/Users/george/Desktop/CS Capstone/capstone/medium":"/Users/george/Desktop/CS Capstone/capstone/medium" f9a71912b4`
    - If you don't want to navigate to the directory of the code you want to fuzz, you can replace $(pwd) with the *full path to the directory you want to fuzz, starting at your home directory*
    - If the terminal prints the following error: _docker: `invalid reference format: repository name must be lowercase`, add "quotation marks" around the `$(pwd):/\[directory\]`
        - This error arises when directory names contain space characters
    - If you are on a Windows machine (and your directory names do not have space characters), you may have to use the following syntax when running this command, since your system recognizes a different filepath format: `docker run --rm -it -v C:\Users\george\Desktop\Capstone\capstone\medium:/Users/george/Desktop/Capstone/capstone/medium f9a71912b4`


## How to Run AFL++ on Exercise 1
This is completed in the target container Docker CLI
1. After starting the docker container, you should be within the `/AFLplusplus` directory. Navigate to the folder of the code you want to fuzz. You will need to go up a directory from `/AFLplusplus` (`cd ..`), and then `cd` into [name of the directory you are adding to the container] from step 4 of "Creating a Container to Fuzz Code".
2. Create a build directory (standard practice to name it build)
    - `mkdir build`
3. Change directory into build
    - `cd build`
4. Add AFL++ tooling to the compiler for your executable:
    - `CC=/AFLplusplus/afl-clang-fast CXX=/AFLplusplus/afl-clang-fast++ cmake ..`
    - Informational Note: `afl-clang-fast/++` is just one example of compilers you can use with AFL++ - different compilers have different advantages. You can use any of the compilers within the `/AFLplusplus` directory, and the `CXX` variable name is always the same as the `CC` variable, with `++` appended to the end. You can read more about the different compilers and their advantages within the [AFL++ docs](https://github.com/AFLplusplus/AFLplusplus/tree/stable/instrumentation).
5. Make the files in build
    - `make`
6. If you do not already have a seed directory, follow this process to create and populate one using the `dd` command.  If you do have such a directory, skip to step 7.
    - `cd ..`  
    - `mkdir seeds`  
    - `dd if=/dev/urandom of=seed_i bs=64 count=10` and repeat this step 5 times, each time changing seed_i (e.g. final files would be seed_0 through seed_4)  
    - `cd ..`  
    - `cd build`

You can read more about the `dd` command at this [Stack Exchange post](https://unix.stackexchange.com/questions/33629/how-can-i-populate-a-file-with-random-data)  

7. Once you have a seed directory, enter the following command:
    - `/AFLplusplus/afl-fuzz -i [full path to your seeds directory] -o out -m none -d -- [full path to the executable]`

Congratulations, you are now running AFL++ on your target code! There should be a UI in terminal which shows you various statistics about the fuzzing process - look for the number of crashes detected.

## Analyzing the Crashes

- Once there is at least 1 crash shown in the UI of AFL++, hit `Ctrl + C` to exit AFL++. You can find the inputs that caused the program to crash by traversing to the `out/default/crashes` directory.
- You can use a bugger, such as `gdb` or `llvm`, to figure out what part of the input actually caused the program to crash. There are also other directories in `out/default` that show you some information gathered during the fuzzing process - feel free to explore them.

## Challenge: Fuzzing Exercise 2

Now that you have run AFL++ on Exercise 1, we would like you to try to run AFL++ on Exercise 2 without instruction from the module. If you get stuck, instructions on how to run AFL++ on Exercise 2 will be in the `exercise2-instructions` directory.

# Phase 3: Analyzing Codebases for potential Vulnerabilities

## How To Use Sourcetrail

- After the project is built, open Sourcetrail and click New Project. Name the project something relevant and in the "Sourcetrail
Project Location" text box, click the three dots on the right and navigate to the directory where your project lives. After the path
is listed in the text box, click "Add Source Group" at the bottom of the window.
- In the new pop up, select the "CDB" option if it is a C or C++ project. A new window will pop up. Click the three dots in
the "Compilation Database" textbox, and navigate to the "compile_commands.json" file within the build folder you created in the
target. This will allow the files to be indexed in Sourcetrail.
- On a Windows machine, this process is the same, but must be done within the virtual machine.
- Once everything is indexed in Sourcetrail, open the project in another program for viewing code (like VS code, sublime, etc.) so you can see the files listed out and can navigate the file tree. This will allow you to glance over code and find things that might be interesting to investigate further using Sourcetrail (Sourcetrail has a search bar, so you can find any function or chunk of code
very quickly).
- The best way to find potential entry points in your targets is too look for files dealing with inputs from an outside source
	- This could look like sensors, GPS systems, user inputs, communication modules, etc.
    - We had success looking at "MAVLink"-related functions and files.
- After finding a file that could be of interest, navigate to it in Sourcetrail by looking it up. You will see the functions in the file and the inputs to those functions. You can click through those things to learn more about them.
- In general, its good practice to bookmark things in Soucetrail that look interesting so you can come back to them later.


# Phase 4: Fuzzing a Target with a Slice

## How to Create a Slice

When creating a [slice](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module), you want to narrow down the code that will be running as much as possible. For example, if you were looking to fuzz a drone system, you may just want to fuzz the communication module or the gps module to see if there are flaws in the logic that the fuzzer you are using can detect. Each fuzzing project is different, based on the layout of the codebase and the build system thats used to compile the executable. Looking at the documentation for the codebase can be very helpful to learn how all the different modules interact with each other, which can then help you figure out where to start looking at the code in Sourcetrail.

For the slice, you can comment out some of the code in the target to ignore features that you are not interested in fuzzing. The essential pieces in order to run the code should be the only code left uncommented. For example, if there is a section that `sleeps` a certain period of time to wait for another module to be up and running, but you are not interested in that module of the target, then comment it out.

The goal of making a slice is to streamline the running process of the program so AFL++ can more efficiently run it internally.

When using AFL++, something that needs to be included in the [wrapper](https://github.com/alex-maleno/Fuzzing-Module#terms-used-throughout-the-module) are the following lines:

`#ifdef __AFL_HAVE_MANUAL_CONTROL`

   `__AFL_INIT();`

`#endif`

These lines need to be included in your `main` before you read inputs from `STDIN`. They allow AFL++ to have control over the inputs by feeding its inputs through `STDIN`.

### How to Create a Slice for Exercise 3
In the wrapper, you should include all files that are necessary for the module you are fuzzing to run. Excess files are unnecessary. For example, let's fuzz `exercise3` that we have created for this module...

## Fuzzing Exercise 3

The first step in understanding a target is figuring out how all the functions interact. Let's look at this in Sourcetrail (if you haven't downloaded Sourcetrail, follow the instructions [here](https://github.com/alex-maleno/Fuzzing-Module#How-To-Download-Sourcetrail)).

### Using Sourcetrail

1. In a terminal window, navigate to the `Fuzzing-Module/exercise3` directory.
    - Note: this terminal window should not be one that is running a Docker container - we will be making a new container for this project. You can close any terminal windows with a Docker container currently running.
2. Create a `build` directory
    - `mkdir build`
3. Go into that `build` directory
    - `cd build`
4. Type the following line into the command line:
    - `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..`
    - This line uses CMake to create a JSON file that will tell Sourcetrail how the files interact with each other.
5. Open up Sourcetrail. On the popup that opens with the app, click "New Project"
6. Create a name for the project. It doesn't matter what the name of it is, but a good idea of a name would be the name of the code you are analyzing (e.g. "exercise3")
7. Select the location this Sourcetrail project is going to "live". This will be the top directory of the code you are running, thus for our purposes it is `Fuzzing-Module/exercise3`. Select this folder wherever you cloned this directory to by clicking on the circle with the three dots in it on the right side fo the "Sourcetrail Project Location" bar.
8. Click the "Add Source Group" button at the bottom of the window.
9. We want to add a source group for "C/C++ from Compilation Database" - click that option, and then "Next"
10. In the "Compilation Database" entry box, click the circle with the three dots in it. This should open up the `exercise3` folder. The file we are looking for is `compile_commands.json` within the `build` folder. Select it, and then click "Open".
11. Click "Create" at the bottom of the popup. This will close the current popup, and cause another popup to appear that is blue. The last step is to index all the files - click "Start"

Once the indexing is done, you will be able to look at a graphical representation of the code! A good place to start is by looking at the files that exist in this project.

Use Sourcetrail to analyze the `Sys_Status` class. We have included a sample slice and wrapper for the specs class in the file `specs-slice.cpp`.

## Solution: How To Fuzz Exercise 3

With a basic understanding of how creating a slice works, we can re-review how to fuzz Exercise 3, which is slightly different than the other pieces of code that we worked with in this module. There are many different slices that can be created using the code in Exercise 3, so you have to tailor the commands to whatever slice you are using. Aside from this, the majority of the steps will be the same. We can walk through these steps more briefly (these should be done in your regular computer terminal):
  1. Make sure that AFLplusplus and docker are running by opening up the docker application and clicking the start button next to the AFLplusplus docker container.
  2. Run the following commands:
    -  `docker ps`
    - `docker commit [id of afl++ container]`
  3. go to the /Fuzzing-Module/exercise3 directory and run the following command:
    - `docker run –rm -it -v $(pwd):/exercise3 [hash from commit two steps before]`. If this syntax does not work, back to the section describing [how to create a target docker container](https://github.com/alex-maleno/Fuzzing-Module#how-to-create-target-docker-container) to refresh yourself on other syntax you may need to use.
  4. Following this, you should be in the AFLplusplus terminal. Within this terminal, do the following:
    - `make` the AFLplusplus executables if needed.
    - Navigate to the code you added to the AFLplusplus container by doing `cd ..` and then `cd [added directory]`
  5. Within this directory, create a `seeds` directory, `cd` into it and create at least 5 seeds, the same way that we did in step 6 of ["How to Run AFL++ on Exercise 1"](https://github.com/alex-maleno/Fuzzing-Module#how-to-run-afl-on-exercise-1).
  6. Once you have your 5 seeds, `cd ..` out of the seeds directory and create the `build` directory. Go into this directory and run the following commands:
    - `CC=/AFLplusplus/afl-clang-fast CXX=/AFLplusplus/afl-clang-fast++ cmake ..`
    - `make`
    - `/AFLplusplus/afl-fuzz -i ../seeds/ -o out -m none -d -- ./specs-slice`
  7. At this point, AFLplusplus should be running and you should be seeing crashes happen. An important thing to notice is that the executable we are using is `./specs-slice`, which is a small section of our code (the slice). When writing your own slice, you should change this parameter to be the name of whatever file you created the slice in.
  8. From running AFLplusplus, there should be ~4 unique crashes. From looking at the code, it is clear that this comes from the `choose_color()` function, which will crash if it takes in any non-numerical inputs. These are the kinds of this to look for in other areas of the program when creating another slice.

  Based on what you have learned about creating a slice from these past sections, take a look at the other files in Exercise 3, and try to create another slice from other areas of the code which seem vulnerable using your new knowledge of fuzzing. 

## Conclusion

Through this module, you have learned the basics of fuzzing. We walked through a basic introduction to fuzzing, and important software to download. We also discussed using AFL++ and Docker, and some example exercises to fuzz. One of the most important parts of this module is understanding the errors that you ran into while going through our tutorial. Although many potential errors are accounted for in our explanations, knowing where these exercises come from is half the battle of understanding how to fuzz because it will provide a foundation for fuzzing much more complex programs, such as flight controller software. If you want to spend more time learning about this, go back through the errors you ran into and things that were missed while walking through the practice exercises.

Fuzzing is used consistently in industries like aviation, finance, healthcare, energy, automotive, and more, as security regulations increase across all industries. If you want to learn more about the practical applications of fuzzing in industry, check out these articles:

- [Making fuzzing smarter](https://cybersecurity.springeropen.com/articles/10.1186/s42400-018-0002-y): This paper discusses fuzzing and how it can be made more efficient, smarter, and more state-of-the-art.
- [Ethereum Network Vulnerability](https://autobahn.security/post/fuzzing-blockchain-2): how advanced fuzz testing discovered a serious DOS vulnerability in the Ethereum network.
- [Different types of fuzzing](https://patricegodefroid.github.io/public_psfiles/Fuzzing-101-CACM2020.pdf): This article discussed a few different types of fuzzing - blackbox, whitebox, and grammar-based - and the effectiveness of each.
- In general...[a list of bugs you can find by fuzzing](https://www.code-intelligence.com/blog/what-bugs-can-you-find-with-fuzzing)
