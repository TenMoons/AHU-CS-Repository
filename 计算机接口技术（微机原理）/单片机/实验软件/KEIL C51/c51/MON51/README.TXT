MONITOR-51 Version 2.9 Release Note:
====================================
Since version 2.8 the MONITOR 51 can be installed on DALLAS 80C320/520/530 
target systems.  Previous versions were not able to handle multiple DPTR
register and crashed when a different DPTR was selected.
Please use serial type 4, 5, 11 or 12 during installation when a DALLAS 
microcontroller should be used.

Since version 2.9 the MONITOR 51 can execute some code before and after 
a go and procedure step command.  This might be used for changing the memory
layout or changing the serial transmission parameters.  
In order to do this, you can insert some code after the BEFORE_GO and AFTER_GO
labels in the INSTALL.A51 configuration file.

