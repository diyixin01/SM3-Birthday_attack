#include "../1_SM3_implementation/mysm3.h"
#include "../1_SM3_implementation/mysm3.cpp"
#include<time.h>
#include <unistd.h>
#include<stdlib.h>
#include<math.h>
#include<string>
typedef unsigned int uint;

int Pollard_Rho(uint image,unsigned char* H,uint c,uint* preiamge);
void  PreimageAttack(uint image);