Here's how you compile this on your machine, assuming you have QT installed:

- qmake fade.pro
  - for me, it's really "/usr/local/Cellar/qt/5.12.1/bin/qmake"
  - this generates a Makefile
- make
  - this runs the Makefile and compiles the program
- At this point you'll have a platform-specific program ready to run.
  - For example, on my Mac, it makes a fade.app program that I can double-click on and open.