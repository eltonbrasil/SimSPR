#ifndef FRESNEL_H
#define FRESNEL_H


class Fresnel
{
public:
    Fresnel();
    float n_1= 1;
    float n_2= 1.5168;

    float u_1= 1;
    float u_2= 1;

    double theta_t, rp_wave, tp_wave, rs_wave, ts_wave;

    void FresnelTermP(double);
    void FresnelTermS(double);
};


#endif // FRESNEL_H
