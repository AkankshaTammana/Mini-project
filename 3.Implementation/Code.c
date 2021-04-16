#include <stdio.h>
#include <math.h>

int main()
{
    float r, l, x, L, radius, z;
    float v1, i1, p1, pf1, v2, i2, pf2, p2;
    float closs, total_closs;
    float p, i, pf, v, v3;
    float rloss, zloss, reg, n;
    char b;
    
    label1:
    printf("Specify the parameters of the transmission line: \n");
    printf("Resistence per meter in ohms: ");
    scanf("%f", &r);
    printf("Inductance per meter in milli-henry: ");
    scanf("%f", &l);
    printf("Lenght of the transmission line and radius in km and cm respectively: ");
    scanf("%f %f", &L, &radius);
    printf("Are there any load specifications(Either Y or N): \n");
    scanf(" %c", &b);
    printf("Enter the input parameters: \n");
    printf("Input voltage and current in kvolts and amperes respectively: ");
    scanf("%f %f", &v1, &i1);
    printf("Input power factor(range must be between 0 and 1): ");
    scanf("%f", &pf1);
    printf("\n");
    
    //Calculating the impedence of the transmission line, generally denoted as z
    x = (2 * 3.14 * 50 * l) / 1000;
    z = (sqrt(r*r + x*x)) * (L);
    
    //Calculating the corona losses of the transmission line, here denoted as total_closs
    closs = (244 * 75 * sqrt(radius/225) * (0.28 * v1) * (0.28 * v1)) / 10000000;   //Calculated for per km
    total_closs = closs * L;                                                        //Calculated for total length of transmission line

    v2 = (v1*1000 - i1*z)/1000;

    p2 = (v1*1000 * i1 * pf1) - (i1 * i1 * z + total_closs * 1000);                 //Calculated output power in watts
    p2 = p2 / 1000;                                                                 //Converting output power from watts to kilo-watts

    //Calculating output power factor
    pf2 = p2 / (i1 * v2);
    if(b != 'Y'){
        printf("The detailed analysis of the transmission line at taken voltage and current are as follows \n");
    }
    
    if(b == 'Y'){
        
        printf("Enter the laod specifications\n");
        printf("Enter load in kWatts: ");
        scanf("%f", &p);
        printf("Enter load current in amperes and power factor: ");
        scanf("%f %f", &i, &pf);
        printf("\n");
        printf("The detailed analysis of the transmission line at taken voltage and current are as follows \n");
        
        if(p2 - p > 50){
            printf("The load is decreased suddenly\n");
            printf("So, the tappings of the input transformer should be changed\n");
            v = p / (i * pf);
            v3 = i*z/1000 + v;
            printf("The tappings must be changed in such a way that voltage at the input side is %f\n", v3);
        }
        else if(p2 - p < -50){
            printf("The load is increased suddenly\n");
            printf("So, the tappings of the input transformer should be changed\n");
            v = p / (i * pf);
            v3 = i*z/1000 + v;
            printf("The tappings must be changed in such a way that voltage at the input side is %f\n", v3);
        }
        else{
            v = v2;
            v3 = v1;
            printf("Load variations are negligible\n");
            printf("No need to change the tappings of the input transformer\n");
        }
        v1 = v3;
        v2 = v;
        i1 = i;
        pf1 = pf;
        pf2 = pf;
        p2 = p;
    }
    
    p1 = (v1*1000 * i1 * pf1) / 1000;
    printf("Output voltage of the transmission line in kv    : %fkv\n", v2);
    printf("Power at sending end of transmission line in kw  : %fkw\n", p1);
    printf("Power at receiving end of transmission line in kw: %fkw\n", p2);
    
    //Calculating total copper losses
    rloss = (i1 * i1 * r * L) / 1000;
    printf("Resistive losses of the transmission line in kw  : %fkw\n", rloss);
    
    //Calculating total Impedence losses
    zloss = (i1 * i1 * z) / 1000;
    printf("Impedence losses of the transmission line in kw  : %fkw\n", zloss);
    
    printf("Corona losses of the transmission line in kw     : %fkw\n", total_closs);
    
    //Calculating the voltage regulation of the transmission line
    reg = (v1 - v2) / v2 * 100;
    printf("Regulation of the transmission line              : %f\n", reg);
    
    //Calculating the efficiency of the transmission line
    n = (p2 / p1) * 100;
    printf("Efficiency of the transmission line              : %f\n", n);
    if(n < 85 || abs(reg) > 20 ){
        printf("Considered parameters are not suitable, so try another parameters\n");
        printf("\n");
        goto label1;
    }
    
    return 0;
}


