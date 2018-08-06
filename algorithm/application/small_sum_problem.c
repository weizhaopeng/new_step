#include "../sort/sort_algor.h"

/*desc:在随机数组中找出左边的小于右边的所有元素之和
 *exam:2 3 4 5 1
 *result：2+(2+3)+(2+3+4)+0 = 16
 */

/*算法：使用归并排序在排序过程中，假定左右两边都升序排好，此时如果
 *i_left < i_right那个右边所有的其他数都大于i_left，层层进行计算
 */

int main(int argc, char **argv) {
	
