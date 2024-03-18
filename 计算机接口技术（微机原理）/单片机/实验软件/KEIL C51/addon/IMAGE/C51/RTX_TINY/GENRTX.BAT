REM This file generates the RTX51 TINY LIBRARY
a51 right.a51
a51 vers.a51
a51 rtx51tny.a51 debug
a51 conf_tny.a51
del rtx51tny.lib
lib51 create rtx51tny.lib
lib51 add right.obj,vers.obj,rtx51tny.obj,conf_tny.obj to rtx51tny.lib
