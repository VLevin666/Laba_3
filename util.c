#include "util.h"
#include <string.h>
int stringCompare(char *l, char *r){
while(*(l++) == *(r++)){if(*l=='\0' || *r=='\0') break;}
return *l - *r;
}
