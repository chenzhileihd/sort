//
//  main.c
//  guibing
//
//  Created by 陈志磊 on 2018/10/29.
//  Copyright © 2018年 陈志磊. All rights reserved.
//

#include <stdio.h>
void merge(int *num,int h,int k)
{
    int tmp = (h+k)/2;
    int tmp_num[10] = {0};
    int tmp_t = 0;
    int tmp_i = 0;
    int tmp_j = 0;
    int tmp_k = 0;
    tmp_j=tmp+1;//2
    tmp_i=h;//1,tmp 1
 while((tmp_i<=tmp)&&(tmp_j<=k))
 {
            if(num[tmp_i]<num[tmp_j])
            {
                tmp_num[tmp_t]=num[tmp_i];
                tmp_i++;
            }
            else{
                tmp_num[tmp_t]=num[tmp_j];
                tmp_j++;
            }
            tmp_t++;
 }
    if(tmp_i < tmp+1)
    {
        for(tmp_k=tmp_i;tmp_k<tmp+1;tmp_k++)
        {
            tmp_num[tmp_t]=num[tmp_k];
            tmp_t++;
        }
    }
    //j l
    if(tmp_j < k)
    {
        for(tmp_k=tmp_j;tmp_k<k;tmp_k++)
        {
            tmp_num[tmp_t]=num[tmp_k];
            tmp_t++;
        }
    }
    for(tmp_k=0;tmp_k<tmp_t;tmp_k++)
    {
        printf("tmp_num[%d] = %d\n",h+tmp_k,tmp_num[tmp_k]);
    }
    printf("tmp_t = %d\n",tmp_t);
    printf("k = %d\n",k);
    printf("h = %d\n",h);

    for(tmp_k=0;tmp_k<tmp_t;tmp_k++)
    {
        *(num+h+tmp_k)=tmp_num[tmp_k];
    }
    printf("\n");
}
void guibing(int *test,int p,int r)
{
    int q = 0;
    if(p>=r)
    {
        return ;
    }
    q=(p+r)/2;
    guibing(test,p,q);
    guibing(test,q+1,r);
    merge(test,p,r);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int iRet = 0;
    int test[8] = {6,5,4,4,8,3,7,1};
    for(iRet =0;iRet<8;iRet++)
    {
        printf("test_start[%d] = %d\n",iRet,test[iRet]);
    }
    printf("\n");
    guibing(test, 0, 7);
    //merge(test,1,2);
    for(iRet =0;iRet<8;iRet++)
    {
        printf("test[%d] = %d\n",iRet,test[iRet]);
    }
    return 0;
}
