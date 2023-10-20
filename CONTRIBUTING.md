# Table of Contents

- [Table of Contents](#table-of-contents)
- [How to contribute to this project](#how-to-contribute-to-this-project)
- [Important note](#important-note)
- [Visual representation of how it works](#visual-representation-of-how-it-works)
  - [How it works](#how-it-works)
  - [Flow chart](#flow-chart)
- [Developing](#developing)
  - [Automatic](#automatic)
  - [Manually](#manually)
  - [Developing with makefiles(Exclusive to a Linux based OS(Debian, Ubuntu and Fedora))](#developing-with-makefilesexclusive-to-a-linux-based-osdebian-ubuntu-and-fedora)

# How to contribute to this project

1. If you have not already, create a new branch in this repository(You can name it whatever you like).
2. Clone your branch onto your local machine where you will do development and testing.
3. As you make changes to your clone, you can push and pull to your branch that you created.
4. When you are satisfied that the feature you wanted to add works, all of the code compiles and all of the various tests have passed, create a pull request and you may ask other members to review your pull request and maybe test your new feature on their local machine's then merge your branch to the develop branch, or you may just go right ahead and merge to the develop branch.
5. If you want to add a new feature again, just sync your current branch that you created with the develop branch, make a git pull onto your local machine for your branch and repeat from step 3.
6. Don't forget to add yourself as a contributor to the README.md file in the contributors table. To do that, edit that file and scroll to the bottom, and just below the most recently added contributor, add this and replace the appropriate fields: 
```
| <img src="<link of your avatar, pfp, profile you want to display goes here>" alt="profile" width="140" height="100"/> | <your username goes here> | <a href="<your website link goes here>"><your website name goes here></a> | <your role in this project goes here> | <your bio goes here> |
```
7. Please find the key roles on <a href="https://www.hexacta.com/infographic-software-development-project-roles-and-responsibilities/">this page</a> and <a href="https://alcor-bpo.com/recruitment-news/10-key-roles-in-a-software-development-team-who-is-responsible-for-what/">this page</a> when you want to add your roles in the README.md file. Note that your roles may overlap with other peoples roles.
8. NB: Merging to main should only happen when we are confident in the stability of our code.

# Important note
Do not ever touch the documentation branch. Do not make any pull requests or any merges from that branch as it is automatically maintained.

# Visual representation of how it works

## How it works
![contributing](images/contributing.png "contributing")

## Flow chart
![contributing-flow-diagram](Diagrams/Coding%20guidelines/contributing%20flow%20diagram.png "contributing-flow-diagram")


# Developing

## Automatic
1. Open a new terminal
2. Run
```
cd COS-214-PROJECT/scripts
```
3. Run either the debug or release bash scripts depending on your requirements and watch the magic happen ✨
4. 
```
./build-and-run-debug.sh
```
5. 
```
./build-and-run-release.sh
```
6. If you are in debug, skip the next steps from here
7. Then open another terminal and from the root of this project run
```
cd COS-214-PROJECT/src/frontend
```
8.  Run
```
npm install
```
9.  Run
```
npm run dev
```

## Manually
1. Open a new terminal
2. Run
```
cd COS-214-PROJECT/src
```
3. For Release(no unit tests, with gui), run
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
```
4. For Debug(google unit tests, with no gui), run
```
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
```
5. Run 
```
cmake --build build
```
6. For Release(no unit tests, with gui), run
```
cd build && ./main
```
7. For Debug(google unit tests, with no gui), run
```
cd build && ctest
```
8. If you are in debug, skip the next steps from here
9. Then open another terminal and from the root of this project run
```
cd COS-214-PROJECT/src/frontend
```
10.  Run
```
npm install
```
11.  Run
```
npm run dev
```

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

***Extra note no file that should be compiled by the <a href="https://github.com/waveyboym/COS-214-Project/blob/main/makefiles/makefile">makefile</a> should be at a directory above this makefile, that is, this makefile should be at the very top of the tree.
This is for maintaining simplicity and making it easy to navigate the project***