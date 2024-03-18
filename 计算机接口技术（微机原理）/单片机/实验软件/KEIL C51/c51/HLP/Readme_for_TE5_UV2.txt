Using the Triscend Debug Monitor DLL for Keil uVision2
======================================================

The te5_uv2.dll library allows the uVision2 debugger to communicate with
the Triscend E5 CSoC for debugging.  This README file details the steps
involved in setting the DLL up and starting a debug session in uVision2.

This document assumes that the user has already installed Triscend
FastChip 1999 or Triscend FastChip 2.0.  For updates to this DLL and 
to other software from Triscend, please visit: 
http://www.triscend.com/products/IndexFCupdate.html

=====================
Important Usage Note
=====================
This DLL is designed for use with Keil uVision 2.05 or later.  If using an 
older version of uVision, please go to Keil's website, http://www.keil.com/, 
to download the latest update.

USAGE
-----
In order to use this DLL, copy te5_uv2.dll into the Keil directory (by
default, uVision2 places itself under C:\Program Files\Keil), under the
C51\BIN.  Once the file has been moved, edit the TOOLS.INI file, under 
root Keil directory and add the following line, modifying the path as needed:

TDRV1=C:\Program Files\Keil\C51\BIN\te5_uv2.dll ("Triscend E5 Driver")

Note: If TDRV1 is already used, change the number to the next available
number.

Once the TOOLS.INI file has been modified and saved, launch uVision2.
Under the menu bar select "Options"|"Options for Target 'Target 1'".  In
the dialogue window that appears, select the "Debug" tab.  There will be
two side-by-side radio buttons along the top of this page; one labelled
"Use Simulator", the other labeled "Use: " followed by a drop down list.
Select this second radio button and in the drop down list, select "Triscend
E5 Driver" (Note: this is what the TDRV1 was named in the TOOLS.INI file).
Other optional debug options are "Load Application at Startup" which will
load the project code into the target when the debug session is started and
"Go till main()" which brings your target to the beginning of the code for
your the function when the debug session is started.

Before starting a debug session in uVision2, there are two tasks to do
outside of uVision2.  One is to use FastChip 1999 or FastChip 2.0 to
download the project to the target.  This is especially important when
debugging a program that will be running from flash.  The primary reason
for doing this, though, is to insure that the mapppers on the E5 are set up
correctly.  If the code and data mappers are not set correctly, the target
may not behave in the proper manner while debugging.

The other item that must be accomplished before starting a debug session is
to insure that the Spider daemon is running.  The Spider daemon is the
application that controls all communication with the E5.  FastChip, the
csoc commands, and Keil all talk to the E5 through Spider.  FastChip 1999
and the FastChip 2.0 Device Link automatically launch the Spider Daemon.
If you used FastChip 1999 or FastChip 2.0 Device Link to download to the E5
or to debug the E5, the Spider daemon should already be running.  If not,
then it is possible to launch the daemon manually.  To do so, use the
command line and type "spiderd -d 5000".  You may have to go to the
FastChip directory to do this if the path is not setup correctly.
Alternatively, instead of using the command line to launch the spider
daemon, use the Run... option under the Windows Start menu to launch it.

Once the project has been downloaded into the target and the Spider daemon
is running, a debug session in uVision2 can be started by clicking
"Debug"|"Start/Stop Debug Session".  The DLL will be loaded and will
connect to the spider daemon and read back the memory.  You'll see the
Disassembly window which shows the mixed C/assembly code for your project.
Under View, you can open the memory window which lets you look at different
areas of memory using prefixes for the different memory regions, like code
(C:0x0000-0xffff), data(D:0x00-0x80), idata(I:0x80-0xff), and
xdata(X:0x0000-0xffff).  There's a watch window where you can set up watch
values, which you can set up either in the window directly, or by typing
"ws " followed by the variable name in the command window at the bottom
left.  There are button for starting, stopping, stepping, and reseting the
target, with more options under the Debug menu option.  You can set up code
breakpoints, by double clicking on instructions in the disassembly window,
by right clicking in the C source window, or by choosing the
"Breakpoints..." option under the Debug menu option.  This last one allows
for the creation of more elaborate types of breakpoints, for which the
uVision2 manual has more information.


