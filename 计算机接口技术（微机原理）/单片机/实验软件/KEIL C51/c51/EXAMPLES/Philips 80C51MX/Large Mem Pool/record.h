#define RecNo    19000    // 19000 records
#define RecSize  20       //  with 20 bytes each


#if defined (__C51__) || defined (__CX51__)

struct record  {
  struct record far *next;
  unsigned char        c0; 
  float                 f;
  unsigned int       i[6];
};	                // size of one record is 20 bytes
 
typedef struct record RECORD;

extern RECORD far *pRecord (unsigned int n);

#endif
