
#include <numeric>
#include <iostream>
#include <math.h>
#include <vector>

double sq(double x){return x * x;}

double gauss(double x, double mean, double a, double s)
{
  return a * exp(- sq(x - mean) / s);
}

double double_gauss(double x, double mean, double a0,
                    double a1, double s1, double s2)
{

  return a0 * (gauss(x, mean, a1, s1) + gauss(x, mean, 1-a1, s2));
}



double derivative_a0(double x, double y, double mean, double a0,
                     double a1, double s1, double s2)
{
  return - 2 * (double_gauss(x, mean, a0, a1, s1, s2)/a0) *
              (double_gauss(x, mean, a0, a1, s1, s2) - y);
}

double derivative_a1(double x, double y, double mean, double a0,
                     double a1, double s1, double s2)
{
  /// the factored out gauss is divided by a, i.e. a = 1

  return - 2 * a0 *((exp(-sq(x-mean)/s1) - exp(-sq(x-mean)/s2)) *
                   (double_gauss(x, mean, a0, a1, s1, s2) - y));
}

double derivative_s1(double x, double y, double mean, double a0,
                     double a1, double s1, double s2)
{
  double derpart = a0 * (sq(x - mean) / sq(s1)) * gauss(x, mean, a1, s1);
  return - 2 * derpart * (double_gauss(x, mean, a0, a1, s1, s2) - y);
}

double derivative_s2(double x, double y, double mean, double a0,
                     double a1, double s1, double s2)
{
  double derpart = a0 * (sq(x - mean) / sq(s2)) * gauss(x, mean, 1-a1, s2);
  return - 2 * derpart * (double_gauss(x, mean, a0, a1, s1, s2) - y);
}


int gaussfit(std::vector<double> x, std::vector<double>y,
             double params[4], double sig, double damps[3])
{
  double ysum = std::accumulate(y.begin(),y.end(),0.0);
  int length = y.size();
  double sum = std::inner_product(x.begin(),x.end(),y.begin(),0.0);
  double mean = sum/ysum;
  double error{};
  double errorprev = 1;
  double der0sum{0};
  double der1sum{0};
  double der2sum{0};
  double der3sum{0};
  int count = 0;
  bool loop = true;
  while ((std::abs(error - errorprev) > sig) && loop)
  {
    count += 1;
    //if (count > 10){return 1;}
    //if (count == 10){loop = false;}
    errorprev = error;
    error = 0;
    der0sum = 0;
    der1sum = 0;
    der2sum = 0;
    der3sum = 0;
    for (int i = 0; i < length; i++)
    {
      der0sum += derivative_a0(x[i], y[i], mean,
                               params[0], params[1], params[2], params[3]);
      der1sum += derivative_a1(x[i], y[i], mean,
                               params[0], params[1], params[2], params[3]);
      der2sum += derivative_s1(x[i], y[i], mean,
                               params[0], params[1], params[2], params[3]);
      der3sum += derivative_s2(x[i], y[i], mean,
                               params[0], params[1], params[2], params[3]);
      double answer = double_gauss(x[i], mean, params[0],
                                   params[1], params[2], params[3]);
      //std::cout << i << ' ' <<  y[i] << ' ' << answer << std::endl;
      error += sq(y[i] - answer);
    }
    error /= length;
    //std::cout<< 'd' << der0sum << ' ' << der1sum << ' ' << der2sum << ' ' << der3sum << std::endl;
    //std::cout << der0sum << ' ' << damps[0] << ' ' << params[0] << std::endl;
    params[0] += der0sum * damps[0] * params[0];
    params[1] += der1sum * damps[1] * params[1];
    if (params[1] > 1){params[1] = 1;}
    if (params[1] < 0){params[1] = 0;}
    params[2] += der2sum * damps[2] * params[2];
    params[3] += der3sum * damps[2] * params[3];
    //std::cout << "e" << error << std::endl;
    //std::cout << 'p' << params[0] << ' ' << params[1]
    //          << ' ' << params[2] << ' ' << params[3] << std::endl;
  }
  std::cout << "Convergence reached with an error of " << error/length << std::endl;
  return 0;
}


/*
//How to run this function:
int main()
{
  std::vector<double> x;
  for (double i = 0; i < 16; i++) {
    x.push_back(i);
  }
  std::vector<double> y = {0.032, 0.044, 0.043, 0.040,
                           0.044, 0.058, 0.070, 0.144,
                           0.151, 0.084, 0.065, 0.054,
                           0.054, 0.040, 0.042, 0.035};
  double params[4] = {0.2, 0.754, 1.1, 100};
  double damps [3] = {0.1,0.1,1};
  if(gaussfit(x,y,params,0.0000001,damps))
  {
    std::cout << "Error - Convergence not reached.  Try different initial guesses" << std::endl;
  };
  std::cout << params[0] << ' ' << params[1] << std::endl;
  std::cout << params[2] << ' ' << params[3] << std::endl;
  return 0;
}
*/
