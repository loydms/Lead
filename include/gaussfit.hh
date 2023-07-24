#ifndef gaussfit_h
#define gaussfit_h
/*
double gauss(double x, double mean, double a, double s)
double derivative_mean(double x, double y, double mean, double a, double s)
double derivative_sig(double x, double y, double mean, double a, double s)
*/
int gaussfit(std::vector<double> x, std::vector<double>y,
             double params[4], double sig, double damps[3]);







#endif
