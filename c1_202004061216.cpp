/* 
1.Ŀ�ģ�ʹ����С���˷������ݵ�����������
2.���ߣ������
  ���ڣ�2023��3��8��
  ѧ�ţ�202004061216
3.���룺��������
  �������Ϻ������ʽ
        ���������
*/ 


#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include <math.h>


int main()  {
	float x[4] = {2.1, 4.0, 7.5, 9.4} ;
	float y[4] = {7.3, 11.3, 17.2, 21.7};//����y=2x+3����һ������
	float y_test[4];
	float average_x, average_y, sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
	float k, b;//kΪ��Ϻ����Ľؾ࣬bΪ��Ϻ�����б�ʣ�
	float error, error_sum = 0.0;
	int i;
	
	
    for(i = 0; i < 4; i++) {         
	    sum_x = sum_x + x[i];//��x�ĺ�  
		sum_y = sum_y + y[i];//��y�ĺ� 
		sum_xy = sum_xy + x[i] * y[i];//��x*y�ĺ� 
		sum_x2 = sum_x2 + x[i] * x[i];//��x^2�ĺ�
	}
    average_x = sum_x / 4;//��x�ľ�ֵ 
    average_y = sum_y / 4;//��y�ľ�ֵ 
    k = (sum_xy - 4 * average_x * average_y) / (sum_x2 - 4 * average_x * average_x);//��С���˷�����Ϻ���б�� 
    b = average_y - k * average_x;//����Ϊ��Ϻ����ؾ�
    printf("��Ϻ���Ϊ��y = %fx + %f\n", k, b);
    
    //������������� 
	for(i = 0; i < 4; i++) {	
		y_test[i] = k * x[i] + b;
		error = fabs(y_test[i] - y[i]);//�����Ϻ�����ʵ�ʺ�������ֵ����� 
		error_sum = error_sum + error * error;//���������ƽ���� 
	    }
	printf("���������Ϊ��%f", sqrt(error_sum / 4));//���������������� 
    return 0;
}    
