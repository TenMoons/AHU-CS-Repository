/* =====================================================================
   David Aha
   August 1988
   Creates waveform domain data
   Usage: create-waveform number num-attributes
   See CART book, page 49 for details

   Requires use of the UNIXSTAT tool named "probdist".
   ===================================================================== */
#include <stdio.h>
#include <math.h>

#define NUMBER_OF_ARGS 3
#define NUMBER_OF_ATTRIBUTES 40
#define NUMBER_OF_CLASSES 3

/*==== Inputs ==== */
int num_instances;
unsigned seed;

/*==== Main array of info ====*/
float h[NUMBER_OF_CLASSES][NUMBER_OF_ATTRIBUTES];

/* =====================================================================
   Main Function
   ===================================================================== */
main(argc,argv)
   int argc;
   char *argv[];
{
   void execute();
   void initialize();

   if (argc != NUMBER_OF_ARGS) 
     { printf("Usage: num-instances seed\n");
       return(0);
     }

   num_instances = atoi(argv[1]);
   seed = atoi(argv[2]);
   initialize();
   execute();
}

/* =====================================================================
   Initializes the algorithm.
   ===================================================================== */
void initialize()
{
   void increment_seed();
  
   int i,j;
   char command[100];

   srandom(seed);

   /*==== Setup for waveform of types 1 through 3 ====*/
   for(i=0; i<3; i++)
      for(j=0; j<40; j++)
	h[i][j] = 0.0;

   /*==== Waveform 1 ====*/
   for(i=1; i<=6; i++)
     h[0][i] = (float)i;
   j=1;
   for(i=11; i>=7; i--)
     { h[0][i] = (float)j;
       j++;
     }

   /*==== Waveform 2 ====*/
   j = 1;
   for(i=9; i<=14; i++)
     { h[1][i] = (float)j;
       j++;
     }
   j=1;
   for(i=19; i>=15; i--)
     { h[1][i] = (float)j;
       j++;
     }

   /*==== Waveform 3 ====*/
   j = 1;
   for(i=5; i<=10; i++)
     { h[2][i] = (float)j;
       j++;
     }
   j=1;
   for(i=15; i>=11; i--)
     { h[2][i] = (float)j;
       j++;
     }

   /*==== Create the required random values ====*/
   system("/bin/rm -f temp");
   sprintf(command,"probdist -s %d ran z %d > temp\n",
	           seed,num_instances*NUMBER_OF_ATTRIBUTES);
   system(command);
   increment_seed();

}
   
/* =====================================================================
   Executes the algorithm.
   ===================================================================== */
void execute()
{
   void increment_seed();

   int num_instance, num_attribute;
   int waveform_type, choice[2];
   FILE *fopen(), *fp;
   float random_attribute_value, multiplier[2];
   char line[100];
   float val[40];

   fp = fopen("temp","r");
   for(num_instance=0; num_instance<num_instances; num_instance++)
     {  /*==== Set up class type ====*/
	waveform_type = (random() % 3);
	switch (waveform_type)
	  { case 0: choice[0] = 0; choice[1] = 1; break;
	    case 1: choice[0] = 0; choice[1] = 2; break;
	    case 2: choice[0] = 1; choice[1] = 2; break;
	  }

	/*==== Set up u and (1-u) for this call ====*/
	multiplier[0] = (float)(random() % 1001)/1000.0;
	multiplier[1] = 1.0 - multiplier[0];

	/*==== Create the instance ====*/
	for(num_attribute=0; num_attribute<NUMBER_OF_ATTRIBUTES;
			     num_attribute++)
	  { /*==== Get the base random attribute value ====*/
	    fgets(line,100,fp);
	    sscanf(line,"%f",&random_attribute_value);

	    /*==== Calculate the value ====*/
	    val[num_attribute] =
	      (multiplier[0] * h[choice[0]][num_attribute]) +
	      (multiplier[1] * h[choice[1]][num_attribute]) +
	      random_attribute_value;
	  }

	/*==== Print the instance to the current output ====*/
        printf("%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%4.2f,%d\n",
	        val[0], val[1], val[2], val[3], val[4],
		val[5], val[6], val[7], val[8], val[9],
		val[10], val[11], val[12], val[13], val[14],
		val[15], val[16], val[17], val[18], val[19], val[20],
	        val[21], val[22], val[23], val[24],
		val[25], val[26], val[27], val[28], val[29],
		val[30], val[31], val[32], val[33], val[34],
		val[35], val[36], val[37], val[38], val[39], waveform_type);
      }
   fclose(fp);
   system("/bin/rm -f temp");
}

/* =====================================================================
   Increments seed
   ===================================================================== */
void increment_seed()
{
   seed += 62010;
}
