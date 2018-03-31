# Lab 1

In this lab we will go over the basics of using ROOT as a command line interface for doing simple calculations as well as in C/C++ macros and in python.

### ROOT Command Line basics

After ROOT has been installed properly on your system it is simple to run an interactive session by running:

    root

To open root a bit faster, without waiting for the logo.

    root -l

Your prompt should now look like:

    root [0]

Here you can do simple calculations, and even create functions in c/c++ style as if you were writing a regular program:

    root [0] 4+4
    (int) 8
    root [1] 4.0+4
    (double) 8.000000
    root [2] double area_circle(double r){ return TMath::Pi() \* r \* r; }
    root [3] area_circle(5.0)
    (double) 78.539816

ROOT can even open a graphical browser to view data and graphs stored in root files:

    root [0] TBrowser a

To exit the root interpreter just enter:

    root [0] .q

### ROOT as C/C++ macros

Although all you code can be typed into the ROOT interpreter, it is more common the make '.C' macros to store your code. These can be run in ROOT by calling the script from the command line:

    root -l Gausian.C

Or from an already opened interpreter session (.x means execute the script):

    root [0] .x Gausian.C

Look at the example script which creates a histogram, fills it with a randomly generated gaussian, and then fits the gaussian.
