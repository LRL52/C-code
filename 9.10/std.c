#include <stdio.h>
int main(void){
    float amount,rate,payment,month_rate,tmp1,tmp2,tmp3;
     
    printf("Enter amount of lean:");
    scanf("%f",&amount);
     
    printf("Enter interest rate:");
    scanf("%f",&rate);
     
    printf("Enter monthly payment:");
    scanf("%f",&payment);
     
    month_rate = rate / 100.0f / 12.0f;
    tmp1 = (amount-payment)+amount*month_rate;
    tmp2 = (tmp1-payment)+tmp1*month_rate;
    tmp3 = (tmp2-payment)+tmp2*month_rate;
     
    printf("Balance remaining after first payment:%.2f\n",tmp1);
    printf("Balance remaining after second payment:%.2f\n",tmp2);
    printf("Balance remaining after third payment:%.2f\n",tmp3);
 
}
