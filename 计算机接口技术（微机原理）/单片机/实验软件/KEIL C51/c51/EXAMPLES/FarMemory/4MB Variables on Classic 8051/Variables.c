/*
 * in a single C source file it is not possible to define more than
 * 64KB far or far const variables.  Therefore we have split the
 * definition into a 2nd file.  
 *
 * Also the linker cannot split far variables of one module into different
 * banks.  Therefore you need to split variables into different modules, 
 * when the far variables of one module exceed the limits of your code/data
 * banks.
 */ 

       unsigned char far large_array1[0x8000];
const  unsigned char far large_carray1[0x8000] = { 1, 2, 3, 4, 5 };

