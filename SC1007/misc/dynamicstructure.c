#include <stdio.h>
#include <stdlib.h>

struct node {
    int age;
    float height;
};

typedef struct node stud_t;

int main()
{

    int num;
    scanf("%d", &num);
    stud_t *S1ptr = (stud_t *) malloc(sizeof(stud_t)*num);

    int i;
    for(i = 0; i < num; i++){
        S1ptr[i].age = i * 5;
        S1ptr[i].height = i * 7.2;
    }
    for(i = 0;i < num;i++){
        printf("%d %f\n", S1ptr[i].age, S1ptr[i].height);
    }

    free(S1ptr);
    return 0;

}
