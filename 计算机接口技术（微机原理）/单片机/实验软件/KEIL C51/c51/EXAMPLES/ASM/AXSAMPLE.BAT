REM This Batch-File generates a Sample-Program for the AX51-Assembler
ax51  asample1.a51 debug xref
ax51  asample2.a51 debug xref
ax51  asample3.a51 debug xref
lx51  asample1.obj,asample2.obj,asample3.obj to asample segments (var1) ixref
ohx51 asample
