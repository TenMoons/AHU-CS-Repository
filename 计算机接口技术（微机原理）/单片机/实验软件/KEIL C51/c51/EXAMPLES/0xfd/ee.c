// 本演示程序用来演示带有0xfd为第二内码的汉字字符串的编译结果
// 如果正确使用了补丁，编译结果的a51或hex文件中均可以看到fd码
// 目标代码长度应该是code=313是正确的
//#pragma src(cca.a51)		 // 用于生成汇编代码查看编译结果
#include <reg51.h>
#include <string.h>
char cc[]="饼昌除待谍洱俘庚过糊积箭烬君魁例笼慢谬凝琵讫驱\
三升数她听妄锡淆旋妖引育札正铸佚";
void main(void) {
unsigned char c1,i;
unsigned int b1;
	c1=strlen(cc);
	for(i=0;i<c1;i++){
		b1+=cc[i];
	}
	while(1);
}

