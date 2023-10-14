# COS-214-Project

## Summary
A restaurant simulation application that makes use of various design patterns.
implemented in C++

## Contributing
Please have a look at <a href="https://github.com/waveyboym/COS-214-Project/blob/main/CONTRIBUTING.md">CONTRIBUTING.md</a> for more details on contributing to this repo

## Building
### Building with visual studio code
1. Download and install C++ build tools by following this <a href="https://github.com/bycloudai/InstallVSBuildToolsWindows">tutorial</a>
2. Download and install <a href="">boost</a> fr your operating system.
3. Download and install <a href="https://cmake.org/download/#latest">cmake</a>
4. Clone this repo
5. Download and install <a href="https://code.visualstudio.com/">visual studio code</a>
6. Download and install <a href="https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools">cmake tools</a> from the visual studio marketplace
7. run 
```
cd "COS-214-Project"
```
8. Add the folder "Source Files" to a new work space in visual studio or open with code from your file manager. ![openwithcode](images/openwithcode.png "openwithcode")
9. Wait for VS code to initialize and set itself up(it may add some files under the build folder)
10. At the bottom of Visual Studio code, you should see a play button, click it and the project should build and run. ![build](images/build.png "build")
11. For a more detailed tutorial on cmake, follow this <a href="https://cmake.org/cmake/help/latest/guide/tutorial/index.html">link</a>
12. Alternative tutorials: 
    * https://code.visualstudio.com/docs/cpp/cmake-linux
    * https://www.youtube.com/watch?v=sc6_86jgQls&ab_channel=TechHara
    

### Building from the command line with windows OS
1. Download and install <a href="https://cmake.org/download/#latest">cmake</a>
2. Follow <a href="">this guide</a> to download and install boost
3. Clone this repo
4. Go to the <a href="https://github.com/waveyboym/COS-214-Project/tree/main/Source%20Files">Source Files</a> directory of this repo on your local machine and open a new terminal there
5. Run 
```
cmake -S . -B build
```
6. Run 
```
cmake --build build
```
7. Run 
```
cd build && ctest
```
8. If any build files are generated on your local machine, please do not commit them; add those files to the <a href="https://github.com/waveyboym/COS-214-Project/blob/main/Source%20Files/.gitignore">gitignore</a> file in the <a href="https://github.com/waveyboym/COS-214-Project/tree/main/Source%20Files">Source Files</a> directory.
9. For a more detailed tutorial on cmake, follow this <a href="https://cmake.org/cmake/help/latest/guide/tutorial/index.html">link</a>

### Building from the command line with a Linux based OS(Debian, Ubuntu and Fedora)
1. Open a new terminal
2. Run 
```
sudo apt-get install libgtest-dev
```
3. Run 
```
sudo apt-get install cmake
```
4. Follow <a href="">this guide</a> to download and install boost
5. Clone this repo
6. Go to the <a href="https://github.com/waveyboym/COS-214-Project/tree/main/Source%20Files">Source Files</a> directory of this repo on your local machine and open a new terminal there
7. Run 
```
cmake -S . -B build
```
8. Run 
```
cmake --build build
```
9. Run 
```
cd build && ctest
``` 
10. If any build files are generated on your local machine, please do not commit them; add those files to the <a href="https://github.com/waveyboym/COS-214-Project/blob/main/Source%20Files/.gitignore">gitignore</a> file in the <a href="https://github.com/waveyboym/COS-214-Project/tree/main/Source%20Files">Source Files</a> directory.
11. For a more detailed tutorial on cmake, follow this <a href="https://cmake.org/cmake/help/latest/guide/tutorial/index.html">link</a>

### Building from the command line with a MacOS
//if you have a mac, please fill this out

## Developing with makefiles(Exclusive to a Linux based OS(Debian, Ubuntu and Fedora))
sub-directories to cpp files work like so:
1. if same directory as makefile, then ```<name of cpp file>.o```
2. if 1 directory below makefile, then ```<name of folder>/<name of cpp file>.o```
3. if 2 directories below makefile, then ```<name of folder>/<name of folder>/<name of cpp file>.o```
4. if 3 directories or more below makefile, the same principle as before follows

NB: If you make a directory that goes really deep, please make sure that it will be compiled by:
```
%.o: %.cpp
	$(CXX) -c -g $< -o $@
``` 
 So if it goes 4 directories deep, you would add:
```
%/%/%/%.o: %.cpp
	$(CXX) -c -g $< -o $@
```

***Extra note, if the OBJECTS is getting too long and you want to breakline, add ``` \``` then continue typing the list of objects on the next line*** 

***Extra note no file that should be compiled by this makefile should be at a directory above this makefile, that is, this makefile should be at the very top of the tree.
This is for maintaining simplicity and making it easy to navigate the project***

## Contributors

Thanks to these wonderful people for their contributions.

| Profile      | Username | Personal Website | Role | Bio |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| <img src="https://avatars.githubusercontent.com/u/93211335?v=4" alt="profile" width="140" height="100"/> | Michael | <a href="https://waveyboym.github.io/">waveyboym</a> | Software developer, Software architect, UI/UX designer | interested in computer science and creating fun CS related projects |
| <img src="https://avatars.githubusercontent.com/u/96811395?v=4" alt="profile" width="140" height="100"/> | Carey | <a href="https://github.com/u21631532">cmokou</a> | Software developer, UI/UX designer | - |
| <img src="https://avatars.githubusercontent.com/u/86027693?v=4" alt="profile" width="140" height="100"/> | Lunga | <a href="https://github.com/Remiku-bit">Remiku-bit</a> | Tech lead, Business analyst | - |
| <img src="https://avatars.githubusercontent.com/u/130374095?v=4" alt="profile" width="140" height="100"/> | Jaden | <a href="https://github.com/u22528492">Jaden Moodley</a> | Software developer | - |
| <img src="https://avatars.githubusercontent.com/u/130366358?v=4" alt="profile" width="140" height="100"/> | Jaide | <a href="https://github.com/JMPastoll">JMPastoll</a> | Project manager, Business analyst  | - |
| <img src="https://avatars.githubusercontent.com/u/133004091?v=4" alt="profile" width="140" height="100"/> | Linda | <a href="https://github.com/LOK3LANI">LOK3LANI</a> | Software developer | - |
| <img src="https://avatars.githubusercontent.com/u/43268664?v=4" alt="profile" width="140" height="100"/> | Nicholas | <a href="https://github.com/NicholasJHarvey">NicholasJHarvey</a> | Software developer | - |
