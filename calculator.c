#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>

//Структура хранящаяя в себе значение и приоритет
struct znach{ 
    unsigned char zn;
    char chislo[3];
};

void find_obmen(unsigned char kh[3],unsigned char ks[3]){
    for (int i=0;i<3;i++){
        kh[i]=ks[i];
    }
    //Функция для присвоения одной переменной, значение другой
}

char* find_sum(char kh[3], char ks[3]) {
    char* ksum =(char*) malloc(sizeof(char)*3);
    //Выделение памяти для указателя
    char per = 0;
    for (int i = 0; i < 3; i++) {
        ksum[i] = kh[i] + ks[i] + per;
        per = (128<=(((kh[i])>>1)+((ks[i])>>1)+(((kh[i]&0b1) + (ks[i]&0b1) + per)>>1)));
    }
    //Поиск суммы, через переполнения
    return ksum;
    //Вывод результата в виде указателя ksum
}

char* find_inv(unsigned char kh[3]){
    char* inv= (char*) malloc(sizeof(char)*3);
    //Выделение памяти для указателя
    unsigned char ed[3];
    ed[0] = 1;
    ed[1] = 0;
    ed[2] = 0;

    for (int i=0;i<3;i++){
        kh[i]=~kh[i];
    }
    inv=find_sum(kh,ed);
    //Нахождение инверсированного числа(~,+1)
    return inv;
    //Вывод результата в виде указателя inv
}

char* find_umn(unsigned char kh[3],unsigned char ks[3]){
    char* umn= (char*) malloc(sizeof(char)*3);
    //Выделение памяти для указателя
    char per = 0;
    unsigned char x24,x20,x16,x12,x8,x4;
    unsigned char y24,y20,y16,y12,y8,y4;

    x24=ks[2]>>4;
    x16=ks[1]>>4;
    x8=ks[0]>>4;
    x20=(ks[2]<<4);
    x20=x20>>4;
    x12=(ks[1]<<4);
    x12=x12>>4;
    x4=(ks[0]<<4);
    x4=x4>>4;

    y24=kh[2]>>4;
    y16=kh[1]>>4;
    y8=kh[0]>>4;
    y20=(kh[2]<<4);
    y20=y20>>4;
    y12=(kh[1]<<4);
    y12=y12>>4;
    y4=(kh[0]<<4);
    y4=y4>>4;

    //Записывем числа так, для упращения записи формулы

    umn[0]=((((((((x24*y16)<<8) + (((x24*y12) + (x20*y16))<<4) + (x20*y12)) <<8) + 
    ((((x24*y8)<<8) + (((x24*y4) + (x20*y8))<<4) + (x20*y4)))) + 
    (((((x16*y24)<<8) + (((x16*y20) + (x12*y24))<<4) + (x12*y20)) <<8) + 
    ((((x8*y24)<<8) + (((x8*y20) + (x4*y24))<<4) + (x4*y20))))) <<16) +
    ((((((x16*y8)<<8) + (((x16*y4)+(x12*y8))<<4) + (x12*y4))+
    (((x8*y16)<<8) + (((x8*y12)+(x4*y16))<<4) + (x4*y12)))) <<8) +
    (((x8*y8)<<8) + (((x8*y4)+ (x4*y8))<<4) + (x4*y4)));

    umn[1]=((((((((x24*y16)<<8) + (((x24*y12) + (x20*y16))<<4) + (x20*y12)) <<8) + 
    ((((x24*y8)<<8) + (((x24*y4) + (x20*y8))<<4) + (x20*y4)))) + 
    (((((x16*y24)<<8) + (((x16*y20) + (x12*y24))<<4) + (x12*y20)) <<8) + 
    ((((x8*y24)<<8) + (((x8*y20) + (x4*y24))<<4) + (x4*y20))))) <<16) +
    ((((((x16*y8)<<8) + (((x16*y4)+(x12*y8))<<4) + (x12*y4))+
    (((x8*y16)<<8) + (((x8*y12)+(x4*y16))<<4) + (x4*y12)))) <<8) +
    (((x8*y8)<<8) + (((x8*y4)+ (x4*y8))<<4) + (x4*y4)))>>8;

    umn[2]=((((((((x24*y16)<<8) + (((x24*y12) + (x20*y16))<<4) + (x20*y12)) <<8) + 
    ((((x24*y8)<<8) + (((x24*y4) + (x20*y8))<<4) + (x20*y4)))) + 
    (((((x16*y24)<<8) + (((x16*y20) + (x12*y24))<<4) + (x12*y20)) <<8) + 
    ((((x8*y24)<<8) + (((x8*y20) + (x4*y24))<<4) + (x4*y20))))) <<16) +
    ((((((x16*y8)<<8) + (((x16*y4)+(x12*y8))<<4) + (x12*y4))+
    (((x8*y16)<<8) + (((x8*y12)+(x4*y16))<<4) + (x4*y12)))) <<8) +
    (((x8*y8)<<8) + (((x8*y4)+ (x4*y8))<<4) + (x4*y4)))>>16;

    //Нахождение умножения с помощью алгоритма Карацубы

    return umn;
    //Вывод результата в виде указателя umn
}

char* find_del(unsigned char kh[3],unsigned char ks[3]){
    unsigned char q[3],ed[3],i=0;
    char* k= (char*) malloc(sizeof(char)*3);
    char* del= (char*) malloc(sizeof(char)*3);
    //Выделение памяти для указателей

    ed[0]=1;
    ed[1]=0;
    ed[2]=0;

    q[0]=0;
    q[1]=0;
    q[2]=0;
    //Создание ed и q для сечтика

    while (ks[2] > kh[2] || (ks[2] == kh[2] && ks[1] > kh[1]) || (ks[2] == kh[2] && ks[1] == kh[1] && ks[0] >= kh[0])){
        unsigned char borrow = 0;
            
        for(i=0;i<3;i++){
            unsigned char diff;
            diff= ks[i] - borrow - kh[i];
            if(diff>ks[i]){
                borrow=1;
            }
            else{
                borrow=0;
            }
            ks[i]=diff;
        }
        k=find_sum(q,ed);
        for(int i=0;i<3;i++){
            q[i]=k[i];
        }
    }
    //Пока делимое больше делителя, делим

    for(int i=0;i<3;i++){
            del[i]=q[i];
        }
    //Передаем значение сетчика 
    free(k);
    //Очищаем дин память
    return del;
    //Вывод результата в виде указателя del
}

char* find_chis(unsigned char zn1[3],unsigned char zn2[3],unsigned char virazhenie){

    char* ks= (char*) malloc(sizeof(char)*3);
    char* ks1= (char*) malloc(sizeof(char)*3);
    
    switch (virazhenie){
        case '*':
        case '/':
            if((((zn1[2]>>7)==1) ^ ((zn2[2]>>7)==1))){
                unsigned char *mn1, *mn2;
                mn1 = (unsigned char *)malloc(3*sizeof(unsigned char));
                find_obmen(mn1, zn1);
                mn2 = (unsigned char *)malloc(3*sizeof(unsigned char));
                find_obmen(mn2, zn2);

                if((zn1[2]>>7)==1){
                    ks=find_inv(mn1);
                    free(mn1);
                    mn1 = ks;
                }else{
                    ks=find_inv(mn2);
                    free(mn2);
                    mn2 = ks;
                } 
                if(virazhenie=='*'){
                    ks1=find_umn(mn2,mn1);
                    ks = find_inv(ks1);
                }
                else{
                    ks1=find_del(mn2,mn1);
                    ks = find_inv(ks1);
                }

                free(ks1);
                free(mn1);
                free(mn2);
            }
            else{
                if(virazhenie=='*'){
                    ks=find_umn(zn1,zn2);
                }
                else{
                    ks=find_del(zn2,zn1);
                }
            }
            break;

        case '+':
            ks=find_sum(zn1,zn2);
            break;

        case '-':
            ks1=find_inv(zn2);
            ks=find_sum(zn1,ks1);
            free(ks1);
            break;

        default:
            break;
    }
    return ks;
}

void find_zero(unsigned char kh[3]){
    for (int i=0;i<3;i++){
        kh[i]=0;
    }
    //Функция для обнуления переменной
}

void find_ka(unsigned char * ka,unsigned char val){
    
    unsigned char ksd[] = {0,0,0};
    ksd[0] = val;
    
    unsigned char kmn10[] = {10,0,0};

    char * ums_it = find_umn(ka, kmn10);
    char * sl_it = find_sum(ums_it, ksd);

    for(int i = 0; i<3; i++){
        ka[i] = sl_it[i];
    }

    free(ums_it);
    free(sl_it);
    //Функция для получения числа из строки
}

void find_dec(unsigned char kh[3],char c[9]){
    unsigned char i,m,x[3],k[3],a[3],q[3],l[3],g[9],d[9];
    char* p;  
    char *p1=&c[8],*p2=p1;
    c[8]='\0';
    for(i=0;i<8;i++){
        c[i]='0';
    }
    for(int i=0;i<3;i++){
        x[i]=0;
        l[i]=0;
    }
    k[0]=10;
    k[1]=0;
    k[2]=0;

    for (i=0;i<9;i++){
        g[i]=0;
    }

    for(i=0;i<3;i++){
        a[i]=kh[i];
    }

    if((a[2] || a[1] || a[0])){
        while ((a[2] || a[1] || a[0])){
            p2--;
            for (int i = 0; i < 3; i++){
                l[i]=a[i];
            }
            p=find_del(k,a);
            for (int i = 0; i < 3; i++){
                a[i]=p[i];
            }
            
            p=find_umn(k,a);
            for (int i = 0; i < 3; i++){
                q[i]=p[i];
            }

            p=find_inv(q);
            for (int i = 0; i < 3; i++){
                q[i]=p[i];
            }

            p=find_sum(l,q);
            for (int i = 0; i < 3; i++){
                x[i]=p[i];
            }
            *p2=x[0]+48;
        }
    }
    else{
        p2--;
        *p2='0';
    }
    
    i=0;
    m=0;

    for(i=0;i<9;i++){
        d[i]=c[i];
    }

    i=0;

    while (!(d[i]-48) && (i<7)){
        i++;
    }

    if (!(d[i]-48) && (i!=7)){
        g[0]=c[8];
        g[1]='\0';
    }
    else{
        while(i<=7){
            g[m]=c[i];
            m++;
            i++;
        }
    }
    g[m]='\0';
    for(i=0;i<9;i++){
        c[i]=g[i];
    }
    //переводим число в 10ый вид с помощью остатков от дел на 10
    //free(p);
}

void find_obr(unsigned char * virazhenie, unsigned char obrviraz[50], unsigned char zn[2],unsigned char znachenie[3]){
    unsigned char k,i=0;
    char vihstr[400],*p,l[9];

    p=&vihstr[0];

    char* ks1= (char*) malloc(sizeof(char)*3);

    struct znach steck[10]; 

    struct znach steckzn[10];

    for(int j=0;j<10;j++){
        steck[j].zn=0;
        steckzn[j].zn=0;
        steck[j].chislo[0]=0;
        steck[j].chislo[1]=0;
        steck[j].chislo[2]=0;
    }

    for(int d=0;d<400;d++){
        vihstr[d]=0;
    }

    struct znach *p_steck = &steck[0];
    struct znach *p_steck2 = &steck[0];
    //struct znach *p_steck = (struct znach*)calloc(10, sizeof(struct znach));
    
    //стек чисел
    struct znach *p_zn = &steckzn[0];
    //стек знаков
    while (virazhenie[i]!='\0'){
        if (virazhenie[i]>='0' && virazhenie[i]<='9'){
            k=i;
            while (virazhenie[k]>='0' && virazhenie[k]<='9'){
                find_ka(p_steck->chislo,virazhenie[k]-48);;
                *p=virazhenie[k];
                p++;
                k++;
            }
            //
            find_dec(p_steck->chislo,l);
            
            printf("\nChislo:\n %s \n",l);

            *p=' ';
            p++;
            p_steck->zn=0;
            p_steck++;
            i=k;
        //запись числа в стек и в выходную строку
        }

        else{

            switch (virazhenie[i])
            {   
                case '*':
                case '/':
                    printf("\nOper:\n %c \n",virazhenie[i]);
                    if (!(p_zn == &steckzn[0])){
                        while ((p_zn-1)->zn >= 3){
                            p_zn--;
                            
                            p_steck--;
                            if ((p_steck>=&steck[1]) && (p_zn->chislo[0]!=0)){
                                
                                if(p_zn->chislo[0]=='/' && !(((p_steck)->chislo[0]) || ((p_steck)->chislo[1]) || ((p_steck)->chislo[2]))){
                                    printf("Eror:Divide by zero");
                                    exit(0);
                                }
                                else{
                                    ks1=find_chis(((p_steck-1)->chislo),(p_steck->chislo),p_zn->chislo[0]);
                                    find_obmen((p_steck-1)->chislo,ks1);
                                    free(ks1);
                                    find_zero(p_steck->chislo);
                                }
                            }
                            else{
                                p_steck++;
                            }

                            *p=p_zn->chislo[0];
                            p++;
                            *p=' ';
                            p++;
                            p_zn->chislo[0]=0;
                            p_zn->zn=0;
                        }
                    }
                    p_zn->zn=3;
                    p_zn->chislo[0]=(virazhenie[i]=='*')?'*':'/';
                    p_zn++;
                    i++;
                    break;

                case '+':
                case '-':
                    printf("\nOper:\n %c \n",virazhenie[i]);
                    if (!(p_zn == &steckzn[0])){
                        while ((p_zn-1)->zn >= 2)
                        {   p_zn--;

                            p_steck--;
                            if ((p_steck>=&steck[1]) && (p_zn->chislo[0]!=0)){

                                ks1=find_chis(((p_steck-1)->chislo),(p_steck->chislo),p_zn->chislo[0]);
                                find_obmen((p_steck-1)->chislo,ks1);
                                free(ks1);
                                find_zero(p_steck->chislo);
                            }
                            else{
                                p_steck++;
                            }

                            *p=p_zn->chislo[0];
                            p++;
                            *p=' ';
                            p++;
                            p_zn->chislo[0]=0;
                            p_zn->zn=0;
                        }
                    }
                    p_zn->zn=2;
                    p_zn->chislo[0]=(virazhenie[i]=='+')?'+':'-';
                    p_zn++;
                    i++;
                    break;

                case '(':
                    printf("\nOper:\n %c \n",virazhenie[i]);
                    if (p_zn == &steckzn[0]){
                        p_zn->zn=1;
                        p_zn->chislo[0]='(';
                        p_zn++;
                    }
                    p_zn->zn=1;
                    p_zn->chislo[0]='(';
                    p_zn++;
                    i++;
                    break;

                case ')':
                    printf("\nOper:\n %c \n",virazhenie[i]);
                    while ((p_zn-1)->zn != 1)
                    {   p_zn--;

                        p_steck--;
                        if ((p_steck>=&steck[1]) && (p_zn->chislo[0]!=0)){

                            ks1=find_chis(((p_steck-1)->chislo),(p_steck->chislo),p_zn->chislo[0]);
                            find_obmen((p_steck-1)->chislo,ks1);
                            free(ks1);
                            find_zero(p_steck->chislo);
                        }
                        else{
                            p_steck++;
                        }
                        
                        *p=p_zn->chislo[0];
                        p++;
                        *p=' ';
                        p++;
                        p_zn->chislo[0]=0;
                        p_zn->zn=0;
                    }
                    p_zn--;
                    p_zn->zn=0;
                    p_zn->chislo[0]=0;
                    i++;
                    break;
            
                default:
                    break;
            }
        }
            //запись знаков в стек и в вых строку
        

}
    while ((p_zn-1)->zn!=0)
    {
        p_zn--;
        p_steck--;
        if ((p_steck > &steck[0])){
            if(p_zn->chislo[0]=='/' && ((p_steck)->chislo[0])==0 && ((p_steck)->chislo[1])==0 && ((p_steck)->chislo[2])==0){
                printf("Eror:Divide by zero\n");
                exit(0);
            }
            else{
                ks1=find_chis((p_steck-1)->chislo,p_steck->chislo,p_zn->chislo[0]);
                find_obmen((p_steck-1)->chislo,ks1);
                find_zero(p_steck->chislo);
                free(ks1);
            }
        }
        *p=p_zn->chislo[0];
        p++;
        p_zn->chislo[0]=0;
        p_zn->zn=0;
    }

    *p='\0';
    for(i = 0; vihstr[i]!='\0'; i++)
    {
        obrviraz[i]=vihstr[i];
    }
    obrviraz[i]='\0';
    p_steck--;
    //получили обратное выражение

    

    
    if(((p_steck->chislo[2])>>7) == 1 ){
        ks1=find_inv(p_steck->chislo);
        find_obmen(p_steck->chislo,ks1);
        free(ks1);
        zn[0]='-';
        zn[1]='\0';
    }
    else{
        zn[0]='+';
        zn[1]='\0';
    }
    //проверка знака
    
    for(int i=0;i<3;i++){
        znachenie[i]=p_steck->chislo[i];
    }
}

int main(){
    unsigned char s[200],h[50],kh[3],f[2],c[9];                               
    
    int *a =malloc(sizeof(int));
    printf("%p\n",a);
    free(a);

    scanf("%s",s);
    find_obr(s,h,f,kh);
    printf("\n %s \n", h);
    find_dec(kh,c);
    if(f[0] =='-'){
        printf("\nRezultat:\n %s%s \n", f,c);
    }
    else{
        printf("\nRezultat:\n %s \n", c);
    }
    
    a=malloc(sizeof(int));
    printf("%p\n",a);
    free(a);
    
    return 0;
}