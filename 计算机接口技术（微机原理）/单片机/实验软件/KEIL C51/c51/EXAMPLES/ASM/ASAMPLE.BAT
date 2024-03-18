REM This Batch-File generates a Sample-Program for the A51-Assembler
a51  asample1.a51 debug xref
a51  asample2.a51 debug xref
a51  asample3.a51 debug xref
bl51 asample1.obj,asample2.obj,asample3.obj to asample precede (var1) ixref
oh51 asample
