#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct TwoBodyModel{
	double mass1, mass2, massTot, ec, massRatio, step, time;
	double u[4];
	double coord[4];
	struct TwoBodyModel* next;
}*TBM;

struct TwoBodyController{

}*TBC;

void *derivative(struct TwoBodyModel *TBM){
	double *r, distanceR;
	float *du;
	int i=0;
	du=(float*)malloc(4*sizeof(float));
	r=(double*)malloc(4*sizeof(double));
	r[0]=TBM->u[0];
	r[1]=TBM->u[1];
	distanceR = sqrt(pow(r[0], 2) + pow(r[1], 2));	
	
	for(i = 0; i < 2; i++){
		du[i] = TBM->u[i + 2];
        du[i + 2] = -((1 + TBM->massRatio) * r[i]) / pow(distanceR, 3);
	} 
	return du;
	
}

void init(struct TwoBodyModel* TBM){
	
	TBM->mass1 = 1;
	TBM->mass2 = 1*TBM->massRatio;
	TBM->massTot = TBM->mass1+TBM->mass2;
	TBM->coord[0] = 0, TBM->coord[1] = 0, TBM->coord[2] = 0, TBM->coord[3] = 0;
	TBM->u[0] = 1, TBM->u[1] = 0,  TBM->u[2] = 0,  TBM->u[3] = sqrt((1 + TBM->massRatio) * (1 + TBM->ec));   
	
}

void newCoord(struct TwoBodyModel *TBM){
	double c1 = (TBM->mass2 / TBM->massTot);   
	double c2 = (TBM->mass1 / TBM->massTot);
	
	TBM->coord[0] = -c2 * TBM->u[0];
    TBM->coord[1] = -c2 * TBM->u[1];
    TBM->coord[2] = c1 * TBM->u[0];
    TBM->coord[3] = c1 * TBM->u[1];

}


void eulers(struct TwoBodyModel *TBM){
	float *du;
	int i;
	du = derivative(TBM);
    
    for(i=0; i < 4; i++){
    	TBM->u[i] = TBM->u[i] + TBM->step*du[i];
	}
}


void eulerCalc(struct TwoBodyModel *TBM){
	float *du;	
    int i;
    FILE *fptr;
	fptr = fopen("Omer TwoBodySimulation.txt", "w");
	
	for( i = 0; i<(TBM->time) / (TBM->step); i++){
		eulers(TBM);
		
	newCoord(TBM);
	fprintf(fptr, "%lf", TBM->coord[0]);
	fprintf(fptr, ", %lf", TBM->coord[1]);
	fprintf(fptr, ", %lf", TBM->coord[2]);
	fprintf(fptr, ", %lf\n", TBM->coord[3]);
		
	}	
}

void RK4(struct TwoBodyModel *TBM){
	int i,j;
	float *du;
	
	du=(float*)malloc(4*sizeof(float));
	int len=sizeof(TBM->u) / sizeof(TBM->u[0]);
	
	double a[4] = {TBM->step/2, TBM->step/2, TBM->step, 0 };
    double b[4] = {TBM->step/6, TBM->step/3, TBM->step/3, TBM->step/6};
    
    double u0[4]= {0,0,0,0};
    double ut[4] = {0,0,0,0};
    
    for(i = 0 ; i < len; i++){
        u0[i] = TBM->u[i];
        ut[i] = 0;
		}  
     for(j = 0; j<4; j++){
       	    du = derivative(TBM);
            int i;
            for(i=0; i<len; i++){
                TBM->u[i] = u0[i] + a[j]*du[i];
                ut[i] = ut[i] + b[j]*du[i];
                
		}  
	}
        for (i = 0; i < len; i++){
            TBM->u[i] = u0[i] + ut[i];
	}
}

void RK4Calc(struct TwoBodyModel *TBM){
	int i;
	float *du;    
    FILE *fptr;
	fptr=fopen("TwoBodySimulation.txt", "w");
    
	for( i = 0; i<(TBM->time)/(TBM->step); i++){
		RK4(TBM);
		
	newCoord(TBM);
	fprintf(fptr, "%lf", TBM->coord[0]);
	fprintf(fptr, ", %lf", TBM->coord[1]);
	fprintf(fptr, ", %lf", TBM->coord[2]);
	fprintf(fptr, ", %lf\n", TBM->coord[3]);
		
	}
	
}




void menu(struct TwoBodyModel *TBM){
	int selection;
 	int i;
   	FILE *fptr;
	fptr=fopen("TwoBodySimulation.txt", "w");

    printf("Please enter the mass ratio of the planets: ");
    scanf("%lf", &TBM->massRatio);
    printf("Please enter the eccentricity of the planets: ");
    scanf("%lf", &TBM->ec);
    printf("Time: ");
    scanf("%lf", &TBM->time);
    printf("Step Size: ");
    scanf("%lf", &TBM->step);
    init(TBM);

    printf("Please choose the desired method:\n1:Runge Kutta Method\n2:Euler's Method\n");
    scanf("%d", &selection);


	for(i=0;i<1;i++){
		if(selection < 1 || selection > 2){
			printf("\nPlease choose a valid option.\n");
		}
		else{
			if(selection == 1)
				RK4Calc(TBM);
			else
				eulerCalc(TBM);
		}
	}

    
	
}


int main(){
	struct TwoBodyModel TBM;
    struct TwoBodyController TBC;
	menu(&TBM);

}














